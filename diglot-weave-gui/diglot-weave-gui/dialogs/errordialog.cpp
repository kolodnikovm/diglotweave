#include "errordialog.h"

ErrorDialog::ErrorDialog( QWidget * parent) : QDialog(parent)
{
    ui.setupUi(this);
}

void ErrorDialog::show_msg(QString message)
{
    ui.labelError->setText(message);
    this->show();
}
