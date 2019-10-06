
#include"stdafx.h"
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;


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
		NextMonthFirstDay = nWhatday + surplus;
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



//��ʱ����д���ѳ�����Ϊ�ο��Ĵ���
////��һ�ַ�������ʽ��ͬ������һ��
//enum Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
//enum Month { January = 1, February, March, April, May, June, July, August, September, October, November, December }m;
//void GiveInstructions(void);
//int GetYearFromUser(void);
//void PrintCalendar(int year);
//void PrintCalendarMonth(int month, int year);
//void IndentFirstLine(int weekday);
//int MonthDays(int month, int year);
//int FirstDayOfMonth(int month, int year);
//string MonthName(int month);
//bool IsLeapYear(int year);
///* Main program */
//int exercise2()
//{
//	int year;
//	GiveInstructions();
//	year = GetYearFromUser();
//	PrintCalendar(year);
//	return 0;
//}
///* Function prototypes */
///*
//* Function: GiveInstructions
//* Usage: GiveInstructions();
//* --------------------------
//* This procedure prints out instructions to the user.
//*/
//void GiveInstructions(void)
//{
//	cout << "This program display a calender for a full year.\nThe year must not be before 1900.\n";
//	cout << "which year?" << "  ";
//}
///*
//* Function: GetYearFromUser
//* Usage: year = GetYearFromUser();
//* --------------------------------
//* This function reads in a year from the user and returns
//* that value.  If the user enters a year before 1900, the
//* function gives the user another chance.
//*/
//int GetYearFromUser(void)
//{
//	int Year;
//	cin >> Year;
//	while (Year<1900)
//	{
//		cout << "The year must be at least 1900.which year?" << "  ";
//		cin >> Year;
//	}
//	cout << endl;
//	cout << endl;
//	return (Year);
//}
///*
//* Function: IsLeapYear
//* Usage: if (IsLeapYear(year)) . . .
//* ----------------------------------
//* This function returns TRUE if year is a leap year.
//*/
//bool IsLeapYear(int year)
//{
//	bool leapyear;
//	leapyear = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
//	return(leapyear);
//}
///*
//* Function: PrintCalendar
//* Usage: PrintCalendar(year);
//* ---------------------------
//* This procedure prints a calendar for an entire year.
//*/
//void PrintCalendar(int year)
//{
//	for (int i = 1; i <= 12; ++i)
//		PrintCalendarMonth(i, year);
//}
///*
//* Function: PrintCalendarMonth
//* Usage: PrintCalendarMonth(month, year);
//* ---------------------------------------
//* This procedure prints a calendar for the given month
//* and year.
//*/
//void PrintCalendarMonth(int month, int year)
//{
//	cout << setw(12) << MonthName(month) << setw(5) << year << endl;
//	cout << setw(3) << "Su" << setw(3) << "Mo" << setw(3) << "Tu" << setw(3) << "We" << setw(3) << "Th" << setw(3) << "Fr" << setw(3) << "Sa" << endl;
//	int m = (FirstDayOfMonth(month, year) + 7) % 7;
//	IndentFirstLine(m);
//	int i = 2;
//	while (i <= MonthDays(month, year))
//	{
//		if ((i + FirstDayOfMonth(month, year) - 1) % 7 == 0)
//		{
//			cout << endl;
//			cout << setw(3) << i;
//			i = i + 1;
//		}
//		else
//		{
//			cout << setw(3) << i;
//			i = i + 1;
//		}
//	}
//	cout << endl; cout << endl; cout << endl;
//}
///*
//* Function: IndentFirstLine
//* Usage: IndentFirstLine(weekday);
//* --------------------------------
//* This procedure indents the first line of the calendar
//* by printing enough blank spaces to get to the position
//* on the line corresponding to weekday.
//*/
//void IndentFirstLine(int m)
//{
//	cout << setw(3 + 3 * m) << 1;
//}
///*
//* Function: MonthDays
//* Usage: ndays = MonthDays(month, year);
//* --------------------------------------
//* MonthDays returns the number of days in the indicated
//* month and year.  The year is required to handle leap years.
//*/
//int MonthDays(int month, int year)
//{
//	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//		return(31);
//	if (month == 2)
//		if (IsLeapYear(year))
//			return(29);
//		else
//			return(28);
//	if (month == 4 || month == 6 || month == 9 || month == 11)
//		return(30);
//}
///*
//* Function: FirstDayOfMonth
//* Usage: weekday = FirstDayOfMonth(month, year);
//* ----------------------------------------------
//* This function returns the day of the week on which the
//* indicated month begins.  This program simply counts
//* forward from January 1, 1900, which was a Monday.
//*/
//int FirstDayOfMonth(int month, int year)
//{
//	int Alldays = 0, Yeardays, weekday, lastyear = 0, days = 0;
//	lastyear = year - 1;
//	while (lastyear >= 1900)
//	{
//		if (IsLeapYear(lastyear))
//		{
//			Yeardays = 366;
//			Alldays += Yeardays;
//			lastyear = lastyear - 1;
//		}
//		else
//		{
//			Yeardays = 365;
//			Alldays += Yeardays;
//			lastyear = lastyear - 1;
//		}
//	}
//	while (month >= 1)
//	{
//		days += MonthDays(month - 1, year);
//		month = month - 1;
//	}
//	weekday = (Alldays + days - 3) % 7;
//	return(weekday);
//}
///*
//* Function: MonthName
//* Usage: name = MonthName(month);
//* -------------------------------
//* MonthName converts a numeric month in the range 1-12
//* into the string name for that month.
//*/
//string MonthName(int month)
//{
//	switch (month)
//	{
//	case 1:return"January"; break;
//	case 2:return"February"; break;
//	case 3:return"Match"; break;
//	case 4:return"April"; break;
//	case 5:return"May"; break;
//	case 6:return"June"; break;
//	case 7:return"July"; break;
//	case 8:return"August"; break;
//	case 9:return"September"; break;
//	case 10:return"Octorber"; break;
//	case 11:return"November"; break;
//	case 12:return"December"; break;
//	}
//}
