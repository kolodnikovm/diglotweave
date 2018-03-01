#include "dictrecord.h"

DictRecord::DictRecord(QString word, QString translate)
{
    this->word = word;
    this->translate = translate;
}

QString DictRecord::GetWord() const
{
    return this->word;
}

QString DictRecord::GetTranslate() const
{
    return this->translate;
}

void DictRecord::ModifyTranslate(QString translate_new)
{
    this->translate = translate_new;
}
