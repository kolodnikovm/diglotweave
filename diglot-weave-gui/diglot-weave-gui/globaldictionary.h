#ifndef GLOBALDICTIONARY_H
#define GLOBALDICTIONARY_H

#include <QMap>
#include "userdictionary.h"

class GlobalDictionary : public UserDictionary
{
public:
    GlobalDictionary();
    void CheckDuplicates();
};

#endif // GLOBALDICTIONARY_H
