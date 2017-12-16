#include <QMouseEvent>
#include <QString>
#include <QTextEdit>
#include "usertextedit.h"

UserTextEdit::UserTextEdit(QWidget *parent) : QTextEdit(parent) { }

void UserTextEdit::SetFormattedText(FormattedText *formattedText)
{
    this->formattedText = formattedText;
    this->setHtml(this->formattedText->GetFormattedText());
}

void UserTextEdit::mousePressEvent(QMouseEvent *mouseEvent)
{
    if (Qt::LeftButton == mouseEvent->button())
    {
        QTextCursor textCursor = cursorForPosition(mouseEvent->pos());
        textCursor.select(QTextCursor::WordUnderCursor);
        setTextCursor(textCursor);

        QString chosen_word = textCursor.selectedText();

        if(chosen_word.size() > 0)
        {
            this->formattedText->ReplaceWord(chosen_word);
            this->setHtml(this->formattedText->GetFormattedText());
        }
    }

    QTextEdit::mousePressEvent(mouseEvent);
}
