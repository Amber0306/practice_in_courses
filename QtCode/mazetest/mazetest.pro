#-------------------------------------------------
#
# Project created by QtCreator 2018-08-28T14:03:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mazetest
TEMPLATE = app


SOURCES += main.cpp\
        caritem.cpp \
    mazeitem.cpp \
    mainwindow.cpp \
    gamecontroller.cpp

HEADERS  += caritem.h \
    mazeitem.h \
    mainwindow.h \
    gamecontroller.h

RESOURCES += \
    image.qrc
