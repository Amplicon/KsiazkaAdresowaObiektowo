#include <iostream>
#include "Menu.h"
#include <windows.h>

char Menu::mainMenu()
{

    for(; ;)
    {
        system("cls");
        cout<<"[======================================================]\n";
        cout<<"|                                                      |\n";
        cout<<"|                    KSIAZKA ADRESOWA                  |\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================+++=========================]\n";
        cout<<"|                                                      |\n";
        cout<<"|1>             Wyswietl wszystkie pozycje            <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|2>             Wyszukaj                              <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|3>             Dodaj pozycje                         <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|4>             Modyfikuj pozycje                     <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|5>             Zmien haslo                           <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|6>             Wyloguj                               <|\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================\\ /=========================]\n";
        cout<<"                            ";
        cin>>choice;

        if (choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6')
        {
            system("cls");
            cout<<"[======================================================]\n";
            cout<<"|                                                      |\n";
            cout<<"|               Podaj 1, 2, 3, 4, 5 lub 6              |\n";
            cout<<"|                                                      |\n";
            cout<<"[==========================+++=========================]\n";
            cout<<"                            ";

            Sleep(1000);
            system("cls");
        }

        else
        {
            return choice;
        }
    }
}

char Menu::logInMenu()
{
    for(;;)
    {

        system("cls");
        cout<<"[======================================================]\n";
        cout<<"|                                                      |\n";
        cout<<"|                    KSIAZKA ADRESOWA                  |\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================+++=========================]\n";
        cout<<"|                                                      |\n";
        cout<<"|1>             Zaloguj...                            <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|2>             Rejestracja                           <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|3>             Wyjscie z programu                    <|\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================\\ /=========================]\n";
        cout<<"                            ";
        cin>>choice;

        if (choice!='1'&&choice!='2'&&choice!='3')
        {
            system("cls");
            cout<<"[======================================================]\n";
            cout<<"|                                                      |\n";
            cout<<"|                     Podaj 1, 2, 3                    |\n";
            cout<<"|                                                      |\n";
            cout<<"[==========================+++=========================]\n";
            cout<<"                            ";

            Sleep(1000);
            system("cls");
        }

        else
        {
            return choice;
        }
    }
}

Menu::Menu(char chc)
{
    choice=chc;
}
