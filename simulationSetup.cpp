
/********************************************************************* 
** Author: Katheen Thurmes
** Date: 8 Oct., 2019
** Description: simulationSetup() sets up a new simulation of 
Lanton's Ant. It sets up a board and game and it sets the game's 
totalMoves data member to reflect how many moves will be played in 
the simulation. It asks the user for the game board's dimensions and
it asks where the ant should be placed (giving the player the option 
to have the ant's location chosen randomly.) It returns the fully set 
up game.
*********************************************************************/ 

#include "simulationSetup.hpp"
#include "Game.hpp"
#include <iostream>
#include "getNumberBetween.hpp"

using std::cin;
using std::cout;
using std::endl;

Game simulationSetup()
{
    cout << "Please select from the following options:\n1. Create custom simulation\n2. Random ant starting location" << endl;
    int rowCount;
    int colCount;
    int steps;
    int antRow;
    int antCol;
    
    int selection;
    selection = getNumberBetween(1,2);

    //Get board dimensions and # of steps from user, regardless of selection
    cout << "Number of rows on the board: " << endl;
    rowCount = getNumberBetween(2, 500);
    cout << "Number of columns on the board: " << endl;
    colCount = getNumberBetween(2, 500);
    cout << "Number of steps during the simulation: " << endl;
    steps = getNumberBetween(1, 5000);

    //If user wants to choose their own ant start location, ask them for it
    if (selection == 1)
    {
        cout << "Starting row of the ant: " << endl;
        antRow = getNumberBetween(1, rowCount) - 1;
        cout << "Starting column of the ant: " << endl;
        antCol = getNumberBetween(1, colCount) - 1; 
    }
    //Choose random start location that is within board limits
    else
    {
        //Random number generation adapted from http://www.cplusplus.com/reference/cstdlib/rand/
        //Accessed 10.8.2019
        antRow = rand() % rowCount;
        antCol = rand() % colCount;

        cout << "Random ant starting location:\nRow " << antRow + 1 << "\nColumn " << antCol + 1 << endl;
    }

    //Set up the game
    Game theGame(steps, rowCount, colCount, antRow, antCol);
    return theGame;
}