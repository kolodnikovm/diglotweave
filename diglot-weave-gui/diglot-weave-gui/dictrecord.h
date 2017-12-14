#ifndef WORDPAIR_H
#define WORDPAIR_H

#include <QString>

class DictRecord
{
private:
    QString word;
    QString translate;
    bool translated;
public:
    DictRecord(QString word, QString translate);

    QString GetWord();
    QString GetTranslate();

    bool IsTranslated();
    void Translate();
};

#endif // WORDPAIR_H
