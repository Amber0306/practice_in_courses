#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
	
	void fun1(int a, int b, int c);
	float fun2();
	float fun3();
	void fun4();
	void fun5();
	void fun6();
	void fun7();
	void fun8();

	void exercise1();
	

	
	int a; int b; int c;
	cin >> a >> b >> c;
	fun1(a, b, c);

	fun2();
	fun3();
	fun4();
	fun5();
	fun6();
	fun7();
	fun8();
	

	exercise1();
	int GetNextMonthFirstDayIsWhatDay1(int  nWhatday, int nDaysOfMonth);
	int  nWhatday = 4; int nDaysOfMonth = 31;
	GetNextMonthFirstDayIsWhatDay1(nWhatday, nDaysOfMonth);
	

	
	

	
	int exercise3();
	exercise3();
	

	
	int exercise2();
	exercise2();
	

	
	int way;
	cin >> way;
	
	int a(2); int b(7);
	int*pa = &a; int *pb = &b;
	int**ppa = &pa; int**ppb = &pb;
	if (way == 1)
	{
		//���ͱ�������
		void mySwap1(int & a, int & b);
		mySwap1(a, b);
		cout << a << '\t' << b << endl;
	}
	else if(way == 2)
	{
		//���ͱ���ָ��
		void mySwap2(int * pa, int * pb);
		mySwap2(&a, &b);
		cout << a << '\t' << b << endl;
	}
	else if(way == 3)
	{
		//���ͱ���ָ�������
		void mySwap3(int * & pa, int * & pb);
		mySwap3(pa, pb);
		cout << a << '\t' << b << endl;
	}
	else if(way == 4)
	{
		//���ͱ���ָ���ָ��
		void mySwap4(int ** ppa, int ** ppb);
		mySwap4(&pa, &pb);
		cout << a << '\t' << b << endl;
	}
	

	
	void MyStrReverse(char*pstr);
	char A[5] = "abcd";
	MyStrReverse(A);
	

	
	void MyStrCat(char*pstr1, char*pstr2);
	char str1[5] = "1234";
	char str2[5] = "abcd";
	
	MyStrCat(str1, str2);
	

    int MyStrCompare(char*pstr1, char*pstr2);
    char M[6] = "hello";
    char N[5] = "here";
    MyStrCompare(M,N);
	


	void MyStrCpy(char*pstr1, const char*pstr2);
	char S[20]; char T[4] = "abc";
	MyStrCpy(S, T);
	


	void EraseDigital(char*pstr1);
	char B[8] = "a97bd4c";
	EraseDigital(B);
	
	
	return 0;
	
}