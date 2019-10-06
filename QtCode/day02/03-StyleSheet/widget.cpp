#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setStyleSheet("QLabel{color:rgb(0,255,255);"
                                 "background-color:red;}");
    ui->label->setStyleSheet("QLabel{color:rgb(0,255,255);"
                             "background-color:blue;"
                             "border-image:url(:/new/prefix1/"
                             "C:/Users/GUO/Pictures/Saved Pictures/"
                             "t013be47f5655ba1c0a.jpg);}");//平铺
    ui->pushButton->setStyleSheet("QPushButton{border-image:url"
                                  "(:/new/prefix1/C:/Users/GUO/"
                                  "Pictures/Saved Pictures/"
                                  "t013be47f5655ba1c0a.jpg);}"
                                  "QPushButton:hover{border-image:url"
                                  "(:/new/prefix1/"
                                  "C:/Users/GUO/Pictures/Saved Pictures"
                                  "/20160824035119507.jpg);}");
}//:/new/prefix1/C:/Users/GUO/Pictures/Saved Pictures/20160824035119507.jpg

Widget::~Widget()
{
    delete ui;
}
