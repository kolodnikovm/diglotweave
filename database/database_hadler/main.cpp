#include <QCoreApplication>
#include "database_handler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    database_handler db_hand;
    qDebug() << db_hand.connect_to_database() << endl;

    db_hand.register_new_user("testing2", "123545");
    QList<QPair<QString, QString>> db = db_hand.get_users_list();
    for (int j = 0; j < db.size(); ++j)
    {
        qDebug() << db[j].first << " | " << db[j].second << endl;
    }
    qDebug() << db_hand.get_user_id_by_name("testing2");
    return a.exec();
}
