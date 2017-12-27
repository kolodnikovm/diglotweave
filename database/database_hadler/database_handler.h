#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <QString>
#include <QtSql>
#include <QSqlQuery>
#include <QFile>

class database_handler
{
public:
    database_handler();

    // QT database driver
    QSqlDatabase sqliteDB;
    // connection to SQLite database, arguments: database name and QT database driver. Returns error or "success"
    QString connect_to_database(QString DB_name = "Database.db", QString QT_db_driver = "QSQLITE");
    // send SQL querry to database, arguments: DDL or DML query
    QSqlQuery SQL_query(QString query);

    // get users information (name and password). Each name is unique
    QList<QPair<QString, QString>> get_users_list();

    // get user id from his name (retrived from list)
    int get_user_id_by_name(QString);

    // insertion in Users table new user (if the names matches insertion failes)
    void register_new_user(QString, QString);

    // get list of pairs (name, id) of specific user's dictionaries
    QList<QPair<QString, int>> get_dictionarylist_by_username(QString);

    // get list of words and translations of specific dictionary
    QList<QPair<QString, QString>> get_dictionary_by_dict_id(int);

    // add new user dictionary, arguments: dictionary name, user_id
    void add_new_user_dictionary(QString, int);

    // add word and translation to user specific dictionary, arguments: word, translation, dictionary id. Each word in russian is unique
    void add_new_word_to_user_dict(QString, QString, int);

    // delete user dictionary, arguments: user_dictionary_id
    void delete_user_dictionary(int);

    // delete all words
    void delete_all_words_from_user_dict(int);

    // delete word and translation to user specific dictionary, arguments: word, translation, dictionary id
    void delete_word_from_user_dict(QString, QString, int);

    // export table of word of specific unit dictionary
    void export_to_csv(int, QString path = "dict.csv");

};

#endif // DATABASE_HANDLER_H
