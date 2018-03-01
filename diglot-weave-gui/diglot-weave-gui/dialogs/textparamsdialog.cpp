#include "textparamsdialog.h"

TextParamsDialog::TextParamsDialog( QWidget * parent, UserAccount* user_account,
                                    FormattedText* formatted_text, UserTextEdit* usertextedit) : QDialog(parent) {
    ui.setupUi(this);

    this->user_account = user_account;
    this->formatted_text = formatted_text;
    this->usertextedit = usertextedit;

    ui.dictComboBox->clear();

    connect(ui.globalDictCheckBox, SIGNAL(clicked(bool)), this, SLOT(check_checkbox(bool)));
    connect(ui.saveParamsButton, SIGNAL (released()), this, SLOT (change_params()));
    connect(ui.cancelParamsButton, SIGNAL (released()), this, SLOT (close()));

    foreach (UserDictionary dict, *(this->user_account->getDictList()))
    {
        ui.dictComboBox->addItem(dict.dict_name);
    }

    if(this->user_account->GetCurDictId() == -1)
    {
        ui.dictComboBox->setEnabled(false);
        ui.globalDictCheckBox->setChecked(true);
    }
    else
    {
        ui.dictComboBox->setEnabled(true);
        ui.globalDictCheckBox->setChecked(false);
    }
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
    }
    else
    {
        this->user_account->SetDictionary(-1);
        this->user_account->MakeGlobalDictionary();
    }
    dict_now = this->user_account->GetCurDictionary();
    this->formatted_text->SetDict(dict_now);
    this->usertextedit->SetFormattedText(this->formatted_text);

    close();
}
