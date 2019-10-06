#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <mybutton.h>
#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
};

#endif // MYWIDGET_H
