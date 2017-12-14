#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "ui_registerdialog.h"
#include "utils.h"
#include "mainwindow.h"
#include "useraccount.h"

class RegisterDialog : public QDialog {
    Q_OBJECT

public:
    RegisterDialog( QWidget * parent = 0);

public slots:
    void make_register();
    void cancel();

private:
    Ui::RegisterDialog ui;
};

#endif // REGISTERDIALOG_H
