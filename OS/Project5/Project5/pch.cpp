// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "pch.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。
int cnt_char;//字符计数器
int cnt_csm;//消费计数器

char str[MAX];//输入的字符串
char buffer[BUF];//缓冲区
int len;//输入长度

void initial()
{
	S1 = BUF;//全部空闲
	S2 = 0;//没有产品

	//生产者PCB初始化
	producer = new PCB();
	strcpy_s(producer->name, "Producer");
	strcpy_s(producer->state, "Ready");
	strcpy_s(producer->reason, "Null");
	producer->breakpoint = 0;
	producer->next = NULL;
	//消费者PCB初始化
	consumer = new PCB();
	//consumer = (PCB*)malloc(sizeof(PCB));
	strcpy_s(consumer->name, "Consumer");
	strcpy_s(consumer->state, "Ready");
	strcpy_s(consumer->reason, "Null");
	consumer->breakpoint = 0;
	consumer->next = NULL;

	//初始化时生产者进程在前消费者在后
	//初始化就绪队列
	ready = producer;
	ready->next = consumer;
	consumer->next = NULL;
	//初始化阻塞队列
	block_s1 = NULL;
	block_s2 = NULL;
	//计数器
	pc = 0;
	cnt_csm = 0;
}

//P操作
void P(int flag)
{
	if (flag == 0)//进行P(g_empty)操作
	{
		S1--;
		if (S1 < 0)
		{
			block(0);
		}
		else
		{
			cout << "信号量S1申请成功！" << endl;
			ready->breakpoint = pc;//保存断点
		}
	}
	else if (flag == 1)//进行P(g_full)操作
	{
		S2--;
		if (S2 < 0)
		{
			block(1);
		}
		else
		{
			cout << "信号量S2申请成功！" << endl;
			ready->breakpoint = pc;//保存断点
		}
	}
	else
	{
		cout << "错误，无此信号量！";
	}
}

//V操作
void V(int flag)
{
	if (flag == 0)//进行V(g_empty)操作
	{
		S1++;
		if (S1 <= 0)
		{
			wakeup(0);//唤醒进程
		}
		ready->breakpoint = pc;//保存断点
	}
	else if (flag == 1)//进行V(g_full)操作
	{
		S2++;
		if (S2 <= 0)
		{
			wakeup(1);
		}
		ready->breakpoint = pc;//保存断点
	}
	else
	{
		cout << "错误，无此信号量！";
	}
}

//进程函数
//阻塞
void block(int flag)
{
	struct PCB * p;
	int num1 = 0;
	int num2 = 0;
	if (flag == 0)//生产者进程（阻塞当前）
	{
		strcpy_s(producer->state,"Block");
		strcpy_s(producer->reason, "S1");
		p = block_s1;
		while (p)//寻找至队尾（阻塞队列）
		{
			num1++;
			p = p->next;//p值为null时表示队尾
		}
		if (!block_s1)//阻塞队列为空
			block_s1 = producer;
		else
			p = producer;//插入队尾
		producer->next = NULL;
		cout << " 生产者进程阻塞" << endl;
		ready->breakpoint = pc;//保留当前断点
		ready = ready->next;//在就绪队列中去掉，指向下一个
		num1++;
	}
	else if (flag == 1)//消费者进程
	{
		strcpy_s(consumer->state, "Block");
		strcpy_s(consumer->reason, "S2");
		p = block_s2;
		while (p)//寻找至队尾
		{
			num2++;
			p = p->next;//p值为null时表示队尾
		}
		if (!block_s2)
			block_s2 = consumer;
		else
			p = consumer;
	
		ready->breakpoint = pc;
		ready = ready->next;//在就绪队列中去掉，指向下一个
		consumer->next = NULL;
		cout << " 消费者进程阻塞" << endl;
		num2++;
	}
	else
	{
		cout << "错误！" << endl;
	}
	cout << "阻塞的生产者进程数为：" << num1 << endl;
	cout << "阻塞的消费者进程数为：" << num2 << endl;
}
//唤醒
void wakeup(int flag)
{
	struct PCB* p;
	struct PCB* q = ready;
	if (flag == 0)//唤醒被阻塞的生产者进程队列中的队首
	{
		p = block_s1;
		block_s1 = block_s1->next;//指针后移
		strcpy_s(p->state, "Ready");
		strcpy_s(p->reason, "Null");
		while (q)//插入就绪队列
		{
			q = q->next;
		}//插入队尾
		q = p;
		p->next = NULL;
		cout << " 生产者进程被唤醒" << endl;
	}
	else if (flag == 1)
	{
		p = block_s2;
		block_s2 = block_s2->next;//指针后移
		strcpy_s(p->state, "Ready");
		strcpy_s(p->reason, "Null");
		while (q->next)
		{
			q = q->next;
		}
		q->next = p;
		p->next = NULL;
		cout << " 消费者进程被唤醒" << endl;
	}
	else
	{
		cout << "错误！" << endl;
	}
}

