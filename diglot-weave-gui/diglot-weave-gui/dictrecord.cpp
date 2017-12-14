#include "dictrecord.h"

DictRecord::DictRecord(QString word, QString translate)
{
    this->word = word;
    this->translate = translate;

    this->translated = false;
}

QString DictRecord::GetWord()
{
    return this->word;
}

QString DictRecord::GetTranslate()
{
    return this->translate;
}

bool DictRecord::IsTranslated()
{
    return this->translated;
}

void DictRecord::Translate()
{
    this->translated = true;
}
