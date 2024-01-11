#include <boost/asio.hpp>
#include <iostream>
#include <functional>

void timer_expired(const boost::system::error_code& /*e*/) {
    std::cout << "Timer expired!" << std::endl;
}

int main() {
    // 创建 io_context 对象
    boost::asio::io_context io;

    // 创建定时器，设置为5秒后到期
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

    // 设置定时器到期后执行的回调函数
    t.async_wait(&timer_expired);

    // 运行 io_context 对象，开始执行异步操作
    io.run();

    return 0;
}
   