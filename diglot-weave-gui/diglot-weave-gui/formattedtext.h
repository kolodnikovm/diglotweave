#ifndef FORMATTEDTEXT_H
#define FORMATTEDTEXT_H

#include <QChar>
#include <QString>
#include <QStringList>
#include <QList>

#include <userdictionary.h>
#include "dictrecord.h"
#include "wordrecord.h"
#include "utils.h"

class FormattedText
{
private:
    UserDictionary dict_now;
    QList<WordRecord> word_list;
    double change_freq;
public:
    FormattedText();
    void SetText(QString text);
    void SetDict(UserDictionary* dict_now);
    void FormatText();
    void SetChangeWordFrequency(double change_freq);
    QString GetFormattedText();
    void ReplaceWord(QString chosen_word);
};

#endif // FORMATTEDTEXT_H
