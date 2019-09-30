#ifndef BOARD_HPP
#define BOARD_HPP

#include "Ant.hpp"

class Board
{
private:
    char **boardLayout;
    Ant agentAnt;
    int rows;
    int cols;
    char getSpaceColor(int, int);
    void antStep();
    void setBoard();

public:
    Board();
    Board(int, int, int, int, int);
    ~Board();
    void moveAnt();
    void printBoard();
};

#endif