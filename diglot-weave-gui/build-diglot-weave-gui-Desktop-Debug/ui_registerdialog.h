/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *regLoginLabel;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *regLoginEdit;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *regPasswordLabel;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *regPasswordEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *registerRegisterButton;
    QPushButton *registerCancelButton;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(396, 115);
        verticalLayout_2 = new QVBoxLayout(RegisterDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        regLoginLabel = new QLabel(RegisterDialog);
        regLoginLabel->setObjectName(QStringLiteral("regLoginLabel"));
        regLoginLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(regLoginLabel);


        horizontalLayout_10->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        regLoginEdit = new QLineEdit(RegisterDialog);
        regLoginEdit->setObjectName(QStringLiteral("regLoginEdit"));

        horizontalLayout_8->addWidget(regLoginEdit);


        horizontalLayout_10->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        regPasswordLabel = new QLabel(RegisterDialog);
        regPasswordLabel->setObjectName(QStringLiteral("regPasswordLabel"));
        regPasswordLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(regPasswordLabel);


        horizontalLayout_13->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        regPasswordEdit = new QLineEdit(RegisterDialog);
        regPasswordEdit->setObjectName(QStringLiteral("regPasswordEdit"));
        regPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_11->addWidget(regPasswordEdit);


        horizontalLayout_13->addLayout(horizontalLayout_11);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        registerRegisterButton = new QPushButton(RegisterDialog);
        registerRegisterButton->setObjectName(QStringLiteral("registerRegisterButton"));

        horizontalLayout->addWidget(registerRegisterButton);

        registerCancelButton = new QPushButton(RegisterDialog);
        registerCancelButton->setObjectName(QStringLiteral("registerCancelButton"));

        horizontalLayout->addWidget(registerCancelButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "\320\236\320\272\320\275\320\276 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270", Q_NULLPTR));
        regLoginLabel->setText(QApplication::translate("RegisterDialog", "\320\233\320\276\320\263\320\270\320\275:", Q_NULLPTR));
        regPasswordLabel->setText(QApplication::translate("RegisterDialog", "\320\237\320\260\321\200\320\276\320\273\321\214:", Q_NULLPTR));
        registerRegisterButton->setText(QApplication::translate("RegisterDialog", "Register", Q_NULLPTR));
        registerCancelButton->setText(QApplication::translate("RegisterDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
