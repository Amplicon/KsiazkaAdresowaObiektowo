#include <iostream>

using namespace std;

class Menu
{
    char choice;

public:

    char mainMenu();
    char logInMenu();
    char searchMenu();
    Menu(char choice=' ');
};
