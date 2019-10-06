#-------------------------------------------------
#
# Project created by QtCreator 2018-07-11T20:40:45
#
#-------------------------------------------------

#模块
QT       += core gui

#高于4版本，添加QT+=widget,为了兼容QT4
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#应用程序的名字
TARGET = 01-Qt-test

#指定makefile的类型，app
TEMPLATE = app

#源文件
SOURCES += main.cpp\
        mywidget.cpp
#头文件
HEADERS  += mywidget.h
