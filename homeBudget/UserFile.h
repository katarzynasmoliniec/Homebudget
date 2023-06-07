#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "user.h"
#include "auxiliaryMethods.h"

using namespace std;

class UserFile
{
    const string FILE_NAME;
  //  string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
  //  Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    UserFile(string nameFileUser) : FILE_NAME(nameFileUser){};

  //  void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
  //  vector <Uzytkownik> wczytajUzytkownikowZPliku();
  //  void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
};
#endif
