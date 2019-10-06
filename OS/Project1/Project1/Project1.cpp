
#include "pch.h"
#include <iostream>

using namespace std;

PCB *head;
PCB * tail;
int Count;

int main()
{
	/*PCB *head = new PCB();
	PCB * tail = new PCB();*/
	//时间片为1
	initial(head,tail);//初始化进程
	print(head,tail);//打印进程运行初始状态
	operation(head,tail);//执行进程
}

void initial(PCB *&head,PCB *&tail)
{
	//初始化循环队列
	initQueue(head,tail);
	cout << "请输入进程总数目：" << endl;
	cin >> Count;
	if (Count < 1)
	{
		cout << "输入错误！";
	}
	else
	{
		for (int i = 0; i < Count; i++)
		{
			PCB *pcb=new PCB();
			pcb->pid = i + 1;
			//用户获取信息
			cout << "请输入第" << pcb->pid << "个进程的名字：" << endl;
			cin >> pcb->pname;
			cout << "请输入进程" << pcb->pname << "需要运行的时间：" << endl;
			cin >> pcb->ptime;
			//其他初始信息
			pcb->palready = 0;
			pcb->status = 'R';
			//信息获取完成后入队
			enQueue(pcb,head,tail);
		}
	}
}

void print(PCB *head, PCB *tail)
{
	cout << endl;
	cout << "进程" << head->pname << "执行" << endl;
	printline();//打印表头
	cout << (head->pid) << '\t' << '\t' << (head->pname) << '\t' << '\t' << (head->ptime)
		<< '\t' << '\t' << (head->palready) << '\t' << '\t' << (head->status) << endl;
	//输出后面所有进程
	PCB *temp = head;
	while (temp != tail)
	{
		temp = temp->next;
		cout << (temp->pid) << '\t' << '\t' << (temp->pname) << '\t' << '\t' << (temp->ptime)
			<< '\t' << '\t' << (temp->palready) << '\t' << '\t' << (temp->status) << endl;
	}
}
void printline()
{
	cout << "进程编号" << "\t" << "进程名" << "\t"
		<< "要求运行时间" << "\t" << "已经运行时间" << "\t" << "进程状态";
	cout << endl;
}

void operation(PCB *&head, PCB *&tail)
{
	int flag = 1;//标记,每执行完一个进程，则加一，循环减一
	while (flag <= Count)
	{
		(head->palready)++;//执行一个时间片
		//如果队首进程已经运行完毕
		if (head->palready == head->ptime || head->ptime == 0)
		{
			head->status = 'E';//将进程状态修改为结束
			print(head,tail);//打印此时进程状态
			//出队列
			deQueue(head,tail);
			flag++;
		}
		else//如果队首进程未执行完毕
		{
			print(head,tail);//打印当前状态
			rotation(head,tail);//进程轮转，放置队尾
		}
	}
	//销毁队列
	destroyQueue(head,tail);
}

//队列操作
void initQueue(PCB * &head, PCB *& tail)
{
	head = tail = NULL;
}
void enQueue(PCB *& p, PCB *&head, PCB *&tail)
{
	if (NULL==head)//如果队列为空
	{
		head = p;
		tail = p;
		p->next = p;
	}
	else//队列不为空
	{
		//插入队尾
		p->next = head;
		tail->next = p;
		tail = p;
	}
}
void deQueue(PCB *&head, PCB *&tail)//队首进程出队列
{
	head = head->next;
	tail->next = head;
}
void rotation(PCB *&head, PCB *&tail)//将队首进程放在队尾
{
	tail = head;
	head = head->next;
}
void destroyQueue(PCB *&head, PCB *&tail)  
{
	PCB *temp = head;
	PCB *p;
	if (head != NULL)
	{
		p = temp->next;
		while (p != tail)
		{
			free(temp);
			temp = p;
			p = p->next;
		}
		free(temp);
	}
}
