#include "logindialog.h"

LoginDialog::LoginDialog( QWidget * parent, UserAccount* user_account) : QDialog(parent) {
    ui.setupUi(this);

    this->user_account = user_account;

    connect(ui.loginLoginButton, SIGNAL (released()), this, SLOT (make_login()));
    connect(ui.loginCancelButton, SIGNAL (released()), this, SLOT (cancel()));
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
        this->close();
}

void LoginDialog::cancel()
{
    this->close();
}
