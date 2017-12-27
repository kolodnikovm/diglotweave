#ifndef UTILS_H
#define UTILS_H

#include <QList>
#include <QPair>
#include <QString>
#include <QRegExp>
#include <QCryptographicHash>
#include <QErrorMessage>
#include <QWidget>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

#include "userdictionary.h"

class utils
{
public:
    static const QString text_open_tag;
    static const QString text_close_tag;

    static const QString highlight_open_tag;
    static const QString highlight_close_tag;

    utils();

    static bool is_input_valid(QString input);
    static bool is_word_valid(QString word_value);
    static bool is_translate_valid(QString translate_value);

    static QString generate_password_hash(QString password);
    static void show_error(QString error_msg);
    static double get_doubled_random();

    static QList<QPair<QString, QString>> read_file(QString file_name);
    static void test(QString test_file, QString check_file);
};

#endif // UTILS_H
