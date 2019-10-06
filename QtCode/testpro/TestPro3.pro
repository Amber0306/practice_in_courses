#-------------------------------------------------
#
# Project created by QtCreator 2018-08-28T16:47:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestPro3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wall.cpp \
    car.cpp \
    gamecontroller.cpp

HEADERS  += mainwindow.h \
    wall.h \
    car.h \
    gamecontroller.h \
    constants.h

RESOURCES += \
    res.qrc
