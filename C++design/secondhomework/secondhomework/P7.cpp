#include"stdafx.h"
#include<iostream>
using namespace std;

//������Ԫ���������и�������
class complex//������Ķ���
{
private:
	double real;//����ʵ��
	double image;//�����鲿
public:
	complex(double real = 0.0, double image = 0.0)//���캯��
	{
		this->real = real, this->image = image;
	}
	void display()
	{
		cout << "(" << real << "," << image << ")" << endl;
	}
	friend complex operator + (complex A, complex B)//����+Ϊ��Ԫ����
	{
		return complex(A.real + B.real, A.image + B.image);//���������+�ĺ���ʵ��
	}
	friend complex operator - (complex A, complex B);//����-Ϊ��Ԫ����
	friend complex operator  -  (complex A);//����-��ȡ����Ϊ��Ԫ����
	friend complex operator++ (complex& A);//����ǰ��++Ϊ��Ԫ����
	friend complex operator++ (complex& A, int);//���غ���++Ϊ��Ԫ����
};
 complex operator - (complex A, complex B)//���������-�ĺ���ʵ��
{
	return complex(A.real - B.real, A.image - B.image);
}
 complex operator - (complex A)//���������-��ȡ�����ĺ���ʵ��
 {
	 return complex(-A.real, -A.image);
 }
 complex operator++ (complex& A)//���������ǰ��++�ĺ���ʵ��
 {
	 return complex(++A.real, A.image);
}
 complex operator++ (complex& A, int)//�������������++�ĺ���ʵ��
 {
	 return complex(A.real++, A.image);
 }
 int p7_1()
 {
	 complex A(100.0, 200.0), B(-10.0, 20.0), C;
	 cout << "A= ", A.display();
	 cout << "B= ", B.display();
	 C = A + B;//ʹ�������������ɸ����ӷ�
	 cout << "C=A+B=", C.display();
	 C = A - B;//ʹ�������������ɸ�������
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

 //����Ϊ��Ա����
 class complex2//������Ķ���
 {
 private:
	 double real;//����ʵ��
	 double image;//�����鲿
 public:
	 complex2(double real = 0.0, double image = 0.0)//���캯��
	 {
		 this->real = real, this->image = image;
	 }
	 void display()
	 {
		 cout << "(" << real << "," << image << ")" << endl;
	 }
	complex2 operator + (complex2 B)//����+
	 {
		 return complex2(real + B.real, image + B.image);//���������+�ĺ���ʵ��
	 }
	 complex2 operator - ( complex2 B);//����-
	  complex2 operator  -  ();//����-��ȡ����
	 complex2 operator++ ();//����ǰ��++
	  complex2 operator++ (int);//���غ���++
 };
 complex2 complex2::operator - (complex2 B)//���������-�ĺ���ʵ��
 {
	 return complex2(real - B.real, image - B.image);
 }
 complex2 complex2::operator - ()//���������-��ȡ�����ĺ���ʵ��
 {
	 return complex2(-real, -image);
 }
 complex2 complex2::operator ++ ()//���������ǰ��++�ĺ���ʵ��
 {
	 return complex2(++real, image);
 }
 complex2 complex2::operator++ ( int)//�������������++�ĺ���ʵ��
 {
	 return complex2(real++, image);
 }
 int p7_2()
 {
	 complex A(100.0, 200.0), B(-10.0, 20.0), C;
	 cout << "A= ", A.display();
	 cout << "B= ", B.display();
	 C = A + B;//ʹ�������������ɸ����ӷ�
	 cout << "C=A+B=", C.display();
	 C = A - B;//ʹ�������������ɸ�������
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

 //����=Ϊ��Ա����������ֵ
 class complex3//������Ķ���
 {
 private:
	 double real;//����ʵ��
	 double image;//�����鲿
 public:
	 complex3(double real = 0.0, double image = 0.0)//���캯��
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
 complex3 complex3::operator + (complex3 B)//����+
 {
	 return complex3(real + B.real, image + B.image);//���������+�ĺ���ʵ��
 }//����һ����ʱ������Ϊ����ֵ
 complex3 complex3:: operator = (complex3 B)
 {
	 real = B.real, image = B.image;//���������=�ĺ���ʵ��
	 cout << "operator= calling..." << endl;
	 return *this;//return complex3(real,image
 }
 int p7_3()
 {
	 complex3 A(100.0, 200.0), B(-10.0, 20.0), C;
	 cout << "A= ", A.display();
	 cout << "B= ", B.display();
	 C = A + B;//ʹ�������������ɸ����ӷ�
	 cout << "C=A+B=", C.display();
	 C = A;
	 cout << "C=A= ", C.display();
	 return 0;
 }

 //����->Ϊ��ĳ�Ա����
 class complex4//������Ķ���
 {
 private:
	 double real;//����ʵ��
	 double image;//�����鲿
 public:
	 complex4(double real = 0.0, double image = 0.0)//���캯��
	 {
		 this->real = real, this->image = image;
	 }
	 void display()
	 {
		 cout << "(" << real << "," << image << ")" << endl;
	 }
 };
 class pcomplex4//����ָ����Ķ���
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
		 static complex4 NullComplex(0, 0);//����ָ��Ϊ��
		 if (PC == NULL)
		 {
			 return &NullComplex;
		 }
		 return PC;
	 }
 };
 int p7_4()
 {
	 pcomplex4 p1;//ָ��δ��ʼ��
	 p1->display();//��ʾԤ�ȶ���ģ�0,0��
	 complex4 c1(100, 200);//
	 p1 = &c1;//ָ�뱻��ʼ��
	 p1->display();//��ʾ��Ч����
	 return 0;
 }

 //�����±����������Ϊ��ĳ�Ա�����ַ�����
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
		 return *(Str + n);//�������������������string����
	 }
	 const char& operator[](int n)const
	 {
		 return *(Str + n);//�������������������const��string����
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

 //��ʾ��̬��̬��
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

 //��ʾ��̬��̬��
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

 //ɾ����̬���������������ĵ���
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
	 A* b = new B(10);//���ͼ���
	 delete b;
	 return 0;
 }

 //�������ʹ��
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

 //�����������ָ������
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
	 person * personArr[5];//�������ָ������
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