#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>

//这个是从网上截取作为参考提供思路的文件

using namespace std;
enum Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
enum Month { January = 1, February, March, April, May, June, July, August, September, October, November, December }m;
void GiveInstructions(void);
int GetYearFromUser(void);
void PrintCalendar(int year);
void PrintCalendarMonth(int month, int year);
void IndentFirstLine(int weekday);
int MonthDays(int month, int year);
int FirstDayOfMonth(int month, int year);
string MonthName(int month);
bool IsLeapYear(int year);
/* Main program */
int exercise2()
{
	int year;
	GiveInstructions();
	year = GetYearFromUser();
	PrintCalendar(year);
	return 0;
}
/* Function prototypes */
/*
* Function: GiveInstructions
* Usage: GiveInstructions();
* --------------------------
* This procedure prints out instructions to the user.
*/
void GiveInstructions(void)
{
	cout << "This program display a calender for a full year.\nThe year must not be before 1900.\n";
	cout << "which year?" << "  ";
}
/*
* Function: GetYearFromUser
* Usage: year = GetYearFromUser();
* --------------------------------
* This function reads in a year from the user and returns
* that value.  If the user enters a year before 1900, the
* function gives the user another chance.
*/
int GetYearFromUser(void)
{
	int Year;
	cin >> Year;
	while (Year<1900)
	{
		cout << "The year must be at least 1900.which year?" << "  ";
		cin >> Year;
	}
	cout << endl; 
	cout << endl;
	return (Year);
}
/*
* Function: IsLeapYear
* Usage: if (IsLeapYear(year)) . . .
* ----------------------------------
* This function returns TRUE if year is a leap year.
*/
bool IsLeapYear(int year)
{
	bool leapyear;
	leapyear = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	return(leapyear);
}
/*
* Function: PrintCalendar
* Usage: PrintCalendar(year);
* ---------------------------
* This procedure prints a calendar for an entire year.
*/
void PrintCalendar(int year)
{
	for (int i = 1; i <= 12; ++i)
		PrintCalendarMonth(i, year);
}
/*
* Function: PrintCalendarMonth
* Usage: PrintCalendarMonth(month, year);
* ---------------------------------------
* This procedure prints a calendar for the given month
* and year.
*/
void PrintCalendarMonth(int month, int year)
{
	cout << setw(12) << MonthName(month) << setw(5) << year << endl;
	cout << setw(3) << "Su" << setw(3) << "Mo" << setw(3) << "Tu" << setw(3) << "We" << setw(3) << "Th" << setw(3) << "Fr" << setw(3) << "Sa" << endl;
	int m = (FirstDayOfMonth(month, year) + 7) % 7;
	IndentFirstLine(m);
	int i = 2;
	while (i <= MonthDays(month, year))
	{
		if ((i + FirstDayOfMonth(month, year) - 1) % 7 == 0)
		{
			cout << endl;
			cout << setw(3) << i;
			i = i + 1;
		}
		else
		{
			cout << setw(3) << i;
			i = i + 1;
		}
	}
	cout << endl; cout << endl; cout << endl;
}
/*
* Function: IndentFirstLine
* Usage: IndentFirstLine(weekday);
* --------------------------------
* This procedure indents the first line of the calendar
* by printing enough blank spaces to get to the position
* on the line corresponding to weekday.
*/
void IndentFirstLine(int m)
{
	cout << setw(3 + 3 * m) << 1;
}
/*
* Function: MonthDays
* Usage: ndays = MonthDays(month, year);
* --------------------------------------
* MonthDays returns the number of days in the indicated
* month and year.  The year is required to handle leap years.
*/
int MonthDays(int month, int year)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return(31);
	if (month == 2)
		if (IsLeapYear(year))
			return(29);
		else
			return(28);
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return(30);
}
/*
* Function: FirstDayOfMonth
* Usage: weekday = FirstDayOfMonth(month, year);
* ----------------------------------------------
* This function returns the day of the week on which the
* indicated month begins.  This program simply counts
* forward from January 1, 1900, which was a Monday.
*/
int FirstDayOfMonth(int month, int year)
{
	int Alldays = 0, Yeardays, weekday, lastyear = 0, days = 0;
	lastyear = year - 1;
	while (lastyear >= 1900)
	{
		if (IsLeapYear(lastyear))
		{
			Yeardays = 366;
			Alldays += Yeardays;
			lastyear = lastyear - 1;
		}
		else
		{
			Yeardays = 365;
			Alldays += Yeardays;
			lastyear = lastyear - 1;
		}
	}
	while (month >= 1)
	{
		days += MonthDays(month - 1, year);
		month = month - 1;
	}
	weekday = (Alldays + days - 3) % 7;
	return(weekday);
}
/*
* Function: MonthName
* Usage: name = MonthName(month);
* -------------------------------
* MonthName converts a numeric month in the range 1-12
* into the string name for that month.
*/
string MonthName(int month)
{
	switch (month)
	{
	case 1:return"January"; break;
	case 2:return"February"; break;
	case 3:return"Match"; break;
	case 4:return"April"; break;
	case 5:return"May"; break;
	case 6:return"June"; break;
	case 7:return"July"; break;
	case 8:return"August"; break;
	case 9:return"September"; break;
	case 10:return"Octorber"; break;
	case 11:return"November"; break;
	case 12:return"December"; break;
	}
}
