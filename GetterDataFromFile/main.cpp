// wyciaganie danych z pliku xml i wlozenie ich do vectora
// sprawdzenie czy data miesci sie w zakresie dat wpisanych od uzytkownika
// sortowanie dat z zakresu (od najstarszej)

#include <iostream>
#include <vector>
#include <cstdlib>

#include <algorithm>
#include <iterator>

#include "Markup.h"

using namespace std;

struct Date
{
    int year = 0, month = 0, day = 0;
};

Date convertDateToVector(string number)
{
    Date date;
    string stringName = "";
    int numberOfPositionInStructur = 1;

    for (size_t posiotionChar = 0; posiotionChar < number.length(); posiotionChar++)
    {
        if (number[posiotionChar] != '-')
        {
            stringName += number[posiotionChar];
        }
        else
        {
            switch(numberOfPositionInStructur)
            {
            case 1:
                date.year = atoi(stringName.c_str());
                break;
            case 2:
                date.month = atoi(stringName.c_str());
                break;
            }
            numberOfPositionInStructur++;
            stringName = "";
        }
    }
    date.day = atoi(stringName.c_str());

    return date;
}

bool comp( const Date& wg1, const Date& wg2)
{
    return (wg1.year < wg2.year)
            || (wg1.year == wg2.year && (wg1.month < wg2.month))
                || (wg1.month == wg2.month && (wg1.day < wg2.day));
}

int main()
{
    vector <Date> dates;
    vector <Date> rightdates;
    CMarkup xml;

    xml.Load( "incomes.xml" );
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("UserId"))
    {
        xml.IntoElem();
        xml.FindElem("Date");

        MCD_STR strDate = xml.GetData();
        dates.push_back(convertDateToVector(strDate));

        xml.FindElem("Incomel");
        int nQty = atoi( MCD_2PCSZ(xml.GetData()) );
        cout << "Incomel: " << nQty << endl;
        xml.OutOfElem();
    }

    for (size_t i = 0; i < dates.size(); i++)
        {
            cout << "Data w wektorze: " << dates[i].day << "-" << dates[i].month << "-" << dates[i].year << endl;
        }

    cout << "---------------" << endl;
    // bilans z wybranego okresu
    // sprawdzenie czy data miesci sie w zakresie dat wpisanych od uzytkownika
    // daty wpisane od uzytkownika sa przykladowymi datami

    int dayFrom = 19;
    int monthFrom = 5;
    int yearFrom = 2020;
    int dayTo = 6;
    int monthTo = 6;
    int yearTo = 2023;

    for (size_t i = 0; i < dates.size(); i++)
        {
            if (dates[i].year < yearFrom || dates[i].year > yearTo)
                cout << "Data poza zakresem!" << endl;
            else if (dates[i].year == yearFrom || dates[i].year == yearTo)
            {
                if (dates[i].month < monthFrom || dates[i].month > monthTo)
                    cout << "Data poza zakresem!" << endl;
                else if (dates[i].month == monthFrom || dates[i].month == monthTo)
                {
                    if (dates[i].day >= dayFrom || dates[i].day <= dayTo)
                    {
                        cout << "Data miesci sie w zakresie" << endl;
                        rightdates.push_back(dates[i]);
                    }
                    else
                        cout << "Data poza zakresem" << endl;
                }
            }
            else
            {
                cout << "Data miesci sie w zakresie" << endl;
                rightdates.push_back(dates[i]);
            }
        }

    cout << "---------------" << endl;

 // sortowanie dat z zakresu (od najstarszej)

    for (size_t i = 0; i < rightdates.size(); i++)
        {
            cout << "Data przed sortowaniem: " << rightdates[i].day << "-" << rightdates[i].month << "-" << rightdates[i].year << endl;
        }

    sort( rightdates.begin(), rightdates.end(), comp );
    for (size_t i = 0; i < rightdates.size(); i++)
        {
            cout << "Data posortowana: " << rightdates[i].day << "-" << rightdates[i].month << "-" << rightdates[i].year << endl;
        }

    return 0;
}
