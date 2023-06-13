#include "auxiliaryMethods.h"

string AuxiliaryMethods :: changeFirstLetterForUpperCaseAndOthersForLowerCase(string str)
{
    if (!str.empty())
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        str[0] = toupper(str[0]);
    }
    return str;
}
string AuxiliaryMethods :: loadLine()
{
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}
char AuxiliaryMethods :: loadChar()
{
    string input = "";
    char charInfo = {0};

    while(true)
    {
        string input = loadLine();

        if (input.length() == 1)
        {
            charInfo = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return charInfo;
}
double AuxiliaryMethods :: loadNumber()
{
    string input = "";
    double number = 0;

    while(true)
    {
        getline(cin, input);
        if (input.find(','))
        {
            replace( input.begin(), input.end(), ',', '.' );
        }
        stringstream myStream(input);

        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}
string AuxiliaryMethods :: doubleToString(double number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
double AuxiliaryMethods :: stringToDouble(string number)
{
    double doubleNum;
    istringstream iss(number);
    iss >> doubleNum;
    return doubleNum;
}
string AuxiliaryMethods :: intToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int AuxiliaryMethods :: stringToInt(string number)
{
    int intNum;
    istringstream iss(number);
    iss >> intNum;
    return intNum;
}
