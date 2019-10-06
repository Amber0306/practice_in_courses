

#ifndef PCH_H
#define PCH_H

#define BUF 20//缓冲区大小
#define MAX 20//最大可输入字符



struct PCB
{
	char name[10];//进程名     Producer Consumer Run Ready Block End
	char state[10];//进程状态（运行态、就绪态、等待态和完成态）
	char reason[10];//阻塞原因（为等待信号量s1或s2）
	int breakpoint;//断点
	struct PCB* next;//阻塞顺序
};

// TODO: 添加要在此处预编译的标头
void initial();
void P(int flag);
void V(int flag);
void block(int flag);
void wakeup(int flag);
void schedule();
void execute();
void display();
void free();

//全局变量
int S1;//信号量，空缓冲单元数目
int S2;//信号量，产品数目

struct PCB * ready;//就绪队列
struct PCB* block_s1;//阻塞队列（消费者）
struct PCB* block_s2;//阻塞队列（生产者）
struct PCB* producer;//生产者进程
struct PCB* consumer;//消费者进程

int pc;//程序计数器
extern int cnt_char;//字符计数器
extern int cnt_csm;//消费计数器

extern char str[MAX];//输入的字符串
extern char buffer[BUF];//缓冲区
extern int len;//输入长度

int sp = 0;//string指针
int in = 0;//生产者指针
int out = 0;//消费者指针
char temp;//临时产品
char p_record[MAX];//生产记录
int pr = 0;//生产记录指针
char c_record[MAX];//消费记录
int cr = 0;//消费记录指针
#endif //PCH_H
