#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <memory>

using boost::asio::ip::tcp;

void handle_client(std::shared_ptr<tcp::iostream> stream) {
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "Thread ID: " << this_id << std::endl;
    std::string message;
#if 0
    char data[1024];
    while (true) {
        if (stream->eof()) {
            stream->clear(); // 清除eof标志
            break; // 检测到流结束
        }
        // (*stream).read(data, sizeof(data));
        // if ((*stream).eof()) break; // 检测到流结束
        // (*stream).read(data, sizeof(data));
        // (*stream).readsome(data, sizeof(data));
        // 使用boost::asio::read和boost::asio::transfer_at_least来读取至少一个字节的数据
        // boost::asio::read(*stream->rdbuf(), boost::asio::buffer(data), boost::asio::transfer_at_least(1));
        stream->getline(data, sizeof(data));
        std::streamsize length = stream->gcount();
        if (length > 0) {
            // if data is "END" or not
            std::string receivedData(data, length-1);

            if (receivedData == "END") {
                *stream << "END" << std::endl;
            } else {
                std::cout << "Received: " << receivedData << std::endl;
                std::cout << receivedData.size() << std::endl;
            }
            std::cout << "length:" << length << std::endl;
            std::cout.write(data, length);
            std::cout << std::endl;

            // 发送确认消息
            *stream << "Received " << length << " bytes" << std::endl;
            stream->flush();
        } 
    }
#else
    while (true) {
        if (stream->eof()) {
            stream->clear(); // 清除eof标志
            break; // 检测到流结束
        }
        // std::string reply;
        std::getline(*stream, message);
        if (message == "END") {
            *stream << "END" << std::endl;
            break;
        }
        std::cout << "Received: " << message << std::endl;
        *stream << "Message received: " << message.size() << std::endl;



        // if (length > 0) {
        //     // if data is "END" or not
        //     std::string receivedData(data, length-1);

        //     if (receivedData == "END") {
        //         *stream << "END" << std::endl;
        //     } else {
        //         std::cout << "Received: " << receivedData << std::endl;
        //         std::cout << receivedData.size() << std::endl;
        //     }
        //     std::cout << "length:" << length << std::endl;
        //     std::cout.write(data, length);
        //     std::cout << std::endl;

        //     // 发送确认消息
        //     *stream << "Received " << length << " bytes" << std::endl;
        //     stream->flush();
        // } 
    }
#endif

    std::cout << "Client disconnected." << std::endl;
}

int main() {
    try {
        boost::asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1234));

        while (true) {
            auto stream = std::make_shared<tcp::iostream>();
            acceptor.accept(*stream->rdbuf());

            std::thread(handle_client, stream).detach();
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
