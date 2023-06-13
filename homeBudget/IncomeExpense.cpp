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
    string dateAdded = "";

    choice = selectOptionFromIncomeMenu();

    if (choice == '1')
    {
        income.setDate(DateFunction :: getTodayDate());
    }
    else if (choice == '2')
    {
        do
        {
            cout << "Podaj date przychodu w formacie(rrrr-mm-dd):" << endl;
            dateAdded = AuxiliaryMethods :: loadLine();
            income.setDate(DateFunction :: convertDateStringToInt(dateAdded));
        }
        while ( income.getDate() == 0);
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
    string dateAdded = "";

    choice = selectOptionFromExpenseMenu();

    if (choice == '1')
    {
        expense.setDate(DateFunction :: getTodayDate());
    }
    else if (choice == '2')
    {
        do
        {
            cout << "Podaj date wydatku w formacie(rrrr-mm-dd):" << endl;
            dateAdded = AuxiliaryMethods :: loadLine();
            expense.setDate(DateFunction :: convertDateStringToInt(dateAdded));
        }
        while ( expense.getDate() == 0);
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

void IncomeExpense :: balance()
{
    double incomesTolal = 0, expensesTotal = 0;

    system("cls");
    cout << "   >>> ZESTAWIENIE PRZYCHODOW I WYDATKOW <<<"  << endl;
    cout << "-----------------------------------------------" << endl;

    if (!incomes.empty())
    {
       cout << "      >>> PRZYCHODY <<<"  << endl;
       sort(incomes.begin(), incomes.end(), [](Income &income1, Income &income2){return income1.getDate() < income2.getDate();});
       for (size_t i = 0; i < incomes.size(); i++)
        {
            dispalyIncomes(incomes[i]);
            incomesTolal += incomes[i].getAmount();
        }
        cout << endl;
    }
    if (!expenses.empty())
    {
        cout << "      >>> WYDATKI <<<"  << endl;
        sort(expenses.begin(), expenses.end(), [](Expense &expense1, Expense &expense2){return expense1.getDate() < expense2.getDate();});
        for (size_t i = 0; i < expenses.size(); i++)
        {
            dispalyExpenses(expenses[i]);
            expensesTotal += expenses[i].getAmount();
        }
        cout << endl;
    }
    cout << "      >>> PRZYCHODY I WYDATKI <<<"  << endl << endl;
    cout << " PRZYCHODY: " << incomesTolal << " zl" << endl;
    cout << " WYDATKI:   " << expensesTotal << " zl" << endl;
    cout << " BILANS:    " << incomesTolal - expensesTotal << " zl" << endl << endl;

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

void IncomeExpense :: balanceThisMonth()
{
    double incomesTolal = 0, expensesTotal = 0;
    int thisMonth = 0;
    bool areAmount = false;

    thisMonth = DateFunction :: loadThisMonth();
    system("cls");
    cout << "   >>> ZESTAWIENIE PRZYCHODOW I WYDATKOW Z BIEACEGO MIESIACA <<<"  << endl;
    cout << "-----------------------------------------------" << endl;

    if (!incomes.empty())
    {
       cout << "      >>> PRZYCHODY Z BIEACEGO MIESIACA<<<" << endl << endl;;
       sort(incomes.begin(), incomes.end(), [](Income &income1, Income &income2){return income1.getDate() < income2.getDate();});

       for (size_t i = 0; i < incomes.size(); i++)
        {
            if (incomes[i].getDate() >= thisMonth)
            {
                dispalyIncomes(incomes[i]);
                incomesTolal += incomes[i].getAmount();
                areAmount = true;
            }
            else if (areAmount)
                cout << "BRAK PRZYCHODOW Z BIEZACEGO OKRESU" << endl << endl;
        }
        cout << endl;
    }
    else {cout << "BRAK PRZYCHODOW Z BIEZACEGO OKRESU" << endl << endl;}

    if (!expenses.empty())
    {
        cout << "      >>> WYDATKI Z BIEACEGO MIESIACA <<<" << endl << endl;
        sort(expenses.begin(), expenses.end(), [](Expense &expense1, Expense &expense2){return expense1.getDate() < expense2.getDate();});
        for (size_t i = 0; i < expenses.size(); i++)
        {
            if (expenses[i].getDate() >= thisMonth)
            {
                dispalyExpenses(expenses[i]);
                expensesTotal += expenses[i].getAmount();
                areAmount = true;
            }
            else if (areAmount)
                cout << "BRAK WYDATKOW Z BIEZACEGO OKRESU" << endl << endl;
        }
        cout << endl;
    }
    else {cout << "BRAK WYDATKOW Z BIEZACEGO OKRESU" << endl << endl;}

    cout << "      >>> PRZYCHODY I WYDATKI <<<"  << endl << endl;
    cout << " PRZYCHODY: " << incomesTolal << " zl" << endl;
    cout << " WYDATKI:   " << expensesTotal << " zl" << endl;
    cout << " BILANS:    " << incomesTolal - expensesTotal << " zl" << endl << endl;

    system("pause");
}
