#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "auxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class IncomeFile
{
    const string FILE_NAME;

public:
    IncomeFile(string nameFileIncome) : FILE_NAME(nameFileIncome){};

    vector <Income> loadIncomesOfLoggedInUserFromFile(int idLoggedUser);
    void addIncomeToFile(Income income);
};
#endif
