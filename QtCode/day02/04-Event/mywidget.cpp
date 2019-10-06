#include "mywidget.h"
#include "ui_mywidget.h"
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include <QEvent>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupimer();
    timerID = this->startTimer(1000);//以毫秒为单位,每隔一秒触发一次计时器
    //this->killTimer();
    timerID2 = this->startTimer(500);//每隔500毫秒一次

    connect(ui->pushButton,&MyButton::clicked,
            [=]()
    {
        qDebug()<<"按钮被按下";
    });

    //安装过滤器
    ui->label_2->installEventFilter(this);
    ui->label_2->setMouseTracking(true);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<(char)event->key();
    if(event->key()==Qt::Key_A)
    {
        qDebug()<<"Qt::Key_A";
    }
}

void MyWidget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==this->timerID)
    {
    static int sec = 0;
    //sec++;
    ui->label->setText(QString("<center><h1>Timer: %1</h1></center>")
                       .arg(sec++));
    if(5==timerID)
    {
        //停止计时器
        this->killTimer(this->timerID);
    }
    }
    else if(event->timerId()==this->timerID2)
    {
        static int sec = 0;
        //sec++;
        ui->label_2->setText(QString("<center><h1>Timer: %1</h1></center>")
                           .arg(sec++));
    }
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"++++++++";
}

void MyWidget::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this,"question","是否关闭窗口");
    if(ret == QMessageBox::Yes)
    {
        //关闭窗口
        //处理关闭窗口事件，接收事件，事件不会继续往下传递
        event->accept();
    }
    else
    {
        //不关闭窗口
        //忽略事件，事件继续给父组件传递
        event->ignore();
    }

}
bool MyWidget::event(QEvent *event)
{

//    //事件分发
//    switch(event->type())
//    {
//    case QEvent::Close:
//        closeEvent(event);
//        break;
//    case QEvent::MouseMove:
//        mouseMoveEvent(event);
//        break;
//        /*
//         */

//    }
    if(event->type()==QEvent::Timer)
    {
        //干掉计时器
        //返回true，停止传播
        //类型不匹配，转换一下
        QTimerEvent *env = static_cast<QTimerEvent*>event;
        timerEvent(event);
        return true;
    }
    else if(event->type()==QEvent::KeyPress)
    {
         QTimerEvent *env = static_cast<QTimerEvent*>event;
         if(env->key()==Qt::key_B)
         {
             return QWidget::event(event);
         }
         return true;
    }
    else
    {
        return QWidget::event(event);
        //return false;
    }
}

 bool MyWidget::eventFilter(QObject *obj, QEvent *e)
 {
     if(obj == ui->label_2)
     {
         QMouseEvent *env = static_cast<QMouseEvent>(e);
         //判断事件
         if(e->type() ==QEvent::MouseMove)
         {
             ui->label_2->setText(QString("Mouse Move:(%1,%2)")
                                  .arg(env->x()).arg(env->y()));
             return true;
         }
         else
         {
              return QWidget::eventFilter(obj,e);
         }
     }
     else
     {
         return QWidget::eventFilter(obj,e);
     }
 }















