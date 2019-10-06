#include "stdafx.h"
#include <iostream>
using namespace std;

float ReverseFloat(float Val)
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

double ReverseDouble(double Val)
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

int ReverseInt(int Val)
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

short ReverseShort(short Val)
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



int Shifting(int a)
{
	int b = ((a >> 24) & 0xFF) | ((a >> 8) & 0xFF00) |
		((a << 8) & 0xFF0000) | ((a << 24) & 0xFF000000);
	return b;
}


void Transposition(int A[3][4], int col, int row)
{
	int i; int j;
	int B[4][3];
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			B[j][i] = A[i][j];
		}
	}
	int k; int n;
	for (k= 0; k < col; k++)
	{
		for (n = 0; n < row; n++)
		{
			cout << B[k][n]<<" ";
		}
		cout << endl;
	}
	
}

void Transposition1(int A[][4], int col, int row)
{
	int i; int j;
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			cout << A[i][j]<<"  ";
		}
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < col ; i++)
	{
		for (j = i; j < row; j++)
		{
			int temp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cout << A[i][j] << '\t';
		}
		cout << endl;
	}
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
			pArray[b] = z + '\0';



			cout << pArray << endl;
		}
		/*j++;
		pArray[8*sizeof(T)] = '\0';
		cout << pArray << endl;*/
	}
	cout << pArray << endl;
}