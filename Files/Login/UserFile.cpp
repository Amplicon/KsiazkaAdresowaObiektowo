#include <iostream>
#include <fstream>
#include <cstdlib>
#include "UserFile.h"
#include "User.h"

void UsersFile::saveToFile(vector<User> &userVector)
{
    unsigned userVectorSize=userVector.size();
    fstream userFileOut;
    userFileOut.open(userFileAddress.c_str(), ios::out);
    for(unsigned i=0; i<userVectorSize; i++)
    {
        userFileOut<<userVector[i].getUserId()<<'|'<<userVector[i].getLogin()<<'|'<<userVector[i].getPassword()<<"|\n";
    }
    userFileOut.close();
    return;
}

////////////////////////////////////////////////////////////
void UsersFile::loadFromFile(vector<User> &userVector, User user)  //Passing vector of user objects by reference
{
    fstream userFileIn;
    string line;
    unsigned i=0;
    int positionOfSeparator1, positionOfSeparator2, wordLength;
    userFileIn.open(userFileAddress.c_str(), ios::in);
    while(getline(userFileIn,line))
    {

        userVector.push_back(user);
        positionOfSeparator1=line.find_first_of('|');
        userVector[i].setUserId(atoi(line.c_str()));
        positionOfSeparator2=line.find_first_of('|',positionOfSeparator1+1);
        wordLength=positionOfSeparator2-positionOfSeparator1-1;
        userVector[i].setLogin(line.substr(positionOfSeparator1+1,wordLength));

        positionOfSeparator1=positionOfSeparator2;

        positionOfSeparator2=line.find_first_of('|',positionOfSeparator1+1);
        wordLength=positionOfSeparator2-positionOfSeparator1-1;
        userVector[i].setPassword(line.substr(positionOfSeparator1+1,wordLength));

        i++;

    }
    userFileIn.close();
    return;

}

