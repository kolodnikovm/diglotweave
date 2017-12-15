#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialogs/dictdialog.h"
#include "dialogs/logindialog.h"
#include "dialogs/registerdialog.h"
#include "dialogs/loadtextdialog.h"
#include "dialogs/aboutdialog.h"
#include "dialogs/textparamsdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->userTextEdit = this->findChild<UserTextEdit*>("mainTextEdit");
    this->mainText = QString();
    this->userAccount = UserAccount();

    connect(ui->action_login, SIGNAL(triggered()), this, SLOT(show_login_dialog()));
    connect(ui->action_reg, SIGNAL(triggered()), this, SLOT(show_register_dialog()));
    connect(ui->action_dict, SIGNAL(triggered()), this, SLOT(show_dict_dialog()));
    connect(ui->action_load_text, SIGNAL(triggered()), this, SLOT(show_load_text_dialog()));
    connect(ui->action_change_params, SIGNAL(triggered()), this, SLOT(show_params_dialog()));
    connect(ui->action_about, SIGNAL(triggered()), this, SLOT(show_about_dialog()));

    connect(ui->action_exit, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::show_login_dialog()
{
    if(!this->userAccount.logged_in)
    {
        LoginDialog* loginDialog = new LoginDialog(this, &(this->userAccount));
        loginDialog->show();
    }
}

void MainWindow::show_register_dialog()
{
    if(!this->userAccount.registered)
    {
        RegisterDialog* registerDialog = new RegisterDialog(this);
        registerDialog->show();
    }
}

void MainWindow::show_dict_dialog()
{
    if(this->userAccount.logged_in)
    {
        DictDialog* dictDialog = new DictDialog(this, &(this->userAccount));
        dictDialog->show();
    }
}

void MainWindow::show_load_text_dialog()
{
    if(this->userAccount.logged_in)
    {
        LoadTextDialog* loadTextDialog = new LoadTextDialog(this, &(this->userAccount));
        loadTextDialog->show();
    }
}

void MainWindow::show_params_dialog()
{
    if(this->userAccount.logged_in)
    {
        TextParamsDialog* textParamsDialog = new TextParamsDialog(this, &(this->userAccount));
        textParamsDialog->show();
    }
}

void MainWindow::show_about_dialog()
{
    AboutDialog* aboutDialog = new AboutDialog(this);
    aboutDialog->show();
}

void MainWindow::set_text(QString loaded_text)
{
    this->mainText = loaded_text;
    this->formattedText = new FormattedText(this->mainText);

    UserDictionary* dict_now = this->userAccount.GetDictionary();
    if(dict_now != 0)
        set_dict(dict_now);
}

void MainWindow::set_dict(UserDictionary* user_dict)
{
    this->formattedText->SetDict(user_dict);
    this->userTextEdit->SetFormattedText(this->formattedText);
}

void MainWindow::close()
{
    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
