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

    choice = selectOptionFromIncomeMenu();

    if (choice == '1')
    {
        income.setDate(DateFunction :: getTodayDate());
    }
    else if (choice == '2')
    {
        cout << "Podaj date przychodu w formacie(rrrr-mm-dd):" << endl;
        string dateAdded = AuxiliaryMethods :: loadLine();
        income.setDate(DateFunction :: convertDateToIntandCheckDate(dateAdded));
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

    choice = selectOptionFromExpenseMenu();

    if (choice == '1')
    {
        expense.setDate(DateFunction :: getTodayDate());
    }
    else if (choice == '2')
    {
        cout << "Podaj date wydatku w formacie(rrrr-mm-dd):" << endl;
        string dateAdded = AuxiliaryMethods :: loadLine();
        expense.setDate(DateFunction :: convertDateToIntandCheckDate(dateAdded));
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
        }
        cout << endl;
    }
    system("pause");
}

void IncomeExpense :: dispalyIncomes(Income income)
{
    cout << endl << "Data:          " << income.getDate() << endl;
    cout << "Kategoria:     " << income.getCategory() << endl;
    cout << "Przychod:      " << fixed << setprecision(2) << income.getAmount() << " zl" << endl;
}
void IncomeExpense :: dispalyExpenses(Expense expense)
{
    cout << endl << "Data:          " << expense.getDate() << endl;
    cout << "Kategoria:     " << expense.getCategory() << endl;
    cout << "Wydatek:       " << fixed << setprecision(2) << expense.getAmount() << " zl" << endl;
}
