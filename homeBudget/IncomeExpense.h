#ifndef INCOMEEXPENSE_H
#define INCOMEEXPENSE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include<algorithm>
#include <iomanip>

#include "Income.h"
#include "Expense.h"
#include "auxiliaryMethods.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"
#include "DateFunction.h"

using namespace std;

class IncomeExpense
{
    vector <Income> incomes;
    vector <Expense> expenses;
    const int LOGGED_IN_USER_ID;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

    char selectOptionFromIncomeMenu();
    char selectOptionFromExpenseMenu();
    void dispalyIncomes(Income income);
    void dispalyExpenses(Expense expense);

public:
    IncomeExpense(string nameFileIncome, string nameFileExpense, int loggedInUserId)
        : LOGGED_IN_USER_ID(loggedInUserId), incomeFile(nameFileIncome), expenseFile(nameFileExpense)
    {
        incomes = incomeFile.loadIncomesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
        expenses = expenseFile.loadExpensesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void addExpense();
    void balance();
};
#endif
