#include"MazeStack.h"
using namespace std;



void MazeMat::initMaze()
{
    for(int i=0;i<M;i++)//给每个迷宫矩阵元素赋予初始信息
        for(int j=0;j<N;j++)
        {
            matrix[i][j].i=i;
            matrix[i][j].j=j;
            matrix[i][j].state=0;//0表示该点是墙
        }

        mazeStack=new MazeStack();
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//随机数种子
        EntryPath.clear();//路径进行初始化
        ExitPath.clear();
        FinalPath.clear();
}

void MazeMat::createMaze()
{

    int i=4;//注意i,j必须为偶数，取迷宫矩阵的中心比较好
    int j=4;
    bool Left=false;
    bool Right=false;
    bool Up=false;
    bool Down=false;

    matrix[i][j].state=1;//设置初始点为非墙区域
    Maze temp;

    temp.i=i;
    temp.j=j;
    temp.state=0;
    mazeStack->Push(temp);
    while(1)//不断循环生成迷宫
    {

        temp.i=i;
        temp.j=j;
        int randNum=0;

        randNum=qrand()%4;//0,1,2,3
        //我们假设入口为左上角(0,0),出口为右下角(M-1,N-1)
        if(temp.i==0&&temp.j==0)//到达入口点
        {
            EntryPath.clear();
          while(mazeStack->isEmpty() == false)
          {

             EntryPath.push_back(mazeStack->GetTop());//获取从初始点到入口的路径
             mazeStack->Pop();

          }
          for(int ii=EntryPath.size()-1;ii>=0;ii--)
          {
              mazeStack->Push(EntryPath[ii]);//还原栈
          }
        }

        if(temp.i==M-1&&temp.j==N-1)
        {
            ExitPath.clear();
          while(mazeStack->isEmpty() == false)
          {

             ExitPath.push_back(mazeStack->GetTop());//获取从初始点到出口的路径
             mazeStack->Pop();

          }
          for(int i=ExitPath.size()-1;i>=0;i--)
          {
              mazeStack->Push(ExitPath[i]);//还原栈
          }
        }

        switch(randNum)
        {

        case 0://向上搜索
            if(Up==false&&i>1&&matrix[i-2][j].state!=1)
            {
                mazeStack->Push(temp);
                matrix[i-1][j].state=1;
                matrix[i-2][j].state=1;

                i=i-2;
                Left=false;
                Right=false;
                Up=false;
                Down=false;
            }
            else
                Up=true;
            break;
        case 1://向下搜索
            if(Down==false&&i<M-2&&matrix[i+2][j].state!=1)
            {
                mazeStack->Push(temp);
                matrix[i+1][j].state=1;
                matrix[i+2][j].state=1;

                i=i+2;
                Left=false;
                Right=false;
                Up=false;
                Down=false;
            }
            else
                Down=true;
            break;
         case 2://向左搜索
             if(Left==false&&j>1&&matrix[i][j-2].state!=1)
            {
                mazeStack->Push(temp);
                matrix[i][j-1].state=1;
                matrix[i][j-2].state=1;

                j=j-2;
                Left=false;
                Right=false;
                Up=false;
                Down=false;
            }
            else
                Left=true;
            break;
         case 3://向右搜索
             if(Right==false&&j<N-2&&matrix[i][j+2].state!=1)
            {
                mazeStack->Push(temp);
                matrix[i][j+1].state=1;
                matrix[i][j+2].state=1;

                j=j+2;
                Left=false;
                Right=false;
                Up=false;
                Down=false;
            }
            else
                Right=true;
            break;
        }//end switch

        if(Left&&Right&&Up&&Down)//不能向上下左右搜索
          {
              if(mazeStack->isEmpty())
               {
                    return ;
               }
               else//进行回溯
               {
                    i = mazeStack->GetTop().i;
                    j = mazeStack->GetTop().j;
                    mazeStack->Pop();

                    Left=false;
                    Right=false;
                    Up=false;
                    Down=false;
               }

          }

    }//end while


}

void MazeMat::displayMaze()
{

     matrix[0][0].state = matrix[M-1][N-1].state = 2;//2表示为出入口
     for(int i=0;i<FinalPath.size();i++)
     {
         matrix[FinalPath.at(i).i][FinalPath.at(i).j].state=3;//3表示为可达路径点
     }
//-----------下面注释了的语句可以在控制台显示迷宫-------------//
//     for(int k=0;k<N+2;k++)
//         cout<<"11";//加上外围墙
//     cout<<endl;
//     for (int i = M-1; i>=0; i--)
//     {
//          cout<<"11";
//          for (int j = 0; j <N; j++)
//          {
//              switch ( matrix[i][j].state )
//                {
//                   case 0:cout<<"11";break;//表示墙
//                   case 1:cout<<"  ";break;//表示空
//                   case 2:cout<<"kk";break;//表示出入口
//                   case 3:cout<<"oo";break;//表示可达路径点
//                }
//          }
//          cout<<"11";
//          cout<<endl;
//     }
//      for(int k=0;k<N+2;k++)
//         cout<<"11";
//     cout<<endl;
}

void MazeMat::FindWay()//根据初始点到入口、出口的路径来计算入口到出口的路径
{
    FinalPath.clear();
    int i=0,j=0;

    for(i=EntryPath.size()-1,j=ExitPath.size()-1;i>=0&&j>=0;i--,j--)
    {
        if(EntryPath.at(i).i!=ExitPath.at(j).i||EntryPath.at(i).j!=ExitPath.at(j).j)
        {
            break;
        }
    }

    if(i<0)//初始点到出口的路径经过入口的情况
    {
        for(int k=ExitPath.size()-EntryPath.size()-1;k>=0;k--)
        {
            FinalPath.push_back(ExitPath.at(k));
        }

    }

    else if(j<0)//初始点到入口的距离经过出口的情况
    {
        for(int k=EntryPath.size()-ExitPath.size()-1;k>=0;k--)
        {
            FinalPath.push_back(EntryPath.at(k));
        }
    }

    else//初始点到入口、出口的路径只有一部分重叠或没有重叠
    {
        for(int k=0;k<=i+1;k++)
        {
            FinalPath.push_back(EntryPath.at(k));
        }

        for(int k=j;k>=0;k--)
        {
            FinalPath.push_back(ExitPath.at(k));
        }
    }


}

