#include "restorepassdialog.h"

RestorePassDialog::RestorePassDialog( QWidget * parent, UserAccount* user_account) : QDialog(parent) {
    ui.setupUi(this);

    this->user_account = user_account;
    connect(ui.sendNewPassButton, SIGNAL (released()), this, SLOT (restore_password()));
}

void RestorePassDialog::restore_password()
{
    QString email_value = ui.emailPassRestoreEdit->text();

    if(!utils::is_email_valid(email_value))
        return utils::show_error("Был введен некорректный e-mail.");

    close();
}
