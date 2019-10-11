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

public:
    Board();
    void setRows(int);
    void setCols(int);
    void setBoardLayout();
    void deleteBoardLayout();
    void printBoard();
    void moveAnt();
    void setAnt(int, int);
    void toggleColor(int, int);
};

#endif