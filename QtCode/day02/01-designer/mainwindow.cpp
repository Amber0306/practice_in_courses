#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStringList>
#include <QCompleter>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->button->setText("123");
    //connect(ui->button,&......,this,.....);

    //QLineEdit
    QString str = ui->lineEdit->text();//获取内容
    qDebug()<<str;

    ui->lineEdit->setText("12345678"); //设置内容

    //QLabel
    //设置文本内容
    ui->labelText->setText("@_@");

    //设置图片
    ui->labelImage->setPixmap(QPixmap(":/\/Image/u150307194203661221.jpeg"));
    //让图片自动适应label大小
    ui->labelImage->setScaledContents(true);

    //设置动画
    //创建动画
    QMovie *myMovie = new QMovie(":/\/Image/t012d779808eb543d70.gif");
    //放置动画
    ui->labelGif->setMovie(myMovie);
    //启动动画
    myMovie->start();
    //适应区域
    ui->labelGif->setScaledContents(true);

    //设置地址
    ui->labelUrl->setText("<h1><a href=\"http://www.baidu.com\">百度一下</a></h1>");
    //打开外部链接
    ui->labelUrl->setOpenExternalLinks(true);

    //数码管
    ui->lcdNumber->display(123);//设置内容

    //进度条
    ui->progressBar->setMaximum(200);//设置最大值
    ui->progressBar->setMinimum(0);//设置最小值
    ui->progressBar->setValue(100);//设置当前值
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    static int i = 0;
    ui->stackedWidget->setCurrentIndex(++i % 4);
}
