#include "Game.hpp"
#include "Menu.hpp"
#include "Ant.hpp"
#include "Board.hpp"

int main()
{
    Board board(10, 5, 1, 0, 0);
    Game theGame(5, board);
    theGame.playGame();
    return 0;
}