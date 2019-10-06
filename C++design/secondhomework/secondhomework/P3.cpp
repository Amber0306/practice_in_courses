#include "stdafx.h"
#include <iostream>
#include<cstring>
#include<fstream>
using namespace std;

extern int G;
void p1dispG()
{
	G = 11;
	cout << "in p1 G= " << G << endl;
}

//枚举类型的使用
enum city{Beijing,Shanghai,Tianjing=6,Chongqing};
int p3_1()
{
	int n;
	cout << "Input a city number(" << Beijing - 1 << " to exit):" << endl;
	cin >> n;
	while (n >= Beijing)
	{
		switch (n) {
		case Beijing:cout << "Beijing" << endl; break;
		case Tianjing:cout << "Tianjing" << endl; break;
		case Chongqing:cout << "Chongqing" << endl; break;
		case Shanghai:cout << "Shanghai" << endl; break;
		default:cout << "Invalid city number!" << endl; break;
		}
		cin >> n;
	}
	return 0;
}

//数组应用-选择排序
int p3_2()
{
	const int MaxN = 5;
	int n, a[MaxN], i, j;
	for (n = 0; n < MaxN; n++)
	{
		cin >> a[n];//输入数组元素
		if (a[n] < 0)
			break;
	}
	//对数组元素逐趟进行排序
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				int t;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << endl;//显示排序结果
	}
	return 0;
}

//计算一个班每个学生各门功课的总成绩，并计算每门功课的平均分
int p3_3()
{
	const int MaxN = 100, CourseN = 5;
	int n;
	int score[MaxN][CourseN + 1] = { 0 };
	float aver[CourseN + 1] = { 0 };
	for (n = 0; n < MaxN; n++)//输入学生成绩
	{
		for (int j = 0; j < CourseN; j++)
		{
			cin >> score[n][j];
			if (score[n][0] < 0)break;
		}
	}
	for (int i = 0; i < n; i++)//计算每个学生的总分
	{
		for (int j = 0; j < CourseN; j++)
		{
			score[i][CourseN] = score[i][CourseN] + score[i][j];
		}
	}
	for (int j = 0; j < CourseN + 1; j++)//计算每门课程的平均分
	{
		for (int i = 0; i < n; i++)
		{
			aver[j] = aver[j] + score[i][j];
		}
		aver[j] = aver[j] / n;
	}
	for (int i = 0; i < n; i++)//输出诶个人的成绩与总分
	{
		for (int j = 0; j < CourseN + 1; j++)
		{
			cout << score[i][j] << endl;
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	for ( int i = 0; i < CourseN + 1; i++)//输出每门功课的平均分
	{
		cout << aver[i] << endl;
	}
	cout << endl;
	return 0;
}

//利用一个多维数组的某列排序的函数将学生某门功课的成绩分班级排序
const int col = 5;
enum dir{Asc,Des};
void sort(int a[][col], int n, int Cn, dir D)//排序
{
	int t[col];//用于暂存一行数据
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)//从待排序序列中选出一个最大（最小）的数组元素
		{
			if (a[i][Cn]<a[j][Cn] && D == Des || a[i][Cn]>a[j][Cn] && D&&Asc)
			{
				memcpy(t, a[i], sizeof(t));//交换数组行
				memcpy(a[i], a[j], sizeof(t));
				memcpy(a[j], t, sizeof(t));
			}
		}
	}
}
int p3_4()
{
	const int CourseN = 5;
	int n;
	int score[][CourseN] = { {20060101,1,82,86,0},
	{20060203,2,80,80,0},
	{20060204,2,86,90,0},
	{20060205,2,90,83,0},
	{20060102,1,75,86,0} };
	n = sizeof(score) / sizeof(score[0]);
	for (int i = 0; i < n; i++)//计算每个学生的总分
	{
		for (int j = 2; j < CourseN - 1; j++)
		{
			score[i][CourseN-1] = score[i][CourseN-1] + score[i][j];
		}
	}
	sort(score, n, 4, Des);//按总分的降序排列
	sort(score, n, 1, Asc);//按班号的升序排列
	for (int i = 0; i < n; i++)//输出每个人的成绩与总分
	{
		for (int j = 0; j < CourseN; j++)
		{
			cout << score[i][j] << endl;
		}
		cout << endl;
	}
	return 0;
}

