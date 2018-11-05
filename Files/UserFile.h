#include <iostream>
#include <vector>
#include "User.h"
#ifndef _UsersFile_h_
#define _UsersFile_h_
using namespace std;

class UsersFile
{
    static string userFileAddress;

public:

    void saveToFile(vector<User> &userVector);
    void loadFromFile(vector<User> &userVector, User user);  //Passing vector by reference

};
#endif // _UsersFile_h_
