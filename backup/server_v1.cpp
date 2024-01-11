#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        // 监听端口1234上的连接
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 1234));

        for (;;) {
            tcp::iostream stream;
            boost::system::error_code ec;

            // 等待并接受连接
            acceptor.accept(*stream.rdbuf(), ec);

            if (!ec) {
                // 向客户端发送消息
                stream << "Hello, Client!" << std::endl;
            }
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
