/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QWidget *widget_3;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *laybutton;
    MyButton *classicbutton;
    QPushButton *helpbutton;
    QPushButton *setbutton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(854, 487);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        gridLayout_3->addWidget(widget_3, 0, 0, 1, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        laybutton = new QPushButton(widget_2);
        laybutton->setObjectName(QStringLiteral("laybutton"));
        laybutton->setMinimumSize(QSize(120, 50));
        laybutton->setIconSize(QSize(50, 50));

        gridLayout->addWidget(laybutton, 0, 3, 1, 1);

        classicbutton = new MyButton(widget_2);
        classicbutton->setObjectName(QStringLiteral("classicbutton"));
        classicbutton->setMinimumSize(QSize(120, 50));
        classicbutton->setStyleSheet(QStringLiteral("border-image: url(:/image/classbutton.jpg);"));
        classicbutton->setIconSize(QSize(50, 50));

        gridLayout->addWidget(classicbutton, 0, 1, 1, 1);

        helpbutton = new QPushButton(widget_2);
        helpbutton->setObjectName(QStringLiteral("helpbutton"));
        helpbutton->setMinimumSize(QSize(120, 50));
        helpbutton->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(helpbutton, 1, 1, 1, 1);

        setbutton = new QPushButton(widget_2);
        setbutton->setObjectName(QStringLiteral("setbutton"));
        setbutton->setMinimumSize(QSize(120, 50));

        gridLayout->addWidget(setbutton, 1, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 4, 1, 1);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        laybutton->setText(QApplication::translate("MainWindow", "\350\277\267\345\256\253\346\250\241\345\274\217", 0));
        classicbutton->setText(QString());
        helpbutton->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        setbutton->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
