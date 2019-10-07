#include <string>
#include <iostream>
#include "Menu.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

char Menu::runMenu()
{
    char userChoice;
    cout << "Please choose from the following options: " << endl;
    cout << menuOptions << endl;
    cin >> userChoice;

    //TODO do input validation here.
    return userChoice;
}

void Menu::setMenuOptions(string options)
{
    menuOptions = options;
}
