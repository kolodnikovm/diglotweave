#include "formattedtext.h"

FormattedText::FormattedText()
{
    this->change_freq = 1.0;
}

void FormattedText::SetText(QString text)
{
    this->text_full = text;

    QStringList string_list = text.split(' ');
    this->word_list.clear();

    for(int i = 0, len = string_list.size(); i < len; ++i)
    {
        QString word_value = string_list[i];
        QString punct_begin, punct_end;
        int word_begin = 0, word_end = word_value.size() - 1;

        for(int i = 0, len = word_value.size(); i < len; ++i)
        {
            QChar c = word_value[i];

            if(c.isPunct())
            {
                word_begin = i + 1;
                punct_begin += c;
            }
            else
                break;
        }

        for(int i = word_value.size() - 1; i >= 0; --i)
        {
            QChar c = word_value[i];

            if(c.isPunct())
            {
                word_end = i - 1;
                punct_end += c;
            }
            else
                break;
        }

        QString word_wrapped = word_value.mid(word_begin, word_end - word_begin + 1);
        WordRecord word_record = WordRecord(word_wrapped);

        word_record.SetPunctMarks(punct_begin, punct_end);
        this->word_list.append(word_record);
    }

    FormatText();
}

void FormattedText::SetDict(UserDictionary* dict_init)
{
    this->dict_init = *dict_init;
    FormatText();
}

void FormattedText::SetChangeWordFrequency(double change_freq)
{
    this->change_freq = change_freq;
    FormatText();
}

void FormattedText::FormatText()
{
    utils::dict_save("vocab.csv", this->dict_init.GetWordPairs());
    utils::text_save("text.txt", this->text_full);
    utils::run_python("text.txt", "vocab.csv", "vocab_out.csv");
    this->dict_now = UserDictionary();
    this->dict_now.SetWordPairs(utils::dict_load("vocab_out.csv"));

    for(int i = 0, len = this->word_list.size(); i < len; ++i)
    {
        this->word_list[i].Reset();

        QString word_now = this->word_list[i].GetWord();
        bool highlighted = false;

        for(int j = 0, len = dict_now.size(); j < len; ++j)
        {
            QString word_init(dict_now[j].GetWord());
            QString word_translate(dict_now[j].GetTranslate());

            if(word_now == word_init)
            {
                if(utils::get_doubled_random() < this->change_freq)
                {
                    this->word_list[i].SetTranslate(word_translate);
                    highlighted = true;
                }

                break;
            }
        }

        if(highlighted)
            this->word_list[i].Highlight();
    }
}

QString FormattedText::GetFormattedText()
{
    QString formatted_text;
    QString highlighted_text;

    for(int i = 0, len = this->word_list.size(); i < len; ++i)
    {
        bool highlighted = this->word_list[i].IsHighlighted();
        QString tag_open, tag_close;

        if(highlighted)
        {
            tag_open = utils::highlight_open_tag;
            tag_close = utils::highlight_close_tag;
        }

        QString word = this->word_list[i].GetFullWord(tag_open, tag_close, false);
        QString translate = this->word_list[i].GetFullWord(tag_open, tag_close, true);

        if(this->word_list[i].HaveTranslate())
        {
            if(!this->word_list[i].IsTranslated())
                highlighted_text += translate;
            else
                highlighted_text += word;
        }
        else
            highlighted_text += word;
    }

    formatted_text += utils::text_open_tag;
    formatted_text += highlighted_text;
    formatted_text += utils::text_close_tag;

    return formatted_text;
}

void FormattedText::ReplaceWord(QString chosen_word)
{
    for(int i = 0, len = word_list.size(); i < len; ++i)
    {
        if(word_list[i].GetTranslate() == chosen_word && word_list[i].IsHighlighted())
        {
            if(!word_list[i].IsTranslated())
                word_list[i].Translate();
        }
    }
}
