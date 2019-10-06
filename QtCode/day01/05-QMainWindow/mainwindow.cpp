#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //菜单栏
    QMenuBar *mBar = menuBar();
    //添加菜单
    QMenu *pFile = mBar->addMenu("文件");
    //添加菜单项，添加动作
    QAction *pNew = pFile->addAction("new");
    //复习lambda表达式
    connect(pNew,&QAction::triggered,
           [=]()
           {
        qDebug()<<"新键被按下"; }
                  );
     pFile->addSeparator();//添加分割线
     QAction *pOpen = pFile->addAction("open");

    //工具栏
     //，菜单下面的快捷方式
     QToolBar *toolBar = addToolBar("toolBar");
     //工具栏添加快捷键
     toolBar->addAction(pNew);
     QPushButton *b = new QPushButton(this);
     //添加小控件
     toolBar->addWidget(b);
     connect(b,&QPushButton::clicked,
             [=]()
     {
         b->setText("123");
     });

    //状态栏
     QStatusBar *sBar=statusBar();
     QLabel *label = new QLabel(this);
     label->setText("Normal text file");
     sBar->addWidget(label);
     //addWidget从左往右添加
     sBar->addWidget(new QLabel("2",this));
     //addPermanentWidget从右往左添加
     sBar->addPermanentWidget(new QLabel("3",this));

    //核心控件
     QTextEdit *textEdit = new QTextEdit(this);
     setCentralWidget(textEdit);

    //浮动窗口
     QDockWidget *dock = new QDockWidget(this);
     addDockWidget(Qt::RightDockWidgetArea,dock);
     //给浮动窗口添加控件
     QTextEdit *textEdit1 = new QTextEdit(this);
     setCentralWidget(textEdit1);
}

MainWindow::~MainWindow()
{

}
