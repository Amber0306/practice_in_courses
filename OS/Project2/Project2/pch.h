#include<string>
#ifndef PCH_H
#define PCH_H

// TODO: 添加要在此处预编译的标头



using namespace std;

struct PCB {
	int InitAdd;
	int EndAdd;
	int Length;
	int Release;
	char name[5];
	char state[5];
};

void Init(PCB *p);
void insert(PCB *p, int i, int temp);
void print(PCB *p, int k);
void add(PCB *p, int temp);
void mix(PCB *p, int i);
void free(PCB *p, int sum);
void input(PCB *p);

int N =6;//初始结构体个数 
#endif //PCH_H
