// LEI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//按优先数调度算法实现处理器调度的程序
#include "pch.h"
#include <iostream>
#include "stdio.h"
#include "string.h"
using namespace std;

#define num 5//假定系统中进程个数为5

struct PCB
{
	char ID;//进程名
	int runtime;//要求运行时间
	int pri;//优先数
	char state; //状态，R-就绪，E-结束
};
struct PCB pcb[num];//定义进程控制块数组

void init()//PCB初始化子程序
{
	int i;
	for (i = 0; i < num; i++)
	{
		cout<<"PCB["<<i+1<<"]:ID pri runtime \n";//为每个进程任意指定pri和runtime
		cout << "Input ID:" << endl;
		cin >> pcb[i].ID;
		cout << "Input pri:" << endl;
		cin >> pcb[i].pri;
		cout << "Input runtime:" << endl;
		cin>>pcb[i].runtime;
		pcb[i].state = 'R';//进程初始状态均为就绪
		getchar();//接收回车符
	}
}


int max()//确定最大优先级进程子程序
{
	int max = -100;//max为最大优先数，初始化为-100
	int i;
	int key;
	for (i = 0; i < num; i++)
	{
		if (pcb[i].state == 'r')//r为辅助状态标志，表示正在运行
			return -1;//返回-1
		else
			if (max < pcb[i].pri&&pcb[i].state == 'R')//从就绪进程中选取优先数最大的进程
			{
				max = pcb[i].pri;//最大优先数
				key = i;
			}
	}
	if (pcb[key].state == 'E')//具有最大优先数的进程若已运行完毕
		return -1;//则返回-1
	else//否则
		return key;//将key作为返回值返回
}

void show()//显示子程序
{
	int i;
	cout << "\nID            pri             runtime                 state\n";
	cout << "-------------------------------------------------\n";
	for (i = 0; i < num; i++)//依次显示每个进程的名、优先数、要求运行时间和状态
	{
		cout << pcb[i].ID <<'\t' << '\t' <<pcb[i].pri << '\t' << '\t' << pcb[i].runtime << '\t' << '\t' << pcb[i].state << endl;
	}
	cout<<" press any key to continue...\n";
}

void run()//进程运行子程序
{
	int i, j;
	int t = 0;//t为运行次数
	for (j = 0; j < num; j++)
	{
		t += pcb[j].runtime;
	}//运行次数即为各个进程运行时间之和
	cout << "\nbefore run,the conditon is:\n";
	show(); //调用show()子程序显示运行前PCB的情况
	getchar();//等待输入回车符

	for (j = 0; j < t; j++)
	{
		while (max() != -1)//具有最大优先数的进程没有运行完，让其运行
		{
			pcb[max()].state = 'r';//将其状态置为r，表示其正在运行
		}
		for (i = 0; i < num; i++)
		{
			if (pcb[i].state == 'r')
			{
				pcb[i].pri -= 1;//将当前运行进程的优先数减1
				pcb[i].runtime--;//要求运行时间减1
				{
					if (pcb[i].runtime == 0)
						pcb[i].state = 'E';//运行完则将该进程状态置为结束
					else
						pcb[i].state = 'R';//未运行完将其状态置为就绪
				}

				show();//显示每次运行后各PCB的情况
				getchar();//等待回车进入下一次运行
			}
		}
	}
}

void main()//按动态优先数调度主程序
{
	init();//初始化各个进程PCB
	run();//进程调度模拟  
}




