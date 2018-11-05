#include <iostream>
#include <vector>
#include "Contact.h"
#ifndef _ContactFile_h_
#define _ContactFile_h_
using namespace std;

class ContactFile
{
    static string contactFileAddress;

private:

    int extractEntryNumber(string line);
    int extractContactOwnerId(string line);
    string extractDataString(string line);


public:

    void saveToFile(vector<Contact> &contactVector);
    void loadFromFile(vector<Contact> &contactVector, Contact contact);  //Passing vector by reference
    void copyTempData();
    void appendDataFile(vector<Contact> &contactVector);
};
#endif // _ContactFile_h_
