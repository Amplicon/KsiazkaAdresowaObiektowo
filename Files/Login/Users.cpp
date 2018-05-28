#include <iostream>
#include "Users.h"
#include "UserFile.h"
#include <vector>
#include <windows.h>
Users::Users()
{
    newFile.loadFromFile(users, newUsr);
}

void Users::registerUser()
{
    system("cls");
    string newName=" ", newPassword=" ";
    cout<<"Podaj Nowa NAZWE Uzytkownika: \n";
    cin>>newName;
    unsigned i = 0;
    while (i<users.size())
    {
        if (newName==users[i].getLogin())
        {
            cout<<"Nazwa: \""<<newName<<"\" Zajeta!\nPodaj Nowa NAZWE Uzytkownika: \n";
            cin>>newName;
        }
        else
        {
            i++;
        }
    }
    cout<<"Podaj HASLO Uzytkownika: \n";
    cin>>newPassword;
    newUsr.setLogin(newName);
    newUsr.setPassword(newPassword);
    newUsr.setUserId(i+1);
    users.push_back(newUsr);
    newFile.saveToFile(users);
    system("cls");
    cout<<"Zarejestrowano Uzytkownika \""<<newName<<"\" pomyslnie!";
    Sleep(1000);
    system("cls");

}

int Users::logIn()
{
    string login, password;
    cout<<"Podaj NAZWE uzytkownika:\n";
    cin>>login;
    unsigned i=0;
    while(i<users.size())
    {
        if(users[i].getLogin()==login)
        {
            for(int j=0; j<3; j++)
            {
                cout<<"Podaj HASLO("<<3-j<<"):\n";
                cin>>password;
                if(users[i].getPassword()==password)
                {
                    system("cls");
                    cout<<"Witaj "<<users[i].getLogin()<<" ! \nZalogowano pomyslnie";

                    Sleep(1000);
                    return users[i].getUserId();
                }
                else
                {
                    cout<<"Bledne haslo\n";
                }
            }
            Sleep(3000);
            return 0;
        }
        else
        {
            i++;
        }
    }
    cout<<"Brak uzytkownika \""<<login<<"\" w bazie";
    Sleep(3000);
    return 0;
}

void Users::changePassword(unsigned currentId)
{
    system("cls");
    cout<<"Wprowadz nowe HASLO: \n";
    string newPasswd=" ";
    cin>>newPasswd;
    users[currentId-1].setPassword(newPasswd);
    newFile.saveToFile(users);

}


