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

    choice = AuxiliaryMethods :: wczytajZnak();
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

    choice = AuxiliaryMethods :: wczytajZnak();
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
        string dateAdded = AuxiliaryMethods :: wczytajLinie();
        income.setDate(DateFunction :: convertDateToIntandCheckDate(dateAdded));
    }

    cout << "Podaj kategorie przychodu:" << endl;
    income.setCategory(AuxiliaryMethods :: wczytajLinie());

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
        string dateAdded = AuxiliaryMethods :: wczytajLinie();
        expense.setDate(DateFunction :: convertDateToIntandCheckDate(dateAdded));
    }

    cout << "Podaj kategorie wydatku:" << endl;
    expense.setCategory(AuxiliaryMethods :: wczytajLinie());

    cout << "Podaj kwote wydatku:" << endl;
    expense.setAmount(AuxiliaryMethods :: loadNumber());
    expense.setIdUser(LOGGED_IN_USER_ID);
    expenses.push_back(expense);

    expenseFile.addExpenseToFile(expense);
    cout << "Nowy wydatek zostal dodany." << endl;
    system("pause");
}
void IncomeExpense :: balanse()
{

}
