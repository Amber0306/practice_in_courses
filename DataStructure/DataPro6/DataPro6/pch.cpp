// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "pch.h"

// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。
#include<iostream>
using namespace std;

void swap(Rectype &x, Rectype &y)
{
	Rectype tmp = x;
	x = y;
	y = tmp;
}

//创建顺序表
void CreateList(Rectype R[], KeyType keys[], int n)
{
	for (int i = 0; i < n; i++)
	{
		R[i].key = keys[i];
	}
}

//输出顺序表
void DisplayList(Rectype R[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << R[i].key << ", ";
	}
	cout << endl;
}
