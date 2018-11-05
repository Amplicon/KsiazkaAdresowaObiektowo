#include <iostream>
#include <vector>
#include "User.h"
#include "UserFile.h"

using namespace std;
class Users
{
    vector <User> users;
    UsersFile newFile;
    User user;

public:

    Users();
    void registerUser();
    int logIn();
    void changePassword(unsigned currentId);
};
