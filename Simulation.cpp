/********************************************************************* 
** Author: Katheen Thurmes
** Date: 8 Oct., 2019
** Description: A simulation object contains all the information 
needed to run a full simulation. It contains a board, an ant, and it 
keeps track of how many moves the ant will do in the simulation. it 
has constructor functions and a function which starts a simulation 
(playGame()). MoveAnt and antStep are functions that control how the 
ant moves across the board throughout the simulation.
*********************************************************************/
#include "Simulation.hpp"
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Simulation::Simulation()
{
}

Simulation::Simulation(int theMoves, int nRows, int nCols, int antRow, int antCol)
{
    totalMoves = theMoves;
    gameBoard = Board();
    gameBoard.setRows(nRows);
    gameBoard.setCols(nCols);
    gameBoard.setBoardLayout();
    agentAnt = Ant(antRow, antCol, 0);
}

/********************************************************************* 
** Description: playGame tells the board to make the ant move, 
keeping track of how many moves the ant has made and stopping when it 
gets to the prescribed number of moves. It also tells the board to 
print its layout after each move. Finally, it deletes the game board 
as soon as the scenario has been played out, preventing memory leaks.
*********************************************************************/
void Simulation::playGame()
{
    int numMovesCompleted = 0;

    //Make moves, printing game board between each.
    while (numMovesCompleted < totalMoves)
    {
        gameBoard.printBoard(agentAnt.getLocationRow(), agentAnt.getLocationCol());
        moveAnt();
        numMovesCompleted++;
    }
    gameBoard.printBoard(agentAnt.getLocationRow(), agentAnt.getLocationCol());

    //Delete the game board when the scenario has been played out
    gameBoard.deleteBoardLayout();
}

/********************************************************************* 
** Description: This function will turn the ant in the direction 
prescribed in the Langton's ant directions. it also changes the color 
of the square that the ant is currently on. It does not move the ant, 
but calls antStep() to move the ant.
*********************************************************************/
void Simulation::moveAnt()
{
    int antRow = agentAnt.getLocationRow();
    int antCol = agentAnt.getLocationCol();

    char antSpaceColor = gameBoard.getSpaceColor(antRow, antCol);

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

/********************************************************************* 
** Description: antStep() moves the ant forward in the direction 
indicated by the ant's orientation. If the ant would go off the board 
if it moved forward one space, then it instead stays where it is. The 
square's color will only be changed if the ant moves off of it.
*********************************************************************/
void Simulation::antStep()
{
    int antRow = agentAnt.getLocationRow();
    int antCol = agentAnt.getLocationCol();
    int antOrientation = agentAnt.getOrientation();

    //Facing up
    if (antOrientation == 0)
    {
        if (antRow + 1 < gameBoard.getRows())
        {
            gameBoard.toggleColor(antRow, antCol);
            agentAnt.setLocation(antRow + 1, antCol);
        }
    }
    //Facing right
    if (antOrientation == 1)
    {
        if (antCol + 1 < gameBoard.getCols())
        {
            gameBoard.toggleColor(antRow, antCol);
            agentAnt.setLocation(antRow, antCol + 1);
        }
    }
    //Facing down
    if (antOrientation == 2)
    {
        if (!(antRow - 1 < 0))
        {
            gameBoard.toggleColor(antRow, antCol);
            agentAnt.setLocation(antRow - 1, antCol);
        }
    }
    //Facing left
    if (antOrientation == 3)
    {
        if (!(antCol - 1 < 0))
        {
            gameBoard.toggleColor(antRow, antCol);
            agentAnt.setLocation(antRow, antCol - 1);
        }
    }
}