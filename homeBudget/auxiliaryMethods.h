#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string str);
    static string loadLine();
    static char loadChar();
    static double loadNumber();
    static string doubleToString(double number);
    static double stringToDouble(string number);
};
#endif
