#include "texture.h"
#include"mazestack.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MazeMat m;//迷宫实例
    m.initMaze();//迷宫初始化
    m.createMaze();//生成迷宫

    m.FindWay();//寻找可达路径
    m.displayMaze();//显示迷宫
    Texture w;

    //在迷宫矩阵的四周加上围墙
    for(int i=0;i<11;i++)
    {
        w.matrix[0][i]=0;
        w.matrix[10][i]=0;
    }
    for(int i=1;i<10;i++)
    {
        w.matrix[i][0]=0;
        w.matrix[i][10]=0;
        for(int j=1;j<10;j++)
        {

           w.matrix[i][j]=m.matrix[i-1][j-1].state;
        }
    }

    w.resize(600,480);
    w.show();
    return a.exec();
}

