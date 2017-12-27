/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <usertextedit.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_about;
    QAction *action_2;
    QAction *action_3;
    QAction *action_exit;
    QAction *action_reg;
    QAction *action_8;
    QAction *action_9;
    QAction *action_freq_change;
    QAction *action_dict_load;
    QAction *action_dict;
    QAction *action_login;
    QAction *action_load_text_by_buffer;
    QAction *action_load_text_by_file;
    QAction *action_load_text;
    QAction *action_change_params;
    QAction *action;
    QAction *action_restore_pass;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    UserTextEdit *mainTextEdit;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_about;
    QMenu *menu_text;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(855, 708);
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_reg = new QAction(MainWindow);
        action_reg->setObjectName(QStringLiteral("action_reg"));
        action_8 = new QAction(MainWindow);
        action_8->setObjectName(QStringLiteral("action_8"));
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_freq_change = new QAction(MainWindow);
        action_freq_change->setObjectName(QStringLiteral("action_freq_change"));
        action_dict_load = new QAction(MainWindow);
        action_dict_load->setObjectName(QStringLiteral("action_dict_load"));
        action_dict = new QAction(MainWindow);
        action_dict->setObjectName(QStringLiteral("action_dict"));
        action_login = new QAction(MainWindow);
        action_login->setObjectName(QStringLiteral("action_login"));
        action_load_text_by_buffer = new QAction(MainWindow);
        action_load_text_by_buffer->setObjectName(QStringLiteral("action_load_text_by_buffer"));
        action_load_text_by_file = new QAction(MainWindow);
        action_load_text_by_file->setObjectName(QStringLiteral("action_load_text_by_file"));
        action_load_text = new QAction(MainWindow);
        action_load_text->setObjectName(QStringLiteral("action_load_text"));
        action_change_params = new QAction(MainWindow);
        action_change_params->setObjectName(QStringLiteral("action_change_params"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_restore_pass = new QAction(MainWindow);
        action_restore_pass->setObjectName(QStringLiteral("action_restore_pass"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setEnabled(true);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mainTextEdit = new UserTextEdit(centralwidget);
        mainTextEdit->setObjectName(QStringLiteral("mainTextEdit"));
        mainTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(mainTextEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 855, 22));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        menu_about = new QMenu(menubar);
        menu_about->setObjectName(QStringLiteral("menu_about"));
        menu_text = new QMenu(menubar);
        menu_text->setObjectName(QStringLiteral("menu_text"));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_text->menuAction());
        menubar->addAction(menu_about->menuAction());
        menu_file->addAction(action_exit);
        menu_about->addAction(action_about);
        menu_text->addAction(action_dict);
        menu_text->addAction(action_load_text);
        menu_text->addAction(action_change_params);
        menu->addAction(action_login);
        menu->addAction(action_reg);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Diglot Weave Dictonary Helper", Q_NULLPTR));
        action_about->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\265\320\272\321\201\321\202", Q_NULLPTR));
        action_3->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\201\320\273\320\276\320\262\320\260\321\200\321\214", Q_NULLPTR));
        action_exit->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270 \320\262\321\213\320\271\321\202\320\270", Q_NULLPTR));
        action_reg->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", Q_NULLPTR));
        action_8->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\320\273\320\276\320\262\320\260\321\200\321\214", Q_NULLPTR));
        action_9->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\320\273\320\276\320\262\320\260\321\200\321\214", Q_NULLPTR));
        action_freq_change->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\207\320\260\321\201\321\202\320\276\321\202\321\203 \320\267\320\260\320\274\320\265\320\275\321\213 \321\202\320\265\320\272\321\201\321\202\320\260", Q_NULLPTR));
        action_dict_load->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\201\320\273\320\276\320\262\320\260\321\200\321\214", Q_NULLPTR));
        action_dict->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\320\273\320\276\320\262\320\260\321\200\320\270", Q_NULLPTR));
        action_login->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", Q_NULLPTR));
        action_load_text_by_buffer->setText(QApplication::translate("MainWindow", "\320\230\320\267 \320\261\321\203\321\204\320\265\321\200\320\260 \320\276\320\261\320\274\320\265\320\275\320\260", Q_NULLPTR));
        action_load_text_by_file->setText(QApplication::translate("MainWindow", "\320\230\320\267 \321\202\320\265\320\272\321\201\321\202\320\276\320\262\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260", Q_NULLPTR));
        action_load_text->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\265\320\272\321\201\321\202", Q_NULLPTR));
        action_change_params->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\202\320\265\320\272\321\201\321\202\320\260", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\320\273\320\276\320\262\320\260\321\200\320\270", Q_NULLPTR));
        action_restore_pass->setText(QApplication::translate("MainWindow", "\320\222\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", Q_NULLPTR));
        mainTextEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        menu_file->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
        menu_about->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", Q_NULLPTR));
        menu_text->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\220\320\272\320\272\320\260\321\203\320\275\321\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
