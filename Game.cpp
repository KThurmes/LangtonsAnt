/********************************************************************* 
** Author: Katheen Thurmes
** Date: 8 Oct., 2019
** Description: A game object contains all the information needed to 
run a full simulation. It contains a board (which contains an ant) 
and it keeps track of how many moves the ant will do in the 
simulation. it has constructor functions and a function which starts 
a simulation (playGame()).
*********************************************************************/ 
#include "Game.hpp"
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Game::Game()
{
}

Game::Game(int theMoves, int nRows, int nCols, int antRow, int antCol)
{
    totalMoves = theMoves;
    gameBoard = Board();
    gameBoard.setRows(nRows);
    gameBoard.setCols(nCols);
    gameBoard.setBoardLayout();
    gameBoard.setAnt((antRow),(antCol));
}

/********************************************************************* 
** Description: playGame tells the board to make the ant move, 
keeping track of how many moves the ant has made and stopping when it 
gets to the prescribed number of moves. It also tells the board to 
print its layout after each move. Finally, it deletes the game board 
as soon as the scenario has been played out, preventing memory leaks.
*********************************************************************/
void Game::playGame()
{
    int numMovesCompleted = 0;

    //Make moves, printing game board between each.
    while (numMovesCompleted < totalMoves)
    {
        gameBoard.printBoard();
        gameBoard.moveAnt();
        numMovesCompleted++;
    }
    gameBoard.printBoard();

    //Delete the game board when the scenario has been played out
    gameBoard.deleteBoardLayout();
}