#include <iostream>
#include <vector>
#include "Contact.h"
#include "ContactFile.h"
#ifndef _Contacts_h_
#define _Contacts_h_
using namespace std;

class Contacts
{
private:

    int currentUserId;
    vector <Contact> contacts;
    ContactFile newFile;
    Contact contact;
    void feedData();
    void displayContact(unsigned contactPositionInVector);
    int findMissingNumber(vector<int>& numbers);
    int part(vector<int>& arr, int lowerPosition, int higherPosition);
    void quicksort(vector<int>& arr, int startPosition, int endPosition);

public:

    Contacts(int id=0);
    void setCurrentUserId(int currentUserId);
    int getCurrentUserId();
    void addContact();
    void editContact(int entryNumber);
    void deleteContact(int entryNumber);
    void modifyContact();
    void searchContact(char surnameOneNameTwo);
    void displayAllContacts();

};

#endif // _Contacts_h_
