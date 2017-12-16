#include "formattedtext.h"

const QString FormattedText::textOpenTag = QString("<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">");
const QString FormattedText::textCloseTag = QString("</p>");

const QString FormattedText::highlightOpenTag = QString("<span style=\" font-weight:600; color:#ef2929;\">");
const QString FormattedText::highlightCloseTag = QString("</span>");

FormattedText::FormattedText() { }

void FormattedText::SetText(QString text)
{
    this->text = text;
}

void FormattedText::SetDict(UserDictionary* dict_now)
{
    this->dict_now = *dict_now;
}

QString FormattedText::GetFormattedText()
{
    QString formatted_text;
    QString pre_highlighted_text(this->text);

    for(int i = 0, len = dict_now.size(); i < len; ++i)
    {
        QString word_init(dict_now[i].GetWord());
        QString word_translate;

        word_translate += this->highlightOpenTag;

        if(!dict_now[i].IsTranslated())
            word_translate += dict_now[i].GetTranslate();
        else
            word_translate += word_init;

        word_translate += this->highlightCloseTag;

        word_init = " " + word_init + " ";
        word_translate = " " + word_translate + " ";

        pre_highlighted_text.replace(word_init, word_translate);
    }

    formatted_text += this->textOpenTag;
    formatted_text += pre_highlighted_text;
    formatted_text += this->textCloseTag;

    return formatted_text;
}

void FormattedText::ReplaceWord(QString chosen_word)
{
    for(int i = 0, len = dict_now.size(); i < len; ++i)
    {
        if(dict_now[i].GetTranslate() == chosen_word)
        {
            if(!dict_now[i].IsTranslated())
                dict_now[i].Translate();
        }
    }
}
