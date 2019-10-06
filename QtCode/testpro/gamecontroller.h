#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include<QTimer>

class QGraphicsScene;
class QKeyEvent;

class Car;
class Wall;


class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene &scene, QObject *parent = 0);
    ~GameController();

    void carHitWall(Car *car,Wall *wall);
    QList<QRect> rlist;
    void addRect(QRect r);
    void addWall();

signals:

public slots:
    void pause();
    void resume();
  //  void gameOver();

protected:
     bool eventFilter(QObject *object, QEvent *event);

private:
    void handleKeyPressed(QKeyEvent *event);

    QTimer timer;
    QGraphicsScene &scene;
    Car *car;
};

#endif // GAMECONTROLLER_H
