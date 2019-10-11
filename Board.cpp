/********************************************************************* 
** Author: Katheen Thurmes
** Date: 8 Oct., 2019
** Description: A board object designed for use in the implementation 
of a Langton's Ant simulation. Its data members include an ant 
object, a board layout in the form of a 2D array, and the number of 
rows and columns the board has.
It has member functions that can tell the ant to make a move, return 
the color of a space, set up the 2D array with all white spaces and 
a visual location of the ant, a function to delete the dynamically 
allocated 2D boardLayout array, a function to display the 2D array 
on the console, and to manipulate its ant.
*********************************************************************/

#include "Board.hpp"
#include "Ant.hpp"
#include <iostream>

using std::cout;
using std::endl;

Board::Board()
{
    //Use default ant constructor
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

/********************************************************************* 
** Description: setBoardLayout uses the rows and cols data members to
construct a 2D array which will represent the game board. the 2D array 
is dynamically allocated in memory, so once the board is finished
being used, the program must call the deleteBoardLayout() function.
*********************************************************************/
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

    boardLayout[1][1] = '#';
}

/********************************************************************* 
** Description: Deletes the dynamically allocated 2D array 
(boardLayout) that is used to represent the game board.
*********************************************************************/
void Board::deleteBoardLayout()
{
    //Delete each sub-array
    for (int i = 0; i < rows; i++)
    {
        delete[] boardLayout[i];
    }

    //Delete the array itself
    delete[] boardLayout;
}

/********************************************************************* 
** Description: Prints a representation of the game board to the 
screen. Blank spaces represent white spaces and # represent black 
spaces. * represents the location of the ant.
*********************************************************************/
void Board::printBoard()
{
    int antRow = agentAnt.getLocationRow();
    int antCol = agentAnt.getLocationCol();

    //Top border
    for (int i = 0; i < cols + 2; i++)
    {
        cout << "-";
    }
    cout << endl;

    //Print each row
    for (int i = (rows - 1); i >= 0; i--)
    {

        cout << "|"; //left side border

        //Print each column
        for (int j = 0; j < cols; j++)
        {
            //Print the location of the ant
            if (i == antRow && j == antCol)
            {
                cout << '*';
            }

            //Print the color of all other squares
            else
            {
                cout << boardLayout[i][j];
            }
        }
        cout << "|"; //right side border
        cout << endl;
    }

    //Bottom border
    for (int i = 0; i < cols + 2; i++)
    {
        cout << "-";
    }
    cout << endl;
}

/********************************************************************* 
** Description: This function will turn the ant in the direction 
prescribed in the Langton's ant directions. it also changes the color 
of the square that the ant is currently on. It does not move the ant, 
but calls antStep() to move the ant.
*********************************************************************/
void Board::moveAnt()
{
    int antRow = agentAnt.getLocationRow();
    int antCol = agentAnt.getLocationCol();

    char antSpaceColor = getSpaceColor(antRow, antCol);

    //Ant is on white space
    if (antSpaceColor == ' ')
    {
        agentAnt.turnRight();
    }

    //Ant is on black space
    else
    {
        agentAnt.turnLeft();
    }

    antStep();
}

void Board::setAnt(int antRow, int antCol)
{
    agentAnt = Ant(antRow, antCol, 3);
}

/********************************************************************* 
** Description: Returns the color of the space on the board indicated 
by row, col. Returns ' ' for white and '#' for black.
*********************************************************************/
char Board::getSpaceColor(int row, int col)
{
    return boardLayout[row][col];
}

/********************************************************************* 
** Description: antStep() moves the ant forward in the direction 
indicated by the ant's orientation. If the ant would go off the board 
if it moved forward one space, then it instead stays where it is. The 
square's color will only be changed if the ant moves off of it.
*********************************************************************/
void Board::antStep()
{
    int antRow = agentAnt.getLocationRow();
    int antCol = agentAnt.getLocationCol();
    int antOrientation = agentAnt.getOrientation();

    //Facing up
    if (antOrientation == 0)
    {
        if (antRow + 1 < rows)
        {
            toggleColor(antRow, antCol);
            agentAnt.setLocation(antRow + 1, antCol);
        }
    }
    //Facing right
    if (antOrientation == 1)
    {
        if (antCol + 1 < cols)
        {
            toggleColor(antRow, antCol);
            agentAnt.setLocation(antRow, antCol + 1);
        }
    }
    //Facing down
    if (antOrientation == 2)
    {
        if (!(antRow - 1 < 0))
        {
            toggleColor(antRow, antCol);
            agentAnt.setLocation(antRow - 1, antCol);
        }
    }
    //Facing left
    if (antOrientation == 3)
    {
        if (!(antCol - 1 < 0))
        {
            toggleColor(antRow, antCol);
            agentAnt.setLocation(antRow, antCol - 1);
        }
    }
}

/********************************************************************* 
** Description: toggleColor(row, col) will change the color of the 
square at row,col. If it was white, it'll be black and if it was 
black, it'll be white.
*********************************************************************/
void Board::toggleColor(int row, int col)
{

    if (getSpaceColor(row, col) == ' ')
    {
        boardLayout[row][col] = '#';
    }

    else
    {
        boardLayout[row][col] = ' ';
    }
}