#include "UserManage.h"

User UserManager :: getNewUserData()
{
    User user;

    user.setId(getNewUserId());

    do
    {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods:: wczytajLinie());
    }
    while (loginExists(user.getLogin()));

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods:: wczytajLinie());

    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods:: wczytajLinie());
    user.setName(AuxiliaryMethods:: zamienPierwszaLitereNaDuzaAPozostaleNaMale(user.getName()));

    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods:: wczytajLinie());
    user.setSurname(AuxiliaryMethods:: zamienPierwszaLitereNaDuzaAPozostaleNaMale(user.getSurname()));

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
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods :: wczytajZnak();

    return choice;
}

void UserManager :: registerUser()
{
    User user = getNewUserData();

    users.push_back(user);
   // userFile.dopiszUzytkownikaDoPliku(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

int UserManager :: loginUser()
{
    string login = "", password = "";

    cout << "Podaj login: ";
    login = AuxiliaryMethods:: wczytajLinie();
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int attempt = 3; attempt > 0; attempt--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attempt << ": ";
                password = AuxiliaryMethods:: wczytajLinie();
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
    newPassword = AuxiliaryMethods :: wczytajLinie();

    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == loggedInUserId)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
  //  userFile.zapiszWszystkichUzytkownikowDoPliku(users);
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

/*
void UserManager :: wypiszWszystkichUzytkownikow()
{
    for (size_t i = 0; i < users.size(); i++)
    {
        cout << users[i].pobierzId() << endl;
        cout << users[i].pobierzLogin() << endl;
        cout << users[i].pobierzHaslo() << endl;
    }
}
*/










