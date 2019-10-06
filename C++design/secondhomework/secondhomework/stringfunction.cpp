#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;




//字符串长度
int StrLen(char*pstr)
{
	char*pHeader = pstr;
	while ('\0' != *pstr)
	{
		pstr++;
	}
	int nLen = pstr - pHeader;
	return nLen;
}

//字符串翻转
void MyStrReverse(char*pstr)
{
	char pstr0[20];
	int i;
	int nLen = StrLen(pstr);
	for (i = 0; '\0' != pstr[i]; i++)
	{
		pstr0[i] = pstr[nLen - 1 - i];
	}
	i++;
	pstr0[i] = '\0';
	cout << pstr0 << endl;
}

//字符串连接
void MyStrCat(char*pstr1, char*pstr2)
{
	char pstr3[10];
	int i, j;
	for (i = 0; pstr1[i] != '\0'; i++)
	{
		pstr3[i] = pstr1[i];
	}
	for (j = 0; pstr2[j] != '\0'; j++, i++)
	{
		pstr3[i] = pstr2[j];
	}
	i++;
	pstr3[i] = '\0';
	cout << pstr3 << endl;

}

//字符串比较
int MyStrCompare(char*pstr1, char*pstr2)
{
	int nLen = StrLen(pstr2);
	int i = 0;
	int bol = 0;
	while (i <= nLen + 1 && bol != 1 && bol != -1)
	{
		int asc1 = pstr1[i];
		int asc2 = pstr2[i];
		if (asc1 > asc2)
		{
			bol = 1;
		}
		else if (asc1 > asc2)
		{
			bol = -1;
		}
		else if (asc1 = asc2)
		{
			bol = 0;
			i++;
		}
	}
	cout << bol << endl;
	return bol;
}

//字符串拷贝
void MyStrCpy(char*pstr1, const char*pstr2)
{
	int i;
	for (i = 0; pstr2[i] != '\0'; i++)
	{
		pstr1[i] = pstr2[i];
	}
	i++;
	pstr1[i] = '\0';
	cout << pstr1 << endl;
}

//将字符串中的数字去掉，字母保留
void EraseDigital(char*pstr1)
{
	int i = 0; int j = 0;
	char pstr2[20];
	while ('\0' != pstr1[i])
	{
		int asc = (int)pstr1[i];

		if (asc >= 48 && asc <= 57)
		{
			pstr2[j] = pstr1[i];
			j++;
		}
		i++;
	}
	j++;
	pstr2[j] = '\0';
	cout << pstr2 << endl;
}

//数列排序
void exercise1()
{
	const int nCount = 11;
	int i = 0; int j = 0;
	int A[nCount] = { 29,98,43,63,22,73,45,11 };//声明一个数组
	for (i = 0; i < nCount - 1; i++)
	{
		for (j = nCount - 1; j >= 1; j--)
		{
			if (A[j] < A[j - 1])
			{
				int c;
				c = A[j];
				A[j] = A[j - 1];
				A[j - 1] = c;
			}

		}
		cout << A[i] << '\t';
	}
	cout << A[nCount - 1] << endl;
}