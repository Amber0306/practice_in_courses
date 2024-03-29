// DataPro5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;
//已知一棵二叉树采用二叉链表存储，对该二叉树实现先序遍历的递归算法和非递归算法
//二叉树数据自动生成

int main()
{
	BTNode *b, *p, *lp, *rp;
	const char * ch = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
	CreateBTree(b, ch);//创建二叉树
	DisplayBTree(b);
	cout << endl;
	//递归算法
	PreOrder(b); cout << endl;
	//非递归算法
	PreOrder1(b);
	//销毁
	DestroyBTree(b);
	return 1;
}

//递归调用
void PreOrder(BTNode *b)
{
	if (b != NULL)
	{
		cout << b->data;
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

//非递归调用
void PreOrder1(BTNode *b)
{
	BTNode *St[MaxSize], *p;
	int top = -1;
	if (b != NULL)
	{
		top++;
		St[top] = b;//根结点进栈
		while (top > -1)//栈不为空时退出循环
		{
			p = St[top];
			top--;
			cout << p->data;
			if (p->rchild != NULL)//有有孩子，进栈
			{
				top++;
				St[top] = p->rchild;
			}
			if (p->lchild != NULL)//有左孩子，进栈
			{
				top++;
				St[top] = p->lchild;
			}
		}
		cout << endl;
	}
}

