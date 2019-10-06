#include "texture.h"
#include<QDebug>
void Texture::keyPressEvent(QKeyEvent *event)//处理按键信息
{
    switch(event->key())
        {
            case Qt::Key_I://进入游戏模式
                 isViewMode=false;
                  break;
            case Qt::Key_O://进入试图模式
                 isViewMode=true;
                  break;
            case Qt::Key_P://选择是否显示可达路径
                 isShowPath=!isShowPath;
                  break;
            //进行方向控制人的行走
            case Qt::Key_Left:
            if(!isViewMode)
            {
                switch(curFace)
                {
                    case North:
                        eyex=curPosx+0.5;
                        eyez=curPosy;
                        centerx=0;
                        centerz=curPosy;
                        curAction=Left;
                        curFace=West;
                    break;
                    case South:
                         eyex=curPosx-0.5;
                         eyez=curPosy;
                         centerx=10;
                         centerz=curPosy;
                        curAction=Left;
                        curFace=East;
                    break;
                    case East:
                        eyex=curPosx;
                        eyez=curPosy+0.5;
                        centerx=curPosx;
                        centerz=-10;
                        curAction=Left;
                        curFace=North;
                    break;
                    case West:
                        eyex=curPosx;
                        eyez=curPosy-0.5;
                        centerx=curPosx;
                        centerz=0;
                        curAction=Left;
                        curFace=South;
                    break;

                }
            } break;

            case Qt::Key_Right:
            if(!isViewMode)
            {
                switch(curFace)
                {
                    case North:
                    eyex=curPosx-0.5;
                    eyez=curPosy;
                    centerx=10;
                    centerz=curPosy;
                    curAction=Right;
                    curFace=East;

                    break;
                    case South:
                    eyex=curPosx+0.5;
                     eyez=curPosy;
                    centerx=0;
                    centerz=curPosy;
                        curAction=Right;
                        curFace=West;
                    break;
                    case East:
                    eyex=curPosx;
                    eyez=curPosy-0.5;
                    centerx=curPosx;
                    centerz=0;
                    curAction=Right;
                    curFace=South;

                    break;
                    case West:
                    eyex=curPosx;
                    eyez=curPosy+0.5;
                    centerx=curPosx;
                    centerz=-10;
                    curAction=Right;
                    curFace=North;
                    break;

                }
            } break;
            case Qt::Key_Up:
            if(!isViewMode)
            {
                switch(curFace)
                        {
                            case North:
                               if(matrix[int(-curPosy-0.5+1)][int(curPosx-0.5)]!=0)
                               {
                                curPosy=curPosy-1;//
                                eyez=curPosy+0.5;
                                curAction=Forward;
                               }

                            break;
                            case South:
                            if(matrix[int(-curPosy-0.5-1)][int(curPosx-0.5)]!=0)
                            {
                                curPosy=curPosy+1;//
                                eyez=curPosy-0.5;
                                curAction=Forward;
                            }
                            break;
                            case East:
                            if(matrix[int(-curPosy-0.5)][int(curPosx-0.5+1)]!=0)
                            {
                                curPosx=curPosx+1;//
                                eyex=curPosx-0.5;
                                curAction=Forward;
                            }
                            break;
                            case West:
                            if(matrix[int(-curPosy-0.5)][int(curPosx-0.5-1)]!=0)
                            {
                                curPosx=curPosx-1;//
                                eyex=curPosx+0.5;
                                curAction=Forward;
                            }
                            break;

                        }
            } break;
            case Qt::Key_Down:
            if(!isViewMode)
            {
                switch(curFace)
                {
                    case North:

                    if(matrix[int(-curPosy-0.5-1)][int(curPosx-0.5)]!=0)
                    {
                     curPosy=curPosy+1;//
                     eyez=curPosy+0.5;
                     curAction=BackWard;
                    }
                    break;
                    case South:
                    if(matrix[int(-curPosy-0.5+1)][int(curPosx-0.5)]!=0)
                    {
                        curPosy=curPosy-1;//
                        eyez=curPosy-0.5;
                        curAction=BackWard;
                    }
                    break;
                    case East:
                    if(matrix[int(-curPosy-0.5)][int(curPosx-0.5-1)]!=0)
                    {
                        curPosx=curPosx-1;//
                        eyex=curPosx-0.5;
                        curAction=BackWard;
                    }
                    break;
                    case West:
                    if(matrix[int(-curPosy-0.5)][int(curPosx-0.5+1)]!=0)
                    {
                        curPosx=curPosx+1;//
                        eyex=curPosx+0.5;
                        curAction=BackWard;
                    }
                        break;

                }
            }  break;

        }
        updateGL();
        QGLWidget::keyPressEvent(event);
}

Texture::Texture(QWidget *parent) :
    QGLWidget(parent)
{
    //初始化视口参数
    eyex=1.5;eyey=1;eyez=-1.5;
    centerx=1.5;centery=1;centerz=-10;
    upx=0;upy=1;upz=0;

    isShowPath=false;//初始时不显示可达路径
    isViewMode=true;//初始时是视图模式
    curAction=Left;
    curFace=North;
    curPosx=1.5;//人的初始位置在入口
    curPosy=-1.5;
}

