#include <QEvent>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "gamecontroller.h"
#include"constants.h"
#include"car.h"
#include"wall.h"
#include <QDebug>

GameController::GameController(QGraphicsScene &scene, QObject *parent) :
    QObject(parent),
    scene(scene),
    car(new Car(*this))
{

    timer.start( 1000/10 );
    Wall *wall=new Wall;

//    scene.addItem(wall);
//    scene.addItem(car);


    car->show();
    scene.installEventFilter(this);//事件过滤器

    resume();




    addRect(QRect(-360,-240,30,540));//1
    addRect(QRect(-330,-240,600,30));//2
    addRect(QRect(300,-240,90,30));  //3
    addRect(QRect(360,-210,30,540)); //4
    addRect(QRect(210,300,150,30));  //5




    addRect(QRect(180,270,30,60));   //6
    addRect(QRect(-240,300,420,30)); //7
    addRect(QRect(-360,300,90,30));  //8
    addRect(QRect(-300,-210,30,180));//9
    addRect(QRect(-270,-180,90,30)); //10
    addRect(QRect(-180,-180,30,90)); //11
    addRect(QRect(-240,-120,60,30)); //12
    addRect(QRect(-270,-60,120,30)); //13
    addRect(QRect(-330,0,60,30));    //14
    addRect(QRect(-300,30,30,120));  //15
    addRect(QRect(-270,120,60,30));  //16
    addRect(QRect(-300,180,30,120)); //17
    addRect(QRect(-120,-210,30,60)); //18
    addRect(QRect(-90,-180,60,30));  //19
    addRect(QRect(0,-210,30,90));    //20
    addRect(QRect(60,-210,30,60));   //21
    addRect(QRect(90,-180,60,30));   //22
    addRect(QRect(-120,-120,240,30));//23
    addRect(QRect(120,-120,30,60));   //24
    addRect(QRect(-120,-90,30,90));  //25
    addRect(QRect(-240,0,270,30));   //26
    addRect(QRect(-240,60,90,30));   //27
    addRect(QRect(-180,90,30,210));  //28
    addRect(QRect(-240,180,30,120)); //29
    addRect(QRect(-150,240,120,30)); //30
    addRect(QRect(-120,60,30,120));  //31
    addRect(QRect(-150,180,180,30)); //32
    addRect(QRect(-60,30,30,120));   //33
    addRect(QRect(0,90,30,90));      //34
    addRect(QRect(0,60,60,30));      //35
    addRect(QRect(-60,-60,150,30));  //36
    addRect(QRect(60,-30,90,30));    //37
    addRect(QRect(60,0,30,210));     //38
    addRect(QRect(90,150,30,30));    //39
    addRect(QRect(120,120,30,60));   //40
    addRect(QRect(120,30,30,60));    //41
    addRect(QRect(150,60,30,30));    //42
    addRect(QRect(180,-210,30,450)); //43
    addRect(QRect(120,210,60,30));   //44
    addRect(QRect(0,240,150,30));    //45
    addRect(QRect(240,180,30,90));   //46
    addRect(QRect(270,240,60,30));   //47
    addRect(QRect(300,120,30,90));   //48
    addRect(QRect(210,120,90,30));   //49
    addRect(QRect(240,60,120,30));   //50
    addRect(QRect(240,-60,30,120));  //51
    addRect(QRect(270,0,60,30));     //52
    addRect(QRect(300,-120,30,90));  //53
    addRect(QRect(240,-120,60,30));  //54
    addRect(QRect(240,-210,30,90));  //55
    addRect(QRect(300,-180,60,30));  //56


    addWall();



    scene.addWidget(car);


}

void GameController::addRect(QRect r){
    if(r.width() != 30){
        for(int i = 0; i < (r.width()/30); i++){ //H
            rlist.append(QRect(r.x() + i*30,r.y(),30,30));
        }
    }
    if(r.height() != 30){
        for(int i = 0; i < (r.height()/30); i++){ //H
            rlist.append(QRect(r.x(),r.y() + i*30,30,30));
        }
    }
}


void GameController::addWall(){
    car->rlist = this->rlist;
    for(int i = 0; i < this->rlist.count(); i++){
        QWidget *ppp = new QWidget();
        ppp->setGeometry(rlist.value(i));
        ppp->setStyleSheet("background-color:#0000FF;");
        scene.addWidget(ppp);
    }
}
GameController::~GameController()
{

}

void GameController::carHitWall(Car *car, Wall *wall)
{
    scene.clear();
}

void GameController::handleKeyPressed(QKeyEvent *event)//处理方向
{
    switch (event->key()) {
        case Qt::Key_Left:
            car->setMoveDirection(Car::MoveLeft);
            qDebug() << "左";
//            car->setPos(100,100);
            car->xxx = -60;
            car->update(90,90,60,60);
            car->advance(Car::MoveLeft);
            break;
        case Qt::Key_Right:
            car->setMoveDirection(Car::MoveRight);
            qDebug() << "右";
            car->advance(Car::MoveRight);
            break;
        case Qt::Key_Up:
            car->setMoveDirection(Car::MoveUp);
            qDebug() << "上";
            car->advance(Car::MoveUp);
            break;
        case Qt::Key_Down:
            car->setMoveDirection(Car::MoveDown);
            qDebug() << "下" << car->head;


            car->advance(Car::MoveDown);
            break;
    }
}


void GameController::pause()//连接定时器信号
{
//    disconnect(&timer, SIGNAL(timeout()),
//               &scene, SLOT(advance()));
}

void GameController::resume()//断开定时器信号
{
//    connect(&timer, SIGNAL(timeout()),
//            &scene, SLOT(advance()));
}


bool GameController::eventFilter(QObject *object, QEvent *event)//事件过滤器
{
    if (event->type() == QEvent::KeyPress) {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}
