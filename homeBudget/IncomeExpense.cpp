#include "IncomeExpense.h"

char IncomeExpense :: selectOptionFromIncomeMenu()
{
    char choice;
    system("cls");
    cout << endl << "   >>> MENU PRZYCHODY <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1.Dadaj Przychod z dnia dzisiejszego " << endl;
    cout << "2.Dodaj Przychod z innego dnia." << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods :: loadChar();
    return choice;
}

char IncomeExpense :: selectOptionFromExpenseMenu()
{
    char choice;
    system("cls");
    cout << endl << "   >>> MENU WYDATKI <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1.Dadaj Wydatek z dnia dzisiejszego " << endl;
    cout << "2.Dodaj Wydatek z innego dnia." << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods :: loadChar();
    return choice;
}

void IncomeExpense :: addIncome()
{
    Income income;
    char choice;

    while(1)
    {
        choice = selectOptionFromIncomeMenu();
        if (choice == '1')
        {
            income.setDate(DateFunction :: getTodayDate());
            break;
        }
        else if (choice == '2')
        {
            do
            {
                cout << "Podaj date przychodu w formacie(rrrr-mm-dd):" << endl;
                income.setDate(DateFunction :: convertDateStringToInt(AuxiliaryMethods :: loadLine()));
            }
            while (income.getDate() == 0);
            break;
        }
        cout << endl << "Wybrano nieprawidlowy numer!" << endl << endl;
        system("pause");
    }

    cout << "Podaj kategorie przychodu:" << endl;
    income.setCategory(AuxiliaryMethods :: loadLine());
    income.setCategory(AuxiliaryMethods:: changeFirstLetterForUpperCaseAndOthersForLowerCase(income.getCategory()));

    cout << "Podaj kwote przychodu:" << endl;
    income.setAmount(AuxiliaryMethods :: loadNumber());
    income.setIdUser(LOGGED_IN_USER_ID);
    incomes.push_back(income);

    incomeFile.addIncomeToFile(income);
    cout << "Nowy przychod zostal dodany." << endl;
    system("pause");
}

void IncomeExpense :: addExpense()
{
    Expense expense;
    char choice;

    while(1)
    {
        choice = selectOptionFromExpenseMenu();
        if (choice == '1')
        {
            expense.setDate(DateFunction :: getTodayDate());
            break;
        }
        else if (choice == '2')
        {
            do
            {
                cout << "Podaj date wydatku w formacie(rrrr-mm-dd):" << endl;
                expense.setDate(DateFunction :: convertDateStringToInt(AuxiliaryMethods :: loadLine()));
            }
            while ( expense.getDate() == 0);
            break;
        }
        cout << endl << "Wybrano nieprawidlowy numer!" << endl << endl;
        system("pause");
    }
    cout << "Podaj kategorie wydatku:" << endl;
    expense.setCategory(AuxiliaryMethods :: loadLine());
    expense.setCategory(AuxiliaryMethods:: changeFirstLetterForUpperCaseAndOthersForLowerCase(expense.getCategory()));

    cout << "Podaj kwote wydatku:" << endl;
    expense.setAmount(AuxiliaryMethods :: loadNumber());
    expense.setIdUser(LOGGED_IN_USER_ID);
    expenses.push_back(expense);

    expenseFile.addExpenseToFile(expense);
    cout << "Nowy wydatek zostal dodany." << endl;
    system("pause");
}

void IncomeExpense :: dispalyIncomes(Income income)
{
    cout << endl << "Data:          " << DateFunction :: convertDateIntToString(income.getDate()) << endl;
    cout << "Kategoria:     " << income.getCategory() << endl;
    cout << "Przychod:      " << fixed << setprecision(2) << income.getAmount() << " zl" << endl;
}

void IncomeExpense :: dispalyExpenses(Expense expense)
{
    cout << endl << "Data:          " << DateFunction :: convertDateIntToString(expense.getDate()) << endl;
    cout << "Kategoria:     " << expense.getCategory() << endl;
    cout << "Wydatek:       " << fixed << setprecision(2) << expense.getAmount() << " zl" << endl;
}

void IncomeExpense :: balance(char choice)
{
    double incomesTolal = 0, expensesTotal = 0;
    int dateFrom = 0, dateTo = 0;

    if (choice == '3')
    {
        dateFrom = DateFunction :: loadThisMonth();
        dateTo = dateFrom + 100;
    }
    else if (choice == '4')
    {
        dateFrom = DateFunction :: loadLastMonth();
        dateTo = dateFrom + 100;
    }
    else if (choice == '5')
    {
        do
        {
            cout << "Podaj date od (w formacie rrrr-mm-dd):" << endl;
            dateFrom = DateFunction :: convertDateStringToInt(AuxiliaryMethods :: loadLine());
            cout << "Podaj date do (w formacie rrrr-mm-dd):" << endl;
            dateTo = DateFunction :: convertDateStringToInt(AuxiliaryMethods :: loadLine());
        }
        while ((dateFrom == 0) || (dateTo == 0));
    }

    system("cls");
    cout << "   >>> ZESTAWIENIE PRZYCHODOW I WYDATKOW  <<<"  << endl;
    cout << "-----------------------------------------------" << endl;

    incomesTolal = selectIncomesByDate(dateFrom, dateTo);
    expensesTotal = selectExpensesByDate(dateFrom, dateTo);
    displayBalance(incomesTolal, expensesTotal);
    system("pause");
}

double IncomeExpense :: selectIncomesByDate(int dateFrom, int dateTo)
{
    double incomesTolal = 0;

    if (!incomes.empty())
    {
       cout << "      >>> PRZYCHODY<<<" << endl << endl;;
       sort(incomes.begin(), incomes.end(), [](Income &income1, Income &income2){return income1.getDate() < income2.getDate();});

       for (size_t i = 0; i < incomes.size(); i++)
        {
            if ((incomes[i].getDate() >= dateFrom) && (incomes[i].getDate() < dateTo))
            {
                dispalyIncomes(incomes[i]);
                incomesTolal += incomes[i].getAmount();
            }
        }
        cout << endl;
    }
    else {cout << "BRAK PRZYCHODOW Z WYBRANEGO OKRESU" << endl << endl;}

    return incomesTolal;
}

double IncomeExpense :: selectExpensesByDate(int dateFrom, int dateTo)
{
    double expensesTotal = 0;

    if (!expenses.empty())
    {
        cout << "      >>> WYDATKI <<<" << endl << endl;
        sort(expenses.begin(), expenses.end(), [](Expense &expense1, Expense &expense2){return expense1.getDate() < expense2.getDate();});
        for (size_t i = 0; i < expenses.size(); i++)
        {
            if ((expenses[i].getDate() >= dateFrom) && ((expenses[i].getDate() < dateTo)))
            {
                dispalyExpenses(expenses[i]);
                expensesTotal += expenses[i].getAmount();
            }
        }
        cout << endl;
    }
    else {cout << "BRAK WYDATKOW Z WYBRANEGO OKRESU" << endl << endl;}

    return expensesTotal;
}

void IncomeExpense :: displayBalance(double &incomesTolal, double &expensesTotal)
{
    cout << "      >>> BILANS PRZYCHODOW I WYDATKOW <<<"  << endl << endl;
    cout << " PRZYCHODY: " << incomesTolal << " zl" << endl;
    cout << " WYDATKI:   " << expensesTotal << " zl" << endl;
    cout.setf(ios_base::showpos);
    cout << " BILANS:    " << incomesTolal - expensesTotal << " zl" << endl << endl;
	cout.unsetf(ios_base::showpos);
}
