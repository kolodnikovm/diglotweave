#include "textparamsdialog.h"

TextParamsDialog::TextParamsDialog( QWidget * parent, UserAccount* user_account) : QDialog(parent) {
    ui.setupUi(this);

    this->user_account = user_account;

    ui.dictComboBox->clear();
    for(int i = 0; i < this->user_account->GetDictionariesCount(); ++i)
        ui.dictComboBox->addItem(this->user_account->GetDictionary(i)->dict_name);

    connect(ui.saveParamsButton, SIGNAL (released()), this, SLOT (change_params()));
    connect(ui.cancelParamsButton, SIGNAL (released()), this, SLOT (close()));
}

void TextParamsDialog::change_params()
{
    int dict_id = ui.dictComboBox->currentIndex();
    this->user_account->SetDictionary(dict_id);

    UserDictionary* dict_now = this->user_account->GetDictionary();
    ((MainWindow*)(parent()))->formattedText->SetDict(dict_now);
    ((MainWindow*)(parent()))->userTextEdit->SetFormattedText(((MainWindow*)(parent()))->formattedText);

    close();
}
