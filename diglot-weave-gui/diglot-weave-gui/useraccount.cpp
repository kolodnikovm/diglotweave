#include "useraccount.h"

UserAccount::UserAccount()
{
    this->verified = false;
    this->logged_in = false;
    this->registered = false;
}

UserAccount::UserAccount(int account_id, QString email, QString login, QString password)
{
    this->account_id = account_id;
    this->email = email;
    this->login = login;
    this->password = password;

    this->verified = false;
    this->logged_in = false;
    this->registered = true;
}

void UserAccount::VerifyAccount()
{
    this->verified = true;
}

bool UserAccount::LogIn(QString login, QString password)
{
    if(this->login.compare(login) == 0 and this->password.compare(password) == 0)
    {
        this->logged_in = true;
        return true;
    }
    else
        return false;
}

void UserAccount::CreateDictionary(QString dict_name)
{
    UserDictionary new_dict(dict_name);
    this->dictionaries.append(new_dict);
}

UserDictionary* UserAccount::GetDictionary(int dict_id)
{
    if(dict_id < this->dictionaries.size())
        return &(this->dictionaries[dict_id]);
    else
        return 0;
}

int UserAccount::GetDictionariesCount()
{
    return this->dictionaries.size();
}

void UserAccount::DeleteDictionary(int dict_id)
{
    this->dictionaries.removeAt(dict_id);
}
