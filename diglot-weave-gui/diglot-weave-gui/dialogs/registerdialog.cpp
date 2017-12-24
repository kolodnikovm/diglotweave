#include "registerdialog.h"

RegisterDialog::RegisterDialog( QWidget * parent) : QDialog(parent) {
    ui.setupUi(this);

    connect(ui.registerRegisterButton, SIGNAL (released()), this, SLOT (make_register()));
    connect(ui.registerCancelButton, SIGNAL (released()), this, SLOT (close()));
}

void RegisterDialog::make_register()
{
    QString login_value = ui.regLoginEdit->text();
    QString password_value = ui.regPasswordEdit->text();

    if(!utils::is_input_valid(login_value))
        return utils::show_error("Был введен некорректный логин");

    if(!utils::is_input_valid(password_value))
        return utils::show_error("Был введен некорректный пароль.");

    QString hash_value = utils::generate_password_hash(password_value);
    UserAccount user_account(0, login_value, hash_value);

    ((MainWindow*)(parent()))->userAccount = user_account;
    ((MainWindow*)(parent()))->show_login_dialog();

    close();
}
