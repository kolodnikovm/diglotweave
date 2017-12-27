#include "database_handler_tests.h"
#include "database_handler.h"

database_handler_tests::database_handler_tests(){}
void database_handler_tests::run_tests()
{
    database_handler db_hand;
        qDebug() << db_hand.connect_to_database() << endl;

        db_hand.register_new_user("login", "password");
        db_hand.register_new_user("login2", "password2");
        QList<QPair<QString, QString>> db = db_hand.get_users_list();

        qDebug() << "Users:";
        for (int j = 0; j < db.size(); ++j)
            qDebug() << "User Record: " << db[j].first << " | " << db[j].second << endl;

        int user_id = db_hand.get_user_id_by_name("login");
        qDebug() << "UserID: " << user_id;

        qDebug() << "Added user_dict_one and user_dict_two.";
        db_hand.add_new_user_dictionary("user_dict_one", user_id);
        db_hand.add_new_user_dictionary("user_dict_two", user_id);

        QList<QPair<QString, int>> dictionary_list = db_hand.get_dictionarylist_by_username("login");
        QMap<QString, int> dicts;

        qDebug() << "Dictionaries:";
        for(int i = 0, len = dictionary_list.size(); i < len; ++i)
        {
            QString dict_name = dictionary_list[i].first;
            int dict_id = dictionary_list[i].second;

            dicts[dict_name] = dict_id;
            qDebug() << "User Dictionary: " << dict_name << " " << dict_id;
        }

        qDebug() << "Added word_one, word_two to user_dict_one";
        db_hand.add_new_word_to_user_dict("word_one", "translate_one", dicts["user_dict_one"]);
        db_hand.add_new_word_to_user_dict("word_two", "translate_two", dicts["user_dict_one"]);

        qDebug() << "Added word_three to user_dict_two";
        db_hand.add_new_word_to_user_dict("word_three", "translate_three", dicts["user_dict_two"]);

        QList<QPair<QString, QString>> dictionary_one = db_hand.get_dictionary_by_dict_id(dicts["user_dict_one"]);
        QList<QPair<QString, QString>> dictionary_two = db_hand.get_dictionary_by_dict_id(dicts["user_dict_two"]);

        qDebug() << "Dictionary: user_dict_one";
        for(int i = 0, len = dictionary_one.size(); i < len; ++i)
            qDebug() << "Dictionary Word: " << dictionary_one[i].first << " " << dictionary_one[i].second;

        qDebug() << "Dictionary: user_dict_two";
        for(int i = 0, len = dictionary_two.size(); i < len; ++i)
            qDebug() << "Dictionary Word: " << dictionary_two[i].first << " " << dictionary_two[i].second;

        qDebug() << "Delete word_one from user_dict_one.";
        db_hand.delete_word_from_user_dict("word_one", "translate_one", dicts["user_dict_one"]);

        qDebug() << "Delete word_three from user_dict_two.";
        db_hand.delete_word_from_user_dict("word_three", "translate_three", dicts["user_dict_two"]);

        dictionary_one = db_hand.get_dictionary_by_dict_id(dicts["user_dict_one"]);
        dictionary_two = db_hand.get_dictionary_by_dict_id(dicts["user_dict_two"]);

        qDebug() << "Dictionary: user_dict_one";
        for(int i = 0, len = dictionary_one.size(); i < len; ++i)
            qDebug() << "Dictionary Word: " << dictionary_one[i].first << " " << dictionary_one[i].second;

        qDebug() << "Dictionary: user_dict_two";
        for(int i = 0, len = dictionary_two.size(); i < len; ++i)
            qDebug() << "Dictionary Word: " << dictionary_two[i].first << " " << dictionary_two[i].second;

        qDebug() << "Delete user dictionary user_dict_two.";
        db_hand.delete_user_dictionary(dicts["user_dict_two"]);

        dictionary_list = db_hand.get_dictionarylist_by_username("login");

        qDebug() << "Dictionaries";
        for(int i = 0, len = dictionary_list.size(); i < len; ++i)
        {
            QString dict_name = dictionary_list[i].first;
            int dict_id = dictionary_list[i].second;
            qDebug() << "User Dictionary: " << dict_name << " " << dict_id;
        }
}
