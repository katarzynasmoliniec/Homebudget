#include "ExpenseFile.h"

vector <Expense> ExpenseFile :: loadExpensesOfLoggedInUserFromFile(int idLoggedUser)
{
    Expense expense;
    vector <Expense> expenses;

    CMarkup xml;

    xml.Load(FILE_NAME);
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("IdUser");
        if (idLoggedUser == atoi( MCD_2PCSZ(xml.GetData())))
        {
            expense.setIdUser(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Date");
            expense.setDate(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Amount");
            expense.setAmount(AuxiliaryMethods :: stringToDouble(xml.GetData()));
            xml.FindElem("Category");
            expense.setCategory(xml.GetData());
            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    xml.ResetPos();
    return expenses;
}

void ExpenseFile :: addExpenseToFile(Expense expense)
{
    CMarkup xml;
    bool fileExists = xml.Load( FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("IdUser", expense.getIdUser());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Amount", AuxiliaryMethods :: doubleToString(expense.getAmount()));
    xml.AddElem("Category", expense.getCategory());
    xml.ResetPos();
    xml.Save(FILE_NAME);
}
