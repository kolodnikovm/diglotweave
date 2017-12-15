#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <QString>
#include <QList>
#include "userdictionary.h"

class UserAccount
{
private:
    int account_id;

    QString email;
    QString login;
    QString password;

    QList<UserDictionary> dictionaries;

    bool verified;
    int dict_id;

public:
    bool logged_in;
    bool registered;

    UserAccount();
    UserAccount(int account_id, QString email, QString login, QString password);
    bool LogIn(QString login, QString password);
    void VerifyAccount();
    void CreateDictionary(QString dict_name);
    UserDictionary* GetDictionary();
    UserDictionary* GetDictionary(int dict_id);
    void SetDictionary(int dict_id);
    int GetDictionariesCount();
    void DeleteDictionary(int dict_id);
};

#endif // USERACCOUNT_H
