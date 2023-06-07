#include <iostream>
#include "homeBudget.h"

using namespace std;

int main()
{
    HomeBudget homeBudget ("Users.xml", "Income.xml", "Expense.xml");
    char choice;
    while (true)
    {
        if (homeBudget.getLoggedInUserId() == 0)
        {
            choice = homeBudget.selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                homeBudget.registerUser();;
                break;
            case '2':
                homeBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
