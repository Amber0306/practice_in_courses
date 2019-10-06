#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;



//��������
void exercise1()
{
	const int nCount = 11;
	int i = 0; int j = 0;
	int A[nCount] = { 29,98,43,63,22,73,45,11 };//����һ������
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

//��֪ĳ���µ�һ�������ڼ����Լ�������ж����죬���¸��µ�һ�������ڼ�
/*
0��ʾ�����죬6��ʾ��������
nWhatday��ʾ����µ�һ�������ڼ���
nDaysOfMonth��ʾ������ж����죻
���أ��¸��µ�һ�������ڼ���
*/
int GetNextMonthFirstDayIsWhatDay1(int  nWhatday, int nDaysOfMonth)
{
	int NextMonthFirstDay;
	int surplus = nDaysOfMonth % 7;
	if (nWhatday <= 3)
	{
		NextMonthFirstDay = nWhatday+ surplus;
	}
	else {
		NextMonthFirstDay = (nWhatday + surplus) - 7;
	}
	return NextMonthFirstDay;
}

//��ӡ����
int Canlender(int nWhatYear, int nWhichDay)
{
	int nYear;
	cin >> nYear;
	bool IsLeapYear = (nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0;
	int i = 28 + IsLeapYear;
	int n(0);
	int nMonths[12] = { 31,i,31,30,31,30,31,31,30,31,30,31 };
	for (int p = 0; p < 12; p++)
	{
		cout << p + 1 << "��" << endl;
		cout << "��" << '\t' << "һ" << '\t' << "��" << "\t" << "��" 
			<< '\t' << "��" << '\t' << "��" << '\t' << "��" << endl;
		if (p > 0)
		{
			n = n + nMonths[p - 1];
		}//����ÿ��������֮��
		int a = (nWhichDay + n % 7) % 7;//����ÿ����һ�������ڼ�
		for (int j = 0; j < a; j++)
		{
			cout << '\t';
		}
		int m = 0;
		for (int k = 1; k <= nMonths[p]; k++)
		{
			cout << k << "\t";
			if (k > 7 * m + 6 - a)
			{
				m += 1;
				cout << endl;
			}
		}//���һ���µ�����
		cout << endl;
	}
	return 0;
}


//1900��1��1��������һ  

int nyear(int year)//�ж���ƽ�꣬��������  
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		return 366;
	}
	else
	{
		return 365;
	}
}

int nmonth(int m, int y)  //������ݺ��·ݣ��ж���һ���µ�����  
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;
	else if (nyear(y) == 366 && m == 2)
		return 29;
	else if (nyear(y) == 365 && m == 2)
		return 28;
	else
		return 30;
}

int getDays(int year, int month)//������ݺ��·�ȷ����1900��1��1���ܹ�������  
{
	int i;
	int sum = 0;
	if (year > 1900)
	{
		for (i = 1900; i < year; i++)
		{
			sum += nyear(i);
		}
	}
	if (month > 1)
	{
		for (i = 1; i < month; i++)
		{
			sum += nmonth(i, year);
		}
	}
	return sum;     //�����ܹ�������  
}

int exercise3()
{
	int i, j, year, month, day, sum, daycount, cases = 1;

	while (cin >> year >> month)
	{
		sum = getDays(year, month);
		day = sum % 7;  //�������������µ�һ��ǰ����Ҫ�����ո񣻵���0�Ļ���ǰ��Ͳ���Ҫ�ո�  
		daycount = nmonth(month, year);//�������µ�����  
		cout << "Case " << cases++ << ": " << year << "��" << month << "��" << endl;
		cout << "Mon Tue Wed Thu Fri Sat Sun" << endl;
		for (i = 0; i<day % 7; i++)
			cout << "    ";  
		for (i = 1, j = day + 1; i <= daycount; i++, j++)
		{
			cout << setw(4) << setiosflags(ios::left) << i;
			if (j % 7 == 0)
			{
				cout << endl;
			}
		}
		cout << endl;
	}

	return 0;
}