//字符串的排序与查找
const int NameLen = 20;
void order(char name[][NameLen], int n)//字符串排序
{
	char temp[NameLen];
	for (int i = 0; i < n - 1; i++)//选择排序
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(name[i], name[j]) > 0)//比较两个字符串大小
			{
				strcpy_s(temp, name[i]);//字符串交换
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], temp);
			}
		}
	}
}
int find(char name[][NameLen], int n, char searchname[NameLen])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(name[i], searchname) == 0)//找到，返回位置
			return i + 1;
		else if (strcmp(name[i], searchname) > 0)//未找完，找不到，返回0
			return 0;
	}
	return 0;//找完，找不到，返回0
}
int p3_5()
{
	char NameTab[][NameLen] = { "Gongjing","liuna","huangping","zhouzijun",
	"linxiaolei","chenhailing","cuipeng","liuping" };
	char searchname[NameLen];
	int n = sizeof(NameTab) / NameLen;
	order(NameTab, n);
	for (int i = 0; i < n; i++)//输入排序后的各姓名
	{
		cout << i + 1 << '\t' << NameTab[i] << endl;
	}
	cout << "Input the searching name: ";
	cin >> searchname;
	if (n = find(NameTab, n, searchname))
	{
		cout << "Position:" << n << endl;
	}
	else {
		cout << "Not found!" << endl;
	}
	return 0;
}

//动态二维矩阵
int p3_6()
{
	int m, n;
	int**dm;
	cout << "Input matric size m,n:";
	cin >> m >> n;
	dm = new int *[m];//建立m个指针存储m行
	for (int i= 0; i < m; i++)//为每行分配n个空间
	{
		if ((dm[i]=new int[n])==NULL)
			exit(0);
	}
	for (int i = 0; i < m; i++)//输入矩阵元素
	{
		for (int j = 0; j < n; j++)
			cin >> dm[i][j];
	}
	for (int i = 0; i < m; i++)//输出矩阵元素
	{
		for (int j = 0; j < n; j++)
			cout << dm[i][j] << endl;
		cout << endl;
	}
	for (int i = 0; i < m; i++)
		delete[]dm[i];//释放m个指针指向的空间
	delete[]dm;//释放m个指针
	return 0;
}

//动态创建多维数组
int p3_7()
{
	float(*p)[3][4];
	int i, j, k;
	p = new float[2][3][4];
	for (int i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				*(*(*(p + i) + j) + k) = i * 100 + j * 10 + k;
			}//通过指针访问数组元素
		}
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				//将指针cp作为数组名使用，通过数组名和下标访问数组元素
				cout << p[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}

//实现两个数据交换的通用代码
void swap_i(int * num1, int * num2)//整数型交换
{
	int t;
	t = *num1;
	*num1 = *num2;
	*num2 = 5;
}
void swap(void* num1, void* num2, int size)
{
	char* first = (char*)num1, *second = (char*)num2;
	for (int k = 0; k < size; k++)
	{
		char temp;
		temp = first[k];
		first[k] = second[k];
		second[k] = temp;
	}
}
int p3_8()
{
	int a = 3, b = 6;
	double x = 2.3, y = 4.5;
	char c1[8] = "John", c2[8] = "Antony";
	cout << "Before swap: a= " << a << " b= " << b << endl;
	swap_i(&a, &b);
	cout << "After swap: a= " << a << " b= " << b << endl;
	cout << "Before swap: x= " << x << " y= " << y << endl;
	swap(&x, &y,sizeof(x));
	cout << "After swap: x= " << x << " y= " << y << endl;
	cout << "Before swap: c1= " << c1 << " c2= " << c2 << endl;
	swap(&c1, &c2,sizeof(c1));
	cout << "After swap: c1= " << c1 << " c2= " << c2 << endl;
	return 0;
}

