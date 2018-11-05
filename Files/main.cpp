#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include "User.h"
#include "Users.h"
#include "UserFile.h"
#include "Contact.h"
#include "Contacts.h"
#include "ContactFile.h"

using namespace std;
string UsersFile::userFileAddress="baza_uzytkownikow.txt";
string ContactFile::contactFileAddress="baza_kontaktow.txt"; //te mozna stad wypieprzyc do odpowiednich klas
int main()
{
    Menu menu;
    Users users;
    Contacts contacts;
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
            contacts.setCurrentUserId(idOfLoggedUser);
            switch(menu.mainMenu())
            {
            case '1':
                contacts.displayAllContacts();
                break;

            case '2':

                contacts.searchContact(menu.searchMenu());
                break;

            case '3':

                contacts.addContact();
                break;

            case '4':

                contacts.modifyContact();
                break;

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
