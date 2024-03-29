// DataPro3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
//#define MaxSize 50

using namespace std;

//typedef struct
//{
//	int i, j;  //方块位置
//	int pre;//本路径中上一个方块的下标
//}Box;       //方块下标
//
//typedef struct
//{
//	Box data[MaxSize];
//	int front, rear; 
//}QuType;   //顺序队类型

const int M = 8, N = 8;
int mg[M + 2][N + 2] =
{
	{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
};

int mg2[M + 2][N + 2] =
{
	{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
};

int main()
{

	if (!mgpath(1, 1, M, N))
	{
		cout << "该迷宫无解！" << endl;
	}
	PathType *path;
	path = (PathType*)malloc(sizeof(PathType));
	path->length = 0;
	mgpath2(1, 1, M, N, *path);
	return 1;
}

void mgpath2(int xi, int yi, int xe, int ye, PathType path)
{
	//求解迷宫路径为(xi,yi)->(xe,ye)
	int di, k, i, j;
	static int count = 0;
	if (xi == xe && yi == ye)
	{
		path.data[path.length].i = xi;
		path.data[path.length].j = yi;
		path.length++;
		cout << "迷宫路径" << (++count) << "如下：" << endl;
		for (k = 0; k < path.length; k++)
			cout << "(" << path.data[k].i << "," << path.data[k].j << ")";
		cout << endl;
	}
	else
	{
		if (mg2[xi][yi] == 0)//(xi,yi)是一个可走方块
		{
			di = 0;
			while (di < 4)
			{
				path.data[path.length].i = xi;//将(xi,yi)添加到path中
				path.data[path.length].j = yi;
				path.length++;
				switch (di)
				{
				case 0:i = xi - 1; j = yi; break;
				case 1:i = xi; j = yi + 1; break;
				case 2:i = xi + 1; j = yi; break;
				case 3:i = xi; j = yi - 1; break;
				default:
					break;
				}
				mg2[xi][yi] = -1;//(xi,yi)不可走
				mgpath2(i, j, xe, ye, path);
				mg2[xi][yi] = 0;//(xi,yi)恢复可走
				path.length--;//回退一个方块
				di++;//继续处理下一个方块
			}
		}
	}
}

bool mgpath(int xi, int yi, int xe, int ye)//搜索路径（xi,yi)->(xe,ye)
{
	Box e;
	int i, j, di, i1, j1;
	QuType *qu;//定义顺序队指针
	InitQueue(qu);
	e.i = xi; e.j = yi; e.pre = -1;
	enQueue(qu, e);//(xi,yi)进队
	mg[xi][yi] = -1;
	while (!QueueEmpty(qu))
	{
		deQueue(qu, e);
		//qu->pop();
		i = e.i; j = e.j;
		if (i == xe && j == ye)//找到出口，输出路径
		{
			print(qu, qu->front);
			DestroyQueue(qu);
			return true;
		}
		for (di = 0; di < 4; di++)//循环扫描每一个方位，把每一个可走方块插入队列
		{
			switch (di)
			{
			case 0: i1 = i - 1; j1 = j; break;
			case 1: i1 = i; j1 = j + 1; break;
			case 2: i1 = i + 1; j1 = j; break;
			case 3: i1 = i; j1 = j - 1; break;
			}
			if (mg[i1][j1] == 0)
			{
				e.i = i1; e.j = j1;
				e.pre = qu->front;//指向路径中上一个方块下标
				enQueue(qu, e);//(i1,j1)进队
				mg[i1][j1] = -1;//避免重复搜索
			}
		}
	}
	DestroyQueue(qu);//销毁队列
	return false;
}

void print(QuType *qu, int front)
{
	int k = front, j, ns = 0;
	cout << endl;
	do
	{
		j = k;
		k = qu->data[k].pre;
		qu->data[j].pre=-1;
	}while (k != 0);
	cout << "一条迷宫路径如下：" << endl;
	k = 0;
	while (k < MaxSize)
	{
		if (qu->data[k].pre==-1)
		{
			ns++;
			cout << "  ("<<qu->data[k].i<<","<<qu->data[k].j<<")";
			if (ns % 5 == 0)cout << endl;
		}
		k++;
	}
	cout << endl;
}

//有关队列的操作
//初始化
void InitQueue(QuType *&q)
{
	q = (QuType*)malloc(sizeof(QuType));
	q->front = q->rear = -1;
}
//销毁队列
void DestroyQueue(QuType *&q)
{
	free(q);
}
//判断队列是否为空
bool QueueEmpty(QuType *q)
{
	return (q->front == q->rear);
}
//进队列
bool enQueue(QuType *&q, Box e)
{
	if (q->rear == MaxSize - 1)
	{
		return false;
	}
	q->rear++;
	q->data[q->rear] = e;
	return true;
}
//出队列
bool deQueue(QuType *&q, Box &e)
{
	if (q->front == q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}