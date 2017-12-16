#-------------------------------------------------
#
# Project created by QtCreator 2017-12-11T22:19:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = diglot-weave-gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dictrecord.cpp \
    formattedtext.cpp \
    dialogs/aboutdialog.cpp \
    dialogs/dictdialog.cpp \
    dialogs/logindialog.cpp \
    dialogs/registerdialog.cpp \
    utils.cpp \
    dialogs/loadtextdialog.cpp \
    usertextedit.cpp \
    userdictionary.cpp \
    useraccount.cpp \
    dialogs/textparamsdialog.cpp \
    wordrecord.cpp \
    globaldictionary.cpp

HEADERS += \
        mainwindow.h \
    dictrecord.h \
    formattedtext.h \
    dialogs/aboutdialog.h \
    dialogs/dictdialog.h \
    dialogs/logindialog.h \
    dialogs/registerdialog.h \
    utils.h \
    usertextedit.h \
    dialogs/loadtextdialog.h \
    userdictionary.h \
    useraccount.h \
    dialogs/textparamsdialog.h \
    wordrecord.h \
    globaldictionary.h

FORMS += \
        mainwindow.ui \
    dialogs/aboutdialog.ui \
    dialogs/dictdialog.ui \
    dialogs/logindialog.ui \
    dialogs/registerdialog.ui \
    dialogs/loadtextdialog.ui \
    dialogs/textparamsdialog.ui
