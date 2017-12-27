#include "registerdialog.h"

RegisterDialog::RegisterDialog( QWidget * parent, database_handler* db_handler) : QDialog(parent) {
    ui.setupUi(this);

    this->db_handler = db_handler;

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

    QList<QPair<QString, QString>> users_list = this->db_handler->get_users_list();
    bool found = false;

    for(int i = 0, len = users_list.size(); i < len; ++i)
        if(users_list[i].first == login_value)
            found = true;

    if(!found)
    {
        this->db_handler->register_new_user(login_value, hash_value);
        ((MainWindow*)(parent()))->show_login_dialog();
    }
    else
        utils::show_error("В системе уже зарегистрирован пользователь с таким логином.");

    close();
}
