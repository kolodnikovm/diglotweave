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
