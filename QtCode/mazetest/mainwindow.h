#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QGraphicsScene;
class QGraphicsView;
class GameController;




class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:

public slots:

private slots:
    void adjustViewSize();//适应

private:
    void initScene();//
    void initSceneBackground();

    QGraphicsScene *scene;//游戏发生的舞台
    QGraphicsView *view;//观察游戏舞台的组件

    GameController *game;

};

#endif // MAINWINDOW_H
