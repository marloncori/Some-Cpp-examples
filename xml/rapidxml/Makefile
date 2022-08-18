
CXX=g++
CXXFLAGS= -g -Wall -Werror
SRCS=parse_xml.cpp rapidxml.hpp
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