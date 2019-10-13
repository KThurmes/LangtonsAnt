#target: dependencies
#	rule to build
#must use tab for rules

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
OBJS = Ant.o Board.o Simulation.o main.o runMenu.o getValidInt.o getNumberBetween.o simulationSetup.o
SRCS = Ant.cpp Board.cpp Simulation.cpp main.cpp runMenu.cpp getValidInt.cpp getNumberBetween.cpp simulationSetup.cpp
HEADERS = Ant.hpp Board.hpp Simulation.hpp runMenu.hpp getValidInt.hpp getNumberBetween.hpp simulationSetup.hpp
#LDFLAGS = -lboost_date_time (any libraries you want to link)

proj1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o proj1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o proj1

valgrind:
	valgrind proj1