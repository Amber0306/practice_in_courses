#ifndef TEXTURE_H
#define TEXTURE_H

#include <QGLWidget>
#include<GL/glu.h>
#include<GL/glu.h>
#include<QKeyEvent>
#define M 11//迷宫的行
#define N 11//迷宫的列
class Texture : public QGLWidget
{
    Q_OBJECT
public:
    enum currentAction{Left,Right,Forward,BackWard};//方向键状态
    enum currentFace{North,South,East,West};//人的朝向
    void keyPressEvent(QKeyEvent*);//键盘按下事件
    GLfloat eyex,eyey,eyez,centerx,centery,centerz,upx,upy,upz;//视口参数
    GLuint textures;//纹理贴图
    currentAction curAction;
    currentFace curFace;
    float curPosx;//人当前位置
    float curPosy;
    int matrix[M][N];//迷宫矩阵（包含四周的墙）
    bool isViewMode;//是否处于全局查看模式
    bool isShowPath;//显示可达路径

    explicit Texture(QWidget *parent = 0);
    //重载opengl的三个函数
    void initializeGL();
    void resizeGL(int w,int h);
    void paintGL();

    void plotCuboid();//画正方体
    void plotSquare();//画正方形
signals:

public slots:

};

#endif // TEXTURE_H
