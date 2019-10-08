/********************************************************************* 
** Title: getValidInt
** Author: Katheen Thurmes
** Date: 6 Oct., 2019
** Description: This file contains two functions: getInt() and 
getValidSelection(). getInt() is a function that will ask the user
to input a number and will do checks to ensure that the input is an 
integer. getValidSelection() is more specific to the Project1 
application. It ensures that the int that was inputted by the user 
was either 1 or 2. 
*********************************************************************/ 

#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;


/********************************************************************* 
** getInt() description: getInt() is a function that will accept 
input from the user and will do checks to ensure that the input is an 
integer. It will continue to ask the user for an integer until the 
user submits a valid integer.
** Return value: Returns the submitted integer.
** Limitation: getInt() will accept decimal values that end in ".0" 
as integers.
*********************************************************************/ 
int getValidInt(){
    //Input validation code and cin stream resetting adapted from https://stackoverflow.com/questions/19521320/why-do-i-get-an-infinite-loop-if-i-enter-a-letter-rather-than-a-number
    //Accessed 1 Oct., 2019

    int input;
    float rawInput;
    cin >> rawInput;

    //Check that the inputted value is a number. If it isn't, ask the user for input again.
    if (!(cin))
    {
        cout << "Please enter an integer." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        rawInput = getValidInt();
    }

    //Check to make sure a decimal value hasn't been entered. If it isn't, ask the user for input again. This also checks that the max/min value of an int hasn't been exceeded
    //Will not reject an input that ends in ".0".
    input = rawInput; //value of "input" will be the floor of "rawInput".
    if (!(rawInput-input == 0)){
        cout << "Please enter an integer between -2147483648 and 2147483647.." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        rawInput = getValidInt();
    }

    return input;
}

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
/* int getValidMenuSelection()
{
    //Get an integer from the user
    int input = getInt();

    //Check that the integer is either 1 or 2.
    if (!(input == 1) && !(input == 2)){
        cout << "Please enter either a \"1\" or a \"2\"." << endl;
        cin.clear();
        input = getValidMenuSelection();
    }

    return input;
} */