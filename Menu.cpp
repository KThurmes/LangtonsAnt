#include <string>
#include <iostream>
#include "Menu.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;

char Menu::showMenu(){
    //return type will have to change if there are more than 9 options.
    char userChoice;
    cout << "Menu: " << endl;
    cout << menuOptions << endl;
    cin >> userChoice;
    return userChoice;
}


void Menu::getUserChoice(){

//#TODO: check input validity


}