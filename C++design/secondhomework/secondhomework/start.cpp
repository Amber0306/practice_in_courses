// secondhomework.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<fstream>
using namespace std;

extern int G;
extern int g;
void p2dispG()
{
	G = 22;
	cout << "in p2 G= " << G << endl;
}
void p2dispg()
{
	g = 33;
	cout << "in p2 g= " << g << endl;
}

template <class T>//模板函数

T Reverser(T Val)
{
	char*p = (char*)&Val;
	for (int i = 0; i < sizeof(Val) / 2; i++)
	{
		char c = p[i];
		p[i] = p[sizeof(Val) - i - 1];
		p[sizeof(Val) - i - 1] = c;
	}
	return Val;
}

template <class T>//模板函数
void Bit(T dVal, char*pArray)
{
	char *pVal = (char*)&dVal;
	
	for (int i = sizeof(T) - 1; i >= 0; i--)
	{
		int k = (int)(pVal[sizeof(T) - 1 - i]);
		int j = 0;
		for (int j = 0; j < 8; j++)
		{
			int x = 1 << j;
			int y = x & k;
			char z = y >> j;
			int b = 8 * (i + 1) - j - 1;
			pArray[b] = z+'\0';
				

				
			cout << pArray << endl;
		}
		/*j++;
		pArray[8*sizeof(T)] = '\0';
		cout << pArray << endl;*/
	}
	cout << pArray << endl;
}
//此处有错误，未知
template <class T>//模板函数
CStu* Sort(CStu* head)
{
	CStu* f = NULL;
	CStu* t = NULL;
	CStu* max;
	CStu* maxbf = NULL;
	CStu* p;
	CStu* q = head->next;

	while (q != NULL)
	{
		for (p = q, max = q; p->next != NULL; p = p->next)
		{
			if (0 > strcmp(p->next->T, max->T))
			{
				maxbf = p;
				max = p->next;
			}
		}

		if (f == NULL)
		{
			f = max;
			t = max;
		}
		else
		{
			t->next = max;
			t = max;
		}

		if (max == q)
		{
			q = q->next;
		}
		else
		{
			maxbf->next = max->next;
		}
	}
	t->next = NULL;
	head->next = f;
	return head;
}



int main()
{   /*
	int X = Reverser(1834);
	int Y = Reverser(X);
	cout << X << '\t' << Y << endl;
	*/
	/*
	int a = 1093;
	int b = Shifting(a);
	int c = Shifting(b);
	cout << a << '\t' << c << endl;
	*/

	//char a = 1;
	//char Array[20];
	//Bit<char>(a, Array);


	//int A[3][4] = { 11,12,13,14,21,22,23,24,31,32,33,34 };
	//int B[4][3];
	//int col = 3; int row = 4;
	//Transposition(A, col, row);

	/*int A[4][4] = { 11,12,13,14,21,22,23,24,31,32,33,34 };
	int col = 3; int row = 4;
	Transposition1(A, col, row);*/

	/*int p1_1();  p1_1();
	int p1_2();  p1_2();
	int p1_3();  p1_3();

	int p2_1();  p2_1();
	int p2_2();  p2_2();
	int p2_3();  p2_3();
	int p2_4();  p2_4();
	int p2_5();  p2_5();
	int p2_6();  p2_6();
	int p2_7();  p2_7();
	int p2_8();  p2_8();
	int p2_9();  p2_9();
	int p2_10();  p2_10();
	int p2_11();  p2_11();
	int p2_12();  p2_12();
	int p2_13();  p2_13();
	int p2_14();  p2_14();
	int p2_15();  p2_15();
	int p2_16();  p2_16();
	int p2_17();  p2_17();
	int p2_18();  p2_18();
	int p2_19();  p2_19();
	
	int p3_1();  p3_1();
	int p3_2();  p3_2();
	int p3_3();  p3_3();
	int p3_4();  p3_4();
	int p3_5();  p3_5();
	int p3_7();  p3_7();
	int p3_8();  p3_8();
	int p3_9();  p3_9();
	int p3_10();  p3_10();
	int p3_11();  p3_11();
	int p3_12();  p3_12();
	int p3_13();  p3_13();
	int p3_14();  p3_14();

	int p4_1();  p4_1();
	int p4_2();  p4_2();
	int p4_3();  p4_3();
	int p4_4();  p4_4();
	int p4_5();  p4_5();
	int p4_6();  p4_6();

	int p5_1();  p5_1();
	int p5_2();  p5_2();
	int p5_3();  p5_3();
	int p5_4();  p5_4();
	int p5_5();  p5_5();
	int p5_6();  p5_6();
	int p5_7();  p5_7();
	int p5_8();  p5_8();
	int p5_9();  p5_9();
	int p5_10();  p5_10();
	int p5_11();  p5_11();
	int p5_12();  p5_12();

	int p6_1();  p6_1();
	int p6_2();  p6_2();
	int p6_3();  p6_3();
	int p6_4();  p6_4();
	int p6_5();  p6_5();
	int p6_6();  p6_6();
	int p6_7();  p6_7();

	int p7_1();  p7_1();
	int p7_2();  p7_2();
	int p7_3();  p7_3();
	int p7_4();  p7_4();
	int p7_5();  p7_5();
	int p7_6();  p7_6();
	int p7_7();  p7_7();
	int p7_8();  p7_8();
	int p7_9();  p7_9();
	int p7_10();  p7_10();
*/


	return 0;
};

