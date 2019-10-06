#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;

//1.1
int p1_1()//the entrance of the procedure
{
	cout << "Hello,C++!" << endl;
	return 0;
}

//1.2
int p1_2()
{
float num1, num2, num3;
cout << "Please input three numbers: ";
cin >> num1 >> num2 >> num3;
cout << "The average of " << num1 << "," << num2 << " and " << num3;
cout << "is: " << (num1 + num2 + num3) / 3 << endl;
return 0;
}


//1.3
int p1_3()
{
float num1, num2, num3;
cout << "Please input three numbers: ";
cin >> num1 >> num2 >> num3;
cout << setw(8) << setprecision(12);
cout << "The average of " << num1 << "," << num2 << " and " << num3;
cout << " is:" << setw(20) << (num1 + num2 + num3) / 3 << endl;
return 0;
}

