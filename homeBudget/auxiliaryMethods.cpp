#include "auxiliaryMethods.h"

string AuxiliaryMethods :: konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods :: konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string AuxiliaryMethods :: wczytajLinie()
{
    string wejscie = "";
    cin.sync();
    getline(cin, wejscie);
    return wejscie;
}

string AuxiliaryMethods :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

string AuxiliaryMethods :: pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

char AuxiliaryMethods :: wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while(true)
    {
        string wejscie = wczytajLinie();

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
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
