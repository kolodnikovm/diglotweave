#ifndef TEXTPARAMSDIALOG_H
#define TEXTPARAMSDIALOG_H

#include <QDialog>
#include "ui_textparamsdialog.h"
#include "useraccount.h"
#include "formattedtext.h"
#include "usertextedit.h"

class TextParamsDialog : public QDialog {
    Q_OBJECT

public:
    TextParamsDialog( QWidget * parent = 0, UserAccount* user_account = 0,
                      FormattedText* formatted_text = 0, UserTextEdit* usertextedit = 0);

public slots:
    void check_checkbox(bool checked);
    void change_params();

private:
    Ui::TextParamsDialog ui;
    UserAccount* user_account;
    FormattedText* formatted_text;
    UserTextEdit* usertextedit;
};

#endif // TEXTPARAMSDIALOG_H
