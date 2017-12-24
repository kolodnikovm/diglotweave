#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <QString>
#include <QList>
#include "userdictionary.h"
#include "globaldictionary.h"

class UserAccount
{
private:
    int account_id;

    QString login;
    QString password;

    QList<UserDictionary> dictionaries;
    GlobalDictionary global_dictionary;

    int dict_id;

public:
    bool logged_in;
    bool registered;

    UserAccount();
    UserAccount(int account_id, QString login, QString password);

    bool LogIn(QString login, QString password);

    void CreateDictionary(QString dict_name);
    void MakeGlobalDictionary();
    UserDictionary* GetDictionary();
    UserDictionary* GetDictionary(int dict_id);
    void SetDictionary(int dict_id);
    int GetDictionariesCount();
    void DeleteDictionary(int dict_id);
};

#endif // USERACCOUNT_H
