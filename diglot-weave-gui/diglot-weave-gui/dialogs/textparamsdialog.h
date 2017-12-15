#ifndef TEXTPARAMSDIALOG_H
#define TEXTPARAMSDIALOG_H

#include <QDialog>
#include "ui_textparamsdialog.h"
#include "mainwindow.h"
#include "useraccount.h"

class TextParamsDialog : public QDialog {
    Q_OBJECT

public:
    TextParamsDialog( QWidget * parent = 0, UserAccount* user_account = 0);

public slots:
    void change_params();

private:
    Ui::TextParamsDialog ui;
    UserAccount* user_account;
};

#endif // TEXTPARAMSDIALOG_H
