#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSoundEffect>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*
    //effect = new QSoundEffect(this);
    //effect->setSource(QUrl::fromLocalFile("../music/MF_SnailRace.wav"));
    //effect->setVolume(0.75f);

    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../music/MF_SnailRace.mp3"));
    //player->play();
connect(player,SIGNAL(aboutToFinish()),this,SLOT(playAgain()));
*/

     QMovie *movie = new QMovie("qrc:/music/background.gif");
     //设置动画
     //QSize size = ui->label->size();
     //movie->setScaledSize(size);
     ui->mylabel->setMovie(movie);
     movie->start();
     ui->mylabel->setAutoFillBackground(true);
     //自动填充背景

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
//播放按钮
void MainWindow::on_pushButton_clicked()
{

    player->play();

}
//停止按钮
void MainWindow::on_pushButton_2_clicked()
{
    player->stop();
    emit stop();
}
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    effect->setLoopCount(arg1);
}
*/
