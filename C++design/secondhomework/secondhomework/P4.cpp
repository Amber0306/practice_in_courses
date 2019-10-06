#include "stdafx.h"
#include <iostream>
#include<fstream>
using namespace std;

//extern型变量的使用
extern void p1dispG();//定义在第三章例题开头处
extern void p2dispG();//定义在start文件里
extern void p2dispg();
int G = 0, g = 0;
int p4_1()
{
	p1dispG();
	p2dispG();
	p2dispg();
	cout << "in p G= " << G << endl;
	cout << "in p g= " << g << endl;
	return 0;
}
//静态局部变量的使用
void fun4_2()
{
	static int n;
	int m = 0;
	n++;
	m++;
	cout << "m= " << m << ", n= " << n << endl;
}
int p4_2()
{
	for (int i = 0; i < 4; i++)
	{
		fun4_2();
	}
	return 0;
}

//揭开程序内存分布的秘密
int k = 300;
const int i = 100;
#define n 5
const int j = 200;
void fun4_3(int i = 1, int j = 2)
{
	const int k = 3;
	static int l = 0;
	int m;
	const char * p = "abcde";
	char * q = new char[n + 1];
	for (m = 0; m < n; m++)
	{
		q[m] = 'A' + m;
	}
	q[m] = '\0';
	cout << "函数参数的地址：" << endl;
	cout << '\t' << "&i= " << &i << '\t' << "&j= " << &j << endl;
	cout << "局部变量的地址：" << endl;
	cout << '\t' << "&k= " << &k << '\t' << "&m= " << &m;
	cout << '\t' << "&p= " << &p << '\t' << "&q= " << &q << endl;
	cout << "静态局部变量的地址：" << endl;
	cout << '\t' << "&l " << &l  << endl;
	cout << "字符串常量的地址：" << endl;
	cout << '\t' << "p串的地址=  " << (void * )p << endl;
	cout << "堆的地址：" << endl;
	cout << '\t' <<"(void* )q= "<< (void*)q << endl;
	cout << '\t' << "q串= " << q << endl;
	delete[]q;
	cout << "\tdelete后，(void* )q= " << (void*)q << endl;
	cout << "\tdelete后，q指向的单元的内容=" << q << endl;
}
int p4_3()
{
L1:fun4_3();
L2:cout << "全局变量的地址：" << endl;
	cout << '\t' << "&i= " << &i << '\t' << "&j= " << &j << '\t' << "&k= " << &k << endl;
	cout << "函数入口的地址：" << endl;
	//cout<<"&fun<<&fun<<'\t'<<"&p4_3= "<<&p4_3<<endl;//VC
	cout << "\t&fun4_3= " << (void *)fun4_3 << '\t' <<
		"&p4_3= " << (void *)p4_3 << endl;
	return 0;
}

//演示标识符作用域
int m= 100;
//int n = 200;
void fun4_4()
{
	cout << "L2: i= " << i << endl;
	{
		int i = 3;
		cout << "L3: i= " << i<< endl;
		{
			for (int i = 4; i < 5; cout << "L6: i= " << i<< endl, i++)
			{
				cout << "L4: i= " <<i << endl;
				{
					int i = 5;
					i++;
					cout << "L5: i= " << i << endl;
				}
			}
		}
	}
}
int p4_4()
{
	fun4_4();
	return 0;
}


//名字空间的使用
#include"TsingHua.h"
int p4_5()
{
	TsingHua::ShowName();//个别声明方式
	return 0;
}

using std::cout;
using std::endl;
int p4_6()
{
	using TsingHua::ShowName;
	ShowName();
	return 0;
}
