#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/beast/core/make_printable.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include "profile_class.h"
#include "profile_collection.h"
#include "post_collection.h"

// change file paths to your filepath
profile_collection profiledb("C:\\Users\\conrad\\team-17-indian\\db\\Profile.db");
PostCollection postdb("C:\\Users\\conrad\\team-17-indian\\db\\Post.db");
using namespace std;
using namespace boost::beast;
using namespace boost::asio;
namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

//------------------------------------------------------------------------------




// Echoes back all received WebSocket messages
void
do_session(tcp::socket socket)
{
    try {
        // Construct the stream by moving in the socket
        websocket::stream<tcp::socket> ws{ std::move(socket) };

        // Set a decorator to change the Server of the handshake
        ws.set_option(websocket::stream_base::decorator(
                [](websocket::response_type& res) {
                    res.set(http::field::server,
                            std::string(BOOST_BEAST_VERSION_STRING) +
                            " websocket-server-sync");
                }));

        // Accept the websocket handshake
        ws.accept();

        for (;;) {
            // This buffer will hold the message from the client
            flat_buffer buffer;
            // Read the message coming from the client
            ws.read(buffer);
            // Put the buffer contents in a string
            string client_message = buffers_to_string(buffer.cdata());
            // Print the client message to terminal
            cout << client_message << endl;
            // Do logic on the message

            // Turn message into an array delimited by  :
            // create array
            int array_size = count(client_message.begin(), client_message.end(), ':') + 1;
            string message_array[array_size];

            // split up message into array
            int i =0;
            string del = ":";
            int start, end = -1*del.size();
            do {
                start = end + del.size();
                end = client_message.find(del, start);
                message_array[i] = client_message.substr(start, end - start);
                i++;
                //cout << client_message.substr(start, end - start) << endl;
            } while (end != -1);

            string message_type = message_array[0];

            // TODO: Sign in
            if (message_type == "signin") {
                string mail = message_array[1];
                string pass = message_array[2];

            }

            // Create post
            if (message_type == "post") {
                try {
                    string owner = message_array[1];
                    string title = message_array[2];
                    string description = message_array[3];
                    int type = stoi(message_array[4]);

                    Post post(owner, title, description, type);
                    postdb.storeToPostDB(post);
                }
                catch (...){}


            }
            // TODO: Add comment
            if (message_type == "comment") {

            }

            // TODO: up vote
            if (message_type == "upvote") {
                string title = message_array[1];

            }
            // TODO: downvote
            if (message_type == "downvote") {

            }
            // Register an account
            if (message_type == "register") {
                // Message to send to client
                const_buffer registerfail("Unable to make account", 22);
                const_buffer registerpass("Account Created", 15);
                bool isCreated = false;
                // get parameters
                string mail = message_array[1];
                string user = message_array[2];
                string pass = message_array[3];
                string confirmPass = message_array[4];
                // try to create user
                try {
                    try{
                        profile_class profile(mail, user, pass, confirmPass);
                        // send to database
                        profiledb.storeToProfileDB(profile);
                        isCreated = true;
                    }
                    catch (profile_class) {
                        cout << "Unable to make account" << endl;
                        const_buffer message("Unable to make account", 22);
                    }

                }
                catch (...){
                    cout << "Unable to make account" << endl;
                    const_buffer message("Unable to make account", 22);
                }



                // This sets all outgoing messages to be sent as text.
                // Text messages must contain valid utf8, this is checked
                // when reading but not when writing.
                ws.text(true);

                // Send a message back saying if the account was created
                if (isCreated == true) ws.write(registerpass);
                else ws.write(registerfail);
            }

        }
    } catch (beast::system_error const& se) {
        // This indicates that the session was closed
        if (se.code() != websocket::error::closed)
            std::cerr << "Error: " << se.code().message() << std::endl;
    } catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


//------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    // Create profile db
    profiledb.create_profileDB();
    profiledb.createProfileTable();

    // Create post db
    postdb.createPostDB();
    postdb.createPostTable();
    try {
        auto const address = net::ip::make_address("127.0.0.1");
        auto const port = static_cast<unsigned short>(2236);

        // The io_context is required for all I/O
        net::io_context ioc{ 1 };

        // The acceptor receives incoming connections
        tcp::acceptor acceptor{ ioc, {address, port} };
        std::cout << "server listen port:" << port << std::endl;
        for (;;) {
            // This will receive the new connection
            tcp::socket socket{ ioc };

            // Block until we get a connection
            acceptor.accept(socket);
            std::cout << "new session coming, address:"
                      << socket.remote_endpoint().address().to_string()
                      << ", port:" << socket.remote_endpoint().port() << std::endl;

            // Launch the session, transferring ownership of the socket
            std::thread(
                    &do_session,
                    std::move(socket)).detach();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}