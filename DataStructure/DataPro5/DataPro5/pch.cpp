// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的
#include "pch.h"
// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。

#include<iostream>
using namespace std;

//创建二叉树
void CreateBTree(BTNode * &b, const char *str)
{
	BTNode *St[MaxSize];
	BTNode * p;
	p = NULL;
	int top = -1, k, j = 0; char ch;
	b = NULL;//初始为空
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':
			top++; St[top] = p; k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
			{
				b = p;
			}
			else
			{
				switch(k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++; ch = str[j];
	}
}

void DisplayBTree(BTNode *b)
{
	if (b != NULL)
	{
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL)
		{
			cout << "(";
			DisplayBTree(b->lchild);
			if (b->rchild != NULL)cout << ",";
			DisplayBTree(b->rchild);
			cout << ")";
		}
	}
}

void DestroyBTree(BTNode * &b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}