#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;

//����a,b,c��ֵ
void fun1(int a, int b, int c)
{
	if (a >= b)
	{
		a = a; b = b;
		if (b >= c)
		{
			b = b; c = c;
		}
		else {
			b = c + b; c = b - c; b = b - c;
		}
	}
	else {
		b = a + b; a = b - a; b = b - a;
		if (b >= c)
		{
			b = b; c = c;
		}
		else {
			b = c + b; c = b - c; b = b - c;
		}
	}
	if (a >= b)
	{
		a = a; b = b;
	}
	else {
		b = a + b; a = b - a; b = b - a;
	}
	cout << a << '\t' << b << '\t' << c << endl;
}

//��1+1/2+1/3+������+1/10��ֵ
float fun2()
{
	float sum1 = 0; float i;
	for (i = 1; i <= 10; i++)
	{
		sum1 = sum1 + 1 / i;
	}
	cout << "the sum is " << sum1 << endl;
	return sum1;
}

//��1-1/2+1/3-������-1/10��ֵ����ĸΪż������Ϊ����
float fun3()
{
	float sum2 = 0; int i;
	for (i = 1; i <= 10; i++)
	{
		float j = i;
		if( i % 2 == 1)
		{
			sum2 = sum2 + 1 / j;
		}
		else {
			sum2 = sum2 - 1 / j;
		}
		int i = (int)j;
	}
	cout << "the sum2 is " << sum2 << endl;
	return sum2;
}

//��0/1+1/2+2/3+������+9/10��ֵ
void fun4()
{
	float sum3 = 0.0; float i = 1;
	for (float i = 1; i <= 10; i++)
	{
		sum3 = sum3 + (i - 1) / i;
		cout << "the sum3 is " << sum3 << endl;
	}
}

//����žų˷���
void fun5()
{
	int i = 9; int j = 1;
	for (i = 9; i >= 1; i--)
	{
		for (j = 1; j < i; j++)
		{
			int k = i * j;
			cout << j << "*" << i << "=" << k;
			cout << '\t';
		}
		cout << endl;
	}
}

//����ͼ�Σ������ǣ����£�
void fun6()
{
	int i = 1; int j = 1; int k = 9;
	for (i = 1; i <= 10; i++)
	{
		for (k = 0; k <= i; k++)
		{
			cout << " ";
		}
		for (j = 0; j < (2*(10-i)-1); j++)
		{
			cout << '*';
		}
		cout << endl;
	}
}


//����ͼ�Σ������ǣ����ϣ�
void fun7()
{
	int i = 0; int j = 0; int k = 0;
	for (i = 0; i <= 10; i++)
	{
		for (k = 0; k <=10- i; k++)
		{
			cout << " ";
		}
		for (j = 0; j < 2 * i - 1; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
}

//����ͼ�Σ���������
void fun8()
{
	int i = 19; int j = 0; int k = 0;
	for (i = 1; i <= 20; i++)
	{
		for (k = 0; k <= i; k++)
		{
			cout << " ";
		}
		for (j = 0; j < 20-i; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
}

