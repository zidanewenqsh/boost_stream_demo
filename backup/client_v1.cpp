#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        // 创建一个流式套接字
        tcp::iostream stream("localhost", "1234");

        if (!stream) {
            std::cerr << "Unable to connect: " << stream.error().message() << std::endl;
            return 1;
        }

        // 从服务器接收消息
        std::string line;
        std::getline(stream, line);
        std::cout << "Server says: " << line << std::endl;

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
