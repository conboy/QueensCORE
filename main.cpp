// https://www.youtube.com/watch?v=ZSefPfZqxpo&t=1858s
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <iostream>
#include <string>
#include <thread>
// g++ -I /usr/include/boost -pthread main.cpp -o server


using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

int main() {
    auto const address = boost::asio::ip::make_address("172.105.111.5");
    auto const port = static_cast<unsigned short>(std::atoi("443"));

    boost::asio::io_context ioc{2};

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
