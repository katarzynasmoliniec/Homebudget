#include "IncomeFile.h"

vector <Income> IncomeFile :: loadIncomesOfLoggedInUserFromFile(int idLoggedUser)
{
    Income income;
    vector <Income> incomes;

    CMarkup xml;

    xml.Load(FILE_NAME);
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("IdUser");
        if (idLoggedUser == atoi( MCD_2PCSZ(xml.GetData())))
        {
            income.setIdUser(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Date");
            income.setDate(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Amount");
            income.setAmount(AuxiliaryMethods :: stringToDouble(xml.GetData()));
            xml.FindElem("Category");
            income.setCategory(xml.GetData());
            incomes.push_back(income);
        }
    }
    xml.ResetPos();
    return incomes;
}

void IncomeFile :: addIncomeToFile(Income income)
{
    CMarkup xml;
    bool fileExists = xml.Load( FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IdUser", income.getIdUser());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Amount", AuxiliaryMethods :: doubleToString(income.getAmount()));
    xml.AddElem("Category", income.getCategory());
    xml.ResetPos();
    xml.Save(FILE_NAME);
}
