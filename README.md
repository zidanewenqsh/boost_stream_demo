# boost_stream_demo
使用boost的流传输实现服务器和客户端案例
# boost install
## version <= 1.65
```bash
sudo apt-get install libboost-all-dev
```

## version >= 1.66
[boost官网](https://www.boost.org/users/download/)

```bash
wget https://boostorg.jfrog.io/artifactory/main/release/1.70.0/source/boost_1_70_0.tar.gz
tar -zxvf boost_1_70_0.tar.gz
cd boost_1_70_0
./bootstrap.sh
./b2
sudo ./b2 install
```

## remove old boost
```bash
sudo apt-get remove libboost-all-dev
sudo apt-get remove libboost-system-dev libboost-thread-dev
```