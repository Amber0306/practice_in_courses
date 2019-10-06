#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;

//整型变量的引用
void mySwap1(int & a, int & b)
{
	int c = a;
	a = b;
	b = c;
}
//整型变量的指针（仅改变变量的值不改变指针）
void mySwap2(int * pa, int * pb)
{
	int pc = *pa;
	*pa = *pb;
	*pb = pc;
}
//整型指针变量的引用（仅通过引用两变量指针来改变指针而不改变两变量的值，两变量指针交换）
void mySwap3(int * & pa, int * & pb)
{
	int * pc = pa;
	pa = pb;
	pb = pc;
}
//整型指针变量的指针（两变量只不改变，仅通过改变两变量指针的指针改变两变量的指针）
void mySwap4(int ** ppa, int ** ppb)
{
	int*pc = *ppa;
	*ppb = *ppa;
	*ppa = pc;
}
