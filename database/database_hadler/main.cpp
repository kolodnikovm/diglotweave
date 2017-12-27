#include <QCoreApplication>
#include "database_handler.h"
#include "database_handler_tests.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    database_handler_tests::run_tests();
    return a.exec();
}
