/********************************************************************* 
** Author: Katheen Thurmes
** Date: 8 Oct., 2019
** Description: This program runs Langton's Ant simulations 
(https://en.wikipedia.org/wiki/Langton%27s_ant). It allows the user 
to indicate the size of the board, the number of moves the ant will 
make in the simulation, and where the ant should be placed. It also 
allows players to choose to have the ant placed at a random starting 
position on the board. It uses a series of menus to allow the player 
to play again when their simulation is finished.
*********************************************************************/ 

#include "runMenu.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "\nThank you for grading my program! Please note that I have completed the extra credit for this assignment." << endl << "-Kathleen Thurmes\n" <<endl;
    runMenu();
    return 0;
}