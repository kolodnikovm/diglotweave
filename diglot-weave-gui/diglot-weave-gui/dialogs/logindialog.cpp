#include "logindialog.h"

LoginDialog::LoginDialog( QWidget * parent, UserAccount* user_account, database_handler* db_handler) : QDialog(parent) {
    ui.setupUi(this);

    this->user_account = user_account;
    this->db_handler = db_handler;

    connect(ui.loginLoginButton, SIGNAL (released()), this, SLOT (make_login()));
    connect(ui.regDialogButton, SIGNAL (released()), this, SLOT (show_register_dialog()));
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

    if(this->user_account->logged_in)
    {
        return utils::show_error("Вы уже авторизованы.");
    }
    else
    {
        QList<QPair<QString, QString>> users_list = this->db_handler->get_users_list();
        bool found = false;
        bool equal_pass = false;
        int account_id = -1;

        for(int i = 0, len = users_list.size(); i < len; ++i)
        {
            if(users_list[i].first == login_value)
            {
                found = true;

                if(users_list[i].second == hash_value)
                {
                    equal_pass = true;
                    account_id = this->db_handler->get_user_id_by_name(login_value);
                }
                break;
            }
        }

        if(found)
        {
            if(equal_pass)
            {
                UserAccount user_account;
                user_account.LogIn(account_id, login_value, hash_value);
                ((MainWindow*)(parent()))->userAccount = user_account;
            }
            else
                return utils::show_error("Вы ввели неверный логин или пароль.");
        }
        else
            return utils::show_error("Вы ввели неверный логин или пароль.");

        close();
    }
}

void LoginDialog::show_register_dialog()
{
    ((MainWindow*)parent())->show_register_dialog();
    close();
}
