#ifndef CARITEM_H
#define CARITEM_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QRectF>

class CarItem:public QGraphicsItem
{
public:
    CarItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setColor(const QColor &color)
    {
        brushColor = color;
    }



//protected:
    void keyPressEvent(QKeyEvent *event);
private:
    QColor brushColor;

};

#endif // CARITEM_H
