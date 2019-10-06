// DataPro6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<math.h>
#include<ctime>

using namespace std;

/*随机生成待排序数据，其个数分为100,1万，10万，100万
*至少采用三种不同类型的排序算法，待排序100时，将结果输出
*个数为1万，10万，100万时，不输出结果，输出排序时间
*希尔排序，快速排序，折半插入排序，二路归并排序
*/

int main()
{
	int n = 100;
	//排序数为100
	/*Rectype *R = new Rectype[100];
	KeyType *a = new KeyType[100];

	GiveRandom(a, 100);
	CreateList(R, a, n);
	cout << "排序前：" << endl;
	DisplayList(R, n);
	QuikSort(R, 0, n - 1);
	cout << "快速排序后：" << endl;
	DisplayList(R, n);

	GiveRandom(a, 100);
	CreateList(R, a, n);
	cout << "排序前：" << endl;
	DisplayList(R, n);
	BinInsertSort(R, n);
	cout << "折半插入排序后：" << endl;
	DisplayList(R, n);

	GiveRandom(a, 100);
	CreateList(R, a, n);
	cout << "排序前：" << endl;
	DisplayList(R, n);
	MergeSort(R, n);
	cout << "二路归并排序后：" << endl;
	DisplayList(R, n);*/

	clock_t start, end;

	cout << endl;
	//1万
	cout << "数据量为一万：" << endl;
	n = 10000;
	Rectype *R1 = new Rectype[10000];
	KeyType *a1 = new KeyType[10000];

	start = clock();
	GiveRandom(a1, 10000);
	CreateList(R1, a1, n);
	QuikSort(R1, 0, n - 1);
	end = clock();
	cout << "快速排序运行时间: " << (double)(end - start) / CLOCKS_PER_SEC << "S" << endl;

	start = clock();
	GiveRandom(a1, 10000);
	CreateList(R1, a1, n);
	BinInsertSort(R1, n);
	end = clock();
	cout << "折半插入排序运行时间: " << (double)(end - start) / CLOCKS_PER_SEC << "S" << endl;

	start = clock();
	GiveRandom(a1, 10000);
	CreateList(R1, a1, n);
	MergeSort(R1, n);
	end = clock();
	cout << "二路归并排序运行时间: " << (double)(end - start) / CLOCKS_PER_SEC << "S" << endl;


	cout << endl;
	//10万
	cout << "数据量为十万：" << endl;
	n = 100000;
	Rectype *R2 = new Rectype[100000];
	KeyType *a2 = new KeyType[100000];

	start = clock();
	GiveRandom(a2, 100000);
	CreateList(R2, a2, n);
	QuikSort(R2, 0, n - 1);
	end = clock();
	cout << "快速排序运行时间: " << (double)(end - start) / CLOCKS_PER_SEC << "S" << endl;

	start = clock();
	GiveRandom(a2, 100000);
	CreateList(R2, a2, n);
	BinInsertSort(R2, n);
	end = clock();
	cout << "折半插入排序运行时间: " << (double)(end - start) / CLOCKS_PER_SEC << "S" << endl;

	start = clock();
	GiveRandom(a2, 100000);
	CreateList(R2, a2, n);
	MergeSort(R2, n);
	end = clock();
	cout << "二路归并排序运行时间: " << (double)(end - start) / CLOCKS_PER_SEC << "S" << endl;


	cout << endl;
	//100万
	cout << "数据量为一百万：" << endl;
	n = 1000000;
	Rectype *R3 = new Rectype[1000000];
	KeyType *a3 = new KeyType[1000000];

	start = clock();
	GiveRandom(a3, 1000000);
	CreateList(R3, a3, n);
	QuikSort(R3, 0, n - 1);
	end = clock();
	cout << "快速排序运行时间: " << (double)(end - start) / CLOCKS_PER_SEC << "S" << endl;

	start = clock();
	GiveRandom(a3, 1000000);
	CreateList(R3, a3, n);
	BinInsertSort(R3, n);
	end = clock();
	cout << "折半插入排序运行时间: " << (double)(end - start) / CLOCKS_PER_SEC << "S" << endl;

	start = clock();
	GiveRandom(a3, 1000000);
	CreateList(R3, a3, n);
	MergeSort(R3, n);
	end = clock();
	cout << "二路归并排序运行时间: " << (double)(end - start) / CLOCKS_PER_SEC << "S" << endl;

	
	return 1;
}

