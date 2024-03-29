// Project2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	PCB p[10];
	Init(p);
	input(p);
}

//初始化空闲区和已分配区 
void Init(PCB *p)
{
	FILE *r = fopen("123.txt", "r");
	printf("起始地址  长度  中止地址    name         状态\n");
	for (int i = 0; i < 6; i++) {
		fscanf(r, "%d%d%d%s%s\n", &p[i].InitAdd, &p[i].Length, &p[i].EndAdd, p[i].name, p[i].state);
		printf("%6d%6d%6d%14s%14s\n", p[i].InitAdd, p[i].Length, p[i].EndAdd, p[i].name, p[i].state);
	}
	fclose(r);
}

//作业装入主存 
void insert(PCB *p, int i, int temp) {
	if (p[i].Length == temp) {
		p[i].Length = temp;
		p[i].EndAdd = p[i].InitAdd + p[i].Length;
		strcpy(p[i].name, "作业");
		strcpy(p[i].state, "已分配");
	}
	else {
		for (int j = N; j >= i; j--)
			p[j + 1] = p[j];
		p[i].Length = temp;
		p[i].EndAdd = p[i].InitAdd + p[i].Length;
		strcpy(p[i].name, "作业");
		strcpy(p[i].state, "已分配");
		p[i + 1].InitAdd = p[i].EndAdd;
		p[i + 1].Length = p[i + 1].EndAdd - p[i + 1].InitAdd;
		N++;
	}
}

//输出作业分匹配后的空闲区 
void print(PCB *p, int k) {
	if (k == 1)
		printf("作业分配成功\n");
	else if (k == 0)
		printf("作业等待\n");
	else if (k == 2)
		printf("作业释放成功\n");
	printf("起始地址  长度   结束地址  name    状态\n");
	for (int i = 0; i < N; i++)
		printf("%5d%8d%8d%10s%9s\n", p[i].InitAdd, p[i].Length, p[i].EndAdd, p[i].name, p[i].state);
}

//作业和主存空闲区比较 
void add(PCB *p, int temp) {
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (strcmp(p[i].name, "空闲") == 0 && p[i].Length >= temp) {
			insert(p, i, temp);
			k = 1;
			break;
		}
	}
	print(p, k);
}

void mix(PCB *p, int i) {
	if (strcmp(p[i - 1].name, "空闲") == 0) {
		p[i - 1].Length = p[i - 1].Length + p[i].Length;
		p[i - 1].EndAdd = p[i].EndAdd;
		for (int j = i; j < N - 1; j++)
			p[j] = p[j + 1];
		N--;
	}
	else if (strcmp(p[i + 1].name, "空闲") == 0) {
		p[i].Length = p[i].Length + p[i + 1].Length;
		p[i].EndAdd = p[i + 1].EndAdd;
		for (int j = i + 1; j < N - 1; j++)
			p[j] = p[j + 1];
		N--;
	}
	for (int i = 0; i < N - 1; i++) {
		if (strcmp(p[i].name, "空闲") == 0 && strcmp(p[i].name, p[i + 1].name) == 0) {
			p[i].Length = p[i].Length + p[i + 1].Length;
			p[i].EndAdd = p[i + 1].EndAdd;
			for (int j = i + 1; j < N - 1; j++)
				p[j] = p[j + 1];
			N--;
		}
	}
}

//作业释放 
void free(PCB *p, int sum) {
	int temp = 1;
	while (temp <= sum)
		for (int i = 0; i < N; i++) {
			if (p[i].Release == temp) {
				strcpy(p[i].name, "空闲");
				strcpy(p[i].state, "未分配");
				mix(p, i);
				print(p, 2);
				temp++;
			}
		}
}

//作业申请
void input(PCB *p) {
	int n;
	int temp;
	int sum = 0;
	printf("输入申请作业内容个数：\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("长度:");
		scanf("%d", &temp);
		add(p, temp);
	}

	//作业释放顺序	
	for (int i = 0; i < N; i++) {
		if (strcmp(p[i].name, "作业") == 0)
			sum++;
	}
	printf("作业个数为：%d\n", sum);
	printf("输入作业的释放顺序\n");
	for (int i = 0; i < N; i++) {
		if (strcmp(p[i].name, "作业") == 0) {
			printf("p[%d]:", i);
			scanf("%d", &temp);
			p[i].Release = temp;
		}
		else
			p[i].Release = 0;
	}
	free(p, sum);
}



