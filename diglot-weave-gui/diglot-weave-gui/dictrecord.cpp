#include "dictrecord.h"

DictRecord::DictRecord(QString word, QString translate)
{
    this->word = word;
    this->translate = translate;
}

QString DictRecord::GetWord()
{
    return this->word;
}

QString DictRecord::GetTranslate()
{
    return this->translate;
}

QString DictRecord::ModifyTranslate(QString translate_new)
{
    this->translate = translate_new;
}
