#ifndef INCOMEEXPENSE_H
#define INCOMEEXPENSE_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "auxiliaryMethods.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"

using namespace std;

class IncomeExpense
{
    vector <int> incomes;
    vector <int> expenses;
    const int LOGGED_IN_USER_ID;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

public:
    IncomeExpense(string nameFileIncome, string nameFileExpense, int loggedInUserId)
        : LOGGED_IN_USER_ID(loggedInUserId), incomeFile(nameFileIncome), expenseFile(nameFileExpense)
    {
       // incomes = incomeFile.wczytajAdresatowZalogowanegoUzytkownikaZPliku(LOGGED_IN_USER_ID);
       // expenses = expenseFile.wczytajAdresatowZalogowanegoUzytkownikaZPliku(LOGGED_IN_USER_ID);
    };
    char selectOptionFromBudgetMenu();
    void addIncome();
    void addExpense();
    void balanse();

};
#endif
