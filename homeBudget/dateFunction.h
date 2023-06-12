#ifndef DATEFUNCTION_H
#define DATEFUNCTION_H

#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <time.h>

using namespace std;

class DateFunction
{
    static int checkIntDate(int y, int m, int d, int daysOfMonth);
    static bool checkYear(int y);

public:
    static int getTodayDate();
    static int convertDateToIntandCheckDate(string date);
};
#endif

