#ifndef USERDICTIONARY_H
#define USERDICTIONARY_H

#include <QString>
#include <QList>

#include "dictrecord.h"
#include "utils.h"

class UserDictionary
{
protected:
    QList<DictRecord> words;
public:
    int dict_id;
    QString dict_name;

    UserDictionary();
    UserDictionary(int dict_id, QString dict_name);
    void add_word(QString word, QString translate);
    void remove_word(QString word, QString translate);
    int size();
    DictRecord& operator[] (const int index);
    QString operator[] (const QString word);
    bool CheckDuplicates(bool output_error = false);
    bool CheckDuplicates(UserDictionary* dict_two, bool output_error);
};

#endif // USERDICTIONARY_H
