#include <iostream>
#include <vector>
#include "User.h"
#include "UserFile.h"

using namespace std;
class Users
{
    vector <User> users;
    UsersFile newFile;
    User newUsr;

public:

    Users();
    void loadUsers();
    void registerUser();
    int logIn();
    void changePassword(unsigned currentId);
};
