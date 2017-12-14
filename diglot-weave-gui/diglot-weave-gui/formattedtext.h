#ifndef FORMATTEDTEXT_H
#define FORMATTEDTEXT_H

#include <QString>

#include <userdictionary.h>
#include "dictrecord.h"

class FormattedText
{
private:
    QString text;

    static const QString textOpenTag;
    static const QString textCloseTag;

    static const QString highlightOpenTag;
    static const QString highlightCloseTag;

    UserDictionary dict_now;
public:
    FormattedText(QString text);
    void SetDict(UserDictionary* dict_now);
    QString GetFormattedText();
    void ReplaceWord(QString chosen_word);
};

#endif // FORMATTEDTEXT_H
