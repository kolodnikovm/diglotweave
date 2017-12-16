#ifndef RESTOREPASSDIALOG_H
#define RESTOREPASSDIALOG_H

#include <QDialog>

#include "useraccount.h"
#include "utils.h"
#include "ui_restorepassdialog.h"

class RestorePassDialog : public QDialog {
    Q_OBJECT

public:
    RestorePassDialog( QWidget * parent = 0, UserAccount* user_account = 0);

public slots:
    void restore_password();

private:
    Ui::RestorePassDialog ui;
    UserAccount* user_account;
};

#endif // RESTOREPASSDIALOG_H
