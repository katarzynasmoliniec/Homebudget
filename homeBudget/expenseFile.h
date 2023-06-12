#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "auxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class ExpenseFile
{
    const string FILE_NAME;

public:
    ExpenseFile(string nameFileExpense) : FILE_NAME(nameFileExpense){};

    vector <Expense> loadExpensesOfLoggedInUserFromFile(int idLoggedUser);
    void addExpenseToFile(Expense expense);
};
#endif
