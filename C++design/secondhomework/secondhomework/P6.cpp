#include"stdafx.h"
#include"TsingHua.h"
#include"Point.h"
#include<iostream>
using namespace std;

int p6_1()
{
	Circle1 cir1(10, 100, 200);
	cir1.ShowCircle();
	cout << "area is: " << cir1.area() << endl;
	cir1.move(10, 20);
	cir1.ShowXY();
	return 0;
}
int p6_2()
{
	Cylinder CY(100, 200, 10.0, 50.0);
	CY.ShowCylinder();
	cout << "total area: " << CY.area() << endl;
	cout << "volume: " << CY.volume();
	return 0;
}

class Point3
{
private:
	int X, Y;
public:
	Point3(int X = 0, int Y = 0)
	{
		this->X = X, this->Y = Y;
		cout << "point(" << X << "," << Y << ")constructing..." << endl;
	}
	~Point3()
	{
		cout << "point(" << X << "," << Y << ")destructing..." << endl;
	}
};
class Circle3 :protected Point3
{
protected:
	double radius;
public:
	Circle3(double R, int X, int Y) :Point3(X, Y)
	{
		radius = R;
		cout << "circle constructing,radius: " << R <<endl;
	}
	~Circle3()
	{
		cout << "circle destructing,radius: " << radius << endl;
	}
};
class tube : protected Circle3
{
private:
	double height;
	Circle3 InCircle;
public:
	tube(double H, double R1, double R2 = 0, int X = 0, int Y = 0) :
		InCircle(R2, X, Y), Circle3(R1, X, Y)
	{
		height= H;
		cout << "tube constructing,height: " << H << endl;
	}
	~tube()
	{
		cout << "desrtructing,height: " << height << endl;
	}
};
int p6_3()
{
	tube TU(100, 20, 5);
	return 0;
}

//类的公有继承，类的兼容
class Cylinder4 : public Circle2
{
private:
	double height;
public:
	Cylinder4(int X, int Y, double R, double H) :Circle2(R, X, Y)
	{
		height = H;
	}
	void ShowCylinder()
	{
		ShowCircle();
		cout << "height of cylinder:" << height << endl;
	}
};
int p6_4()
{
	Point p(1, 1);//point类对象
	Circle2 cir(20, 20, 15.5);//circle类对象
	Cylinder4 cy(300, 300, 15.5, 50);//cylinder类对象
	Point * Pp;//point类指针
	Pp = &p;//将基类对象的地址赋值给指向基类的指针
	Pp->ShowXY();
	//以下运行不成功
	//Pp = &cir;//将派生类对象地址赋值给指向基类的指针
	//Pp->ShowXY();//
	//Pp = &cy;//将派生类对象地址赋值给指向基类的指针
	//Pp->ShowXY();
	//Circle2 &RC = cy;//circle类引用了派生类cylinder对象
	//RC.ShowXY();
	//p = cir;//circle类对象赋值给基类point类的对象
	//p.ShowXY();
	return 0;
}

//多继承的二义性
class Car
{
private:
	int power;
	int seat;
public:
	Car(int power, int seat)
	{
		this->power = power;
		this->seat = seat;
	}
	void show()
	{
		cout << "car: power: " << power << "   seat: " << seat << endl;
	}
};
class Wagon
{
private:
	int power;
	int load;
public:
	Wagon(int power, int load)
	{
		this->power = power;
		this->load = load;
	}
	void show()
	{
		cout << "wagon: power: " << power << "   load: " << load << endl;
	}
};
class StationWagon : public Car, public Wagon
{
public:
	StationWagon(int power, int seat, int load) :
		Wagon(power, load), Car(power, seat){}
	void showSW()
	{
		cout << "StationWagon: " << endl;
		Car::show();
		Wagon::show();
	}
};
int p6_5()
{
	StationWagon sw(105, 3, 8);
	//sw.show();//not clear
	sw.showSW();
	return 0;
}

class automobile
{
private:
	int power;
public:
	automobile();
	automobile(int power)
	{
		this->power = power;
		cout << "automobile constructing..." << endl;
	}
	void show()
	{
		cout << "   power:" << power;
	}
};
class Car6 :public automobile
{
private:
	int seat;
public:
	Car6(int power, int seat) :automobile(power)
	{
		this->seat = seat;
	}
	void show()
	{
		cout << "car: ";
		automobile::show();
		cout << "   seat: " << seat << endl;
	}
};
class Wagon6 :public automobile
{
private:
	int load;
public:
	Wagon6(int power, int load) :automobile(power)
	{
		this->load = load;
	}
	void show()
	{
		cout << "wagon: ";
		automobile::show();
		cout << "   load: " << load << endl;
	}
};
class StationWagon6 : public Car6, public Wagon6
{
public:
	StationWagon6(int Cpower, int Wpower, int seat, int load) :
		Wagon6(Wpower, load), Car6(Cpower, seat) {}
	void show()
	{
		cout << "StationWagon: " << endl;
		Car6::show();
		Wagon6::show();
	}
};
int p6_6()
{
	StationWagon6 sw(105, 108, 3, 8);
	sw.show();
	return 0;
}
//虚基类的构造函数
class Car7:virtual public automobile
{
private:
	int seat;
public:
	Car7(int power, int seat) :automobile(power)
	{
		this->seat = seat;
	}
	void show()
	{
		cout << "car: ";
		automobile::show();
		cout << "   seat: " << seat << endl;
	}
};
class Wagon7 :virtual public automobile
{
private:
	int load;
public:
	Wagon7(int power, int load) :automobile(power)
	{
		this->load = load;
	}
	void show()
	{
		cout << "wagon: ";
		automobile::show();
		cout << "   load: " << load << endl;
	}
};
class StationWagon7 : public Car7, public Wagon7
{
public:
	StationWagon7(int Cpower, int Wpower, int seat, int load) :
		Wagon7(Wpower, load), Car7(Cpower, seat)
	{
		cout << "stationwagon constructing..." << endl;
	}
	void show()
	{
		cout << "StationWagon: " << endl;
		Car7::show();
		Wagon7::show();
	}
};
int p6_7()
{
	StationWagon7 sw(105, 108, 3, 8);
	sw.show();
	return 0;
}         
