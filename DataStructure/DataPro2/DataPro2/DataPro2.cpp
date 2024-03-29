// DataPro2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#define MaxSize 100

using namespace std;

typedef char ElemType;
typedef struct linknode
{
	ElemType data;
	struct linknode *next;
}LinkStNode;                                     //栈链结点类型

bool Match(char exp[], int n);

int main()
{
	char a[] = "(13+2)(()";
	char b[] = "(1=(1)((3)))";
	bool IsMatch1 = Match(a, 9);
	bool IsMatch2 = Match(b, 13);
	cout << a << "  match or not:  " 
		<< IsMatch1 << endl;
	cout << b << "  match or not:  "
		<< IsMatch2 << endl;
}
//初始化栈
void InitStack(LinkStNode *&s)
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
void DestroyStack(LinkStNode *&s)                     //销毁栈
{                                                                            
	LinkStNode *pre = s, *p = s->next;                  //pre指向头结点，p指向首结点
	while (p != NULL)                                              //循环到p为空  
	{
		free(pre);
		pre = p;                                                           //pre和p同步后移
		p = pre->next;
	}
	free(pre);
}
//判断栈是否为空
bool StackEmpty(LinkStNode *s)
{
	return (s->next == NULL);
}

//入栈操作
void Push(LinkStNode *&s, ElemType e)
{
	LinkStNode *p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
//出栈操作
bool Pop(LinkStNode *&s, ElemType &e)
{
	LinkStNode *p;
	if (s->next == NULL)
	{
		return false;
	}
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}
//取栈顶元素
bool GetTop(LinkStNode *s, ElemType &e)
{
	if (s->next == NULL)
	{
		return false;
	}
	e = s->next->data;
	return true;
}
//匹配
bool Match(char exp[], int n)
{
	int i = 0; char e;
	bool match = true;
	LinkStNode *st;
	InitStack(st);
	while (i < n && match)
	{
		if (exp[i] == '(')
		{
			Push(st, exp[i]);
		}
		else if (exp[i] == ')')
		{
			if (GetTop(st, e) == true)
			{
				if (e != '(')
				{
					match = false;
				}
				else
				{
					Pop(st, e);
				}
			}
			else 
			{
				match = false;
			}
		}
		i++;
	}
	if (!StackEmpty(st))
	{
		match = false;
	}
	DestroyStack(st);
	return match;
}