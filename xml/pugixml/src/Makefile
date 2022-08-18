
CXX=g++
CXXFLAGS= -g -Wall
SRCS=parse_xml2.cpp pugixml.cpp
OBJS=$(SRCS:.cpp=.o)
EXEC=parse_xml

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