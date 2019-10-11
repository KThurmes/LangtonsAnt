/********************************************************************* 
** Author: Katheen Thurmes
** Date: 8 Oct., 2019
** Description: runMenu() is the driver function of the program. 
Using input from the user, it runs functions that set up the game and 
run the simulations. It will continue to let the player run 
simulations until the player chooses to exit the program.
*********************************************************************/ 
#include "runMenu.hpp"
#include "Game.hpp"
#include "getNumberBetween.hpp"
#include "simulationSetup.hpp"
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


void runMenu()
{
    int selection;

    cout << "Please select from the following options:\n1. Start Langton's Ant simulation\n2. Quit"
         << endl;
    //Use getNumberBetween for input validation
    selection = getNumberBetween(1,2);

    //Run new simulations until the player chooses to exit.
    while (selection == 1)
    {
        Game theGame = simulationSetup();
        theGame.playGame();

        //Ask if the user wants to do it again
        cout << "Please select from the following options:\n1. Run another simulation\n2. Quit" << endl;
        selection = getNumberBetween(1,2);
    }
}
