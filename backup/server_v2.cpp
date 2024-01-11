#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1234));

        tcp::iostream stream;
        acceptor.accept(*stream.rdbuf());

        std::string message;
        while (std::getline(stream, message)) {
            std::cout << "Received: " << message << std::endl;
            if (message == "exit") break;
            stream << "Message received: " << message << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
