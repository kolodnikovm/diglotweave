#include "database_handler.h"

database_handler::database_handler(){}


QString database_handler::connect_to_database(QString DB_name, QString QT_db_driver)
{
    // specify QT database driver
    sqliteDB = QSqlDatabase::addDatabase(QT_db_driver);
    sqliteDB.setDatabaseName(DB_name);

    // open database
    if (!sqliteDB.open())
    {
        return sqliteDB.lastError().text();
    }
    else
    {
        return sqliteDB.databaseName() + " successfully opened";
    }
}

QSqlQuery database_handler::SQL_query(QString query)
{
    // make an object
    QSqlQuery qsqlq;

    // execute query
    if (!qsqlq.exec(query))
    {
        qDebug() << qsqlq.lastError().text();
    }

    return qsqlq;
}

QList<QPair<QString, QString>> database_handler::get_users_list()
{
    // DML query execution
    QString qstr = "SELECT * FROM Users";
    QSqlQuery qsqlq = SQL_query(qstr);

    QSqlRecord rec = qsqlq.record();

    QList<QPair<QString, QString>> Users_list;
    QPair<QString, QString> user;

    while (qsqlq.next())
    {
        user.first = qsqlq.value(rec.indexOf("User_name")).toString();
        user.second = qsqlq.value(rec.indexOf("User_password")).toString();
        Users_list.push_back(user);
    }

    return Users_list;
}

int database_handler::get_user_id_by_name(QString username)
{
    // DML query execution
    QString qstr = "SELECT User_id FROM Users WHERE User_name = '%1'";
    qstr = qstr.arg(username);
    QSqlQuery qsqlq = SQL_query(qstr);
    qsqlq.next();
    int i = qsqlq.value(0).toInt();

    return i;
}

void database_handler::register_new_user(QString username, QString pass)
{
    QString qstr = "INSERT INTO Users VALUES (null, '%1', '%2')";
    qstr = qstr.arg(username).arg(pass);
    QSqlQuery qsqlq = SQL_query(qstr);
}

QList<QPair<QString, QString>> database_handler::get_dictionarylist_by_username(QString username)
{
    // DML query execution
    QString qstr = "SELECT User_dict_Name, User_dict_id FROM User_dictionaries WHERE User_id IN (SELECT User_id FROM Users WHERE User_name = '%1')";
    qstr = qstr.arg(username);
    QSqlQuery qsqlq = SQL_query(qstr);

    QSqlRecord rec = qsqlq.record();

    QList<QPair<QString, QString>> dictionary_by_user_list;
    QPair<QString, QString> user_dictionary;

    while (qsqlq.next())
    {
        user_dictionary.first = qsqlq.value(rec.indexOf("User_dict_Name")).toString();
        user_dictionary.second = qsqlq.value(rec.indexOf("User_dict_id")).toString();
        dictionary_by_user_list.push_back(user_dictionary);
    }

    return dictionary_by_user_list;
}

QList<QPair<QString, QString>> database_handler::get_dictionary_by_dict_id(int dict_id)
{
    // DML query execution
    QString qstr = "SELECT Word, Translation FROM Global_dictionary WHERE Gdict_word_id IN (SELECT Gdict_word_id FROM Translations WHERE User_dict_id = %1)";
    qstr = qstr.arg(dict_id);
    QSqlQuery qsqlq = SQL_query(qstr);

    QSqlRecord rec = qsqlq.record();

    QList<QPair<QString, QString>> dictionary;
    QPair<QString, QString> words;

    while (qsqlq.next())
    {
        words.first = qsqlq.value(rec.indexOf("Word")).toString();
        words.second = qsqlq.value(rec.indexOf("Translation")).toString();
        dictionary.push_back(words);
    }

    return dictionary;
}

