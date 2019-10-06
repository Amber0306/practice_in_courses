#ifndef MYITEM_H
#define MYITEM_H

#include "caritem.h"
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QRectF>

class CarItem;
class MyItem:public QGraphicsItem
{
public:
    MyItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    void keyPressEvent(QKeyEvent *event);
private:
     CarItem *car;
};

#endif // MYITEM_H
