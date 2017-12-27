#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "ui_registerdialog.h"

#include "utils.h"
#include "mainwindow.h"
#include "useraccount.h"
#include "database_handler.h"

class RegisterDialog : public QDialog {
    Q_OBJECT

public:
    RegisterDialog( QWidget * parent = 0, database_handler* db_handler = 0);

public slots:
    void make_register();

private:
    Ui::RegisterDialog ui;
    database_handler* db_handler;
};

#endif // REGISTERDIALOG_H
