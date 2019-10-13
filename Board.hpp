#ifndef BOARD_HPP
#define BOARD_HPP

#include "Ant.hpp"

class Board
{
private:
    char **boardLayout;
    int rows;
    int cols;

public:
    Board();
    void setRows(int);
    void setCols(int);
    int getRows();
    int getCols();
    char getSpaceColor(int, int);
    void setBoardLayout();
    void deleteBoardLayout();
    void printBoard(int, int);
    void toggleColor(int, int);
};

#endif