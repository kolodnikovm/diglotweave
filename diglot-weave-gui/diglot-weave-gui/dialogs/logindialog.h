#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "ui_logindialog.h"
#include "useraccount.h"
#include "utils.h"

class LoginDialog : public QDialog {
    Q_OBJECT

public:
    LoginDialog( QWidget * parent = 0, UserAccount* user_account = 0);

public slots:
    void make_login();

private:
    Ui::LoginDialog ui;
    UserAccount* user_account;
};

#endif // LOGINDIALOG_H