void database_handler::add_new_user_dictionary(QString dict_name, int user_id)
{
    // check if that name exist and insertion query
    QString qstr1 = "SELECT EXISTS(SELECT * FROM User_dictionaries WHERE User_dict_name = '%1' LIMIT 1)";
    QString qstr2 = "INSERT INTO User_dictionaries VALUES (%2, null, '%1')";
    qstr1 = qstr1.arg(dict_name);
    qstr2 = qstr2.arg(dict_name).arg(user_id);
    QSqlQuery qsqlq1 = SQL_query(qstr1);
    // must position record to retrieve data
    qsqlq1.next();
    int i = qsqlq1.value(0).toInt();
    if (!i) QSqlQuery qsqlq2 = SQL_query(qstr2);
}

void database_handler::add_new_word_to_user_dict(QString word, QString translation, int dict_id)
{
    // check if that name exist and insertion query
    QString qstr1 = "INSERT INTO Global_dictionary VALUES (null, '%1', '%2')";
    qstr1 = qstr1.arg(word).arg(translation);
    QSqlQuery qsqlq1 = SQL_query(qstr1);
    // recieve id of added word and insert it and dict id to joint table
    QString qstr2 = "SELECT Gdict_word_id FROM Global_dictionary WHERE Word = '%1' AND Translation = '%2'";
    qstr2 = qstr2.arg(word).arg(translation);
    QSqlQuery qsqlq2 = SQL_query(qstr2);
    // must position record to retrieve data
    qsqlq2.next();
    int i = qsqlq2.value(0).toInt();
    QString qstr3 = "INSERT INTO Translations VALUES (%1, %2)";
    qstr3 = qstr3.arg(dict_id).arg(i);
    QSqlQuery qsqlq3 = SQL_query(qstr3);
}

void database_handler::delete_user_dictionary(int dict_id)
{
    QString qstr1 = "DELETE FROM User_dictionaries WHERE User_dict_id = %1";
    qstr1 = qstr1.arg(dict_id);
    QSqlQuery qsqlq1 = SQL_query(qstr1);

    QString qstr2 = "DELETE FROM WHERE User_dict_id = %1";
    qstr2 = qstr2.arg(dict_id);
    QSqlQuery qsqlq2 = SQL_query(qstr2);
}

void database_handler::delete_all_words_from_user_dict(int dict_id)
{
    QString qstr2 = "DELETE FROM Translations WHERE User_dict_id = %1";
    qstr2 = qstr2.arg(dict_id);
    QSqlQuery qsqlq2 = SQL_query(qstr2);
}

void database_handler::delete_word_from_user_dict(QString word, QString translation, int dict_id)
{
    // recieve id of deleting word and delete it and dict id from joint table
    QString qstr1 = "SELECT Gdict_word_id FROM Global_dictionary WHERE Word = '%1' AND Translation = '%2'";
    qstr1 = qstr1.arg(word).arg(translation);
    QSqlQuery qsqlq1 = SQL_query(qstr1);
    // must position record to retrieve data
    qsqlq1.next();
    int i = qsqlq1.value(0).toInt();

    QString qstr2 = "DELETE FROM Translations WHERE User_dict_id = %1 AND Gdict_word_id = %2 ";
    qstr2 = qstr2.arg(dict_id).arg(i);
    QSqlQuery qsqlq2 = SQL_query(qstr2);
}

void database_handler::export_to_csv(int dict_id, QString path)
{
    QString qstr = "SELECT Word, Translation FROM Global_dictionary WHERE Gdict_word_id IN (SELECT Gdict_word_id FROM Translations WHERE User_dict_id = %1)";
    qstr = qstr.arg(dict_id);
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(qstr);
    int rows = model->rowCount();
    int cols = model->columnCount();
    QString textData;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) {

                textData += model->data(model->index(i,j)).toString();
                textData += ", ";
        }
        textData += "\n";
    }

    QFile csvFile(path);
    if(csvFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

        QTextStream out(&csvFile);
        out << textData;

        csvFile.close();
    }

}
