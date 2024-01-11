#include <boost/asio.hpp>
#include <cstddef>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "header.h"
using boost::asio::ip::tcp;

const std::string getColorCode(Color color) {
    switch (color) {
        case RED: return REDCOLOR;
        case GREEN: return GREENCOLOR;
        case YELLOW: return YELLOWCOLOR;
        case BLUE: return BLUECOLOR;
        case PURPLE: return PURPLECOLOR;
        case CYAN: return CYANCOLOR;
        case LRED: return LREDCOLOR;
        case LGREEN: return LGREENCOLOR;
        case LYELLOW: return LYELLOWCOLOR;
        case LBLUE: return LBLUECOLOR;
        case LPURPLE: return LPURPLECOLOR;
        case LCYAN: return LCYANCOLOR;
        default: return RESET;
    }
}

int main() {
    try {
        boost::asio::io_service io_service;
        tcp::iostream stream("localhost", "1234");

        if (!stream) {
            std::cerr << "Unable to connect: " << stream.error().message() << std::endl;
            return 1;
        }

        // 发送大量数据
        std::string large_message = "";
        for (int i = 0; i < 1024; i++) {
            large_message += 'a' + i % 26;
            large_message += 'A' + i % 26;
            large_message += '0' + i % 10;
        }
        // large_message += '\n'; // 在消息末尾添加换行符
        std::cout << large_message.size() << std::endl;
        std::cout << large_message << std::endl;
        size_t i = 0,  num = 0, n = 100, j = 0; 
        std::string send_message;
        while (i < large_message.size()) {
            if (i + n > large_message.size()) {
                num = large_message.size() - i;
            } else {
                num = n;
            }
            // std::cout << "Sending: " << large_message.substr(i, num) << ", Size:" << num <<std::endl;
            send_message = getColorCode(static_cast<Color>(j % NumberOfColors));
            send_message += large_message.substr(i, num);
            send_message += RESET;
            // stream.write(send_message.c_str(), send_message.size());
            // stream << std::endl; // 发送结束标记
            stream << send_message << std::endl;
            i += n;
            j++;
        }
        stream << "END" << std::endl;
        // stream.write(large_message.c_str(), large_message.size());
        // stream << std::endl; // 发送结束标记

        // 接收并打印服务器的回复
        std::string reply;
        while (std::getline(stream, reply)) {
            if (reply.empty()) {
                break; // 如果接收到空字符串，退出循环
            }
            if (reply == "END") {
                std::cout << "Server replied: END" << std::endl;
                break; // 接收到结束消息，退出循环
            }
            std::cout << "Server replied: " << reply << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
