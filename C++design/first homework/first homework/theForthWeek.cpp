#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;



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

//已知某个月的一号是星期几，以及这个月有多少天，求下个月的一号是星期几
/*
0表示星期天，6表示星期六；
nWhatday表示这个月的一号是星期几；
nDaysOfMonth表示这个月有多少天；
返回：下个月的一号是星期几；
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

//打印日历
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
		cout << p + 1 << "月" << endl;
		cout << "日" << '\t' << "一" << '\t' << "二" << "\t" << "三" 
			<< '\t' << "四" << '\t' << "五" << '\t' << "六" << endl;
		if (p > 0)
		{
			n = n + nMonths[p - 1];
		}//计算每个月天数之和
		int a = (nWhichDay + n % 7) % 7;//计算每个月一号是星期几
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
		}//打出一个月的日历
		cout << endl;
	}
	return 0;
}


//1900年1月1号是星期一  

int nyear(int year)//判断是平年，还是润年  
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

int nmonth(int m, int y)  //根据年份和月份，判断那一个月的天数  
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

int getDays(int year, int month)//输入年份和月份确定到1900年1月1日总共多少天  
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
	return sum;     //返回总共多少天  
}

int exercise3()
{
	int i, j, year, month, day, sum, daycount, cases = 1;

	while (cin >> year >> month)
	{
		sum = getDays(year, month);
		day = sum % 7;  //这里算出来这个月的一号前面需要几个空格；等于0的话，前面就不需要空格  
		daycount = nmonth(month, year);//算出这个月的天数  
		cout << "Case " << cases++ << ": " << year << "年" << month << "月" << endl;
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

