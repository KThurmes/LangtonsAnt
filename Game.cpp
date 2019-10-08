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
    gameBoard.setAnt((antRow-1),(antCol-1));
}

void Game::playGame()
{
    int numMovesCompleted = 0;

    //make moves, printing game board between each.
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