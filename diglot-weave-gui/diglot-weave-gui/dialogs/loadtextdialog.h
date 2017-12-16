#ifndef LOADTEXTDIALOG_H
#define LOADTEXTDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QTextStream>

#include "ui_loadtextdialog.h"
#include "useraccount.h"
#include "utils.h"
#include "formattedtext.h"
#include "usertextedit.h"

class LoadTextDialog : public QDialog {
    Q_OBJECT

public:
    LoadTextDialog( QWidget * parent = 0, UserAccount* user_account = 0,
                    FormattedText* formatted_text = 0, UserTextEdit* usertextedit = 0);

public slots:
    void load_text_by_file();
    void load_text();

private:
    Ui::LoadTextDialog ui;
    UserAccount* user_account;
    FormattedText* formatted_text;
    UserTextEdit* usertextedit;
};

#endif // LOADTEXTDIALOG_H
