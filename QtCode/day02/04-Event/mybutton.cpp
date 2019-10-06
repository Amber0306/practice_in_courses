#include "mybutton.h"
#include <QMouseEvent>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}
void MyButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        qDebug()<<"按下的是左键";
        //事件接受后，就不会往下传递

        e->ignore();//忽略，事件继续传递，给谁传、
        //事件传递给了父组件，而不是父类
    }
    else
    {
        //不做处理
        //QPushButton::mousePressEvent(e);
        //事件的忽略，不接收往下传递
    }//
    QPushButton::mousePressEvent(e);
}
