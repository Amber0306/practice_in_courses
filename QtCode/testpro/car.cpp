#include "car.h"
#include <QPainter>
#include "wall.h"
#include "constants.h"
#include "gamecontroller.h"
#include<QDebug>
#include <QMessageBox>
Car::Car(GameController &controller):
    head(0,0),
    speed(1),
    moveDirection(NoMove),
    controller(controller)
{   
    this->setMaximumSize(30,30);
    this->setGeometry(-30,-30,30,30);
    this->head.rx() = -30;
    this->head.ry() = -30;
    this->setObjectName("lian");
    this->setStyleSheet("#lian{background-image:url(':/new/img/lian.png');}");
}

QRectF Car::boundingRect() const
{
    return QRectF(-CAR_SIZE,    -CAR_SIZE,
                   CAR_SIZE * 2, CAR_SIZE * 2 );

}


void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(QColor(0,255,0,255));
    painter->drawRect(-360 + this->xxx,-240,30,30);//-360,-240,30,540
}

void Car::paintEvent(QPaintEvent *)
{


}

void Car::setMoveDirection(Direction direction)
{
    moveDirection = direction;
}

void Car::advance(int step)
{
    if (!step) {
        return;
    }
    if (tickCounter++ % speed != 0) {
        return;
    }
    if (moveDirection == NoMove) {
        return;
    }

    switch (moveDirection) {
        case MoveLeft:
            moveLeft();

            break;
        case MoveRight:
            moveRight();

            break;
        case MoveUp:
            moveUp();

            break;
        case MoveDown:
            moveDown();

            break;
    }


//    setPos(head);//设置坐标
    qDebug() << head;
    this->setGeometry(head.x(),head.y(),30,30);

    if(rlist.contains(QRect(head.x(),head.y(),30,30))){
        qDebug() << "*******************";
        QMessageBox::information(this,"","撞墙了");
    } else {
        qDebug() << "7777777777";
    }

    if(head == QPointF(-270,330)){
        QMessageBox::information(this,"","出来了！");
    }

    if(head == QPointF(270,-270)){
        QMessageBox::information(this,"","出来了！");
    }

    //
}


void Car::moveLeft()
{
    this->xxx += 30;
    head.rx() -= CAR_SIZE;
    qDebug() << head.rx();
}

void Car::moveRight()
{
    head.rx() += CAR_SIZE;
}

void Car::moveUp()
{
    head.ry() -= CAR_SIZE;
}

void Car::moveDown()
{
    head.ry() += CAR_SIZE;
}





