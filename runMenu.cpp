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

    //Ask user if they want to do a full custom simulation or have ant placed at random location
    cout << "Please select from the following options:\n1. Start Langton's Ant simulation\n2. Quit"
         << endl;
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
