#ifndef DICTDIALOG_H
#define DICTDIALOG_H

#include <QDialog>
#include <QList>
#include "ui_dictdialog.h"
#include "userdictionary.h"
#include "useraccount.h"
#include "formattedtext.h"
#include "usertextedit.h"

class DictDialog : public QDialog {
    Q_OBJECT

public:
    DictDialog( QWidget * parent = 0, UserAccount* user_account = 0,
                FormattedText* formatted_text = 0, UserTextEdit* usertextedit = 0);

public slots:
    void add_dictionary();
    void add_word();
    void remove_word();

private slots:
    void rewrite_list();
    void rewrite_table();

private:
    Ui::DictDialog ui;
    UserAccount* user_account;
    FormattedText* formatted_text;
    UserTextEdit* usertextedit;
};

#endif // DICTDIALOG_H
