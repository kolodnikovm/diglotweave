#include <QCoreApplication>
#include "database_handler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    database_handler db_hand;
    qDebug() << db_hand.connect_to_database() << endl;

    db_hand.export_to_csv(1);
    return a.exec();
}
