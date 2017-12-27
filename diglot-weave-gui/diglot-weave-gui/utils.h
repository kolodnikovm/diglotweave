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
#include <QProcess>

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

    static void dict_save(QString in_dict_name, QList<QPair<QString, QString>> in_dict);
    static void text_save(QString in_text_name, QString text_full);
    static void run_python(QString in_text_name, QString in_dict_name, QString out_dict_name);
    static QList<QPair<QString, QString>> dict_load(QString out_dict_name);
};

#endif // UTILS_H
