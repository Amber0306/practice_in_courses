#include "pch.h"
#include <iostream>
#define N 20
using namespace std;

struct PCB {
	int pid;//进程编号
	char pname[N];//进程名
	int ptime;//要求运行时间，假设进程需要运行的时间单位数
	int palready;//已运行的时间单位数，初始值为0
	char status;//进程的状态，共两种状态：R为就绪，E为结束
	struct PCB* next;//指向下一个PCB的首地址
};

PCB pcb1, pcb2, pcb3, pcb4, pcb5, *head, *tail, *rp;

void initial();
void print();
void operation();

int main()
{
	initial();//初始化进程
	print();//打印进程运行初始状态
	operation();//执行进程
}

void initial()
{
	pcb1.pid = 1;
	pcb2.pid = 2;
	pcb3.pid = 3;
	pcb4.pid = 4;
	pcb5.pid = 5;
	pcb1.palready = pcb2.palready = pcb3.palready = pcb4.palready = pcb5.palready = 0;
	pcb1.status = pcb2.status = pcb3.status = pcb4.status = pcb5.status = '\R';
	cout << "请输入第" << pcb1.pid << "个进程的名字：" << endl;
	cin >> pcb1.pname;
	cout << "请输入进程" << pcb1.pname << "需要运行的时间：" << endl;
	cin >> pcb1.ptime;
	cout << "请输入第" << pcb2.pid << "个进程的名字：" << endl;
	cin >> pcb2.pname;
	cout << "请输入进程" << pcb2.pname << "需要运行的时间：" << endl;
	cin >> pcb2.ptime;
	cout << "请输入第" << pcb3.pid << "个进程的名字：" << endl;
	cin >> pcb3.pname;
	cout << "请输入进程" << pcb3.pname << "需要运行的时间：" << endl;
	cin >> pcb3.ptime;
	cout << "请输入第" << pcb4.pid << "个进程的名字：" << endl;
	cin >> pcb4.pname;
	cout << "请输入进程" << pcb4.pname << "需要运行的时间：" << endl;
	cin >> pcb4.ptime;
	cout << "请输入第" << pcb5.pid << "个进程的名字：" << endl;
	cin >> pcb5.pname;
	cout << "请输入进程" << pcb5.pname << "需要运行的时间：" << endl;
	cin >> pcb5.ptime;
	//构成循环队列
	pcb1.next = &pcb2;
	pcb2.next = &pcb3;
	pcb3.next = &pcb4;
	pcb4.next = &pcb5;
	pcb5.next = &pcb1;
	head = &pcb1;
	tail = &pcb5;
}

void printline()
{
	cout << "进程编号" << "\t" << "进程名" << "\t"
		<< "要求运行时间" << "\t" << "已经运行时间" << "\t" << "进程状态";
	cout << endl;
}

void print()
{
	cout << "进程" << head->pname << "执行" << endl;
	printline();//打印表头
	cout << (head->pid) << '\t' << '\t' << (head->pname) << '\t' << '\t' << (head->ptime)
		<< '\t' << '\t' << (head->palready) << '\t' << '\t' << (head->status) << endl;
	//输出后面所有进程
	rp = head;
	while (rp != tail)
	{
		rp = rp->next;
		cout << (rp->pid) << '\t' << '\t' << (rp->pname) << '\t' << '\t' << (rp->ptime)
			<< '\t' << '\t' << (rp->palready) << '\t' << '\t' << (rp->status) << endl;
	}
}

void operation()
{
	int flag = 1;//标志单元
	while (flag <= 5)
	{
		(head->palready)++;//执行一个时间片
		//如果队首进程已经运行完毕
		if (head->palready == head->ptime || head->ptime == 0)
		{
			head->status = 'E';//将进程状态修改为结束
			print();//打印此时进程状态
			//出队列
			head = head->next;
			tail->next = head;
			flag++;
		}
		else//如果队首进程未执行完毕
		{
			print();//打印当前状态
			tail = head;
			head = head->next;//进程轮转，放置队尾
		}
	}
}

