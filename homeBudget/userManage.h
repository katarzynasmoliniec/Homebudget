#ifndef USERMANAGE_H
#define USERMANAGE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <iterator>

#include "user.h"
#include "UserFile.h"
#include "auxiliaryMethods.h"

using namespace std;

class UserManager
{
    vector <User> users;
    int loggedInUserId;
    UserFile userFile;

    User getNewUserData();
    bool loginExists(string login);
    int getNewUserId();

public:
    UserManager(string nameFileUser) : userFile(nameFileUser)
    {
        loggedInUserId = 0;
        users = userFile.loadUsersFromFile();
    };
    char selectOptionFromUserMenu();
    void registerUser();
    int loginUser();
    void changePasswordUser();
    void logoutUser();
    bool isUserLoggedIn();
    int getLoggedInUserId();
};
#endif
