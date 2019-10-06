#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
}
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    //sprintf格式化
    /*QString str = QString（“abc %1 ^_^ %2").arg(123).arg("amber");
     * str = abc 123 ^_^ amber
     */

    if(ev->button() ==Qt::LeftButton)
    {
        qDebug()<<"left";
    }

    QString text = QString("<center><h1>Mouse Press: (%1,%2)</h1></center>")
            .arg( i).arg(j);
    this->setText(text);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Release: (%1,%2)</h1></center>")
            .arg( ev->x()).arg(ev->y());
    this->setText(text);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Move: (%1,%2)</h1></center>")
            .arg( ev->x()).arg(ev->y());
    this->setText(text);
}

void MyLabel::enterEvent(QEvent *event)
{
    QString text = QString("<center><h1>Mouse enter</h1></center>");
    this->setText(text);
}

void MyLabel::leaveEvent(QEvent *event)
{
    QString text = QString("<center><h1>Mouse leave</h1></center>");
    this->setText(text);
}

