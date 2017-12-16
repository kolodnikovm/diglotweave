#ifndef WORDRECORD_H
#define WORDRECORD_H

#include <QString>
#include "dictrecord.h"

class WordRecord : public DictRecord
{
private:
    bool translated;
    bool highlighted;
    bool has_translate;

    QString start_punct_marks;
    QString stop_punct_marks;

public:
    WordRecord(QString word);

    void SetPunctMarks(QString start_punct_marks, QString stop_punct_marks);
    void SetTranslate(QString translate);
    QString GetFullWord(QString tag_open, QString tag_close, bool translated = false);

    bool IsTranslated();
    bool HaveTranslate();
    void Translate();

    bool IsHighlighted();
    void Highlight();
    void UnHighlight();
};

#endif // WORDRECORD_H
