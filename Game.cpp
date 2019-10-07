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
/*     int rowCount;
    int colCount;
    int steps;
    int antRow;
    int antCol;

    cout << "Number of rows on the board: " << endl;
    cin >> rowCount;
    cout << "Number of columns on the board: " << endl;
    cin >> colCount;
    cout << "Number of steps during the simulation: " << endl;
    cin >> steps;
    cout << "Starting row of the ant: " << endl;
    cin >> antRow;
    cout << "Starting column of the ant: " << endl;
    cin >> antCol; */

    //Add input validation
}

Game::Game(int theMoves, int nRows, int nCols, int antRow, int antCol)
{
    totalMoves = theMoves;
    gameBoard = Board();
    gameBoard.setRows(nRows);
    gameBoard.setCols(nCols);
    gameBoard.setBoardLayout();
    gameBoard.setAnt(antRow,antCol);
}

/* void Game::runStartMenu()
{
    char usersChoice = startMenu.runMenu();
    switch (usersChoice)
    {
    case '1':
        //TODO: Load up new game
        playGame();
        runEndMenu();
        break;

    case '2':
        //quit
        break;
    }
    cout << "Thanks for playing!" << endl;
} */

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

/* void Game::runEndMenu()
{
    char usersChoice = endMenu.runMenu();
    switch (usersChoice)
    {
    case '1':
        //TODO: Load up new game
        playGame();
        runEndMenu();
        break;

    case '2':
        break;
    }
} */

/* void Game::setStartMenu(Menu &sMenu)
{
    startMenu = sMenu;
}

void Game::setEndMenu(Menu &eMenu)
{
    endMenu = eMenu;
} */