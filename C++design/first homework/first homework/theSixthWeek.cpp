#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;


//×Ö·û´®³¤¶È
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

//×Ö·û´®·­×ª
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

//×Ö·û´®Á¬½Ó
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

//×Ö·û´®±È½Ï
int MyStrCompare(char*pstr1,char*pstr2)
{
	int nLen = StrLen(pstr2);
	int i = 0; 
	int bol = 0;
	while (i <= nLen+1 && bol != 1 && bol!=-1 )
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

//×Ö·û´®¿½±´
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

//½«×Ö·û´®ÖÐµÄÊý×ÖÈ¥µô£¬×ÖÄ¸±£Áô
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