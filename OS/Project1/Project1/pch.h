
#ifndef PCH_H
#define PCH_H

// TODO: 添加要在此处预编译的标头
#define N 20

struct PCB {
	int pid;//进程编号
	char pname[N];//进程名
	int ptime;//要求运行时间，假设进程需要运行的时间单位数
	int palready;//已运行的时间单位数，初始值为0
	char status;//进程的状态，共两种状态：R为就绪，E为结束
	struct PCB* next;//指向下一个PCB的首地址
};

void initial(PCB *&head, PCB *&tail);
void initQueue(PCB * &head, PCB * &tail);
void enQueue(PCB *& p, PCB *&head, PCB *&tail);

void print(PCB *head, PCB *tail);
void printline();

void operation(PCB *&head, PCB *&tail);
void deQueue(PCB *&head, PCB *&tail);
void rotation(PCB *&head, PCB *&tail);
void destroyQueue(PCB *&head, PCB *&tail);

#endif //PCH_H
