#include "useraccount.h"

UserAccount::UserAccount()
{
    this->account_id = -1;
    this->logged_in = false;
    this->registered = false;

    this->dict_id = -1;
}

void UserAccount::LogIn(int account_id, QString login, QString password)
{
    this->account_id = account_id;
    this->login = login;
    this->password = password;

    this->logged_in = true;
    this->registered = true;
}

void UserAccount::CreateDictionary(QString dict_name)
{
    int dict_id = this->dictionaries.size();

    UserDictionary new_dict(dict_id, dict_name);
    this->dictionaries.append(new_dict);

    if(this->dict_id == -1)
        this->dict_id = 0;
}

void UserAccount::MakeGlobalDictionary()
{
    this->global_dictionary = UserDictionary();

    for(int i = 0, dict_count = this->dictionaries.size(); i < dict_count; ++i)
    {
        for(int j = 0, word_count = this->dictionaries[i].size(); j < word_count; ++j)
        {
            QString word = this->dictionaries[i][j].GetWord();
            QString translate = this->dictionaries[i][j].GetTranslate();

            this->global_dictionary.add_word(word, translate);
        }
    }

    this->global_dictionary.CheckDuplicates();
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
