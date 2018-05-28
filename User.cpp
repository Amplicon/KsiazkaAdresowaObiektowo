#include <iostream>
#include "User.h"


User::User(int id,string pas, string log)
{
    userId=id;
    password=pas;
    login=log;
}

void User::setUserId(int id)
{
    userId=id;
}
void User::setLogin(string lgn)
{
    login=lgn;
}

void User::setPassword(string pwd)
{
    password=pwd;
}

int User::getUserId()
{
    return userId;
}

string User::getPassword()
{
    return password;
}

string User::getLogin()
{
    return login;
}
