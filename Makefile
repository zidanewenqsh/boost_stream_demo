CXX = g++
CXXFLAGS = -Wall -Wextra -g
BOOST_LIBS = -lboost_system -lpthread
TARGETS = server client boost_stream boost_timer

all: $(TARGETS)

server: server.cpp
	$(CXX) $(CXXFLAGS) -o server server.cpp $(BOOST_LIBS)

client: client.cpp
	$(CXX) $(CXXFLAGS) -o client client.cpp $(BOOST_LIBS)

boost_stream: boost_stream.cpp
	$(CXX) $(CXXFLAGS) -o boost_stream boost_stream.cpp $(BOOST_LIBS)

boost_timer: boost_timer.cpp
	$(CXX) $(CXXFLAGS) -o boost_timer boost_timer.cpp $(BOOST_LIBS)
	
clean:
	rm -f $(TARGETS)
