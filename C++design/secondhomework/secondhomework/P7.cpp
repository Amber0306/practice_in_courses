#include"stdafx.h"
#include<iostream>
using namespace std;

//重载友元函数，进行复数运算
class complex//复数类的定义
{
private:
	double real;//复数实部
	double image;//复数虚部
public:
	complex(double real = 0.0, double image = 0.0)//构造函数
	{
		this->real = real, this->image = image;
	}
	void display()
	{
		cout << "(" << real << "," << image << ")" << endl;
	}
	friend complex operator + (complex A, complex B)//重载+为友元函数
	{
		return complex(A.real + B.real, A.image + B.image);//重载运算符+的函数实现
	}
	friend complex operator - (complex A, complex B);//重载-为友元函数
	friend complex operator  -  (complex A);//重载-（取负）为友元函数
	friend complex operator++ (complex& A);//重载前置++为友元函数
	friend complex operator++ (complex& A, int);//重载后置++为友元函数
};
 complex operator - (complex A, complex B)//重载运算符-的函数实现
{
	return complex(A.real - B.real, A.image - B.image);
}
 complex operator - (complex A)//重载运算符-（取负）的函数实现
 {
	 return complex(-A.real, -A.image);
 }
 complex operator++ (complex& A)//重载运算符前置++的函数实现
 {
	 return complex(++A.real, A.image);
}
 complex operator++ (complex& A, int)//重载运算符后置++的函数实现
 {
	 return complex(A.real++, A.image);
 }
 int p7_1()
 {
	 complex A(100.0, 200.0), B(-10.0, 20.0), C;
	 cout << "A= ", A.display();
	 cout << "B= ", B.display();
	 C = A + B;//使用重载运算符完成复数加法
	 cout << "C=A+B=", C.display();
	 C = A - B;//使用重载运算符完成复数减法
	 cout << "C=A-B=", C.display();
	 C = -A + B;
	 cout << "C=-A+B=", C.display();
	 C = A ++;
	 cout << "C=A++", C.display();
	 C = ++A;
	 cout << "C=++A=", C.display();
	 C = A + 5;
	 C.display();
	 return 0;
 }

 //重载为成员函数
 class complex2//复数类的定义
 {
 private:
	 double real;//复数实部
	 double image;//复数虚部
 public:
	 complex2(double real = 0.0, double image = 0.0)//构造函数
	 {
		 this->real = real, this->image = image;
	 }
	 void display()
	 {
		 cout << "(" << real << "," << image << ")" << endl;
	 }
	complex2 operator + (complex2 B)//重载+
	 {
		 return complex2(real + B.real, image + B.image);//重载运算符+的函数实现
	 }
	 complex2 operator - ( complex2 B);//重载-
	  complex2 operator  -  ();//重载-（取负）
	 complex2 operator++ ();//重载前置++
	  complex2 operator++ (int);//重载后置++
 };
 complex2 complex2::operator - (complex2 B)//重载运算符-的函数实现
 {
	 return complex2(real - B.real, image - B.image);
 }
 complex2 complex2::operator - ()//重载运算符-（取负）的函数实现
 {
	 return complex2(-real, -image);
 }
 complex2 complex2::operator ++ ()//重载运算符前置++的函数实现
 {
	 return complex2(++real, image);
 }
 complex2 complex2::operator++ ( int)//重载运算符后置++的函数实现
 {
	 return complex2(real++, image);
 }
 int p7_2()
 {
	 complex A(100.0, 200.0), B(-10.0, 20.0), C;
	 cout << "A= ", A.display();
	 cout << "B= ", B.display();
	 C = A + B;//使用重载运算符完成复数加法
	 cout << "C=A+B=", C.display();
	 C = A - B;//使用重载运算符完成复数减法
	 cout << "C=A-B=", C.display();
	 C = -A + B;
	 cout << "C=-A+B=", C.display();
	 C = A++;
	 cout << "C=A++", C.display();
	 C = ++A;
	 cout << "C=++A=", C.display();
	 C = A + 5;
	 C.display();
	 return 0;
 }

 //重载=为成员函数，并赋值
 class complex3//复数类的定义
 {
 private:
	 double real;//复数实部
	 double image;//复数虚部
 public:
	 complex3(double real = 0.0, double image = 0.0)//构造函数
	 {
		 this->real = real, this->image = image;
	 }
	 void display()
	 {
		 cout << "(" << real << "," << image << ")" << endl;
	 }
	 complex3 operator + (complex3 B);
		 complex3 operator = (complex3 B);
 }; 
 complex3 complex3::operator + (complex3 B)//重载+
 {
	 return complex3(real + B.real, image + B.image);//重载运算符+的函数实现
 }//创建一个临时对象作为返回值
 complex3 complex3:: operator = (complex3 B)
 {
	 real = B.real, image = B.image;//重载运算符=的函数实现
	 cout << "operator= calling..." << endl;
	 return *this;//return complex3(real,image
 }
 int p7_3()
 {
	 complex3 A(100.0, 200.0), B(-10.0, 20.0), C;
	 cout << "A= ", A.display();
	 cout << "B= ", B.display();
	 C = A + B;//使用重载运算符完成复数加法
	 cout << "C=A+B=", C.display();
	 C = A;
	 cout << "C=A= ", C.display();
	 return 0;
 }

 //重载->为类的成员函数
 class complex4//复数类的定义
 {
 private:
	 double real;//复数实部
	 double image;//复数虚部
 public:
	 complex4(double real = 0.0, double image = 0.0)//构造函数
	 {
		 this->real = real, this->image = image;
	 }
	 void display()
	 {
		 cout << "(" << real << "," << image << ")" << endl;
	 }
 };
 class pcomplex4//复数指针类的定义
 {
 private:
	 complex4 * PC;
 public:
	 pcomplex4(complex4*PC = NULL)
	 {
		 this->PC = PC;
	 }
	 complex4 * operator->()
	 {
		 static complex4 NullComplex(0, 0);//避免指针为空
		 if (PC == NULL)
		 {
			 return &NullComplex;
		 }
		 return PC;
	 }
 };
 int p7_4()
 {
	 pcomplex4 p1;//指针未初始化
	 p1->display();//显示预先定义的（0,0）
	 complex4 c1(100, 200);//
	 p1 = &c1;//指针被初始化
	 p1->display();//显示有效数据
	 return 0;
 }

 //重载下标运算符【】为类的成员函数字符串类
 class String
 {
 private:
	 char *Str;
	 int len;
 public:
	 void ShowStr()
	 {
		 cout << "string: " << Str << ", length: " << len << endl;
	 }
	 String(const char * p=NULL)
	 {
		 if (p)
		 {
			 len = strlen(p);
			 Str = new char[len + 1];
			 strcpy_s(Str, 12,p);
		 }
		 else
		 {
			 len = 0;
			 Str = NULL;
		 }
	 }
	 ~String()
	 {
		 if (Str != NULL)
		 {
			 delete[] Str;
		 }
	 }
	 char& operator[](int n)
	 {
		 return *(Str + n);//重载运算符【】，处理string对象
	 }
	 const char& operator[](int n)const
	 {
		 return *(Str + n);//重载运算符【】，处理const，string对象
	 }
 };
 int p7_5()
 {
	 String s1("0123456789abcdef");
	 s1.ShowStr();
	 s1[10] = 'A';
	 cout << "s1[10]=A" << endl;
	 s1.ShowStr();
	 const String s2("ABCDEFGHIJKLMN");
	 cout << "s2[10]=" << s2[10] << endl;
	 return 0;
 }

 //演示静态多态性
 class Point
 {
 private:
	 int X, Y;
 public:
	 Point(int X = 0, int Y = 0)
	 {
		 this->X = X, this->Y = Y;
	 }
	 double area()
	 {
		 return 0.0;
	}
 };
 const double PI = 3.14159;
 class Circle6 :public Point
 {
 private:
	 double radius;
 public:
	 Circle6(double R, int X, int Y) :Point(X, Y)
	 {
		 radius = R;
	 }
	 double area()
	 {
		 return PI * radius*radius;
	 }
 };
 int p7_6()
 {
	 Point p1(10, 10);
	 cout << "p1.area() = " << p1.area() << endl;
	 Circle6 c1(10, 10, 20);
	 cout << "c1.area() = " << c1.area() << endl;
	 Point *Pp;
	Pp = &c1;
	cout << "Pp->area()=" << Pp->area() << endl;
	Point& Rp = c1;
	cout << "Rp.area()=" << Rp.area() << endl;
	return 0;
 }

 //演示动态多态性
 class Point7
 {
 private:
	 int X, Y;
 public:
	 Point7(int X = 0, int Y = 0)
	 {
		 this->X = X, this->Y = Y;
	 }
	 virtual double area()
	 {
		 return 0.0;
	 }
 };

 class Circle7 :public Point7
 {
 private:
	 double radius;
 public:
	 Circle7(double R, int X, int Y) :Point7(X, Y)
	 {
		 radius = R;
	 }
	 double area()
	 {
		 return PI * radius*radius;
	 }
 };
 int p7_7()
 {
	 Point7 p1(10, 10);
	 cout << "p1.area() = " << p1.area() << endl;
	 Circle7 c1(10, 10, 20);
	 cout << "c1.area() = " << c1.area() << endl;
	 Point7 *Pp;
	 Pp = &c1;
	 cout << "Pp->area()=" << Pp->area() << endl;
	 Point7& Rp = c1;
	 cout << "Rp.area()=" << Rp.area() << endl;
	 return 0;
 }

 //删除动态对象虚析构函数的调用
 class A
 {
 public:
	 virtual ~A()
	 {
		 cout << "A::~A() is called." << endl;
	 }
	 A()
	 {
		 cout << "A::A() is called." << endl;
	 }
 };
 class B :public A
 {
 private :
	 int * ip;
 public:
	 B(int size = 0)
	 {
		 ip = new int[size];
		 cout << "B::B() is called." << endl;
	 }
	 ~B()
	 {
		 cout << "~B::B() is called." << endl;
		 delete[] ip;
	 }
 };
 int p7_8()
 {
	 A* b = new B(10);//类型兼容
	 delete b;
	 return 0;
 }

 //抽象类的使用
 class Shape//the virtual class
 {
 public:
	 virtual double area()const = 0;
	 virtual void show() = 0;
 };
 class point :public Shape
 {
 protected:
	 int X, Y;
 public:
	point(int X = 0, int Y = 0)
	 {
		 this->X = X, this->Y = Y;
	 }
	void show()
	{
		cout << "(" << X << "," << "Y" << ")" << endl;
	}
	double area()const
	 {
		 return 0.0;
	 }
 };
 class Circle9 :public point
 {
 protected:
	 double radius;
 public:
	 Circle9(double R, int X, int Y) :point(X, Y)
	 {
		 radius = R;
	 }
	 double area()const
	 {
		 return PI * radius*radius;
	 }
	 void show()
	 {
		 cout << "Centre of circle:";
		 cout << "(" << X << "," << Y << ")" << endl;
		 cout << "radius:" << radius << endl;
	 }
 };
 class Cylinder: public Circle9
 {
 private:
	 double height;
 public:
	 Cylinder(int X, int Y, double R, double H) :Circle9(R, X, Y)
	 {
		 height = H;
	 }
	 double area()const
	 {
		 return 2 * Circle9::area() + 2 * PI*radius*height;
	 }
	 void ShowCylinder()
	 {
		 Circle9::show();
		 cout << "height of cylinder:" << height << endl;
	 }
 };
 int p7_9()
 {
	 Cylinder cy(100, 200, 10, 50);
	 Shape * p;
	 p = &cy;
	 p->show();
	 cout << "total area: " << p->area() << endl;
	 Circle9 cir(5, 10, 100);
	 Shape &r = cir;
	 r.show();
	 return 0;
 }

 //抽象类与对象指针数组
 #include<cstring>
 class person
 {
 protected:
	 char name[20];
 public:
	 person(const char* iname) { strcpy_s(name, iname); }
	 virtual void who_am_I() = 0;
	 virtual ~person() { cout << "~person() called." << endl; }
 };
 class student :public person
 {
 private:
	 char major[20];
 public:
	 student(const char* iname, const char* imajor) :person(iname)
	 {
		 strcpy_s(major, imajor);
	 }
	 void who_am_I()
	 {
		 cout << "My name is " << name << " ,I major in " << major << endl;
	 }
	 ~student()
	 {
		 cout << "~student() called!" << endl;
	 }
 };
 class teacher :public person
 {
 private:
	 char teach[20];
 public:
	 teacher(const char* iname, const char* iteach) :person(iname)
	 {
		 strcpy_s(teach, iteach);
	 }
	 void who_am_I()
	 {
		 cout << "My name is " << name << " ,I teach " << teach << endl;
	 }
	 ~teacher()
	 {
		 cout << "~teacher() called!" << endl;
	 }
 };
 int p7_10()
 {
	 person * personArr[5];//基类对象指针数组
	 personArr[0] = new student("Joe","computer");
	 personArr[1] = new teacher("Mary","mathmatics");
	 personArr[2] = new student("Jasmine","physics");
	 personArr[3] = new teacher("Antony","chemical");
	 personArr[4] = new student("Jayden","biology");
	 for (int i = 0; i < 5; i++)
	 {
		 personArr[i]->who_am_I();
		 delete personArr[i];
	 }
	 return 0;
 }