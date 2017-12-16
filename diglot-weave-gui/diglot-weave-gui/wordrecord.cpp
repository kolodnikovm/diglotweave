#include "wordrecord.h"

WordRecord::WordRecord(QString word) : DictRecord(word, "")
{
    this->translated = false;
    this->highlighted = false;
    this->has_translate = false;
}

void WordRecord::SetPunctMarks(QString start_punct_marks, QString stop_punct_marks)
{
    this->start_punct_marks = start_punct_marks;
    this->stop_punct_marks = stop_punct_marks;
}

void WordRecord::SetTranslate(QString translate)
{
    this->translate = translate;
    this->has_translate = true;
}

QString WordRecord::GetFullWord(QString tag_open, QString tag_close, bool translate)
{
    QString word_full;

    word_full += this->start_punct_marks;
    word_full += tag_open;

    if(!translate)
        word_full += this->GetWord();
    else
        word_full += this->GetTranslate();

    word_full += tag_close;
    word_full += this->stop_punct_marks + " ";

    return word_full;
}

bool WordRecord::IsTranslated()
{
    return this->translated;
}

bool WordRecord::HaveTranslate()
{
    return this->has_translate;
}

void WordRecord::Translate()
{
    if(this->has_translate)
        this->translated = true;
}

bool WordRecord::IsHighlighted()
{
    return this->highlighted;
}

void WordRecord::Highlight()
{
    this->highlighted = true;
}
