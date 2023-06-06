// Dodawanie Datych do pliku xml
// Sprawdzenie czy podana data jest wlasciwa
// Plus funckja ktora pobiera dzisiejsza date

#include <iostream>
#include <ctime>
#include <cstdio>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <winbase.h>
#include <sstream>

#include "Markup.h"

using namespace std;

bool checkYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int checkDate(int d, int m, int y, int *daysOfMonth)
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    if (!checkYear(y))
        return ((d > 0 && d <= *daysOfMonth) && (m >= 1 && m <= 12) && (y >= 2000 && y < st.wYear)) || (y == st.wYear && m <= st.wMonth && d <= *daysOfMonth);
    else
        if (m == 2)
            return ((d > 0 && d <= *daysOfMonth +1) && (m >= 1 && m <= 12) && (y >= 2000 && y < st.wYear)) || (y == st.wYear && m <= st.wMonth && d <= *daysOfMonth);
        else
            return ((d > 0 && d <= *daysOfMonth) && (m >= 1 && m <= 12) && (y >= 2000 && y < st.wYear)) || (y == st.wYear && m <= st.wMonth && d <= *daysOfMonth);
}

string convertToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string convertDatesToStringStructur(int d, int m, int y)
{
    string date = "";
    date = convertToString(y) + "-" + convertToString(m) + "-" + convertToString(d);
    cout << date;

    return date;
}

string addDate()
{
    tm t = {};
    int year = 0, month = 0, day = 0;
    int daysOfMonth[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    string date = "";

    cout << "Podaj date(rrrr-mm-dd):" << endl;
    cin.sync();
    cin >> get_time(&t, "%Y-%m-%d");

    day = t.tm_mday;
    month = t.tm_mon + 1;
    year = t.tm_year + 1900;

    if (!checkDate(day, month, year, &daysOfMonth[month-1]))
    {
        cout << "Wrong date!" << endl;
        system("pause");
        exit(0);
    }
    else
    {
        cout << "Correct date!" << endl;
        date = convertDatesToStringStructur(day, month, year);
    }
    return date;
}

string getTodaysDate()
{
    string newDate = "";
    char bufor[ 64 ];
    time_t czas;
    time( & czas );
    tm czasTM = * localtime( & czas );

    strftime( bufor, sizeof( bufor ), "%Y-%m-%d", & czasTM );
    newDate = bufor;

    return newDate;
}

int main()
{
    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("UserId", "1");
    xml.IntoElem();
    xml.AddElem("Item", "1");
    xml.AddElem("Date", addDate());
    xml.AddElem("Incomel", "2000");
    xml.AddElem("Amount", "500");
    xml.OutOfElem();

    xml.AddElem("UserId", "2");
    xml.IntoElem();
    xml.AddElem("Item", "1");
    xml.AddElem("Date", addDate());
    xml.AddElem("Incomel", "3000");
    xml.AddElem("Amount", "100");
    xml.OutOfElem();

    xml.Save("incomes.xml");

    return 0;
}
