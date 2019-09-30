#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

class Menu
{

private:
    string menuOptions = "1. Start Langton's Ant simulation \n2. Quit\n";

public:
    char showMenu();
    void getUserChoice();

};

#endif