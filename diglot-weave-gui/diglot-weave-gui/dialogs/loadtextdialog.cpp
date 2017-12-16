#include "loadtextdialog.h"

LoadTextDialog::LoadTextDialog( QWidget * parent, UserAccount* user_account,
                                FormattedText* formatted_text, UserTextEdit* usertextedit) : QDialog(parent) {
    ui.setupUi(this);

    this->user_account = user_account;
    this->formatted_text = formatted_text;
    this->usertextedit = usertextedit;

    connect(ui.loadTextByFileButton, SIGNAL (released()), this, SLOT (load_text_by_file()));
    connect(ui.loadTextButton, SIGNAL (released()), this, SLOT (load_text()));
    connect(ui.closeTextButton, SIGNAL (released()), this, SLOT (close()));
}

void LoadTextDialog::load_text_by_file()
{
    QString text_loaded;

    QString fileName = QFileDialog::getOpenFileName(this, "Открыть текстовый файл", "/home/", "Text Files (*.txt)");
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
        return utils::show_error("Произошла ошибка при попытке открытия файла.");
    }

    QTextStream in(&file);
    while(!in.atEnd())
        text_loaded += in.readLine();
    file.close();

    ui.loadTextEdit->setText(text_loaded);
}

void LoadTextDialog::load_text()
{
    QString text_contents = ui.loadTextEdit->toPlainText();

    UserDictionary* dict_now = this->user_account->GetDictionary();
    if(dict_now != 0)
        this->formatted_text->SetDict(dict_now);

    this->formatted_text->SetText(text_contents);
    this->usertextedit->SetFormattedText(this->formatted_text);

    close();
}
