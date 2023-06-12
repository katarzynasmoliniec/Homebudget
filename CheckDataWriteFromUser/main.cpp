
// Sprawdzenie poprawnosci wpisanych dat przez uzytkownika

#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <winbase.h>
#include <sstream>
#include <vector>

using namespace std;

struct Date
{
    int year = 0, month = 0, day = 0;
};

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

Date convertDateToIntStructur( string number)
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

int main()
{
    tm t = {};
    int yearFrom = 0, monthFrom = 0, dayFrom = 0, dayTo = 0, monthTo = 0, yearTo = 0;
    int daysOfMonth[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

    cout << "Podaj date od (rrrr-mm-dd):" << endl;
    cin >> get_time(&t, "%Y-%m-%d");

    dayFrom = t.tm_mday;
    monthFrom = t.tm_mon + 1;
    yearFrom = t.tm_year + 1900;

    if (!checkDate(dayFrom, monthFrom, yearFrom, &daysOfMonth[monthFrom-1]))
        cout << "Wrong date!" << endl;
    else
        cout << "Correct date!" << endl;

    cout << "Podaj date do (rrrr-mm-dd):" << endl;
    cin >> get_time(&t, "%Y%m%d");

    cout << t;
    dayTo = t.tm_mday;
    monthTo = t.tm_mon + 1;
    yearTo = t.tm_year + 1900;

   if (!checkDate(dayTo, monthTo, yearTo, &daysOfMonth[monthTo-1]))
        cout << "Wrong date!" << endl;
    else
        cout << "Correct date!" << endl;*/

    return 0;
}
