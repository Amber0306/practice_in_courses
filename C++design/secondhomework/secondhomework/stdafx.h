// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once



#include <stdio.h>
#include <tchar.h>




// TODO: 在此处引用程序需要的其他头文件




float ReverseFloat(float Val);
double ReverseDouble(double Val);
int ReverseInt(int Val);
short ReverseShort(short Val);
int Shifting(int a);

void Transposition(int A[3][4],int col, int row);
void Transposition1(int A[][4], int col, int row);

struct CStu
{
	char sNumer[13];
	char sName[6];
	int  nScores[5];
	CStu* next;
};
CStu* CreateLinkerFromBinaryFile(const char*pBinaryFileName);

//int input(CStu s[], int n);
//void output(CStu s[], int n);
//void sort1(CStu a[], int n);
// queue();
int List();

int p1_1();  
int p1_2(); 
int p1_3();  

int p2_1();  
int p2_2();  
int p2_3();  
int p2_5(); 
int p2_6();  
int p2_7();  
int p2_8(); 
int p2_9(); 
int p2_10();  
int p2_11();  
int p2_12();  
int p2_13();  
int p2_14();  
int p2_15();  
int p2_16();  
int p2_17();  
int p2_18(); 
int p2_19();  

int p3_1(); 
int p3_2(); 
int p3_3(); 
int p3_4();  
int p3_5(); 
int p3_7();  
int p3_8();  
int p3_9();  
int p3_10();  
int p3_11();  
int p3_12();  
int p3_13(); 
int p3_14();  

int p4_1();  
int p4_2();  
int p4_3();  
int p4_4();  
int p4_5();  
int p4_6(); 

int p5_1_a();  
int p5_1_b();
int p5_2();  
int p5_3();  
int p5_4();  
int p5_6();  
int p5_7();  
int p5_8();  
int p5_9();  
int p5_10();  
int p5_11();  
int p5_12();  

int p6_1();  
int p6_2();  
int p6_3();  
int p6_4();  
int p6_5(); 
int p6_6(); 
int p6_7(); 

int p7_1();  
int p7_2();  
int p7_3();  
int p7_4();  
int p7_5();  
int p7_6();  
int p7_7(); 
int p7_8();  
int p7_9();  
int p7_10();  
