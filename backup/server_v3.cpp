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

        char data[1024];
        while (true) {
            stream.read(data, sizeof(data));
            std::streamsize length = stream.gcount();
            if (length > 0) {
                std::cout.write(data, length);
                std::cout << std::endl;

                // 发送确认消息
                stream << "Received " << length << " bytes" << std::endl;
            }

            if (stream.eof()) break; // 检测到流结束
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}