#include "globaldictionary.h"

GlobalDictionary::GlobalDictionary() { }

void GlobalDictionary::CheckDuplicates()
{
    QMap<int, bool> dupl;

    for(int i = 0, len = this->words.size(); i < len; ++i)
    {
        QString word_one = this->words[i].GetWord();

        if(dupl.contains(i))
            if(dupl[i])
                continue;

        dupl[i] = false;

        for(int j = i + 1, len = this->words.size(); j < len; ++j)
        {
            QString word_two = this->words[j].GetWord();

            if(word_one == word_two)
            {
                dupl[j] = true;
                break;
            }
        }
    }

    for(int i = this->words.size() - 1; i >= 0; --i)
    {
        if(dupl[i])
            this->words.removeAt(i);
    }
}
