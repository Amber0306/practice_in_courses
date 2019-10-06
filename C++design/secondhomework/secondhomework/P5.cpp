#include "stdafx.h"
#include<cstring>
#include <iostream>

using namespace std;

//面向过程的时钟程序
struct Clock {
	int H, M, S;
};
Clock MyClock;
void SetTime(int H, int M, int S)
{
	MyClock.H = (H >= 0 && H < 24) ? H : 0;
	MyClock.M = (M >= 0 && M < 60) ? M : 0;
	MyClock.S = (S >= 0 && S < 60) ? S : 0;
}
void ShowTime()
{
	cout << MyClock.H << ":";
	cout << MyClock.M << ":";
	cout << MyClock.S << endl;
}
int p5_1_a()
{
	ShowTime();
	SetTime(8, 30, 30);
	ShowTime();
	return 0;
}
class clock1 {
private:
	int H, M, S;
public:
	void SetTime(int H, int M, int S)
	{
		H = (H >= 0 && H < 24) ? H : 0;
		M = (M >= 0 && M < 60) ? M : 0;
		S = (S >= 0 && S < 60) ? S : 0;
	}
	void ShowTime()
	{
		cout << H << ":";
		cout << M << ":";
		cout << S << endl;
	}
};
int p5_1_b()
{
	clock1 MyClock;
	ShowTime();
	SetTime(8, 30, 30);
	ShowTime();
	return 0;
}

//构造函数和析构函数
class clock2
{
private:
	int H, M, S;
public:
	clock2(int h = 0, int m = 0, int s = 0)
	{
		H = h, M = m, S = s;
		cout << "constructor :" << H << ":" << M <<":" << S << endl;
	}
	~clock2()
	{
		cout << "destructor :" << H << ":" << M << ":" << S << endl;
	}
};
int p5_2()
{
	clock2 C3(10, 0, 0);
	clock2 C4(11, 0, 0);
	return 0;
}
clock2 C1(8, 0, 0);
clock2 C2(9, 0, 0);

//基本的字符串类
class String {
private:
	char * Str;
	int len;
public:
	void ShowStr()
	{
		cout << "string: " << Str << ",length: " << len << endl;
	}
	String()
	{
		len = 0;
		Str = NULL;
	}
	String(const char * p)
	{
		len = strlen(p);
		Str = new char[len + 1];
		strcpy_s(Str, 20,p);
	}
	~String()
	{
		if (Str != NULL)
		{
			delete[]Str;
			Str = NULL;
		}
	}
};
int p5_3()
{
	char s[] = "ABCDE";
	String s1(s);
	String s2("123456");
	s1.ShowStr();
	s2.ShowStr();
	return 0;
}

//拷贝构造函数
class clock4
{
private:
	int H, M, S;
public:
	clock4(int h = 0, int m = 0, int s = 0)
	{
		H = h, M = m, S = s;
		cout << "constructor :" << H << ":" << M << ":" << S << endl;
	}
	~clock4()
	{
		cout << "destructor :" << H << ":" << M << ":" << S << endl;
	}
	clock4(clock4 & p)
	{
		cout << "copy constructor,before call:" << H << ":" << M << ":" << S << endl;
		H = p.H;
		M = p.M;
		S = p.S;
	}
	void ShowTime()
	{
		cout << H << ":";
		cout << M << ":";
		cout << S << endl;
	}
};
clock4 fun(clock4 C)
{
	return C;
}
int p5_4()
{
	clock4 C1(8, 0, 0);
	clock4 C2(9, 0, 0);
	clock4 C3(C1);
	fun(C2);
	clock4 C4;
	C4 = C2;
	return 0;
}

