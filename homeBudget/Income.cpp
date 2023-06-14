#include "Income.h"

void Income :: setIdUser(int newIdUser)
{
    idUser = newIdUser;
}
void Income :: setDate(int newDate)
{
    date = newDate;
}
void Income :: setAmount(double newAmount)
{
    amount = newAmount;
}
void Income :: setCategory(string newCategory)
{
    category = newCategory;
}

int Income :: getIdUser()
{
    return idUser;
}
int Income :: getDate()
{
    return date;
}
double Income :: getAmount()
{
    return amount;
}
string Income :: getCategory()
{
    return category;
}
