#include "userdictionary.h"

UserDictionary::UserDictionary() { }

UserDictionary::UserDictionary(int dict_id, QString dict_name)
{
    this->dict_id = dict_id;
    this->dict_name = dict_name;
}

void UserDictionary::add_word(QString word, QString translate)
{
    DictRecord dict_record(word, translate);
    this->words.append(dict_record);
}

void UserDictionary::remove_word(QString word, QString translate)
{
    int word_index = -1;

    for(int i = 0; i < this->words.size(); ++i)
    {
        QString _word = this->words[i].GetWord();
        QString _translate = this->words[i].GetTranslate();

        if(_word == word && _translate == translate)
        {
            word_index = i;
            break;
        }
    }

    if(word_index != -1)
        this->words.removeAt(word_index);
}

DictRecord& UserDictionary::operator [](const int index)
{
    if(index >= 0 && index <= this->words.size())
        return this->words[index];
    else
        return *(new DictRecord("NONE", "NONE"));
}

int UserDictionary::size()
{
    return this->words.length();
}
