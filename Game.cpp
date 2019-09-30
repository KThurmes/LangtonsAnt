#include "Game.hpp"

Game::Game()
{
    //Use default constructor for gameBoard, default moveCount is 5.
    totalMoves = 5;
}

Game::Game(int theMoves, Board theBoard){
    totalMoves = theMoves;
    delete &gameBoard;
    gameBoard = theBoard;
}


void Game::runMainMenu(){
    char usersChoice = gameMenu.showMenu();
    switch (usersChoice){
        case '1': 
            //TODO: get user input on new game. Load up new game
            playGame();
            break;
 
        case '2': 
            break;
    }
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
}