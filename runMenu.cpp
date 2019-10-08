#include "runMenu.hpp"
#include "Game.hpp"
#include "getNumberBetween.hpp"
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void simulationSetup();

void runMenu()
{
    int selection;
    //Ask user if they want to do a custom simulation or a default
    cout << "Please select from the following options:\n1. Start Langton's Ant simulation\n2. Quit"
         << endl;
    selection = getNumberBetween(1,2);

    if (selection == 1)
    {
        simulationSetup();
    }
    //else end
}

void simulationSetup()
{
    cout << "Please select from the following options:\n1. Create custom simulation\n2. Random ant starting location" << endl;
    int rowCount;
    int colCount;
    int steps;
    int antRow;
    int antCol;
    
    int selection;
    selection = getNumberBetween(1,2);

    cout << "Number of rows on the board: " << endl;
    rowCount = getNumberBetween(2, 500);
    cout << "Number of columns on the board: " << endl;
    colCount = getNumberBetween(2, 500);
    cout << "Number of steps during the simulation: " << endl;
    steps = getNumberBetween(1, 5000);

    if (selection == 1)
    {
        cout << "Starting row of the ant: " << endl;
        antRow = getNumberBetween(1, rowCount);
        cout << "Starting column of the ant: " << endl;
        antCol = getNumberBetween(1, colCount);
    }
    else
    {
        //Random number generation adapted from http://www.cplusplus.com/reference/cstdlib/rand/
        //Accessed 10.8.2019
        antRow = rand() % rowCount + 1;
        antCol = rand() % colCount + 1;

        cout << "Random ant starting location:\nRow " << antRow << "\nColumn " <<antCol << endl;
        
    }

    Game theGame(steps, rowCount, colCount, antRow, antCol);
    theGame.playGame();

    //ask if the user wants to do it again
    cout << "Please select from the following options:\n1. Run another simulation\n2.Quit"
         << endl;
    selection = getNumberBetween(1,2);
    if (selection == 1)
    {
        simulationSetup();
    }
}