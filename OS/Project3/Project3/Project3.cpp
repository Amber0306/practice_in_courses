#include "pch.h"
#include <iostream>
#include <string>
#define N 20
using namespace std;

int area[8][8];//表示位示图
string locate[8][8];//对应位置的作业名


int main()
{
	//初始化
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			area[i][j] = 0;//初始都为空闲
		}
	}
	//接收选择
	int choice;
	while (true)
	{
		cout << "退出请按0，分配外存请按1，回收外存请按2，查看位示图请按3：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:exit(0);
		case 1:
			allocate(); break;
		case 2:
			reclaim(); break;
		case 3:
			print(); break;
		default:
			cout << "错误，请重新选择！" << endl;
		}
	}
}


int allocate()
{
	int i, j;//遍历位示图
	int num = 0;
	//获取待分配的大小

	string name;
	cout << "请输入作业名字:" << endl;
	cin >> name;

	int need;
	cout << "请输入需要分配的外存大小：" << endl;
	cin >> need;

	//获得磁盘剩余可用容量大小
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (area[i][j] == 0)
				num++;
		}
	}
	//分配外存
	if (need > num)
	{
		cout << "磁盘空间不够，分配失败！" << endl;
	}
	else
	{

		cout << "硬盘分配成功！" << endl;
		cout << "分配的物理地址为：" << endl;
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				if (need <= 0)
					break;//当所需要的空间都分配完毕时退出循环
				if (area[i][j] == 0)
				{
					area[i][j] = 1;
					locate[i][j] = name;
					cout << "第" << i << "柱面" << "      " << "第" << j / 4 << "磁道" << "      "
						<< "第" << j % 4 << "物理记录" << endl;
					need--;
				}
			}
		}
		return 0;//正确分配后退出
	}
}

	void reclaim()
 {
	int i,j;
	int w = 0;
	string name;
	cout << "请输入需要回收的作业名：";
	cin >> name;
	for (i = 0; i <8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (locate[i][j] == name)
			{
				area[i][j] = 0;
				locate[i][j] = "#";
				w++;
				cout << "字节号，位数：" << i << "," << j << endl;
			}
		}
	}
	if (w == 0)
	{
		cout << "该作业不存在!" << endl;
	}


	//int i, j;//位示图二维
	//int cylinder;//柱面号
	//int track;//磁道号
	//int record;//物理记录号
	//cout << "输入需要回收的物理地址：" << endl;
	//cout << "柱面号（0-7）：";
	//cin >> cylinder;
	//cout << "磁道号（0-1）：";
	//cin >> track;
	//cout << "物理记录号（0-3）：";
	//cin >> record;
	////计算出在位示图中的位置
	//i = cylinder;
	//j = track * 4 + record;
	////修改位示图
	//area[i][j] = 0;
	//cout << "位示图中（" << i << "，" << j << ")";
	//cout << "回收成功！" << endl;
}

//打印位示图
void print()
{
	cout << "-磁盘存储位示图-" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << area[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}