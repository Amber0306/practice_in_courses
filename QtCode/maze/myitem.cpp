#include "myitem.h"

#include <QPainter>

MyItem::MyItem()
{
     CarItem *car = new CarItem;
     car->setVisible(true);
     car->show();
}

QRectF MyItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-440-penWidth/2,-330-penWidth/2,
                  880+penWidth/2,660+penWidth/2);
}

void MyItem::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor(187,16,245,255));
    //painter->drawRect(0,0,20,20);

    painter->drawRect(-360,-240,30,540);//1
    painter->drawRect(-330,-240,600,30);//2
    painter->drawRect(300,-240,90,30);  //3
    painter->drawRect(360,-210,30,540); //4
    painter->drawRect(210,300,150,30);  //5
    painter->drawRect(180,270,30,60);   //6
    painter->drawRect(-240,300,420,30); //7
    painter->drawRect(-360,300,90,30);  //8
    painter->drawRect(-300,-210,30,180);//9
    painter->drawRect(-270,-180,90,30); //10
    painter->drawRect(-180,-180,30,90); //11
    painter->drawRect(-240,-120,60,30); //12
    painter->drawRect(-270,-60,120,30); //13
    painter->drawRect(-330,0,60,30);    //14
    painter->drawRect(-300,30,30,120);  //15
    painter->drawRect(-270,120,60,30);  //16
    painter->drawRect(-300,180,30,120); //17
    painter->drawRect(-120,-210,30,60); //18
    painter->drawRect(-90,-180,60,30);  //19
    painter->drawRect(0,-210,30,90);    //20
    painter->drawRect(60,-210,30,60);   //21
    painter->drawRect(90,-180,60,30);   //22
    painter->drawRect(-120,-120,240,30);//23
    painter->drawRect(120,-120,30,60);   //24
    painter->drawRect(-120,-90,30,90);  //25
    painter->drawRect(-240,0,270,30);   //26
    painter->drawRect(-240,60,90,30);   //27
    painter->drawRect(-180,90,30,210);  //28
    painter->drawRect(-240,180,30,120); //29
    painter->drawRect(-150,240,120,30); //30
    painter->drawRect(-120,60,30,120);  //31
    painter->drawRect(-150,180,180,30); //32
    painter->drawRect(-60,30,30,120);   //33
    painter->drawRect(0,90,30,90);      //34
    painter->drawRect(0,60,60,30);      //35
    painter->drawRect(-60,-60,150,30);  //36
    painter->drawRect(60,-30,90,30);    //37
    painter->drawRect(60,0,30,210);     //38
    painter->drawRect(90,150,30,30);    //39
    painter->drawRect(120,120,30,60);   //40
    painter->drawRect(120,30,30,60);    //41
    painter->drawRect(150,60,30,30);    //42
    painter->drawRect(180,-210,30,450); //43
    painter->drawRect(120,210,60,30);   //44
    painter->drawRect(0,240,150,30);    //45
    painter->drawRect(240,180,30,90);   //46
    painter->drawRect(270,240,60,30);   //47
    painter->drawRect(300,120,30,90);   //48
    painter->drawRect(210,120,90,30);   //49
    painter->drawRect(240,60,120,30);   //50
    painter->drawRect(240,-60,30,120);  //51
    painter->drawRect(270,0,60,30);     //52
    painter->drawRect(300,-120,30,90);  //53
    painter->drawRect(240,-120,60,30);  //54
    painter->drawRect(240,-210,30,90);  //55
    painter->drawRect(300,-180,60,30);  //56


}


void MyItem::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
       case Qt::Key_Up:car->moveBy(0,-2);
           break;
       case Qt::Key_Down: car->moveBy(0,2);
           break;
       case Qt::Key_Left:car-> moveBy(-2,0);
           break;
       case Qt::Key_Right:car-> moveBy(2,0);
           break;
       default:
           break;

    }
}

