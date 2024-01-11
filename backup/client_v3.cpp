#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_service io_service;
        tcp::iostream stream("localhost", "1234");

        if (!stream) {
            std::cerr << "Unable to connect: " << stream.error().message() << std::endl;
            return 1;
        }

        // 发送大量数据
        std::string large_message(10000, 'A');
        stream.write(large_message.c_str(), large_message.size());
        stream << std::endl; // 发送结束标记

        // 接收并打印服务器的回复
        std::string reply;
        while (std::getline(stream, reply)) {
            if (reply.empty()) {
                break; // 如果接收到空字符串，退出循环
            }
            std::cout << "Server replied: " << reply << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
