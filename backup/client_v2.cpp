#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_service io_service;
        tcp::iostream stream("localhost", "1234");

        if (!stream) {
            std::cerr << "Unable to connect: " << stream.error().message() << std::endl;
            return 1;
        }

        std::string messages[] = {"Hello", "World", "exit"};
        std::string reply;

        for (const auto& msg : messages) {
            stream << msg << std::endl;
            std::getline(stream, reply);
            std::cout << "Server replied: " << reply << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
