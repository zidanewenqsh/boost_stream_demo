#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <string>
#include <iostream>

int main() {
    // 使用 Boost 的字符串流
    std::string buffer;
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string>> stream(buffer);
    // 向流中写入数据
    stream << "Hello, Boost!";
    stream.flush(); // 确保数据被写入到字符串

    // 读取并打印数据
    std::cout << "Stream content: " << buffer << std::endl;

    return 0;
}
