#-------------------------------------------------
#
# Project created by QtCreator 2018-07-25T21:37:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 04-Event
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    mylabel.cpp \
    mybutton.cpp

HEADERS  += mywidget.h \
    mylabel.h \
    mybutton.h

FORMS    += mywidget.ui

CONFIG +=C++11
