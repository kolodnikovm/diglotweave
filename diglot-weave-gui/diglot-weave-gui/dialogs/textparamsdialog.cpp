#include "textparamsdialog.h"

TextParamsDialog::TextParamsDialog( QWidget * parent, UserAccount* user_account,
                                    FormattedText* formatted_text, UserTextEdit* usertextedit) : QDialog(parent) {
    ui.setupUi(this);

    this->user_account = user_account;
    this->formatted_text = formatted_text;
    this->usertextedit = usertextedit;

    ui.dictComboBox->clear();
    for(int i = 0; i < this->user_account->GetDictionariesCount(); ++i)
        ui.dictComboBox->addItem(this->user_account->GetDictionary(i)->dict_name);

    connect(ui.globalDictCheckBox, SIGNAL(clicked(bool)), this, SLOT(check_checkbox(bool)));
    connect(ui.saveParamsButton, SIGNAL (released()), this, SLOT (change_params()));
    connect(ui.cancelParamsButton, SIGNAL (released()), this, SLOT (close()));
}

void TextParamsDialog::check_checkbox(bool checked)
{
    ui.dictComboBox->setEnabled(checked);
}

void TextParamsDialog::change_params()
{
    double change_freq = ui.freqDoubleSpinBox->value();
    this->formatted_text->SetChangeWordFrequency(change_freq);

    UserDictionary* dict_now;

    if(!ui.globalDictCheckBox->isChecked())
    {
        int dict_id = ui.dictComboBox->currentIndex();
        this->user_account->SetDictionary(dict_id);
        dict_now = this->user_account->GetDictionary();
    }
    else
    {
        this->user_account->SetDictionary(-1);
        this->user_account->MakeGlobalDictionary();
        dict_now = this->user_account->GetDictionary();
    }

    this->formatted_text->SetDict(dict_now);
    this->usertextedit->SetFormattedText(this->formatted_text);

    close();
}
