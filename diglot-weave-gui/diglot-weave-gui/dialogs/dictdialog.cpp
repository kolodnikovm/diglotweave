#include "dictdialog.h"

DictDialog::DictDialog( QWidget * parent, UserAccount* user_account) : QDialog(parent) {
    ui.setupUi(this);

    this->user_account = user_account;

    connect(ui.addDictButton, SIGNAL (released()), this, SLOT (add_dictionary()));
    connect(ui.addWordButton, SIGNAL (released()), this, SLOT (add_word()));
    connect(ui.closeDictButton, SIGNAL (released()), this, SLOT (close()));

    connect(ui.dictList, SIGNAL (itemSelectionChanged()), this, SLOT (rewrite_table()));

    this->rewrite_list();
}

void DictDialog::add_dictionary()
{
    QString dict_value = ui.dictNameEdit->text();
    this->user_account->CreateDictionary(dict_value);
    this->rewrite_list();
}

void DictDialog::add_word()
{
    QString word_value = ui.dictWordEdit->text();
    QString translate_value = ui.dictTranslateEdit->text();
    int dict_index = ui.dictList->currentRow();

    if(dict_index >= 0 && dict_index < this->user_account->GetDictionariesCount())
    {
        this->user_account->GetDictionary(dict_index)->add_word(word_value, translate_value);
        this->rewrite_table();
    }
}

void DictDialog::rewrite_list()
{
    ui.dictList->clear();
    for(int i = 0; i < this->user_account->GetDictionariesCount(); ++i)
        ui.dictList->addItem(this->user_account->GetDictionary(i)->dict_name);
}

void DictDialog::rewrite_table()
{
    int dict_index = ui.dictList->currentRow();
    int word_count = this->user_account->GetDictionary(dict_index)->size();

    ui.dictContentTable->clear();
    ui.dictContentTable->setRowCount(word_count);
    ui.dictContentTable->setColumnCount(2);

    for(int word_index = 0; word_index < word_count; ++word_index)
    {
        UserDictionary user_dictionary = *(this->user_account->GetDictionary(dict_index));

        QString word_value = user_dictionary[word_index].GetWord();
        QTableWidgetItem *word_item = new QTableWidgetItem(word_value);
        ui.dictContentTable->setItem(word_index, 0, word_item);

        QString translate_value = user_dictionary[word_index].GetTranslate();
        QTableWidgetItem *translate_item = new QTableWidgetItem(translate_value);
        ui.dictContentTable->setItem(word_index, 1, translate_item);
    }
}
