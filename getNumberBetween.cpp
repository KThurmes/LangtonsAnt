/********************************************************************* 
** getValidSelection() description: getValidSelection() is a 
function that will ask the user to select either a "1" or a "2". It 
will call getInt() to accept an integer from the user and then it 
will test to make sure the integer is either 1 or 2. If it is not, 
it will ask the user again to submit either 1 or 2 until the user 
does.
** Return value: Returns the submitted integer. It will either be a 
1 or a 2.
*********************************************************************/ 

#include "getValidInt.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int getNumberBetween(int low, int high){
    //Get an integer from the user
    int input = getValidInt();

    //Check that the integer is between low and high.
    if (input < low || input > high){
        cout << "Please enter an integer between " << low << " and " << high << "." << endl;
        cin.clear();
        input = getNumberBetween(low, high);
    }

    return input;

}