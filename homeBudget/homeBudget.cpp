#include "homeBudget.h"

int HomeBudget :: getLoggedInUserId()
{
    return userManager.getLoggedInUserId();
}
void HomeBudget :: registerUser()
{
    userManager.registerUser();
}
void HomeBudget :: loginUser()
{
    userManager.loginUser();
    if (userManager.isUserLoggedIn())
    {
        incomeExpense = new IncomeExpense(NAME_FILE_INCOME, NAME_FILE_EXPENSE, userManager.getLoggedInUserId());
    }

}
void HomeBudget :: changePasswordUser()
{
    userManager.changePasswordUser();
}
void HomeBudget :: logoutUser()
{
    userManager.logoutUser();
    delete incomeExpense;
    incomeExpense = NULL;
}
char HomeBudget :: selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods :: loadChar();

    return choice;
}
char HomeBudget :: selectOptionFromUserMenu()
{
    return userManager.selectOptionFromUserMenu();
}

void HomeBudget :: addIncome()
{
    if(userManager.isUserLoggedIn())
    {
         incomeExpense->addIncome();
    }
    else
    {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}

void HomeBudget :: addExpense()
{
    if(userManager.isUserLoggedIn())
    {
         incomeExpense->addExpense();
    }
    else
    {
        cout << "Aby dodac wydatek, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}
void HomeBudget :: balanceThisMonth()
{
    if(userManager.isUserLoggedIn())
    {
         incomeExpense->balanceThisMonth();
    }
    else
    {
        cout << "Aby zobaczyc bilans, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}
void HomeBudget :: balance()
{
    if(userManager.isUserLoggedIn())
    {
         incomeExpense->balance();
    }
    else
    {
        cout << "Aby zobaczyc bilans, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}
