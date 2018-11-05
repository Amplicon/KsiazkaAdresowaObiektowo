#include <iostream>
#include "Contacts.h"
#include <windows.h>
Contacts::Contacts(int id)
{
    currentUserId=id;
    newFile.loadFromFile(contacts, contact);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Contacts::feedData()
{
    string name, surname, phoneNum, mail, address;

    cin.ignore();
    cout<<"Podaj IMIE: ";
    getline(cin, name);
    contact.setName(name);

    cout<<"\nPodaj NAZWISKO: ";
    getline(cin, surname);
    contact.setSurname(surname);

    cout<<"\nPodaj NUMER TELEFONU: ";
    getline(cin, phoneNum);
    contact.setNumber(phoneNum);

    cout<<"\nPodaj adres E-MAIL: ";
    getline(cin, mail);
    contact.setMail(mail);

    cout<<"\nPodaj ADRES: ";
    getline(cin, address);
    contact.setAddress(address);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Contacts::setCurrentUserId(int currentUserId)
{
    this->currentUserId=currentUserId;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int Contacts::getCurrentUserId()
{
    return currentUserId;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Contacts::addContact()
{
    int highestEntryNumber=0, numberCounter=0;
    contact.setContactOwnerId(getCurrentUserId());
    vector <int> numbers;

    for(unsigned i=0; i<contacts.size(); i++)
    {
        if(contacts[i].getContactOwnerId()==getCurrentUserId())
        {
            numbers.push_back(contacts[i].getEntryNumber());
            if(highestEntryNumber<contacts[i].getEntryNumber())
            {
                highestEntryNumber=contacts[i].getEntryNumber();
            }
            numberCounter++;
        }
    }
    if(numberCounter == 0)
    {
        contact.setEntryNumber(1);   //this would happen if there was no previous records connected to given id
    }
    else if(numberCounter == highestEntryNumber)
    {
        contact.setEntryNumber(numberCounter+1);
    }
    else
    {
        contact.setEntryNumber(findMissingNumber(numbers));
    }
    feedData();
    contacts.push_back(contact);//pushes object of contact to vector
    newFile.appendDataFile(contacts);

    return;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Contacts::editContact(int entryNumber)
{
    for (unsigned i=0; i<contacts.size(); i++)
    {
        if(contacts[i].getContactOwnerId()==getCurrentUserId()&&contacts[i].getEntryNumber()==entryNumber)
        {
            feedData();
            contacts[i].setName(contact.getName());
            contacts[i].setSurname(contact.getSurname());
            contacts[i].setMail(contact.getMail());
            contacts[i].setNumber(contact.getNumber());
            contacts[i].setAddress(contact.getAddress());
            newFile.saveToFile(contacts);
            return;
        }
    }
    system("cls");
    cout<<"Nie znaleziono kontatktu o podanym numerze ("<<entryNumber<<") !";
    Sleep(500);
    system("cls");
    return;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Contacts::deleteContact(int entryNumber)
{
    for (unsigned i=0; i<contacts.size(); i++)
    {
        if(contacts[i].getContactOwnerId()==getCurrentUserId()&&contacts[i].getEntryNumber()==entryNumber)
        {
            contacts.erase(contacts.begin() + i );
            newFile.saveToFile(contacts);
            return;
        }
    }
    system("cls");
    cout<<"Nie znaleziono kontatktu o podanym numerze ("<<entryNumber<<") !";
    Sleep(500);
    system("cls");
    return;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Contacts::searchContact(char surnameOneNameTwo)
{
    int currentUserId = this->currentUserId;
    unsigned i=0;
    char choice;
    string itemToSearch;
    bool found = false;
    system("cls");
    switch(surnameOneNameTwo)
    {
    case '1':

        cout<<"Wprowadz NAZWISKO: ";
        cin.ignore();
        getline(cin,itemToSearch);
        for(; i<contacts.size(); i++)
        {
            if(contacts[i].getContactOwnerId() == currentUserId && contacts[i].getSurname() == itemToSearch)
            {
                displayContact(i);
                found = true;
            }
        }
        break;

    case '2':

        cout<<"Wprowadz IMIE: ";
        cin.ignore();
        getline(cin,itemToSearch);
        for(; i<contacts.size(); i++)
        {
            if(contacts[i].getContactOwnerId() == currentUserId && contacts[i].getName() == itemToSearch)
            {
                displayContact(i);
                found = true;
            }
        }
        break;
    }

    if(found==false)
    {
        system("cls");
        cout<<"Nie znaleziono wpisu";
        Sleep(500);
        return;
    }
    else
    {
        cout<<"Czy chcesz zmodyfikowac pozycje?\nt/n: ";
        cin>>choice;
        if(choice=='t'||choice=='T')
        {
            modifyContact();
        }
        else
        {
            return;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Contacts::displayContact(unsigned v)
{
    cout<<"\nWpis numer: "<<contacts[v].getEntryNumber()<<endl;
    cout<<"Imie:       "<<contacts[v].getName()<<endl;
    cout<<"Nazwisko:   "<<contacts[v].getSurname()<<endl;
    cout<<"Adres:      "<<contacts[v].getAddress()<<endl;
    cout<<"E-Mail:     "<<contacts[v].getMail()<<endl;
    cout<<"Telefon:    "<<contacts[v].getNumber()<<endl;

    cout<<"+----------/\n\n";
    return;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Contacts::modifyContact()
{
    char choice;
    int positionNumber;
    for(;;)
    {
        system("cls");

        cout<<"[======================================================]\n";
        cout<<"|                                                      |\n";
        cout<<"|                   MODYFIKUJ POZYCJE                  |\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================+++=========================]\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|1>             Edytuj                                <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|2>             Usun                                  <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|3>             Cofnij                                <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================\\ /=========================]\n";
        cout<<"                            ";
        cin>>choice;

        switch(choice)
        {
        case '1':

            system("cls");

            cout<<"[======================================================]\n";
            cout<<"|                                                      |\n";
            cout<<"|                  EDYTUJ POZYCJE NUMER                |\n";
            cout<<"|                                                      |\n";
            cout<<"[==========================\\ /=========================]\n";
            cout<<"                            ";
            cin>>positionNumber;
            editContact(positionNumber);
            break;

        case '2':
            system("cls");

            cout<<"[======================================================]\n";
            cout<<"|                                                      |\n";
            cout<<"|                   USUN POZYCJE NUMER                 |\n";
            cout<<"|                                                      |\n";
            cout<<"[==========================\\ /=========================]\n";
            cout<<"                            ";
            cin>>positionNumber;
            deleteContact(positionNumber);
            break;

        case '3':
            return;

        default:
            system("cls");
            cout<<"[======================================================]\n";
            cout<<"|                                                      |\n";
            cout<<"|                   Podaj 1, 2, lub 3                  |\n";
            cout<<"|                                                      |\n";
            cout<<"[==========================+++=========================]\n";
            cout<<"                            ";

            Sleep(1000);
            system("cls");
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
int Contacts::findMissingNumber(vector<int>& numbers)
{

    int upperLimes=numbers.size()-1;

    quicksort(numbers,0,upperLimes);

    for(int i=0;i<=upperLimes;i++)
    {
        if(numbers[i]+1 < numbers[i+1])
        {
            return numbers[i]+1;
        }
    }
    return 0; //that is an error
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Contacts::quicksort(vector<int>& arr, int l, int r)
{
    int p;
    if (l < r)
    {
        p = part(arr, l, r);
        quicksort(arr, l, p);
        quicksort(arr, p+1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
int Contacts::part(vector<int>& arr, int l, int r)
{
    int x = arr[l];
    int i = l, j = r, w;
    while (true)
    {
        while (arr[j] > x)
            j--;
        while (arr[i] < x)
            i++;
        if (i < j)
        {
            w = arr[i];
            arr[i] = arr[j];
            arr[j] = w;
            i++;
            j--;
        }
        else
            return j;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Contacts::displayAllContacts()
{
    bool found = false;
    char choice;
    system("cls");
    for (unsigned i = 0; i < contacts.size(); i++)
    {
        if (contacts[i].getContactOwnerId() == getCurrentUserId())
        {
            displayContact(i);
            found = true;
        }
    }

    if(found == false)
    {
        system ("cls");
        cout << "Nie znaleziono ZADNEJ pozycji";
        Sleep (500);
        return;
    }
    else
    {
        cout << "Czy chcesz zmodyfikowac pozycje?\nt/n: ";
        cin >> choice;
        if (choice == 't' || choice == 'T')
        {
            modifyContact();
        }
        else
        {
            return;
        }
    }
}
