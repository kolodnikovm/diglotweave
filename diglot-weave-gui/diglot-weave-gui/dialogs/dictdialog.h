#ifndef DICTDIALOG_H
#define DICTDIALOG_H

#include <QDialog>
#include <QList>
#include "ui_dictdialog.h"
#include "userdictionary.h"
#include "useraccount.h"

class DictDialog : public QDialog {
    Q_OBJECT

public:
    DictDialog( QWidget * parent = 0, UserAccount* user_account = 0);

public slots:
    void add_dictionary();
    void add_word();

private slots:
    void rewrite_list();
    void rewrite_table();

private:
    Ui::DictDialog ui;
    UserAccount* user_account;
};

#endif // DICTDIALOG_H
