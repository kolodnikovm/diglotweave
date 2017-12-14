/********************************************************************************
** Form generated from reading UI file 'loadtextdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADTEXTDIALOG_H
#define UI_LOADTEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoadTextDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *loadTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *loadTextByFileButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadTextButton;
    QPushButton *closeTextButton;

    void setupUi(QDialog *LoadTextDialog)
    {
        if (LoadTextDialog->objectName().isEmpty())
            LoadTextDialog->setObjectName(QStringLiteral("LoadTextDialog"));
        LoadTextDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(LoadTextDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        loadTextEdit = new QTextEdit(LoadTextDialog);
        loadTextEdit->setObjectName(QStringLiteral("loadTextEdit"));

        verticalLayout->addWidget(loadTextEdit);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        loadTextByFileButton = new QPushButton(LoadTextDialog);
        loadTextByFileButton->setObjectName(QStringLiteral("loadTextByFileButton"));

        horizontalLayout_2->addWidget(loadTextByFileButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loadTextButton = new QPushButton(LoadTextDialog);
        loadTextButton->setObjectName(QStringLiteral("loadTextButton"));

        horizontalLayout->addWidget(loadTextButton);

        closeTextButton = new QPushButton(LoadTextDialog);
        closeTextButton->setObjectName(QStringLiteral("closeTextButton"));

        horizontalLayout->addWidget(closeTextButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(LoadTextDialog);

        QMetaObject::connectSlotsByName(LoadTextDialog);
    } // setupUi

    void retranslateUi(QDialog *LoadTextDialog)
    {
        LoadTextDialog->setWindowTitle(QApplication::translate("LoadTextDialog", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \321\202\320\265\320\272\321\201\321\202\320\260", Q_NULLPTR));
        loadTextByFileButton->setText(QApplication::translate("LoadTextDialog", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\265\320\272\321\201\321\202 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", Q_NULLPTR));
        loadTextButton->setText(QApplication::translate("LoadTextDialog", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\265\320\272\321\201\321\202", Q_NULLPTR));
        closeTextButton->setText(QApplication::translate("LoadTextDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadTextDialog: public Ui_LoadTextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADTEXTDIALOG_H
