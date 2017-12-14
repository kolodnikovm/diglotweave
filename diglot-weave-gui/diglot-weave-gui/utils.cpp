#include "utils.h"

utils::utils( ){ }

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
    ErrorDialog* errorDialog = new ErrorDialog();
    errorDialog->show_msg(error_msg);
}
