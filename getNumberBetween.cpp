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