//带时间加法的时钟类
class clock5
{
private:
	int H, M, S;
public:
	clock5(int h = 0, int m = 0, int s = 0)
	{
		H = h, M = m, S = s;
		cout << "constructor :" << H << ":" << M << ":" << S << endl;
	}
	~clock5()
	{
		cout << "destructor :" << H << ":" << M << ":" << S << endl;
	}
	clock5(clock5 & p)
	{
		cout << "copy constructor,before call:" << H << ":" << M << ":" << S << endl;
		H = p.H;
		M = p.M;
		S = p.S;
	}
	void SetTime(int h, int m, int s)
	{
		H = h;
		M = m;
		S = s;
	}
	void ShowTime()
	{
		cout << H << ":";
		cout << M << ":";
		cout << S << endl;
	}
	void TimeAdd(clock5 * Cp);
	void TimeAdd(int h,int m,int s);
	void TimeAdd(int s);
};
void clock5::TimeAdd(clock5 * Cp)
{
	H = (Cp->H + H + (Cp->M + M + (Cp->S + S) / 60) / 60) % 24;
	M = (Cp->M + M + (Cp->S + S) / 60) % 60;
	S = (Cp->S + S) % 60;
}
void clock5::TimeAdd(int h, int m, int s)
{
	H = (h + H + (m + M + (s + S) / 60) / 60) % 24;
	M = (m + M + (s + S) / 60) % 60;
	S = (s + S) % 60;
}
void clock5::TimeAdd(int s)
{
	H = (H + ( M + (s + S) / 60) / 60) % 24;
	M = (M + (s + S) / 60) % 60;
	S = (s + S) % 60;
}
int p5_6()
{
	clock5 c1;
	clock5 c2(8, 20, 20);
	c1.TimeAdd(4000);
	c1.ShowTime();
	c2.TimeAdd(&c1);
	c2.ShowTime();
	return 0;
}

//求一个班学生某门功课的总评成绩
const int MaxN = 100;
const double Rate = 0.6;//平时成绩比例
class Score {
private:
	long No;//学号
	const char* Name;//姓名
	int Peace;//平时成绩
	int Final;//期末考试成绩
	int Total;//总评成绩
public:
	Score(long no = 0,const char* name= NULL, int peace = 0, int final = 0,int total=0);//
	void Count();
	void ShowScore();
};
Score::Score(long no,const char* name, int peace, int final,int total)//构造函数
{
	No = no;
	Name = name;
	Peace = peace;
	Final = final;
	Total = total;
}
void Score::Count()
{
	Total = Peace + Rate + Final * (1 - Rate) + 0.5;
}
void Score::ShowScore()
{
	cout << No << "\t" << Name << '\t' << Peace << '\t' << Final << "\t" << Total << endl;
}
int p5_7()
{
	Score ClassScore1[3];
	Score ClassScore2[3] = { Score(200607001,"liuna",80,79),
	Score(200607002,"cuiping",90,85),Score(200607003,"zhoujun",70,55) };
	for(int i=0;i<3;i++)
	{
		ClassScore2[i].Count();
	}
	for (int i = 0; i < 3; i++)
	{
		ClassScore2[i].ShowScore();
	}
	return 0;
}

//计算火车旅途时间的组合类
class clock8
{
private:
	int H, M, S;
public:
	void ShowTime()
	{
		cout << H << ":";
		cout << M << ":";
		cout << S << endl;
	}
	void SetTime(int H=0, int M=0, int S=0)
	{
		this->H = H;
		this->M = M;
		this->S = S;
	}
	clock8(int H = 0, int M = 0, int S = 0)
	{
		this->H = H;
		this->M = M;
		this->S = S;
	}
	int GetH() { return H; }
	int GetM() { return M; }
	int GetS() { return S; }
};
class TrainTrip
{
private:
	const char* trainNo;//车次
	clock8 startTime;//出发时间
	clock8 endTime;//到达时间
public:
	TrainTrip(const char * trainNo, clock8 S, clock8 E)
	{
		this->trainNo = trainNo;
		startTime = S;
		endTime = E;
	}
	clock8 TripTime()
	{
		int tH, tM, tS;//存储小时、分、秒数
		int carry = 0;//借位
		clock8 tTime;//存储临时时间
		(tS = endTime.GetS() - startTime.GetS()) > 0 ? carry = 0 : tS += 60, carry = 1;
		(tM = endTime.GetM() - startTime.GetM()-carry) > 0 ? carry = 0 : tM += 60, carry = 1;
		(tH = endTime.GetH() - startTime.GetH() - carry) > 0 ? carry = 0 : tH += 24;
		tTime.SetTime(tH, tM, tS);
		return tTime;
	}
};
int p5_8()
{
	clock8 c1(8, 10, 10), c2(6, 1, 2);
	clock8 c3;
	TrainTrip t1("K16", c1, c2);
	c3 = t1.TripTime();
	c3.ShowTime();
	return 0;
}

