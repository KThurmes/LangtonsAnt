#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

class Menu
{

private:
    string menuOptions = "";

public:
    char runMenu();
    void setMenuOptions(string);
    void gameStartup();
};

#endif