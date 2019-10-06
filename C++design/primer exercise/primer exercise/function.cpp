#include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

void assign()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3;   //int converted to float
	int guess(3.9832);//double converted to int
	int debt = 7.2E12;//result not defined in C++
	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;
}

void typecast()
{
	int auks, bats, coots;
	//the following statement adds the values as double,
	//then converts the result to int 
	auks = 19.99 + 11.99;
	//these statements add values as int 
	bats = (int)19.99 + (int)11.99;//old Csyntax
	coots = int(19.99) + int(11.99);//new C++ syntax
	cout << "auks = " << auks << ", bats = " << bats;
	cout << ", coots = " << coots << endl;

	char ch = 'z';
	cout << "The code for " << ch << " is ";//print as char
	cout << int(ch) << endl;//print as int
	cout << "Yes,the code is ";
	cout << static_cast<int>(ch) << endl;//using static_cast
}

void arrrayone()
{
	int yams[3];  //create array with three elements
	yams[0] = 7; //assign value to first elsment
	yams[1] = 8; 
	yams[2] = 6;

	int yamcosts[3] = { 20,30,5 }; //create,initialize array
	//note:if your C++ compileror translator can'tinitialize
	//this array,use static int yamcosts[3] instead of int yamcosts[3]
	cout << "\nSize of array = " << sizeof yams << " bytes.\n";
	cout << "Size of one element = " << sizeof yams[0] << " bytes.\n";
}

void strings()
{
	const int Size = 15;
	char name1[Size];//empty array
	char name2[Size] = "C++owboy";//initialized array
	//note:some implementations may require the static keyword
	//to initialize the array name2
	cout << "Howdy! I'm " << name2;
	cout << "! What's your name? \n";
	cin >> name1;
	cout << "Well, " << name1 << ", your name has ";
	cout << strlen(name1) << " letters and is stored \n";
	cout << "in an array of " << sizeof(name1) << " bytes.\n";
	cout << "Your initial is " << name1[0] << ".\n";
	name2[3] = '\0';//set to null character
	cout << "Here are the first three characters of my name: ";
	cout << name2 << endl;
}

void instr2()
{
	const int arsize = 20;
	char name[arsize];
	char dessert[arsize];
	cout << "Enter your name:\n";
	cin.getline(name, arsize);//reads through newline
	cout << "Enter your favorite dessert:\n";
	cin.getline(dessert, arsize);
	cout << "I have somme delicious " << dessert;
	cout << " for you, " << name << ".\n";
}      

void numstr()
{
	cout << "What year was your house built?" << endl;
	int year;
	(cin >> year).get();
	cout << "What is its street address?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "Year built: " << year << endl;
	cout << "Address: " << address << endl;
	cout << "Done!\n";
}

struct inflatable//structure declaration
{
	char name[20];
	float  volume;
	double price;
};
int structur()
{
	inflatable guest =
	{
		"Glorious Gloria",//namevalue
		1.88,             //volume value
		29.99             //price value
	};//guest is a structure variable of type inflatable
	//It's initialized to the indicated values
	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	};//pal is a secong variable of type inflatble
	//note:some implementations require using
	//static inflatable guest =
	cout << "Expand your guest list with " << guest.name;
	cout << " and " << pal.name << "!\n";
	//pal.name is the name member of the pal variable
	cout << "You can have the both for $";
	cout << guest.price + pal.price << "!\n";
	return 0;
}

int assign_st()
{
	inflatable bouquet = { "sunflowers",0.20,12.49 };
	inflatable choice;
	cout << "bouquet: " << bouquet.name << " for $";
	cout << bouquet.price << endl;
	choice = bouquet;
	//assignone structure to another
	cout << "choice: " << choice.name << " for $";
	cout << choice.price << endl;
	return 0;
}

void arrarynew()
{
	double* p3 = new double [3];//space for three doubles
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[0] = 0.8;
	p3 = p3 + 1;
	cout << "Now the p3[0] is " << p3[0] << endl;
	p3 = p3 - 1;
	delete[]p3;
}

