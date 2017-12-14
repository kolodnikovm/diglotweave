/********************************************************************************
** Form generated from reading UI file 'dictdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTDIALOG_H
#define UI_DICTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DictDialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *dictNameEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addDictButton;
    QHBoxLayout *horizontalLayout;
    QListWidget *dictList;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *dictWordEdit;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *dictTranslateEdit;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *addWordButton;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *dictContentTable;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *saveDictButton;
    QPushButton *closeDictButton;

    void setupUi(QDialog *DictDialog)
    {
        if (DictDialog->objectName().isEmpty())
            DictDialog->setObjectName(QStringLiteral("DictDialog"));
        DictDialog->resize(420, 514);
        verticalLayout_6 = new QVBoxLayout(DictDialog);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        dictNameEdit = new QLineEdit(DictDialog);
        dictNameEdit->setObjectName(QStringLiteral("dictNameEdit"));

        horizontalLayout_4->addWidget(dictNameEdit);


        horizontalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        addDictButton = new QPushButton(DictDialog);
        addDictButton->setObjectName(QStringLiteral("addDictButton"));

        horizontalLayout_3->addWidget(addDictButton);


        horizontalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dictList = new QListWidget(DictDialog);
        dictList->setObjectName(QStringLiteral("dictList"));

        horizontalLayout->addWidget(dictList);


        verticalLayout_5->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        dictWordEdit = new QLineEdit(DictDialog);
        dictWordEdit->setObjectName(QStringLiteral("dictWordEdit"));

        horizontalLayout_7->addWidget(dictWordEdit);


        horizontalLayout_10->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        dictTranslateEdit = new QLineEdit(DictDialog);
        dictTranslateEdit->setObjectName(QStringLiteral("dictTranslateEdit"));

        horizontalLayout_8->addWidget(dictTranslateEdit);


        horizontalLayout_10->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        addWordButton = new QPushButton(DictDialog);
        addWordButton->setObjectName(QStringLiteral("addWordButton"));

        horizontalLayout_9->addWidget(addWordButton);


        horizontalLayout_10->addLayout(horizontalLayout_9);


        verticalLayout_6->addLayout(horizontalLayout_10);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        dictContentTable = new QTableWidget(DictDialog);
        if (dictContentTable->columnCount() < 2)
            dictContentTable->setColumnCount(2);
        dictContentTable->setObjectName(QStringLiteral("dictContentTable"));
        dictContentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        dictContentTable->setSelectionMode(QAbstractItemView::SingleSelection);
        dictContentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        dictContentTable->setColumnCount(2);

        verticalLayout_8->addWidget(dictContentTable);


        verticalLayout_6->addLayout(verticalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        saveDictButton = new QPushButton(DictDialog);
        saveDictButton->setObjectName(QStringLiteral("saveDictButton"));

        horizontalLayout_5->addWidget(saveDictButton);

        closeDictButton = new QPushButton(DictDialog);
        closeDictButton->setObjectName(QStringLiteral("closeDictButton"));

        horizontalLayout_5->addWidget(closeDictButton);


        verticalLayout_6->addLayout(horizontalLayout_5);


        retranslateUi(DictDialog);

        QMetaObject::connectSlotsByName(DictDialog);
    } // setupUi

    void retranslateUi(QDialog *DictDialog)
    {
        DictDialog->setWindowTitle(QApplication::translate("DictDialog", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\201\320\273\320\276\320\262\320\260\321\200\320\265\320\271", Q_NULLPTR));
        dictNameEdit->setPlaceholderText(QApplication::translate("DictDialog", "\320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\273\320\276\320\262\320\260\321\200\321\217", Q_NULLPTR));
        addDictButton->setText(QApplication::translate("DictDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\273\320\276\320\262\320\260\321\200\321\214", Q_NULLPTR));
        dictWordEdit->setPlaceholderText(QApplication::translate("DictDialog", "\321\201\320\273\320\276\320\262\320\276", Q_NULLPTR));
        dictTranslateEdit->setPlaceholderText(QApplication::translate("DictDialog", "\320\277\320\265\321\200\320\265\320\262\320\276\320\264", Q_NULLPTR));
        addWordButton->setText(QApplication::translate("DictDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\273\320\276\320\262\320\276", Q_NULLPTR));
        saveDictButton->setText(QApplication::translate("DictDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        closeDictButton->setText(QApplication::translate("DictDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\261\320\265\320\267 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DictDialog: public Ui_DictDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTDIALOG_H