//产生随机数
void GiveRandom(KeyType a[],int n)
{
	int i = 0;
	while (i < n)
	{
		a[i] = rand();
		i++;
	}
}
//快速排序
void disppart(Rectype R[], int s,int t)//显示一趟划分后的结果
{
	static int i = 1;
	int j;
	cout << "第" << i << "次划分：" << endl;
	for (j = 0; j < s; j++)
	{
		cout << "     ";
	}
	for (j = s; j <= t; j++)
	{
		cout << R[j].key;
		cout << ",";
	}
	cout << endl;
	i++;
}
int partition(Rectype R[], int s, int t)//一次划分
{
	int i = s, j = t;
	Rectype tmp = R[i];//以R[i]为基准
	while (i < j)//两端交替向中间扫描
	{
		while (j > i && R[j].key >= tmp.key)
		{
			j--;
		}
		R[i] = R[j];
		while (i < j && R[i].key <= tmp.key)
		{
			i++;
		}
		R[j] = R[i];
	}
	R[i] = tmp;
	//disppart(R, s, t);
	return i;
}
void QuikSort(Rectype R[], int s, int t)//递增快速排序
{
	int i;
	if (s < t)
	{
		i = partition(R, s, t);
		QuikSort(R, s, i - 1);
		QuikSort(R, i + 1, t);
	}
}
//折半插入排序
void BinInsertSort(Rectype R[], int n)
{
	int i, j, low, high, mid;
	Rectype tmp;
	for (i = 1; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)//反序时
		{
			//cout << "i=" << i << ",插入" << R[i].key << ",插入结果：";
			tmp = R[i];
			low = 0; high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (tmp.key < R[mid].key)
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (j = i - 1; j >= high + 1; j--)
			{
				R[j + 1] = R[j];
			}
			R[high + 1] = tmp;
		}
		//DisplayList(R, n);
	}
}

//二路归并排序
void Merge(Rectype R[], int low, int mid, int high)//一次归并，将两个有序表归并成一个
{
	Rectype *R1;
	int i = low, j = mid + 1, k = 0;//i,j分别为第一、二段下标
	R1 = (Rectype *)malloc((high - low + 1) * sizeof(Rectype));
	while (i <= mid && j <= high)
	{
		if (R[i].key <= R[j].key)
		{
			R1[k] = R[i];
			i++; k++;
		}
		else 
		{
			R1[k] = R[j];
			j++; k++;
		}
	}
	while (i <= mid)//第一段余下部分复制到R1
	{
		R1[k] = R[i];
		i++; k++;
	}
	while (j <= high)//第二段余下部分复制到R2
	{
		R1[k] = R[j];
		j++; k++;
	}
	for (k = 0, i = low; i <= high; k++, i++)
		R[i] = R1[k];//将R1复制回R中
}
int counts = 1;
void MergePass(Rectype R[], int length, int n)//实现一趟归并
{
	int i;
	//cout << "第" <<(counts++) << "趟归并：";
	//归并length长的两相邻子表
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)//归并length长的两相邻子表
	{
		//cout << "R[" << i << "," << i + length - 1 
		//	<< "]和R[" << i + length << "," << i + 2 * length - 1 << "]归并";
		Merge(R, i, i + length - 1, i + 2 * length - 1);
	}
	//余下两个子表后者长度小于length
	if (i + length - 1 < n - 1)
	{
		/*cout << "*R[" << i << "," << i + length - 1
			<< "]和R[" << i + length << "," << n - 1 << "]归并";*/
		Merge(R, i, i + length - 1, n - 1);
	}
	/*cout << endl;
	cout << "归并结果：";*/
	//DisplayList(R, n);
}
void MergeSort(Rectype R[], int n)//实现算法
{
	int length;
	for (length = 1; length < n; length = 2 * length)
		MergePass(R, length, n);
}
