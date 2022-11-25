#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/beast/core/make_printable.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <thread>

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
            if (client_message == "register") {
                // Send a message back
                const_buffer message("Hello, world!", 13);

                // This sets all outgoing messages to be sent as text.
                // Text messages must contain valid utf8, this is checked
                // when reading but not when writing.
                ws.text(true);

                // Write the buffer as text
                ws.write(message);
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