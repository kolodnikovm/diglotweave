#include "dictdialog.h"

DictDialog::DictDialog( QWidget * parent, UserAccount* user_account,
                        FormattedText* formatted_text, UserTextEdit* usertextedit) : QDialog(parent) {
    ui.setupUi(this);

    this->user_account = user_account;
    this->formatted_text = formatted_text;
    this->usertextedit = usertextedit;

    connect(ui.importDictButton, SIGNAL (released()), this, SLOT (import_dictionary()));
    connect(ui.addDictButton, SIGNAL (released()), this, SLOT (add_dictionary()));
    connect(ui.removeDictButton, SIGNAL(released()), this, SLOT (remove_dictionary()));
    connect(ui.addWordButton, SIGNAL (released()), this, SLOT (add_word()));
    connect(ui.removeWordButton, SIGNAL(released()), this, SLOT (remove_word()));
    connect(ui.closeDictButton, SIGNAL (released()), this, SLOT (close()));

    connect(ui.dictList, SIGNAL (itemSelectionChanged()), this, SLOT (rewrite_word_table()));
    connect(ui.dictContentTable, SIGNAL (itemSelectionChanged()), this, SLOT(choose_word()));

    this->rewrite_dict_list();
}

void DictDialog::import_dictionary()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Открыть словарь", "/home/", "CSV Files (*.csv);All Files (*)");
    QFile f(file_name);

    if(!f.open(QIODevice::ReadOnly)) {
        return utils::show_error("Произошла ошибка при попытке открытия файла.");
    }

    QFileInfo file_info(f.fileName());
    QString file_name_path(file_info.fileName());
    QStringList file_name_listed = file_name_path.split('.');
    QString file_name_only = file_name_listed[0];

    this->user_account->CreateDictionary(file_name_only);
    int dict_index = this->user_account->GetDictionariesCount() - 1;
    bool failed = false;

    QTextStream in(&f);

    while(!in.atEnd())
    {
        QString word_translate_line;
        in >> word_translate_line;
        QStringList word_translate = word_translate_line.split(',');

        if(word_translate.size() == 2)
        {
            QString word_value = word_translate[0];
            QString translate_value = word_translate[1];

            bool word_valid = utils::is_word_valid(word_value);

            if(!word_valid)
            {
                failed = true;
                break;
            }

            bool translate_valid = utils::is_translate_valid(translate_value);

            if(!translate_valid)
            {
                failed = true;
                break;
            }

            this->user_account->GetDictionary(dict_index)->add_word(word_value, translate_value);
        }
        else if(word_translate_line.size() != 0 && word_translate_line.indexOf(',') == -1)
        {
            utils::show_error("Некорректный формат записей в словаре.");
            failed = true;
            break;
        }
    }

    if(failed)
        this->user_account->DeleteDictionary(dict_index);
    else
        this->user_account->CheckDuplicates();

    f.close();
    this->rewrite_dict_list();
}

void DictDialog::add_dictionary()
{
    QString dict_value = ui.dictNameEdit->text();
    this->user_account->CreateDictionary(dict_value);
    this->rewrite_dict_list();
}

void DictDialog::remove_dictionary()
{
    int dict_index = ui.dictList->currentRow();

    if(dict_index >= 0 && dict_index < this->user_account->GetDictionariesCount())
    {
        this->user_account->DeleteDictionary(dict_index);
        this->rewrite_dict_list();
        this->rewrite_word_table();
    }
}

void DictDialog::add_word()
{
    QString word_value = ui.dictWordEdit->text();
    QString translate_value = ui.dictTranslateEdit->text();
    int dict_index = ui.dictList->currentRow();

    if(dict_index >= 0 && dict_index < this->user_account->GetDictionariesCount())
    {
        bool word_valid = utils::is_word_valid(word_value);

        if(!word_valid)
            return;

        bool translate_valid = utils::is_translate_valid(translate_value);

        if(!translate_valid)
            return;

        UserDictionary* dict_now = this->user_account->GetDictionary(dict_index);
        bool modified = false;

        for(int i = 0, word_count = dict_now->size(); i < word_count; ++i)
        {
            if(word_value == dict_now->GetRecord(i).GetWord())
            {
                dict_now->GetRecord(i).ModifyTranslate(translate_value);
                modified = true;
                break;
            }
        }

        if(!modified)
        {
            dict_now->add_word(word_value, translate_value);
            this->user_account->CheckDuplicates(true);
        }

        this->rewrite_word_table();
    }
}

void DictDialog::choose_word()
{
    int current_row = ui.dictContentTable->currentRow();

    QString word = ui.dictContentTable->item(current_row, 0)->text();
    QString translate = ui.dictContentTable->item(current_row, 1)->text();

    ui.dictWordEdit->setText(word);
    ui.dictTranslateEdit->setText(translate);
}

void DictDialog::remove_word()
{
    int dict_index = ui.dictList->currentRow();
    int current_row = ui.dictContentTable->currentRow();

    QString word = ui.dictContentTable->item(current_row, 0)->text();
    QString translate = ui.dictContentTable->item(current_row, 1)->text();

    this->user_account->GetDictionary(dict_index)->remove_word(word, translate);
    this->rewrite_word_table();
}

void DictDialog::rewrite_dict_list()
{
    ui.dictList->clear();

    foreach (UserDictionary dict, *(this->user_account->getDictList()))
    {
        ui.dictList->addItem(dict.dict_name);
    }
}

void DictDialog::rewrite_word_table()
{
    int dict_index = ui.dictList->currentRow();

    ui.dictContentTable->clear();
    ui.dictContentTable->setRowCount(0);
    ui.dictContentTable->setColumnCount(2);

    if(dict_index >= 0 && dict_index < this->user_account->GetDictionariesCount())
    {
        const UserDictionary &selDict = user_account->getDictList()->at(dict_index);
        int word_count = selDict.size();
        ui.dictContentTable->setRowCount(word_count);

        const QList<DictRecord> wordList = selDict.GetListWords();

        for(int i = 0; i < wordList.size(); ++i)
        {
            QString word_value = wordList.at(i).GetWord();
            QTableWidgetItem *word_item = new QTableWidgetItem(word_value);
            ui.dictContentTable->setItem(i, 0, word_item);

            QString translate_value = wordList.at(i).GetTranslate();
            QTableWidgetItem *translate_item = new QTableWidgetItem(translate_value);
            ui.dictContentTable->setItem(i, 1, translate_item);
        }

        if(this->user_account->GetCurDictionary() == this->user_account->GetDictionary(dict_index))
        {
            this->formatted_text->SetDict(this->user_account->GetCurDictionary());
            this->usertextedit->SetFormattedText(this->formatted_text);
        }
    }
}
