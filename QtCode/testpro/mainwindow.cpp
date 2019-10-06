#include <QGraphicsView>
#include <QTimer>

#include "constants.h"
#include "gamecontroller.h"
#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene, this)),
    game(new GameController(*scene, this))
{
    setCentralWidget(view);
    resize(880, 660);

    initScene();
    initSceneBackground();



    QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

MainWindow::~MainWindow()
{

}
void MainWindow::adjustViewSize()
{
    qDebug() << "45454";
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}

void MainWindow::initScene()
{
    scene->setSceneRect(-440, -330, 880, 660);//窗口大小和位置
}

void MainWindow::initSceneBackground()
{
    QPixmap bg(CAR_SIZE, CAR_SIZE);//矩形
    QPainter p(&bg);//画笔
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0, CAR_SIZE, CAR_SIZE);//填充背景

    view->setBackgroundBrush(QBrush(bg));
}
