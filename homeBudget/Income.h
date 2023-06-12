#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int idUser, date;
    double amount;
    string category;

public:
    void setIdUser(int newIdUser);
    void setDate(int newDate);
    void setAmount(double newAmount);
    void setCategory(string newCategory);
    int getIdUser();
    int getDate();
    double getAmount();
    string getCategory();
};
#endif
