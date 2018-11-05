#include <iostream>
#ifndef _Contact_h_
#define _Contact_h_
using namespace std;

class Contact
{
    int contactOwnerId, entryNum;
    string name, surname, number, mail, address;

public:

    Contact(int id=0, int nr=0,string nme="", string snme="", string num="", string ml="", string addrs="");

    void setContactOwnerId(int id);
    void setEntryNumber(int nr);
    void setName(string nme);
    void setSurname(string snme);
    void setNumber(string num);
    void setMail(string ml);
    void setAddress(string addrs);

    int getContactOwnerId();
    int getEntryNumber();
    string getName();
    string getSurname();
    string getNumber();
    string getMail();
    string getAddress();

};
#endif // _Contact_h_
