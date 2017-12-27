#include <QCoreApplication>
#include "database_handler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    database_handler db_hand;
    qDebug() << db_hand.connect_to_database() << endl;
    return a.exec();
}
