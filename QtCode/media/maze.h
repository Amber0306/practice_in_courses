#ifndef MAZE_H
#define MAZE_H

#include<iostream>
#include<ctime>
#include<QTime>
#include<vector>

#define M 9//迷宫的行 行和列必须为基数
#define N 9//迷宫的列
//构造迷宫类型//

using namespace std;
class MazeStack;//用于存储迷宫信息的栈

class Maze
{
public:
    int i;//迷宫矩阵的行和列i,j
    int j;//
    int state;//当前矩阵元素的状态：是否是墙
};


class MazeMat
{
public:
    Maze matrix[M][N];//存储迷宫矩阵元素的信息
    vector<Maze> EntryPath;//保存从初始点到入口的路径
    vector<Maze> ExitPath;//保存从初始点到出口的路径
    vector<Maze> FinalPath;//保存从入口到出口的路径
    MazeStack *mazeStack;//用于存储迷宫信息的栈


    void initMaze();//初始化迷宫矩阵
    void createMaze();//产生迷宫
    void displayMaze();//显示迷宫
    void FindWay();//找到从入口到出口的路径
};
//////////////////
#endif // MAZE_H
