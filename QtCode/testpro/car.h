#ifndef CAR_H
#define CAR_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPaintEvent>

#include <QPushButton>
class GameController;


class Car : public QWidget
{
public:
    enum Direction {
        NoMove,
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };
    QPointF        head;
    QList<QRect> rlist;

    Car(GameController & controller);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void paintEvent(QPaintEvent*);
    void setMoveDirection(Direction direction);

    void advance(int step);

    int xxx =90;

    QPushButton *ppp;

protected:



private:

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void handleCollisions();


    int            speed;
    int            tickCounter;

    Direction      moveDirection;
    GameController &controller;
};

#endif // CAR_H
