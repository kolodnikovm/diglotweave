#include "useraccount.h"

UserAccount::UserAccount()
{
    this->logged_in = false;
    this->registered = false;

    this->dict_id = -1;
}

UserAccount::UserAccount(int account_id, QString login, QString password)
{
    this->account_id = account_id;
    this->login = login;
    this->password = password;

    this->logged_in = false;
    this->registered = true;
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

    if(this->dict_id == -1)
        this->dict_id = 0;
}

void UserAccount::MakeGlobalDictionary()
{
    this->global_dictionary = GlobalDictionary();

    for(int i = 0, dict_count = this->dictionaries.size(); i < dict_count; ++i)
    {
        for(int j = 0, word_count = this->dictionaries[i].size(); j < word_count; ++j)
        {
            QString word = this->dictionaries[i][j].GetWord();
            QString translate = this->dictionaries[i][j].GetTranslate();

            this->global_dictionary.add_word(word, translate);
        }
    }
}

UserDictionary* UserAccount::GetDictionary()
{
    if(this->dict_id != -1)
        return this->GetDictionary(this->dict_id);
    else
        return &(this->global_dictionary);
}

UserDictionary* UserAccount::GetDictionary(int dict_id)
{
    if(dict_id < this->dictionaries.size() && dict_id >= 0)
        return &(this->dictionaries[dict_id]);
    else
        return 0;
}

void UserAccount::SetDictionary(int dict_id)
{
    if(dict_id < this->dictionaries.size())
        this->dict_id = dict_id;
}

int UserAccount::GetDictionariesCount()
{
    return this->dictionaries.size();
}

void UserAccount::DeleteDictionary(int dict_id)
{
    this->dictionaries.removeAt(dict_id);
}
