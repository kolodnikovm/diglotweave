#include "useraccount.h"

UserAccount::UserAccount()
{
    this->account_id = -1;
    this->logged_in = false;
    this->registered = false;

    this->dict_id = -1;
}

UserAccount::UserAccount(database_handler* db_handler)
{
    this->db_handler = db_handler;

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

    this->LoadData();
}

void UserAccount::LoadData()
{
    QList<QPair<QString, int>> dict_list = this->db_handler->get_dictionarylist_by_username(this->login);

    for(int i = 0, dict_count = dict_list.size(); i < dict_count; ++i)
    {
        QString dict_name = dict_list[i].first;
        int own_dict_id = dict_list[i].second;

        this->CreateDictionary(dict_name, own_dict_id);

        QList<QPair<QString, QString>> dict_words = this->db_handler->get_dictionary_by_dict_id(own_dict_id);

        for(int j = 0, word_count = dict_words.size(); j < word_count; ++j)
        {
            QString word_value = dict_words[j].first;
            QString translate_value = dict_words[j].second;

            this->GetDictionaryByOwnID(own_dict_id)->add_word(word_value, translate_value);
        }
    }

    this->CheckDuplicates();
}

void UserAccount::SaveData()
{
    QList<QPair<QString, int>> dict_list = this->db_handler->get_dictionarylist_by_username(this->login);

    for(int i = 0, dict_count = this->dictionaries.size(); i < dict_count; ++i)
    {
        QString dict_name = this->dictionaries[i].dict_name;
        int dict_id = this->dictionaries[i].dict_id;
        bool found = false;

        if(dict_id != -1)
        {
            for(int j = 0, db_dict_count = dict_list.size(); j < db_dict_count; ++j)
            {
                int _dict_id = dict_list[j].second;

                if(dict_id == _dict_id)
                {
                    found = true;
                    break;
                }
            }
        }

        if(!found)
        {
            this->db_handler->add_new_user_dictionary(dict_name,
                                                      this->account_id);
            dict_id = this->db_handler->get_dictionary_id_by_dict_name(dict_name);
        }

        QList<QPair<QString, QString>> word_list = this->db_handler->get_dictionary_by_dict_id(dict_id);

        for(int j = 0, word_count = this->dictionaries[i].size(); j < word_count; ++j)
        {
            QString word_value = this->dictionaries[i][j].GetWord();
            QString translate_value = this->dictionaries[i][j].GetTranslate();
            bool found = false;

            for(int r = 0, db_word_count = word_list.size(); r < db_word_count; ++r)
            {
                if(word_value == word_list[r].first && translate_value == word_list[r].second)
                {
                    found = true;
                    break;
                }
            }

            if(!found)
                this->db_handler->add_new_word_to_user_dict(word_value, translate_value, dict_id);
        }
    }

    for(int i = 0, db_dict_count = dict_list.size(); i < db_dict_count; ++i)
    {
        QString dict_name = dict_list[i].first;
        int dict_id = dict_list[i].second;
        bool found = false;

        for(int j = 0, dict_count = this->dictionaries.size(); j < dict_count; ++j)
        {
            int _dict_id = this->dictionaries[j].dict_id;

            if(dict_id == _dict_id)
            {
                found = true;
                break;
            }
        }

        if(!found)
        {
            this->db_handler->delete_user_dictionary(dict_id);
        }
        else
        {
            QList<QPair<QString, QString>> word_list = this->db_handler->get_dictionary_by_dict_id(dict_id);

            for(int j = 0, db_word_count = word_list.size(); j < db_word_count; ++j)
            {
                QString word_value = word_list[j].first;
                QString translate_value = word_list[j].second;
                bool found = false;
                UserDictionary user_dict = *(this->GetDictionaryByOwnID(dict_id));

                for(int r = 0, word_count = user_dict.size(); r < word_count; ++r)
                {
                    if(word_value == user_dict[r].GetWord() && translate_value == user_dict[r].GetTranslate())
                    {
                        found = true;
                        break;
                    }
                }

                if(!found)
                    this->db_handler->delete_word_from_user_dict(word_value, translate_value, dict_id);
            }
        }
    }
}

void UserAccount::CheckDuplicates(bool output_error)
{
    for(int i = 0, dict_count = this->dictionaries.size(); i < dict_count; ++i)
    {
        bool found = this->GetDictionary(i)->CheckDuplicates(output_error);
        if(found)
            output_error = false;

        for(int j = i + 1; j < dict_count; ++j)
        {
            bool found = this->GetDictionary(i)->CheckDuplicates(this->GetDictionary(j),
                                                                 output_error);
            if(found)
                output_error = false;
        }
    }
}

void UserAccount::CreateDictionary(QString dict_name, int dict_id)
{
    int dict_id_now = dict_id;

    UserDictionary new_dict(dict_id_now, dict_name);
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
    if(this->dict_id >= 0 && this->dict_id < this->dictionaries.size())
        return &(this->dictionaries[dict_id]);
    else
        return 0;
}

UserDictionary* UserAccount::GetDictionaryByOwnID(int dict_id)
{
    int list_dict_id = -1;

    for(int i = 0, len = this->dictionaries.size(); i < len; ++i)
    {
        if(this->dictionaries[i].dict_id == dict_id)
        {
            list_dict_id = i;
            break;
        }
    }

    if(list_dict_id != -1)
        return &(this->dictionaries[list_dict_id]);
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

const QList<UserDictionary> * UserAccount::getDictList()
{
    return &dictionaries;
}

