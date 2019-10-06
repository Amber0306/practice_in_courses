#pragma once
#include"stdafx.h"
#include"Point.h"
#include<iostream>
using namespace std;


namespace TsingHua
{
	int year = 2009;
	char name[] = "TsingHua Software";
	void ShowName()
	{
		cout << name << "  " << year << endl;
	}
}

//从point中派生出circle类
const double PI = 3.14159;
class Circle1 :public Point
{
private:
	double radius;
public:
	Circle1(double R, int X, int Y) :Point(X, Y)
	{
		radius = R;
	}
	double area()
	{
		return PI * radius*radius;
	}
	void ShowCircle()
	{
		cout << "Centre of circle:";
		ShowXY();
		cout << "radius:" << radius << endl;
	}
};
//circle类中派生出圆柱类
class Circle2 :protected Point
{
protected:
	double radius;
public:
	Circle2(double R, int X, int Y) :Point(X, Y)
	{
		radius = R;
	}
	double area()
	{
		return PI * radius*radius;
	}
	void ShowCircle()
	{
		cout << "Centre of circle:";
		ShowXY();
		cout << "radius:" << radius << endl;
	}
};
class Cylinder :protected Circle2
{
private:
	double height;
public:
	Cylinder(int X, int Y, double R, double H) :Circle2(R, X, Y)
	{
		height = H;
	}
	double area()
	{
		return 2 * Circle2::area() + 2 * PI*radius*height;
	}
	double volume()
	{
		return Circle2::area()*height;
	}
	void ShowCylinder()
	{
		ShowCircle();
		cout << "height of cylinder:" << height << endl;
	}
};