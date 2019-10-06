#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;

//2.1
int p2_1()
{
	cout << 'A' << '\t' << ';' << '\n';
	cout << '\102' << '\011' << '\073' << '\012';
	cout << '\103' << '\11' << '\73' << '\12';
	cout << '\x44' << '\x09' << '\x3b' << '\x0a';
	cout << '\x45' << '\x9' << '\x3b' << '\xa';
	cout << "\x46\x09\x3b\x0d\x0a";
	cout << "\xcd\xcd\xcd\xcd\xcd" << endl;
	return 0;
}


//2.2
int p2_2()
{
int a;
a = 2 * 3 + -3 % 5 - 4 / 3;
float b;
b = 5 + 3.2e3 - 5.6 / 0.03;
cout << a << "\t" << b << endl;
int m = 3, n = 4;
a = m++ - (--n);
cout << a << "\t" << m << "\t" << n << endl;
return 0;
}


//2.4
int p2_3()
{
int i = 10, j = 20, k;
k = (i < j) ? i : j;
cout << i << '\t' << j << '\t' << k << endl;
k = i - j ? i + j : i - 3 ? j : i;
cout << i << '\t' << j << '\t' << k << endl;
return 0;
}


//2.5
int p2_5()
{
int n;
cout << "Enter the score: ";
cin >> n;
if (n >= 60)
if (n >= 90)
cout << "The degree is A." << endl;
else if (n >= 80)
cout << "The degree is B." << endl;
else
cout << "The degree is C." << endl;
else
cout << "The degree is D." << endl;
return 0;
}

//2.6
int p2_6()
{
int n;
cout << "Enter a score: ";
cin >> n;
switch (n / 10)
{
case 9: case 10:
cout << "The degree is A." << endl;
break;
case 8:
cout << "The degree is B." << endl;
break;
case 7: case 6:
cout << "The degree is C." << endl;
break;
default:
cout << "The degree is D." << endl;
break;
}
return 0;
}

//2.7
int p2_7()
{
int i, sum = 0;
for (i = 1; i < 100; ++i, ++i)
sum = sum + i;
cout << "sum = " << sum << endl;
return 0;
}

//2.8   maybe there are some errors in the procedure
int p2_8()
{
const int cock = 20, hen = 33, chick = 100;
int i, j, k;
for (i = 0; i <=cock; i++)
for (j = 0; j <= hen; j++)
for (k = 0; k <= chick; k++)
//the number of the cock,hen,chick and the money must be the int
if ((i + j + k)==100 && (5 * i + 3 * j + k / 3) == 100 && k % 3 == 0)
cout << "鸡翁、鸡婆、鸡雏各有：\t" << i << '\t' << j << '\t' << k << endl;
return 0;
}

//2.9
int p2_9()
{
int i = 1, sum = 0;
while (i < 100)
{
sum = sum + i;
++i, ++i;
}
cout << "sum = " << sum << endl;
return 0;
}

//2.10
int p2_10()
{
int i = 1, sum = 0;
do
{
sum = sum + i;
++i, ++i;
} while (i < 100);
cout << "sum = " << sum << endl;
return 0;
}

//2.11
int p2_11()
{
int i, n;
while (1)
{
cin >> n;
if (n <= 1)
break;
for (i = 2; i < n; i++)
if (n%i == 0)break;
i >= n ? cout << n << "shi su shu\n" : cout << n << "bu shi su shu\n";
}
return 0;
}

int p2_12()
{
int i, n;
while (1)
{
cin >> n;
if (n <= 1)
break;
for (i = 2; i < n; i++)
if (n%i == 0)goto goon;
goon: i >= n ? cout << n << "shi su shu\n" : cout << n << "bu shi su shu\n";
}
return 0;
}

//2.13
int max(int x,int y)
{
int z;
z = (x > y) ? x : y;
return z;
}
int p2_13()
{
int a, b;
cin >> a >> b;
cout << max(a, b) << endl;
return 0;
}

//2.14
void swap(int a, int b)
{
int t;
t = a, a = b, b = t;
}
int p2_14()
{
int x = 2, y = 5;
cout << "x = " << x << " y = " << y << endl;
swap(x, y);
cout << "after swap: ";
cout << "x = " << x << " y = " << y << endl;
return 0;
}

//2.15
int max(int x, int y, int z)
{
int t;
t = x > y ? x : y;
return(t > z ? t : z);
}
int min(int x, int y, int z)
{
int t;
t = x < y ? x : y;
return(t < z ? t : z);
}
int dif(int x, int y, int z)
{
return max(x, y, z) - min(x, y, z);
}
int p2_15()
{
int a, b, c;
cin >> a >> b >> c;
cout << "Max - Min = " << dif(a, b, c) << endl;
return 0;
}

//2.16
int fac(int n)
{
int t;
if (n == 1)
t = 1;
else
t = n * fac(n - 1);
return(t);
}
int p2_16()
{
const int max_n = 12;//int类型数能表示的n！的最大n
int n;
cout << "Input a integer number:";
cin >> n;
if (n >= 1 && n <= max_n)
cout << "Factorial of " << n << " is: " << fac(n) << endl;
else
cout << "Invalid n." << endl;
return 0;
}

//2.17
inline double CirArea(double radius)
{
return 3.14*radius*radius;
}
int p2_17()
{
double r1(1.0), r2(2);
cout << CirArea(r1) << endl;
cout << CirArea(r1 + r2 + 4) << endl;
return 0;
}

//2.18
int add(int x, int y)
{
cout << "(int,int)\t";
return x + y;
}
double add(double x, double y)
{
cout << "(double,double)\t";
return x + y;
}
int add(int x, double y)
{
cout << "(int,double)\t";
return x + y;
}
double add(double x, int y)
{
cout << "(double,int)\t";
return x + y;
}
int p2_18()
{
cout << add(9, 8) << endl;
cout << add(9.0, 8.0) << endl;
cout << add(9, 8.0) << endl;
cout << add(9.0, 8) << endl;
return 0;
}

int p2_19()
{
int x, i(0);
srand(124);//设置种子
do
{
x = rand();
if (x >= 5 && x <= 1000)
{
x = (x / 5) * 5;
cout << x / 10.0 << "\t";
i++;
}
} while (i < 100);
return 0;
}