//模拟处理器调度
void schedule()
{
	
	int num = 0;
	//取就绪队列
	PCB* p = ready;
	if (ready == NULL)
		return;
	//统计就绪队列中进程个数
	while (p)
	{
		num++;
		p = p->next;
	}
	cout << "就绪队列中共有" << num << "个进程" << endl;

	int random;
	time_t t;
	srand(unsigned(time(&t)));
	random = rand() % num;//产生随机数
	if (random == 1)//随机选择一就绪进程作为现行进程
	{
		p = ready;
		ready = ready->next;
		ready->next = p;
		p->next = NULL;//取出就绪队列队首
		strcpy_s(ready->state, "Run");//新的就绪队列队首执行
		strcpy_s(ready->next->state, "Ready");
	}
	else
		strcpy_s(ready->state, "Run");
	pc = ready->breakpoint;
}

//模拟处理器指令执行
void execute()
{
	if (strcmp(ready->name, "Producer") == 0)
	{
		//生产者进程
		switch (pc)
		{
		case 0://produce
			cout << "生产者生产字符" << str[sp] << endl;
			p_record[pr] = str[sp];//添加至生产记录
			sp = (sp + 1) % len;
			pc++;
			ready->breakpoint = pc;//保存断点
			break;
		case 1://P（S1）
			pc++;
			cout << "占有一个S1信号" << endl;
			P(0);
			break;
		case 2://PUT
			buffer[in] = p_record[pr];//放到缓冲区
			cout << "字符" << buffer[in] << "成功进入缓冲区" << endl;
			pr++;//修改指针
			in = (in + 1) % BUF;
			pc++;//计数器加一
			ready->breakpoint = pc;//保存断点
			break;
		case 3://V(S2)
			pc++;
			cout << "释放一个S2信号" << endl;
			V(1);
			break;
		case 4://GOTO 0
			cout << "生产者进程GOTO 0" << endl;
			pc = 0;
			cnt_char--;//字符计数器减一
			cout << "剩余" << cnt_char << "个字符" << endl;
			ready->breakpoint = pc;

			if (cnt_char<=0)
			{
				cout << "生产者进程结束" << endl;
				strcpy_s(producer->state, "End");
				strcpy_s(producer->reason, "Null");
				ready->breakpoint = -1;
				ready = ready->next;
			}
		}
	}
	else
	{
		//消费者进程
		switch (pc)
		{
		case 0://P(S2)
			pc++;
			cout << "占有一个S2信号" << endl;
			P(1);
			break;
		case 1://GET
			temp = buffer[out];
			cout << "消费者取字符" << endl;
			out = (out + 1) % BUF;
			pc++;//计数器加一
			ready->breakpoint = pc;//保存断点
			break;
		case 2://V(S1)
			pc++;
			cout << "释放一个S1信号" << endl;
			V(1);
			break;
		case 3://consume
			cout << "消费者消费字符" << temp << endl;
			c_record[cr] = temp;//添加至生产记录
			cr++;
			cnt_csm++;
			if (cnt_csm >= len)
			{
				strcpy_s(consumer->state, "End");
				consumer->breakpoint = -1;
				return;
			}
			pc++;
			ready->breakpoint = pc;//保存断点
			break;
		case 4://GOTO 0
			cout << "消费者进程GOTO 0" << endl;
			pc = 0;
			ready->breakpoint = pc;
		}
	}
}

void display()
{
	int i, j;
	cout << "****************************************" << endl;
	//cout << "模拟字符串：" << str << endl;

	cout << "已经生产：";
	for (j = 0; j <= pr; j++)
		cout << p_record[j];
	cout << endl;

	cout << "已经消费：";
	for (j = 0; j <= cr; j++)
		cout << c_record[j];
	cout << endl;

	cout << "缓存区内：";
	for (j = cr; j <= pr; j++)
		cout << buffer[j];
	cout << endl;

	
	cout << "----------------------------------------" << endl;
	cout << "进程控制块信息" << endl;
	cout << "进程名"<<"      "<<"进程状态" << "      " <<"等待原因" << "      " << "断点" << endl;
	cout << producer->name << "        " << producer->state << "        "
		<< producer->reason << "          " << producer->breakpoint << endl;
	cout << consumer->name << "        " << consumer->state << "        "
		<< consumer->reason << "          " << consumer->breakpoint << endl;
	cout << "----------------------------------------" << endl;
	cout << "****************************************" << endl;
	//cout << endl;
}

void free()
{
	PCB* temp1,*temp2;
	temp1 = ready;
	while (temp1)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	temp1 = block_s1;
	while (temp1)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	temp1 = block_s2;
	while (temp1)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	//temp1 = producer;
	//free(temp1);
	/*while (temp1)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}*/
	//temp1 =consumer;
	//free(consumer);
	/*while (temp1)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}*/
}