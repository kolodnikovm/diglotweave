#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QString>

#include "formattedtext.h"
#include "usertextedit.h"
#include "userdictionary.h"
#include "useraccount.h"
#include "database_handler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    UserAccount userAccount;
    FormattedText* formattedText;
    UserTextEdit* userTextEdit;
    database_handler* dbHandler;

public slots:
    void show_login_dialog();
    void show_register_dialog();
    void show_dict_dialog();
    void show_load_text_dialog();
    void show_params_dialog();
    void show_about_dialog();

    void close();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
