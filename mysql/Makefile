
MYSQL_CONCPP_DIR = "C:\\Program Files\\MySQL\\MySQL Server 8.0"
#MYSQL_CONCPP_DIR = "C:\\Program Files\\MySQL\\Connector C++ 8.0"
CPPFLAGS = -I $(MYSQL_CONCPP_DIR)/include -L $(MYSQL_CONCPP_DIR)/lib
LDLIBS = -lmysql
#LDLIBS = -lmysqlcppconn
CXX = g++
CXXFLAGS = -g -Wall -std=c++11
SRCS = mysql_connection_jdbc.cpp 
OBJS = $(SRCS:%.cpp=%.o)
TARGET = mysql_connection_jdbc

all:
	$(SRCS) $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ $(LDLIBS)

.cpp.o: 
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@ $(LDLIBS)

clean: 
	del *.o 

.PHONY:
	all clean

