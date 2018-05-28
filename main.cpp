#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include "User.h"
#include "Users.h"
#include "UserFile.h"

using namespace std;
string UsersFile::userFileAddress="baza_uzytkownikow.txt";
int main()
{
    Menu menu;
    Users users;
    unsigned idOfLoggedUser = 0;
    while(true)
    {
        if (idOfLoggedUser==0)
        {
            switch(menu.logInMenu())
            {
            case '1':
                idOfLoggedUser=users.logIn();
                break;

            case '2':
                users.registerUser();
                break;

            case '3':
                exit(0);
            }
        }
        else
        {
            switch(menu.mainMenu())
            {

            case '5':
                users.changePassword(idOfLoggedUser);
                break;

            case'6':
                idOfLoggedUser=0;
                break;
            }
        }

    }
    return 0;
}
