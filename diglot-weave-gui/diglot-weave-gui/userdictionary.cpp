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
    if(index >= 0 && index < this->words.size())
        return this->GetRecord(index);
    else
        return *(new DictRecord("NONE", "NONE"));
}

DictRecord& UserDictionary::GetRecord(int index)
{
    return this->words[index];
}

QString UserDictionary::operator [](const QString word_value)
{
    for(int i = 0, len = size(); i < len; ++i)
        if(word_value == this->words[i].GetWord())
            return this->words[i].GetTranslate();

    return "NONE";
}

int UserDictionary::size()
{
    return this->words.length();
}

bool UserDictionary::CheckDuplicates(bool output_error)
{
    QMap<int, bool> dupl;
    bool found = false;

    for(int i = 0, len = this->words.size(); i < len; ++i)
    {
        QString word_one = this->words[i].GetWord();

        if(dupl.contains(i))
            if(dupl[i])
                continue;

        dupl[i] = false;

        for(int j = i + 1, len = this->words.size(); j < len; ++j)
        {
            QString word_two = this->words[j].GetWord();

            if(word_one == word_two)
            {
                dupl[j] = true;
                found = true;
                break;
            }
        }
    }

    if(found)
    {
        if(output_error)
            utils::show_error("В одном из словарей обнаружены дублирующие записи.");

        for(int i = this->words.size() - 1; i >= 0; --i)
            if(dupl[i])
                this->words.removeAt(i);
    }

    return found;
}

bool UserDictionary::CheckDuplicates(UserDictionary *dict_two, bool output_error)
{
    QMap<int, bool> dupl;
    bool found = false;

    for(int i = 0, len = this->words.size(); i < len; ++i)
    {
        QString word_one = this->words[i].GetWord();

        for(int j = 0, len = dict_two->words.size(); j < len; ++j)
        {
            if(dupl.contains(j))
                if(dupl[j])
                    continue;

            dupl[i] = false;

            QString word_two = dict_two->words[j].GetWord();

            if(word_one == word_two)
            {
                dupl[j] = true;
                found = true;
                break;
            }
        }
    }

    if(found)
    {
        if(output_error)
            utils::show_error("В одном из словарей обнаружены дублирующие записи.");

        for(int i = dict_two->words.size() - 1; i >= 0; --i)
            if(dupl[i])
                dict_two->words.removeAt(i);
    }

    return found;
}

QList<QPair<QString, QString>> UserDictionary::GetWordPairs()
{
    QList<QPair<QString, QString>> words;

    for(int i = 0, len = this->size(); i < len; ++i)
        words.append(QPair<QString, QString>(this->words[i].GetWord(),
                                             this->words[i].GetTranslate()));

    return words;
}

void UserDictionary::SetWordPairs(QList<QPair<QString, QString>> words)
{
    this->words.clear();

    for(int i = 0, len = words.size(); i < len; ++i)
        this->words.append(DictRecord(words[i].first,
                                      words[i].second));
}
