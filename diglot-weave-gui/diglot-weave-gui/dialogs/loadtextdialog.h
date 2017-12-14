#ifndef LOADTEXTDIALOG_H
#define LOADTEXTDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QTextStream>

#include "ui_loadtextdialog.h"
#include "mainwindow.h"
#include "useraccount.h"
#include "utils.h"

class LoadTextDialog : public QDialog {
    Q_OBJECT

public:
    LoadTextDialog( QWidget * parent = 0, UserAccount* user_account = 0);

public slots:
    void load_text_by_file();
    void load_text();
    void close_text();

private:
    Ui::LoadTextDialog ui;
    UserAccount* user_account;
};

#endif // LOADTEXTDIALOG_H
