#include "Game.hpp"
#include "Menu.hpp"
#include "Ant.hpp"
#include "Board.hpp"

int main()
{
    Menu sMenu;
    Menu eMenu;
    sMenu.setMenuOptions("1. Start Langton's Ant simulation\n2. Quit \n");
    eMenu.setMenuOptions("1. Play again\n2.Exit\n");

    Game theGame(5, 10, 5, 1, 0, 0);
    theGame.setStartMenu(sMenu);
    theGame.setEndMenu(eMenu);
    theGame.runStartMenu();
    return 0;
}