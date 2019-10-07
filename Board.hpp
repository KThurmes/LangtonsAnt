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
    void moveAnt();
    void printBoard();
    void setBoardLayout();
    void setRows(int);
    void setCols(int);
    void deleteBoardLayout();
    void setAnt(int, int);
};

#endif