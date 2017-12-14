#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QRegExp>
#include <QCryptographicHash>

#include "dialogs/errordialog.h"

class utils
{
public:
    utils();

    static bool is_input_valid(QString input);
    static bool is_email_valid(QString email);
    static QString generate_password_hash(QString password);
    static void show_error(QString error_msg);
};

#endif // UTILS_H
