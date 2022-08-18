
CXX=g++
CXXFLAGS= -g -Wall
SRCS=parse_json.cpp dist/jsoncpp.cpp
OBJS=(SRCS:.cpp=.o)
EXEC=parse

all:
	$(SRCS) $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $< -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o

.PHONY:
	all clean	