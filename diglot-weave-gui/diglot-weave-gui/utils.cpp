#include "utils.h"

utils::utils( ){ }

const QString utils::text_open_tag = QString("<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">");
const QString utils::text_close_tag = QString("</p>");

const QString utils::highlight_open_tag = QString("<span style=\" font-weight:600; color:#ef2929;\">");
const QString utils::highlight_close_tag = QString("</span>");

bool utils::is_input_valid(QString input)
{
    QRegExp re("\\w*");

    if(input.length() == 0)
        return false;
    else if(!re.exactMatch(input))
        return false;
    else
        return true;
}

bool utils::is_email_valid(QString email)
{
    QRegExp mailRE("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailRE.setCaseSensitivity(Qt::CaseInsensitive);
    mailRE.setPatternSyntax(QRegExp::RegExp);

    if(email.length() == 0)
        return false;
    else if(!mailRE.exactMatch(email))
        return false;
    else
        return true;
}

bool utils::is_word_valid(QString word_value)
{
    bool is_parsed = true;

    QRegExp word_re("[а-яА-Я]+");
    word_re.setCaseSensitivity(Qt::CaseInsensitive);
    word_re.setPatternSyntax(QRegExp::RegExp);

    if(!word_re.exactMatch(word_value))
    {
        utils::show_error("Значение исходного слова содержит недопустимые символы.");
        is_parsed = false;
    }
    else if(word_value.size() > 55)
    {
        utils::show_error("Длина слова в словаре не должна превышать 55 символов.");
        is_parsed = false;
    }
    else if(word_value.size() == 0)
    {
        utils::show_error("Значение слова не должно быть пустым.");
        is_parsed = false;
    }

    return is_parsed;
}

bool utils::is_translate_valid(QString translate_value)
{
    bool is_parsed = true;

    QRegExp translate_re("[a-zA-Z]+");
    translate_re.setCaseSensitivity(Qt::CaseInsensitive);
    translate_re.setPatternSyntax(QRegExp::RegExp);

    if(!translate_re.exactMatch(translate_value))
    {
        utils::show_error("Значение перевода слова содержит недопустимые символы.");
        is_parsed = false;
    }
    else if(translate_value.size() > 55)
    {
        utils::show_error("Длина перевода в словаре не должна превышать 55 символов.");
        is_parsed = false;
    }
    else if(translate_value.size() == 0)
    {
        utils::show_error("Значение перевода не должно быть пустым.");
        is_parsed = false;
    }

    return is_parsed;
}

QString utils::generate_password_hash(QString password)
{
   QString hash_value = QString(QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Md5).toHex());
   return hash_value;
}

void utils::show_error(QString error_msg)
{
    QErrorMessage* error_message = new QErrorMessage();
    error_message->showMessage(error_msg);
}

double utils::get_doubled_random()
{
    return double(qrand()) / double(RAND_MAX);
}
