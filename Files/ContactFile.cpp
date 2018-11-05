#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "ContactFile.h"
#include "Contact.h"
// EWENTUALNIE konstruktor moglby sprawdzic czy plik juz istnieje i cos zrobic jesli tak/nie

void ContactFile::saveToFile(vector<Contact> &contactVector)
{
    unsigned contactVectorSize=contactVector.size();
    fstream contactFileOut;
    contactFileOut.open(contactFileAddress.c_str(), ios::out);
    for(unsigned i=0; i<contactVectorSize; i++)
    {
        contactFileOut<<contactVector[i].getEntryNumber()<<'|'<<contactVector[i].getContactOwnerId()
                      <<'|'<<contactVector[i].getName()<<'|'<<contactVector[i].getSurname()
                      <<'|'<<contactVector[i].getNumber()<<'|'<<contactVector[i].getMail()
                      <<'|'<<contactVector[i].getAddress()<<"|\n";
    }
    contactFileOut.close();
    return;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void ContactFile::loadFromFile(vector<Contact> &contactVector, Contact contact)                     //Passing vector of user objects by reference
{
    fstream contactFileIn;
    string line, word;
    int positionOfSeparator1=0, positionOfSeparator2=0, wordLength=0;
    contactFileIn.open(contactFileAddress.c_str(), ios::in);
    while(getline(contactFileIn,line))
    {
        contact.setEntryNumber( extractEntryNumber(line) );
        contact.setContactOwnerId( extractContactOwnerId(line) );
        line=extractDataString(line);
        positionOfSeparator1=line.find_first_of('|');
        contact.setName( line.substr(0,positionOfSeparator1) );                            //1slowo
        for(unsigned j=2; j<6; j++)
        {
            positionOfSeparator2=line.find_first_of('|',positionOfSeparator1+1);
            wordLength=positionOfSeparator2-positionOfSeparator1-1;
            if(j==2)
                contact.setSurname(line.substr(positionOfSeparator1+1,wordLength));   //2slowo
            if(j==3)
                contact.setNumber(line.substr(positionOfSeparator1+1,wordLength));    //3...
            if(j==4)
                contact.setMail(line.substr(positionOfSeparator1+1,wordLength));      //4...
            if(j==5)
                contact.setAddress(line.substr(positionOfSeparator1+1,wordLength));   //ostatnie slowo
            positionOfSeparator1=positionOfSeparator2;                                         //offset separatora
        }
        contactVector.push_back(contact);
    }
    contactFileIn.close();
    return;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int ContactFile::extractEntryNumber(string line)
{
    return atoi(line.c_str());
}
////////////////////////////////////////////////////////////////////////////////////////////////
int ContactFile::extractContactOwnerId(string line)
{
    string ContactOwnerIdInString;
    int positionOfSeparator1,positionOfSeparator2,numberLength;
    positionOfSeparator1=line.find_first_of('|');
    positionOfSeparator2=line.find_first_of('|',positionOfSeparator1+1);
    numberLength=positionOfSeparator2-positionOfSeparator1-1;
    ContactOwnerIdInString=line.substr(positionOfSeparator1+1,numberLength);
    return atoi(ContactOwnerIdInString.c_str());
}
////////////////////////////////////////////////////////////////////////////////////////////////
string ContactFile::extractDataString(string line)
{
    string dataString;
    int positionOfSeparator;
    positionOfSeparator=line.find_first_of('|');
    positionOfSeparator=line.find_first_of('|',positionOfSeparator+1);
    dataString=line.erase(0,positionOfSeparator+1);
    return dataString;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void ContactFile::copyTempData()
{
    string line;
    fstream file, contactFileOut;
    file.open((contactFileAddress+"TEMP").c_str(),ios::in);
    contactFileOut.open(contactFileAddress.c_str(),ios::out);
    while(getline(file,line))
    {
        contactFileOut<<line<<endl;
    }
    file.close();
    contactFileOut.close();
    remove((contactFileAddress+"TEMP").c_str());
}
////////////////////////////////////////////////////////////////////////////////////////////////
void ContactFile::appendDataFile(vector<Contact> &contactVector)
{
    string line;
    fstream file, contactFileOut;
    unsigned lastEntry=contactVector.size()-1;//tu moze byc problem -1

    contactFileOut.open((contactFileAddress+"TEMP").c_str(),ios::out);
    file.open(contactFileAddress.c_str(),ios::in);
    while(getline(file,line))
    {
        contactFileOut<<line<<endl;
    }
    contactFileOut<<contactVector[lastEntry].getEntryNumber()<<'|'<<contactVector[lastEntry].getContactOwnerId()
                  <<'|'<<contactVector[lastEntry].getName()<<'|'<<contactVector[lastEntry].getSurname()
                  <<'|'<<contactVector[lastEntry].getNumber()<<'|'<<contactVector[lastEntry].getMail()
                  <<'|'<<contactVector[lastEntry].getAddress()<<"|\n";

    file.close();
    contactFileOut.close();
    copyTempData();
    return;
}
