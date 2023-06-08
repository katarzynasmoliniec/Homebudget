#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>

#include "user.h"
#include "auxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class UserFile
{
    const string FILE_NAME;

public:
    UserFile(string nameFileUser) : FILE_NAME(nameFileUser){};

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void writeAllUsersToFile(User user);
};
#endif
