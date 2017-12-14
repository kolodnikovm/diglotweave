/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

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

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *loginLoginLabel;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *loginLoginEdit;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *horizontalLayout_23;
    QLabel *loginPasswordLabel;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *loginPasswordEdit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *loginLoginButton;
    QPushButton *loginCancelButton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(400, 115);
        verticalLayout_2 = new QVBoxLayout(LoginDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loginLoginLabel = new QLabel(LoginDialog);
        loginLoginLabel->setObjectName(QStringLiteral("loginLoginLabel"));

        horizontalLayout->addWidget(loginLoginLabel);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        loginLoginEdit = new QLineEdit(LoginDialog);
        loginLoginEdit->setObjectName(QStringLiteral("loginLoginEdit"));

        horizontalLayout_2->addWidget(loginLoginEdit);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        loginPasswordLabel = new QLabel(LoginDialog);
        loginPasswordLabel->setObjectName(QStringLiteral("loginPasswordLabel"));

        horizontalLayout_23->addWidget(loginPasswordLabel);


        horizontalLayout_24->addLayout(horizontalLayout_23);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        loginPasswordEdit = new QLineEdit(LoginDialog);
        loginPasswordEdit->setObjectName(QStringLiteral("loginPasswordEdit"));
        loginPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(loginPasswordEdit);


        horizontalLayout_24->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_24);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        loginLoginButton = new QPushButton(LoginDialog);
        loginLoginButton->setObjectName(QStringLiteral("loginLoginButton"));

        horizontalLayout_5->addWidget(loginLoginButton);

        loginCancelButton = new QPushButton(LoginDialog);
        loginCancelButton->setObjectName(QStringLiteral("loginCancelButton"));

        horizontalLayout_5->addWidget(loginCancelButton);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\320\236\320\272\320\275\320\276 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270", Q_NULLPTR));
        loginLoginLabel->setText(QApplication::translate("LoginDialog", "\320\233\320\276\320\263\320\270\320\275", Q_NULLPTR));
        loginLoginEdit->setText(QString());
        loginPasswordLabel->setText(QApplication::translate("LoginDialog", "\320\237\320\260\321\200\320\276\320\273\321\214", Q_NULLPTR));
        loginLoginButton->setText(QApplication::translate("LoginDialog", "Login", Q_NULLPTR));
        loginCancelButton->setText(QApplication::translate("LoginDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
