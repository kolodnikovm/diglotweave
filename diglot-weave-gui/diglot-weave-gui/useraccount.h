#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <QString>
#include <QList>
#include "userdictionary.h"

class UserAccount
{
private:
    int account_id;

    QString login;
    QString password;

    QList<UserDictionary> dictionaries;
    UserDictionary global_dictionary;

    int dict_id;

public:
    bool logged_in;
    bool registered;

    UserAccount();

    void LogIn(int account_id, QString login, QString password);

    void CreateDictionary(QString dict_name);
    void MakeGlobalDictionary();
    UserDictionary* GetDictionary();
    UserDictionary* GetDictionary(int dict_id);
    void SetDictionary(int dict_id);
    int GetDictionariesCount();
    void DeleteDictionary(int dict_id);
};

#endif // USERACCOUNT_H
