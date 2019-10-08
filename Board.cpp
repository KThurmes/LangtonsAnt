#include "Board.hpp"
#include "Ant.hpp"
#include <iostream>

using std::cout;
using std::endl;

Board::Board()
{
    //cout << "creating a new generic board!" << endl;

    //Default ant constructor
    Ant player;
    agentAnt = player;

    rows = 0;
    cols = 0;
}

void Board::setRows(int r)
{
    rows = r;
}

void Board::setCols(int c)
{
    cols = c;
}

void Board::setBoardLayout()
{
    boardLayout = new char *[rows]; //An array of pointers to arrays of chars
    for (int i = 0; i < rows; i++)
    {
        boardLayout[i] = new char[cols];
    }

    //Initialize all spaces to white
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            boardLayout[i][j] = ' ';
        }
    }
}

void Board::deleteBoardLayout()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] boardLayout[i];
    }
    delete[] boardLayout;
    cout << "Deleting a boardLayout!" << endl;
}

void Board::printBoard()
{
    int antRow = agentAnt.getLocationRow();
    int antCol = agentAnt.getLocationCol();

    //cout << "Printing board: " << endl;
    for( int i = 0; i < cols + 2 ; i++){
        cout << "-";
    }
    cout << endl;
    for (int i = (rows - 1); i >= 0; i--)
    {
        cout << "|";
        for (int j = 0; j < cols; j++)
        {
            //Print the location of the ant
            if (i == antRow && j == antCol)
            {
                cout << 'X';
            }

            //Print the color of all other squares
            else
            {
                cout << boardLayout[i][j];
            }
        }
        cout << "|";
        cout << endl;
    }
    for( int i = 0; i < cols + 2 ; i++){
        cout << "-";
    }
    cout<<endl;
    //cout << "Ant space: '" << getSpaceColor(antRow, antCol) << "'" << endl;

    //cout << "Ant orientation: " << agentAnt.getOrientation() << endl;
}

char Board::getSpaceColor(int row, int col)
{
    return boardLayout[row][col];
}

void Board::moveAnt()
{
    int antRow = agentAnt.getLocationRow();
    int antCol = agentAnt.getLocationCol();

    char antSpaceColor = getSpaceColor(antRow, antCol);

    //Ant is on white space
    if (antSpaceColor == ' ')
    {
        agentAnt.turnRight();
        boardLayout[antRow][antCol] = '#';
    }

    //Ant is on black space
    else if (antSpaceColor == '#')
    {
        agentAnt.turnLeft();
        boardLayout[antRow][antCol] = ' ';
    }

    else
    {
        //ruh-roh
        //TODO
    }

    antStep();
}

void Board::antStep()
{
    int antRow = agentAnt.getLocationRow();
    int antCol = agentAnt.getLocationCol();
    int antOrientation = agentAnt.getOrientation();

    if (antOrientation == 0)
    {
        if (antRow + 1 < rows)
        {
            agentAnt.setLocation(antRow + 1, antCol);
        }
    }
    if (antOrientation == 1)
    {
        if (antCol + 1 < cols)
        {
            agentAnt.setLocation(antRow, antCol + 1);
        }
    }
    if (antOrientation == 2)
    {
        if (!(antRow - 1 < 0))
        {
            agentAnt.setLocation(antRow - 1, antCol);
        }
    }
    if (antOrientation == 3)
    {
        if (!(antCol - 1 < 0))
        {
            agentAnt.setLocation(antRow, antCol - 1);
        }
    }
}

void Board::setAnt(int antRow, int antCol){
    agentAnt = Ant(antRow, antCol, 1);
}