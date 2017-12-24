#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QRegExp>
#include <QCryptographicHash>
#include <QErrorMessage>

class utils
{
public:
    static const QString text_open_tag;
    static const QString text_close_tag;

    static const QString highlight_open_tag;
    static const QString highlight_close_tag;

    utils();

    static bool is_input_valid(QString input);
    static bool is_email_valid(QString email);

    static bool is_word_valid(QString word_value);
    static bool is_translate_valid(QString translate_value);

    static QString generate_password_hash(QString password);
    static void show_error(QString error_msg);
    static double get_doubled_random();
};

#endif // UTILS_H
