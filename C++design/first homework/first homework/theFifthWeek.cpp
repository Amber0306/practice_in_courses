#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;

//���ͱ���������
void mySwap1(int & a, int & b)
{
	int c = a;
	a = b;
	b = c;
}
//���ͱ�����ָ�루���ı������ֵ���ı�ָ�룩
void mySwap2(int * pa, int * pb)
{
	int pc = *pa;
	*pa = *pb;
	*pb = pc;
}
//����ָ����������ã���ͨ������������ָ�����ı�ָ������ı���������ֵ��������ָ�뽻����
void mySwap3(int * & pa, int * & pb)
{
	int * pc = pa;
	pa = pb;
	pb = pc;
}
//����ָ�������ָ�루������ֻ���ı䣬��ͨ���ı�������ָ���ָ��ı���������ָ�룩
void mySwap4(int ** ppa, int ** ppb)
{
	int*pc = *ppa;
	*ppb = *ppa;
	*ppa = pc;
}
