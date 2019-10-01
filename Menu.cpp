#include <string>
#include <iostream>
#include "Menu.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

char Menu::showMenu()
{
    //return type will have to change if there are more than 9 options.
    char userChoice;
    cout << "Please choose from the following options: " << endl;
    cout << menuOptions << endl;
    cin >> userChoice;
    return userChoice;
}

void Menu::getUserChoice()
{

    //#TODO: check input validity
}

void Menu::setMenuOptions(string options)
{
    menuOptions = options;
}