#include "logindialog.h"

LoginDialog::LoginDialog( QWidget * parent, UserAccount* user_account) : QDialog(parent) {
    ui.setupUi(this);

    this->user_account = user_account;

    connect(ui.loginLoginButton, SIGNAL (released()), this, SLOT (make_login()));
    connect(ui.regDialogButton, SIGNAL (released()), this, SLOT (show_register_dialog()));
    connect(ui.restorePassButton, SIGNAL (released()), this, SLOT (show_restore_password_dialog()));
    connect(ui.loginCancelButton, SIGNAL (released()), this, SLOT (close()));
}

void LoginDialog::make_login()
{
    QString login_value = ui.loginLoginEdit->text();
    QString password_value = ui.loginPasswordEdit->text();

    if(!utils::is_input_valid(login_value))
        return utils::show_error("Был введен некорректный логин");

    if(!utils::is_input_valid(password_value))
        return utils::show_error("Был введен некорректный пароль.");

    QString hash_value = utils::generate_password_hash(password_value);
    bool logged_in = this->user_account->LogIn(login_value, hash_value);

    if(!logged_in)
        return utils::show_error("Был введён неверный логин и/или пароль.");
    else
        close();
}

void LoginDialog::show_register_dialog()
{
    ((MainWindow*)parent())->show_register_dialog();
    close();
}

void LoginDialog::show_restore_password_dialog()
{
    ((MainWindow*)parent())->show_restore_pass_dialog();
    close();
}
