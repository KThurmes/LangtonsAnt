#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

class Menu
{

private:
    string menuOptions = "";

public:
    char showMenu();
    void getUserChoice();
    void setMenuOptions(string);
};

#endif