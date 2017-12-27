#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "ui_logindialog.h"

#include "useraccount.h"
#include "mainwindow.h"
#include "utils.h"
#include "database_handler.h"

class LoginDialog : public QDialog {
    Q_OBJECT

public:
    LoginDialog( QWidget * parent = 0, UserAccount* user_account = 0, database_handler* db_handler = 0);

public slots:
    void make_login();
    void show_register_dialog();

private:
    Ui::LoginDialog ui;
    UserAccount* user_account;
    database_handler* db_handler;
};

#endif // LOGINDIALOG_H
