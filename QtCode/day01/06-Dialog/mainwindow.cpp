#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("对话框");

    QAction *p1 = menu->addAction("模态对话框");
    connect(p1,&QAction::triggered,
            [=](){
        QDialog dlg;
        dlg.exec();
        qDebug()<<"11111";
    }
    );

    QAction *p2 = menu->addAction("非模态对话框");
    connect(p2,&QAction::triggered,
            [=](){
        //定义为成员
        dlg.show();
        qDebug()<<"21111";
        //动态分配（指定父对象可能会内存泄漏，多次分配一次释放）
        QDialog *p = new QDialog;
        p->setAttribute(Qt::WA_DeleteOnClose);
        p->show();
    }
    );

    QAction *p3 = menu->addAction("关于对话框");
    connect(p3,&QAction::triggered,
            [=](){
        QMessageBox::about(this,"about","关于QT");}
              );

    QAction *p4 = menu->addAction("关于对话框");
    connect(p4,&QAction::triggered,
            [=](){
        int ret = QMessageBox::question(this,"question","Are you OK?");
        //可以指定QMessage::Ok|QMessage::Cancel,或者是其他的操作
        switch (ret) {
        case QMessageBox::Yes:
            qDebug()<<"i am ok";
            break;
        case QMessageBox::No:
            qDebug()<<"i am bad";
            break;
        default:
            break;
        }}
              );

    QAction *p5 = menu->addAction("对话框");
    connect(p5,&QAction::triggered,
            [=]()
            {
                QString path = QFileDialog::getOpenFileName(
                            this,"open","../",
                            "source(*.cpp *.h);;"
                            "Text(*.txt);;all(*.*)"
                        );
                qDebug()<<path;
            }
              );
}

MainWindow::~MainWindow()
{

}
