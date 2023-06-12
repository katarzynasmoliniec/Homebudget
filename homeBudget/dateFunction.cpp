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

    cout << "Wczytano dzisiejsza date: " << date << endl;
    Sleep(1500);
    return date;
}

bool DateFunction :: checkYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int DateFunction :: checkIntDate( int year, int month, int day, int daysOfMonth)
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

int DateFunction :: convertDateToIntandCheckDate( string number)
{
    int year = 0, month = 0, day = 0, newDate = 0;
    int daysOfMonth[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    string stringName = "";
    string stringDate = "";
    int numberOfPositionInStructur = 1;

    for (size_t i = 0; i < number.length(); i++)
    {
        if (number[i] != '-')
        {
            stringName += number[i];
            stringDate += number[i];
        }
        else
        {
            switch(numberOfPositionInStructur)
            {
            case 1:
                year = atoi(stringName.c_str());
                break;
            case 2:
                month = atoi(stringName.c_str());
                break;
            }
            numberOfPositionInStructur++;
            stringName = "";
        }
    }
    if (stringName != "")
        day = atoi(stringName.c_str());

    if (!DateFunction :: checkIntDate(year, month, day, daysOfMonth[month-1]))
    {
        cout << "Podano nieprawidlowa date: " << stringDate << endl;
        Sleep(1500);
    }
    else
    {
        cout << "Podano prawidlowa date: " << stringDate <<  endl;
        Sleep(1500);
    }

    newDate =  atoi(stringDate.c_str());
    return newDate;
}