//含有对象计数器的学生类
class student {
private:
	char* Name;
	int No;
	static int countS;
public:
	static int GetCount()
	{
		return countS;
	}
	student(const char* = "", int = 0);
	student(student&);
	~student();
};
student::student(const char* Name, int No)
{
	this->Name = new char[strlen(Name) + 1];
	strcpy_s(this->Name,13, Name);
	this->No = No;
	++countS;
	cout << "constructing:" << Name << endl;
}
student::student(student&r)
{
	Name = new char[strlen(Name) + 1];
	strcpy_s(Name,13, r.Name);
	No = r.No;
	++countS;
	cout << "copy constructing:" << r.Name << endl;
}
student::~student()
{
	cout << "destructing:" << Name << endl;
	delete[]Name;
	--countS;
}
int student::countS = 0;
int p5_9()
{
	cout << student::GetCount() << endl;//使用类调用静态成员函数
	student s1("Antony");//建立一个新对象
	cout << s1.GetCount() << endl;//通过对象调用静态成员函数
	student s2(s1);//利用已有对象建立一个新对象
	cout << s1.GetCount() <<endl;
	student s3[2];//建立一个对象数组
	cout << student::GetCount() << endl;
	student * s4 = new student[3];//建立一个动态数组
	cout << student::GetCount() << endl;
	delete[]s4;//删除动态对象数组
	cout << student::GetCount() << endl;
	return 0;
}
class clock10
{
private:
	int H, M, S;
public:
	void ShowTime()
	{
		cout << H << ":";
		cout << M << ":";
		cout << S << endl;
	}
	void SetTime(int H = 0, int M = 0, int S = 0)
	{
		this->H = H;
		this->M = M;
		this->S = S;
	}
	clock10(int H = 0, int M = 0, int S = 0)
	{
		this->H = H;
		this->M = M;
		this->S = S;
	}
	friend clock10 TripTime(clock10 &StartTime, clock10 &EndTime);
};
clock10 TripTime(clock10 &StartTime, clock10 &EndTime)
{
	int tH, tM, tS;//存储小时、分、秒数
	int carry = 0;//借位
	clock10 tTime;//存储临时时间
	(tS = EndTime.S - StartTime.S) > 0 ? carry = 0 : tS += 60, carry = 1;
	(tM = EndTime.M - StartTime.M - carry) > 0 ? carry = 0 : tM += 60, carry = 1;
	(tH = EndTime.H - StartTime.H - carry) > 0 ? carry = 0 : tH += 24;
	tTime.SetTime(tH, tM, tS);
	return tTime;
}
int p5_10()
{
	clock10 c1(8, 10, 10), c2(6, 1, 2);
	clock10 c3;
	c3 = TripTime(c1, c2);
	c3.ShowTime();
	return 0;
}

//计算火车旅途时间的友元类
class TrainTrip11;
class clock11
{
private:
	int H, M, S;
public:
	void ShowTime()
	{
		cout << H << ":";
		cout << M << ":";
		cout << S << endl;
	}
	void SetTime(int H = 0, int M = 0, int S = 0)
	{
		this->H = H;
		this->M = M;
		this->S = S;
	}
	clock11(int H = 0, int M = 0, int S = 0)
	{
		this->H = H;
		this->M = M;
		this->S = S;
	}
	friend class TrainTrip11;
};
class TrainTrip11 {
private:
	const char* trainNo;//车次
	clock11 startTime;//出发时间
	clock11 endTime;//到达时间
public:
	TrainTrip11(const char * trainNo, clock11 S, clock11 E)
	{
		this->trainNo = trainNo;
		startTime = S;
		endTime = E;
	}
	clock11 TripTime11()
	{
		int tH, tM, tS;//存储小时、分、秒数
		int carry = 0;//借位
		clock11 tTime;//存储临时时间
		(tS = endTime.S - startTime.S) > 0 ? carry = 0 : tS += 60, carry = 1;
		(tM = endTime.M - startTime.M - carry) > 0 ? carry = 0 : tM += 60, carry = 1;
		(tH = endTime.H - startTime.H - carry) > 0 ? carry = 0 : tH += 24;
		tTime.SetTime(tH, tM, tS);
		return tTime;
	}
 };
int p5_11()
{
	clock11 c1(8, 10, 10), c2(6, 1, 2);
	clock11 c3;
	TrainTrip11 t1("K16", c1, c2);
	c3 = t1.TripTime11();
	c3.ShowTime();
	return 0;
}                      

//演示常数据成员的使用
class A {
private:
	const int & r;//常引用数据成员
	const int a;//常数据成员
	static const int b;//静态常数据成员
public:
	A(int i) :a(i), r(a)//常数据成员只能通过初始化列表获得初始值
	{
		cout << "constructor!" << endl;
	}
	void display()
	{
		cout << a << "  " << b << "  " << r << endl;
	}
};
const int A::b = 3;//静态常数据成员在类外说明和初始化
int p5_12()
{
	A a1(1);
	a1.display();
	A a2(2);
	a2.display();
	return 0;
}