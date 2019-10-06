#include <QApplication>
#include <QWidget> //窗口控件基类
#include <QPushButton>

int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    QWidget w;
    w.setWindowTitle("主要看气质");//设置标题


    QPushButton b;
    b.setText("..");//给按钮添加名字
    b.setParent(&w);//指定父对象
    b.move(100,100);//移动坐标，做尚未起点

    QPushButton b1(&w);//通过构造函数传参
    b1.setText("abc");

    //如果不指定父对象，对象与对象（窗口和窗口）没有关系
    //A指定B为它的父对象，前者放在后者的上面
    //指定父对象，两种方式1）setParent
    //2)通过构造函数传参
    //只要父对象显示，上面的子对象自动显示
    w.show();

    app.exec();
    return 0;
}
