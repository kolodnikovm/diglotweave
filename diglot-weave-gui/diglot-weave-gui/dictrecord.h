#ifndef WORDPAIR_H
#define WORDPAIR_H

#include <QString>

class DictRecord
{
protected:
    QString word;
    QString translate;
public:
    DictRecord(QString word, QString translate);

    QString GetWord();
    QString GetTranslate();
};

#endif // WORDPAIR_H
