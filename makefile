#target: dependencies
#	rule to build
#must use tab for rules

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
OBJS = Ant.o Board.o Game.o main.o Menu.o runMenu.o getValidInt.o getNumberBetween.o
SRCS = Ant.cpp Board.cpp Game.cpp main.cpp Menu.cpp runMenu.cpp getValidInt.cpp getNumberBetween.cpp
HEADERS = Ant.hpp Board.hpp Game.hpp Menu.hpp runMenu.hpp getValidInt.hpp getNumberBetween.hpp
#LDFLAGS = -lboost_date_time (any libraries you want to link)

proj1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o proj1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o proj1

valgrind:
	valgrind proj1