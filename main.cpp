// https://www.youtube.com/watch?v=ZSefPfZqxpo&t=1858s
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <iostream>
#include <string>
#include <thread>
// g++ -I /usr/include/boost -pthread websocket.cpp 

using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

int main() {
    auto const address = boost::asio::ip::make_address("127.0.0.1");
    auto const port = static_cast<unsigned short>(std::atoi("8083"));

    boost::asio::io_context ioc{1};

    tcp::acceptor acceptor{ioc, {address, port}};

    while(1)
    {
        tcp::socket socket{ioc};
        acceptor.accept(socket);
        std::cout<<"socket accepted"<<std::endl;

        std::thread{}.detach();
    }

    return 0;
}
