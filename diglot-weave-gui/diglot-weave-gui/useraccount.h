#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <QString>
#include <QList>

#include "userdictionary.h"
#include "database_handler.h"

class UserAccount
{
private:
    int account_id;

    QString login;
    QString password;

    QList<UserDictionary> dictionaries;
    UserDictionary global_dictionary;
    database_handler* db_handler;

    int dict_id;

public:
    bool logged_in;
    bool registered;

    UserAccount();
    UserAccount(database_handler* db_handler);

    const QList<UserDictionary> * getDictList();

    void LogIn(int account_id, QString login, QString password);
    void LoadData();
    void SaveData();

    void CreateDictionary(QString dict_name, int dict_id = -1);
    void CheckDuplicates(bool output_error = false);
    void MakeGlobalDictionary();
    UserDictionary* GetCurDictionary();
    int GetCurDictId() {return dict_id;}
    UserDictionary* GetDictionary(int dict_id);
    UserDictionary* GetDictionaryByOwnID(int own_dict_id);
    void SetDictionary(int dict_id);
    int GetDictionariesCount();
    void DeleteDictionary(int dict_id);
};

#endif // USERACCOUNT_H
