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

QList<QPair<QString, QString>> utils::read_file(QString file_name)
{
    QList<QPair<QString, QString>> test_list;

    QFile file(file_name);
    file.open(QIODevice::ReadOnly);

    QTextStream in_file(&file);

    while(!in_file.atEnd())
    {
        QString new_line = in_file.readLine();
        QStringList new_line_list = new_line.split(' ');
        test_list.append(QPair<QString, QString>(new_line_list[0],
                                                 new_line_list[1]));
    }

    file.close();
    return test_list;
}

void utils::test(QString test_file_name, QString check_file_name)
{
    UserDictionary test_dict(0, "dict_name");

    QList<QPair<QString, QString>> init_values;
    init_values = read_file(test_file_name);

    QList<QPair<QString, QString>> check_values;
    check_values = read_file(check_file_name);

    for(int i = 0, len = init_values.size(); i < len; ++i)
        test_dict.add_word(init_values[i].first, init_values[i].second);

    test_dict.CheckDuplicates();
    int dict_count = test_dict.size();
    int test_count = check_values.size();

    qDebug() << "test";
    qDebug() << QString("%1 %2").arg(QString::number(dict_count),
                                     QString::number(test_count)) << endl;

    if(dict_count != test_count)
    {
         qDebug() << "NOT EQUAL";
    }
    else
    {
         qDebug() << "EQUAL";

        for(int i = 0; i < test_count; ++i)
        {
            QString word_value = check_values[i].first;
            QString translate_one = check_values[i].second;
            QString translate_two = test_dict[word_value];
            bool translate_equal = translate_one.compare(translate_two) == 0;

            qDebug() << QString("%1 (%2 == %3) = %4").arg(word_value,
                                                          translate_one, translate_two,
                                                          QString::number(translate_equal));
        }
    }
}

double utils::get_doubled_random()
{
    return double(qrand()) / double(RAND_MAX);
}

void utils::run_python(QString in_text, QString in_vocab, QString out_vocab)
{
    QString program = "./run_python.sh";
    QStringList arguments;
    arguments << in_text << in_vocab << out_vocab;

    QProcess::execute(program, arguments);
}
