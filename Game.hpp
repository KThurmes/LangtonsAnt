#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Menu.hpp"

class Game
{

private:
    // Menu::Menu startMenu;
    // Menu::Menu endMenu;
    Board gameBoard;
    int totalMoves;

public:
    Game();
    Game(int, int, int, int, int);
    void playGame();
    // void runStartMenu();
    // void runEndMenu();
};

#endif