void Texture::initializeGL()
{
    glClearColor(0,0,0,0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);

    textures=bindTexture(QPixmap(":/image/4.bmp"));
    glEnable(GL_TEXTURE_2D);
}

void Texture::resizeGL(int w, int h)
{
    glViewport( 0, 0, (GLint)w, (GLint)h );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,w/h,0.1,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Texture::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(isViewMode)//是视图模式的情况下
    {
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       gluLookAt(5.5,20,-5.5,5.5,0,-5.5,0,0,-1);

       //显示人的位置
       glColor4f(1,1,0,0.5);
       glPushMatrix();
       glTranslatef(curPosx,0.5,curPosy);
       plotSquare();
       glPopMatrix();

  }
   else//处于游戏模式时
   {
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       gluLookAt(eyex,eyey,eyez,centerx,centery,centerz,upx,upy,upz);
   }
    //画出三维的迷宫
   for(int i=0;i<11;i++)//注意这里的11=9+2，如果改变迷宫的大小，需要更改这里的值
       for(int j=0;j<11;j++)//注意这里的11=9+2，如果改变迷宫的大小，需要更改这里的值
       {
           if(matrix[i][j]==0)
           {
              if(i==1&&j==0)
               glColor3f(1,0,1);//用红色表示入口
              else if(i==9&&j==10)
               glColor3f(0,1,0);//用蓝色表示出口
              else
               glColor3f(1,1,1);
               glPushMatrix();
               glTranslatef(0.5+j,0.5,-0.5-i);
               plotCuboid();
               glPopMatrix();

               glPushMatrix();
               glTranslatef(0.5+j,1.5,-0.5-i);
               plotCuboid();
               glPopMatrix();

           }
           if((matrix[i][j]==3||matrix[i][j]==2)&&isShowPath)
           {

               glColor4f(0,1,0,0.5);//用绿色表示可达路径
               glPushMatrix();
               glTranslatef(0.5+j,0.5,-0.5-i);
               plotSquare();
               glPopMatrix();

           }

       }
}


void Texture::plotCuboid()//绘制边长为1的正方体
{

    glBindTexture(GL_TEXTURE_2D,textures);

    glBegin(GL_QUADS);							// 开始绘制四边形
                // 下面

    glTexCoord2f(0.0,0.0);glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0,0.0);glVertex3f( 0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0,1.0);glVertex3f( 0.5f, -0.5f,  0.5f);
    glTexCoord2f(0.0,1.0);glVertex3f(-0.5f, -0.5f,  0.5f);
    glEnd();



    glBegin(GL_QUADS);
    //上面

     glTexCoord2f(0.0,0.0);glVertex3f(-0.5f, 0.5f, -0.5f);
     glTexCoord2f(1.0,0.0);glVertex3f( 0.5f, 0.5f, -0.5f);
     glTexCoord2f(1.0,1.0);glVertex3f( 0.5f, 0.5f,  0.5f);
     glTexCoord2f(0.0,1.0);glVertex3f(-0.5f, 0.5f,  0.5f);
    glEnd();

    glBegin(GL_QUADS);
                    // 前面
    glTexCoord2f(0.0,0.0);glVertex3f(-0.5f, -0.5f,  0.5f);
    glTexCoord2f(1.0,0.0);glVertex3f( 0.5f, -0.5f,  0.5f);
    glTexCoord2f(1.0,1.0);glVertex3f( 0.5f,  0.5f,  0.5f);
    glTexCoord2f(0.0,1.0); glVertex3f(-0.5f,  0.5f,  0.5f);
    glEnd();

    glBegin(GL_QUADS);
    // 后面
     glTexCoord2f(0.0,0.0);glVertex3f(-0.5f, -0.5f, -0.5f);
     glTexCoord2f(0.0,1.0);glVertex3f(-0.5f,  0.5f, -0.5f);
     glTexCoord2f(1.0,1.0);glVertex3f( 0.5f,  0.5f, -0.5f);
     glTexCoord2f(1.0,0.0);glVertex3f( 0.5f, -0.5f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
                    // 右面
     glTexCoord2f(0.0,0.0);glVertex3f( 0.5f, -0.5f, -0.5f);
     glTexCoord2f(0.0,1.0);glVertex3f( 0.5f,  0.5f, -0.5f);
     glTexCoord2f(1.0,1.0);glVertex3f( 0.5f,  0.5f,  0.5f);
     glTexCoord2f(1.0,0.0);glVertex3f( 0.5f, -0.5f,  0.5f);
    glEnd();

    glBegin(GL_QUADS);
                    // 左面
     glTexCoord2f(0.0,0.0);glVertex3f(-0.5f, -0.5f, -0.5f);
     glTexCoord2f(1.0,0.0);glVertex3f(-0.5f, -0.5f,  0.5f);
     glTexCoord2f(1.0,1.0);glVertex3f(-0.5f,  0.5f,  0.5f);
     glTexCoord2f(0.0,1.0);glVertex3f(-0.5f,  0.5f, -0.5f);

    glEnd();

}

void Texture::plotSquare()//绘制正方形
{

    glBegin(GL_QUADS);							// 开始绘制四边形
                // 下面

    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f,  0.5f);
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glEnd();

}




