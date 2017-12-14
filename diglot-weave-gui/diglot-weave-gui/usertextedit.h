#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>
#include <QMouseEvent>

#include <formattedtext.h>

class UserTextEdit : public QTextEdit {
private:
    FormattedText* formattedText;
public:
    UserTextEdit(QWidget* parent);
    void SetFormattedText(FormattedText* formattedText);
protected:
    void mousePressEvent(QMouseEvent *mouseEvent);
};

#endif // MYTEXTEDIT_H
