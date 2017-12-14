#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <QDialog>
#include <QString>
#include "ui_errordialog.h"

class ErrorDialog : public QDialog {
    Q_OBJECT

public:
    ErrorDialog( QWidget * parent = 0);
    void show_msg(QString message);

private:
    Ui::ErrorDialog ui;
};

#endif // ERRORDIALOG_H
