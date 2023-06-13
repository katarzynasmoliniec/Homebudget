#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "auxiliaryMethods.h"
#include "UserManage.h"
#include "IncomeExpense.h"

using namespace std;

class HomeBudget
{
    UserManager userManager;
    IncomeExpense *incomeExpense;
    const string NAME_FILE_INCOME;
    const string NAME_FILE_EXPENSE;

public:
    HomeBudget(string nameFileUser, string nameFileIncome, string nameFileExpense)
    : userManager(nameFileUser), NAME_FILE_INCOME(nameFileIncome), NAME_FILE_EXPENSE(nameFileExpense)
    {
        incomeExpense = NULL;
    };

    ~HomeBudget()
    {
        delete incomeExpense;
        incomeExpense = NULL;
    }

    int getLoggedInUserId();
    void registerUser();
    void loginUser();
    void changePasswordUser();
    void logoutUser();

    void addIncome();
    void addExpense();
    void balance(char choice);

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
};
#endif
