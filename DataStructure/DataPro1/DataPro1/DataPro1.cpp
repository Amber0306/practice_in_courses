// DataPro1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	Node* next;//指向后继结点

	/*Node();
	~Node()*/;
}LinkNode;
void CreateList(LinkNode * &L, ElemType a[], int n);
void InitList(LinkNode *L);
void DispList(LinkNode *L);
void ListInsert(LinkNode*&L, ElemType e);
void UnionList(LinkNode*LA, LinkNode*LB, LinkNode*&LC);
void sort(LinkNode*&L);

int main()
{
	int a[] = { 12,1,23,25,21,60 };
	int b[] = { 90,60,10,15,25,56 };
	int na = 6;
	int nb = 6;
	LinkNode  *LA, *LB;

	CreateList(*&LA, a, na);
	CreateList(*&LB, b, nb);
	cout << "两个链表分别为：" << endl;

	DispList(LA);
	DispList(LB);

	sort(*&LA);
	sort(*&LB);

	LinkNode *LC;
	UnionList(LA, LB, *&LC);

	cout << "合并后链表为：" << endl;
	DispList(LC);
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

//建立链表
	void CreateList(LinkNode * &L, ElemType a[], int n)
	{
	LinkNode *s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

//初始化
void InitList(LinkNode *L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

//显示
void DispList(LinkNode *L)
{
	LinkNode *p = L->next;
	while (p != NULL)
	{
		cout << p->data<<"  ";
		p = p->next;
	}
	cout << endl;
}

//插入
void ListInsert(LinkNode*&L, ElemType e)
{
	LinkNode *pre = L, *p;
	while (pre->next != NULL && pre->next->data < e)
	{
		pre = pre->next;
	}
	p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = e;
	p->next = pre->next;
	pre->next = p;
}

//合并
void UnionList(LinkNode*LA, LinkNode*LB, LinkNode*&LC)
{
	LinkNode* pa = LA->next, *pb = LB->next;
	LinkNode *r, *s;
	LC = (LinkNode*)malloc(sizeof(LinkNode));
	r = LC;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data < pb->data)
		{
			s = (LinkNode*)malloc(sizeof(LinkNode));
			s->data = pa->data;
			r->next = s; r = s;
			pa = pa->next;
		}
		else
		{
			s = (LinkNode*)malloc(sizeof(LinkNode));
			s->data = pb->data;
			r->next = s; r = s;
			pb = pb->next;
		}
	}
	while (pa != NULL)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = pa->data;
		r->next = s; r = s;
		pa = pa->next;
	}
	while (pb != NULL)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = pb->data;
		r->next = s; r = s;
		pb = pb->next;
	}
	r->next = NULL;
}

//排序
void sort(LinkNode*&L)
{
	LinkNode *p, *pre, *q;
	p = L->next->next;
	L->next->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}