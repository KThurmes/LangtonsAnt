#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Menu.hpp"
class Game
{

private:
    Menu gameMenu;
    Board gameBoard;
    int totalMoves;

public:
    Game();
    Game(int,const Board&);
    void playGame();
    void runMainMenu();
};

#endif