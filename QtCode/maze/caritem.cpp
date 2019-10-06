#include "caritem.h"

#include <QPainter>
#include <QKeyEvent>

CarItem::CarItem()
{
    brushColor=Qt::yellow;


   //setFlag(QGraphicsItem::ItemIsMovable);
   setFlag(QGraphicsItem::ItemIsFocusable);

}

QRectF CarItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-440-penWidth/2,-330-penWidth/2,
                 880+penWidth/2,660+penWidth/2);
}

void CarItem::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   // QImage image;
   // image.load(":/image/小车1.jpg");
    //painter->drawImage(QPoint(-271,331),image);
    //painter->drawPixmap(rect(-270,300,30,30),
                        //QPixmap(":/image/车顶1.jpg"));
    //painter->
    if(hasFocus())
    {
        painter->setPen(QPen(QColor(255,255,0,255)));
    }else{
        painter->setPen(QPen(QColor(100,100,100,100)));
    }
    painter->setBrush(brushColor);
    painter->drawRect(-270,330,30,30);
}


void CarItem::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
       case Qt::Key_Up:this-> moveBy(0,-10);
           break;
       case Qt::Key_Down: this->moveBy(0,2);
           break;
       case Qt::Key_Left:this-> moveBy(-2,0);
           break;
       case Qt::Key_Right:this-> moveBy(2,0);
           break;
       default:
           break;

    }
}

