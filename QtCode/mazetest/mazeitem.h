#ifndef MAZEITEM_H
#define MAZEITEM_H

#include <QGraphicsItem>

class MazeItem: public QGraphicsItem
{
public:

    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    MazeItem();
};

#endif // MAZEITEM_H
