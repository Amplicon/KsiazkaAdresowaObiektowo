#include <iostream>
#ifndef _User_h_
#define _User_h_
using namespace std;

class User
{
    int userId;
    string login, password;

public:

    void setUserId(int id);
    void setLogin(string lgn);
    void setPassword(string pwd);
    int getUserId();
    string getPassword();
    string getLogin();
    User(int id=0,string pas="", string log="");
};
#endif // _User_h_
