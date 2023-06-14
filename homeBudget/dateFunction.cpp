#include "DateFunction.h"

int DateFunction :: getTodayDate()
{
    char bufor[10];
    int date = 0;
    time_t t;
    time(& t);
    tm tTM = * localtime(& t);
    strftime(bufor, sizeof( bufor ), "%Y%m%d", & tTM );
    date = atoi(bufor);
    return date;
}

bool DateFunction :: checkYear(int &y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int DateFunction :: checkIntDate( int &year, int &month, int &day, int &daysOfMonth)
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    if (!DateFunction :: checkYear(year))
        return ((day > 0 && day <= daysOfMonth) && (month >= 1 && month <= 12) && (year >= 2000 && year < st.wYear)) || (year == st.wYear && month <= st.wMonth && day <= daysOfMonth);
    else
        if (month == 2)
            return ((day > 0 && day <= daysOfMonth +1) && (month >= 1 && month <= 12) && (year >= 2000 && year < st.wYear)) || (year == st.wYear && month <= st.wMonth && day <= daysOfMonth);
        else
            return ((day > 0 && day <= daysOfMonth) && (month >= 1 && month <= 12) && (year >= 2000 && year < st.wYear)) || (year == st.wYear && month <= st.wMonth && day <= daysOfMonth);
}

int DateFunction :: convertDateStringToInt(string number)
{
    int year = 0, month = 0, day = 0, newDate = 0;
    int daysOfMonth[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    string stringDate = "";

    size_t found = number.find_first_of("-");
    stringDate = number.substr(0, found) + number.substr(found+1);
    year = AuxiliaryMethods ::stringToInt(number.substr(0, found));
    month = AuxiliaryMethods ::stringToInt(number.substr(found+1));

    found = stringDate.find_last_of("-");
    stringDate = stringDate.substr(0, found) + stringDate.substr(found+1);
    day =  AuxiliaryMethods ::stringToInt(number.substr(found+2));
    newDate = AuxiliaryMethods ::stringToInt(stringDate);

    if (!DateFunction :: checkIntDate(year, month, day, daysOfMonth[month-1]))
    {
        cout << "Podano nieprawidlowa date: " << number << endl;
        Sleep(1500);
        newDate = 0;
    }
    return newDate;
}

string DateFunction :: convertDateIntToString (int number)
{
    string newDate ="";
    newDate = AuxiliaryMethods :: intToString(number);
    newDate.insert(4,"-");
    newDate.insert(7,"-");
    return newDate;
}
int DateFunction :: loadThisMonth()
{
    int monthToDay = 0;
    monthToDay = DateFunction :: getTodayDate();
    monthToDay =  (monthToDay/ 100) * 100;
    return monthToDay;
}
int DateFunction :: loadLastMonth()
{
    int lastMonth = 0;
    lastMonth = DateFunction :: getTodayDate();
    lastMonth =  ((lastMonth/ 100) * 100) - 100;
    return lastMonth;
}
