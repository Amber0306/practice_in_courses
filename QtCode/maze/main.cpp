
#include "myitem.h"
#include "caritem.h"

#include <QApplication>

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QDebug>
#include <QWidget>

class AScene:public QGraphicsScene{
public:
    void keyPressEvent(QKeyEvent *event)
    {
        QGraphicsScene::keyPressEvent(event);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
   //w.show();

    //场景
    AScene scene;
    //QGraphicsRectItem *item = new QGraphicsRectItem(0,0,100,100);
    MyItem *item1 = new MyItem;
    scene.addItem(item1);

    CarItem *car = new CarItem;
    scene.addItem(car);


    //connect(car,CarItem::keyPressEvent(event),item1,)


    //视图

    QGraphicsView view(&scene);
    view.setForegroundBrush(QColor(0,0,0,100));
    //QPixmap 设置背景图片
    view.resize(880,660);
    view.show();


    return a.exec();
}

/*
void keyPressEvent(QKeyEvent *event)
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
*/
