#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"

class Game
{

private:
    Board gameBoard;
    int totalMoves;

public:
    Game();
    Game(int, int, int, int, int);
    void playGame();

};

#endif