#include "UserFile.h"

vector <User> UserFile :: loadUsersFromFile()
{
    User user;
    vector <User> users;

    CMarkup xml;

    xml.Load( FILE_NAME);
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        user.setId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Name");
        user.setName(xml.GetData());
        xml.FindElem("Surname");
        user.setSurname(xml.GetData());
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());

        users.push_back(user);
        xml.OutOfElem();
    }
    return users;
}

void UserFile :: addUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load( FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(FILE_NAME);
}

void UserFile :: writeAllUsersToFile( User user)
{
    CMarkup xml;

    xml.Load( FILE_NAME);
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        if (user.getId() == atoi( MCD_2PCSZ(xml.GetData())))
        {
            xml.FindElem("Password");
            xml.RemoveElem();
            xml.AddElem("Password", user.getPassword());
            xml.OutOfElem();
        }
        xml.OutOfElem();
    }
    xml.Save(FILE_NAME);
}