//超长整数加法
char * ladd(char* s1, char* s2)
{
	int n1, n2, n;
	char*res, c = 0;
	n1 = strlen(s1);//n1为字符串s1的长度
	n2 = strlen(s2);//n2为字符串s2的长度
	n = n1 > n2 ? n1 : n2;//字符串s1,s2的最大长度
	res = new char[n + 2];//申请结果串的内存
	for (int i = n + 1; i >= 0; i--)//将s1从低位开始搬到res，没有数字的位及最高位填‘0’
	{
		res[i] = i > n - n1 ? s1[i - n - 1 + n1] : '0';
	}
	for (int i = n; i >= 0; i--)
	{
		char tchar;
		tchar = i > n - n2 ? res[i] - '0' + s2[i - n + n2 - 1] - '0' + c : res[i] - '0' + c;
		//将数字符变成数
		c = tchar > 9 ? 1 : 0;//设进位
		res[i] = c > 0 ? tchar - 10 + '0' : tchar + '0';//将数字变成数字字符
	}
	return res;
}
int p3_9()
{
	char num1[100], num2[100], *num;
	cin >> num1 >> num2;
	num = ladd(num1, num2);
	cout << num1 << " + " << num2 << " = " << num << endl;
	delete[]num;
	return 0;
}

//模拟简单菜单程序
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { if (b == 0)return 0x7fffffff; else return a / b; }
int(*menu[])(int a, int b) = { add,sub,mul,divi };
int p3_10()
{
	int num1, num2, choice;
	cout << "Select operater:" << endl;
	cout << "   1:add" << endl;
	cout << "   2:sub" << endl;
	cout << "   3:multiply" << endl;
	cout << "   4:divide" << endl;
	cin >> choice;
	cout << "Input number(a,b):";
	cin >> num1 >> num2;
	cout << "Result:" << menu[choice - 1](num1, num2) << endl;
	return 0;
}

//使用引用参数实现两个数的交换
void swap(int &refx,int &refy)
{
	int temp;
	temp = refx;
	refx = refy;
	refy = temp;
}
int p3_11()
{
	int x = 3, y = 5;
	cout << "Before swap: x= " << x << " y= " << y << endl;
	swap(x, y);
	cout << "After swap: x= " << x << " y= " << y << endl;
	return 0;
}

//使用引用作为函数的返回值
int max1(int a[], int n)//求数组a[]中元素的最大值
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[t])t = i;
	}
	return a[t] + 0;
}
int& max2(int a[], int n)//求数组a[]中元素的最大值
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[t])t = i;
	}
	return a[t];
}
int& sum(int a[], int n)//求数组a[]中元素的和
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += a[i];
	}
	return s;
}
int p3_12()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int m1 = max1(a, 10);
	int m2 = max2(a, 10);
	int& m3 = max2(a, 10);
	int& m4 = sum(a, 10);
	cout << "m1= " << m1 << endl;
	cout << "m2= " << m2 << endl;
	cout << "m3= " << m3 << endl;
	cout << "m4= " << m4 << endl;
	m3 += 10;
	max2(a, 10) - +100;
	cout << sum(a, 10) << endl;
	return 0;
}

