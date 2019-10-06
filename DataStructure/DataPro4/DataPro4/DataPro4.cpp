// DataPro4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;
/*
 *给定一个序列如（12，1，23，35，21，60，90，60，10，15，25，26）
 *根据数据构造出哈夫曼树，并输出哈夫曼编码
*/

int main()
{
	int n = 12;
	int  nums[12] = {12,1,23,35,21,60,90,60,10,15,25,26};
	HTNode ht[M];
	HCode hcd[N];
	for (int i = 0; i < n; i++)
	{
		ht[i].data = nums[i];
		ht[i].weight = nums[i];//使权重和结点值相同
	}
	CreateHT(ht, n);
	CreateHCode(ht, hcd, n);
	DisplayHCode(ht, hcd, n);
	return 1;
}

void CreateHT(HTNode ht[], int n0)//n0个叶子结点
{
	int i, k, lnode, rnode;
	int min1, min2;//表示权
	for (i = 0; i < 2 * n0 - 1; i++)//共有2*n0-1个结点
	{
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}
	for (i = n0; i <= 2 * n0 - 2; i++)//构造哈夫曼树的n0-1个结点
	{
		min1 = min2 = 32767;
		lnode = rnode = -1;
		for (k = 0; k <= i - 1; k++)
		{
			if (ht[k].parent == -1)
			{
				if (ht[k].weight < min1)
				{
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].weight < min2)
				{
					min2 = ht[k].weight;
					rnode = k;
				}
			}
			ht[i].weight = ht[lnode].weight + ht[rnode].weight;
			ht[i].lchild = lnode;
			ht[i].rchild = rnode;//ht[i]作为双亲结点
			ht[lnode].parent = i;
			ht[rnode].parent = i;
		}
	}
}

void CreateHCode(HTNode ht[], HCode hcd[], int n0)
{
	int i, f, c;
	HCode hc;
	for (i = 0; i < n0; i++)
	{
		hc.start = n0;
		c = i;
		f = ht[i].parent;
		while (f != -1)//循环直到无双亲结点，即根结点
		{
			if (ht[f].lchild == c)//当前结点是双亲结点的左孩子
			{
				hc.cd[hc.start--] = '0';
			}
			else
			{
				hc.cd[hc.start--] = '1';
			}
			c = f; f = ht[f].parent;//再对双亲结点进行同样的操作
		}
		hc.start++;
		hcd[i] = hc;
	}
}
void DisplayHCode(HTNode ht[], HCode hcd[], int n)//输出哈夫曼编码
{
	int i,k;
	int sum = 0, m = 0, j;
	cout << "输出哈夫曼编码：" << endl;
	for (i = 0; i < n; i++)
	{
		j = 0;
		cout << ht[i].data << "     ";
		j++;
		for (k = hcd[i].start; k <= n; k++)
		{
			cout << hcd[i].cd[k];
			j++;
		}
		m += ht[i].weight;
		sum += ht[i].weight*j;
		cout << endl;
	}
	
}