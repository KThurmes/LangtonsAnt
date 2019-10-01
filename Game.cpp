#include "Game.hpp"
#include <string>
#include <iostream>
#include "Menu.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Game::Game()
{
    totalMoves = 5;
}

Game::Game(int theMoves, int nRows, int nCols, int antRow, int antCol, int antOrient)
{
    totalMoves = theMoves;
    gameBoard = Board();
    gameBoard.setRows(nRows);
    gameBoard.setCols(nCols);
    gameBoard.setBoardLayout();
}

void Game::runStartMenu()
{
    char usersChoice = startMenu.showMenu();
    switch (usersChoice)
    {
    case '1':
        //TODO: get user input on new game. Load up new game
        playGame();
        runEndMenu();
        break;

    case '2':
        //gameBoard.deleteBoardLayout();
        //quit
        break;
    }
    //gameBoard.deleteBoardLayout();
    cout << "Thanks for playing!" << endl;
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
    gameBoard.deleteBoardLayout();
}

void Game::runEndMenu()
{
    char usersChoice = endMenu.showMenu();
    switch (usersChoice)
    {
    case '1':
        playGame();
        runEndMenu();
        break;
    case '2':
        break;
    }
}

void Game::setStartMenu(Menu &sMenu)
{
    startMenu = sMenu;
}

void Game::setEndMenu(Menu &eMenu)
{
    endMenu = eMenu;
}