//学生成绩的排序，结构数组的应用
struct student
{
	char name[20];
	float score;
	student* next;
};
int input(student s[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cin >> s[i].name;
		cin >> s[i].score;
		if (s[i].score < 0)break;
	}
	return i;
}
void output(student s[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		cout << s[i].name << '\t' << s[i].score << endl;
}
void sort1(student a[], int n)//按分数排序
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].score < a[j].score)
			{
				student t;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
int p3_13()
{
	const int maxNum = 100;
	int num;
	student s[maxNum];
	num = input(s, maxNum);
	sort1(s, num);
	output(s, num);
	return 0;
}

//单向链表的排序查找插入删除
student* Search(student* head, int key)//查找关键词小于key的结点前驱
{
	student* p = head;
	while (p->next != NULL)
	{
		if (p->next->score< key)
		{
			return p;
		}
		p = p->next;
	}
	return p;
}
void Insertstudent(student*p, student*newp)//在P后插入结点newp
{
	newp->next = p->next;
	p->next = newp;
}
void Delstudent(student*p)//删除P结点的一个后继节点
{
	student* q;
	if (p->next != NULL) 
	{
		q = p->next;
		p->next = q->next;
		delete q;
	}
}
void DelList(student* head)//销毁整个链表
{
	student* p = head;
	while (head->next != NULL)
	{
		head = head->next;
		delete p;
		p = head;
	}
	delete head;
}
void DisList(student* head)//显示链表各元素
{
	student* p = head;
	while (p->next != NULL)
	{
		cout << p->next->name << '\t' << p->next->score << endl;
		p = p->next;
	}
}
//构造链表，手动输入
int List()
{
	student* newp, *head, *p;
	char name[6];
	float score, low = 60;
	if((newp =new student)== NULL)
	{
		cout << "new student fail! " << endl;
	    exit(0);
	}
	head = newp;
	head->next = NULL;
	cout << "Input name and score(- 1 to exit):" << endl;
	cin >> name >> score;
	while (score > 0)
	{
		if ((newp = new student) == NULL)
		{
			cout << "new student fail! " << endl;
			exit(0);
		}
		strcpy_s(newp->name, name);
		newp->score = score;
		newp->next = NULL;
		p = Search(head, score);
		Insertstudent(p, newp);
		cin >> name >> score;
	}
	cout << "Before delete:" << endl;
	DisList(head);
	for (p = Search(head, low); p->next != NULL; p = Search(head, low))
	{
		Delstudent(p);
	}
	cout << "After delete:" << endl;
	DisList(head);
	DelList(head);
	return 0;
}
//
//student* Search(student* head, int key)//查找关键词小于key的结点前驱
//{
//	student* p = head;
//	while (p->next != NULL)
//	{
//		if (p->next->score < key)
//		{
//			return p;
//		}
//		p = p->next;
//	}
//	return p;
//}

//void Insertstudent(student*p, student*newp)//在P后插入结点newp
//{
//	newp->next = p->next;
//	p->next = newp;
//}
//void Delstudent(student*p)//删除P结点的一个后继节点
//{
//	student* q;
//	if (p->next != NULL)
//	{
//		q = p->next;
//		p->next = q->next;
//		delete q;
//	}
//}
//void DelList(student* head)//销毁整个链表
//{
//	student* p = head;
//	while (head->next != NULL)
//	{
//		head = head->next;
//		delete p;
//		p = head;
//	}
//	delete head;
//}
//void DisList(student* head)//显示链表各元素
//{
//	student* p = head;
//	while (p->next != NULL)
//	{
//		cout << p->next->name << '\t' << p->next->score << endl;
//		p = p->next;
//	}
//}
//构造链表，手动输入
int p3_14()
{
	student* newp, *head, *p;
	char name[20];
	float score, low = 60;
	if ((newp = new student) == NULL)
	{
		cout << "new student fail! " << endl;
		exit(0);
	}
	head = newp;
	head->next = NULL;
	cout << "Input name and score(- 1 to exit):" << endl;
	cin >> name >> score;
	while (score > 0)
	{
		if ((newp = new student) == NULL)
		{
			cout << "new student fail! " << endl;
			exit(0);
		}
		strcpy_s(newp->name, name);
		newp->score = score;
		newp->next = NULL;
		p = Search(head, score);
		Insertstudent(p, newp);
		cin >> name >> score;
	}
	cout << "Before delete:" << endl;
	DisList(head);
	for (p = Search(head, low); p->next != NULL; p = Search(head, low))
	{
		Delstudent(p);
	}
	cout << "After delete:" << endl;
	DisList(head);
	DelList(head);
	return 0;
}

//显示联合体中各类型成员的内存排列
int p3_15()
{
	union UData
	{
		char ch;
		short sint;
		long lint;
		unsigned unint;
		float f;
		double d;
		char str[10];
	};
	UData u;
	strcpy_s(u.str, "123456789");
	cout << "char:" << '\t' << u.ch << endl;
	cout << "short:" << '\t' << u.sint << endl;
	cout << "long:" << '\t' << u.lint << endl;
	cout << "unsigned:" << '\t' << u.unint << endl;
	cout << "float:" << '\t' << u.f << endl;
	cout << "double:" << '\t' << u.d << endl;
	cout << "string:" << '\t' << u.str << endl;
	return 0;
}