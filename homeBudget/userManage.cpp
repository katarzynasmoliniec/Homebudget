#include "UserManage.h"

User UserManager :: getNewUserData()
{
    User user;

    user.setId(getNewUserId());

    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods:: loadLine());
    user.setName(AuxiliaryMethods:: changeFirstLetterForUpperCaseAndOthersForLowerCase(user.getName()));

    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods:: loadLine());
    user.setSurname(AuxiliaryMethods:: changeFirstLetterForUpperCaseAndOthersForLowerCase(user.getSurname()));

    do
    {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods:: loadLine());
    }
    while (loginExists(user.getLogin()));

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods:: loadLine());

    return user;
}

bool UserManager :: loginExists(string login)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UserManager :: getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

char UserManager :: selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods :: loadChar();

    return choice;
}

void UserManager :: registerUser()
{
    User user = getNewUserData();

    users.push_back(user);
    userFile.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

int UserManager :: loginUser()
{
    string login = "", password = "";

    cout << "Podaj login: ";
    login = AuxiliaryMethods:: loadLine();
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int attempt = 3; attempt > 0; attempt--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attempt << ": ";
                password = AuxiliaryMethods:: loadLine();
                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserId = users[i].getId();
                    return loggedInUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return loggedInUserId = 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return loggedInUserId = 0;
}

void UserManager :: changePasswordUser()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods :: loadLine();

    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == loggedInUserId)
        {
            users[i].setPassword(newPassword);
            userFile.writeAllUsersToFile(users[i]);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
}

void UserManager :: logoutUser()
{
    loggedInUserId = 0;
    cout << "Uzytkownik wylogowany!" << endl;
    system("pause");
}

bool UserManager :: isUserLoggedIn()
{
    if(loggedInUserId > 0)
            return true;
    else
        return false;
}

int UserManager :: getLoggedInUserId()
{
    return loggedInUserId;
}
