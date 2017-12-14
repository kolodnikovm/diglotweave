#ifndef USERDICTIONARY_H
#define USERDICTIONARY_H

#include <QString>
#include <QList>
#include "dictrecord.h"

class UserDictionary
{
private:
    QList<DictRecord> words;
public:
    QString dict_name;

    UserDictionary();
    UserDictionary(QString dict_name);
    void add_word(QString word, QString translate);
    void remove_word(QString word, QString translate);
    int size();
    DictRecord& operator[] (const int index);
};

#endif // USERDICTIONARY_H
