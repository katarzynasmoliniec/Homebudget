#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>

#include "IncomeFile.h"
#include "auxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class ExpenseFile :public IncomeFile
{
    int idOstatniegoAdresata;

public:
    ExpenseFile(string nameFileExpense) : IncomeFile(nameFileExpense)
    {
        idOstatniegoAdresata =0;
    };

};
#endif
