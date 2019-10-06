// DataStructure6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "time.h"
using namespace std;

void BinInsertSort(RecType R[],int n)//折半插入排序，时间复杂度O(n2)
{
	int i, j, low, high, mid;
	RecType tmp;
	for (i = 1; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)//反序时
		{
			tmp = R[i];//将R[i]保存到tmp中
			low = 0;
			high = i - 1;
			while (low<=high)//在R[low...high]中查找插入的位置
			{
				mid = (low + high) / 2;//取中间位置
				if (tmp.key < R[mid].key)
					high = mid - 1;//插入点在左半区
				else
					low = mid + 1;//插入点在右半区
			}//找位置high
			for (j = i - 1; j >= high + 1; j--)//集中进行元素后移
				R[j + 1] = R[j];
			R[high + 1] = tmp;//插入tmp
		}
	}
}

void ShellSort(RecType R[], int n)//希尔排序，一般认为时间复杂度O(n1.3)
{
	int i, j, d;
	RecType tmp;
	d = n / 2;//增量置初值
	while (d > 0)
	{
		for (i = d; i < n; i++)//对所有组采用直接插入排序
		{
			tmp = R[i];//对相隔d个位置一组采用直接插入排序
			j = i - d;
			while (j >= 0 && tmp.key < R[j].key)
			{
				R[j + d] = R[j];
				j = j - d;
			}
			R[j + d] = tmp;
		}
		d = d / 2;//减小增量
	}
}

int partition(RecType R[], int s, int t)//一趟划分
{
	int i = s, j = t;
	RecType tmp = R[i];//以R[i]为基准
	while (i < j)//从两端交替向中间扫描，直至i=j为止
	{
		while (j > i&&R[j].key >= tmp.key)
			j--;//从右向左扫描，找一个小于tmp.key的R[j]
		R[i] = R[j];//找到这样的R[j],放入R[i]处
		while (i < j&&R[j].key <= tmp.key)
			i++;//从左向右扫描，找一个大于tmp.key的R[i]
		R[j] = R[i];//找到这样的R[i],放入R[j]处
	}
	R[i] = tmp;
	return i;
}

void QuickSort(RecType R[], int s, int t)//对R[s..t]的元素快速排序。快速排序的时间复杂度为O(nlog2n)
{
	int i;
	if (s < t)//区间内至少存在两个元素的情况
	{
		i = partition(R, s, t);
		QuickSort(R, s, i - 1);//对左区间递归排序
		QuickSort(R, i + 1, t);//对右区间递归排序
	}
}

void Merge(RecType R[], int low, int mid, int high)
{
	RecType * R1;
	int i = low, j = mid + 1, k = 0;
	R1 = (RecType *)malloc((high - low + 1) * sizeof(RecType));
	while(i<=mid&&j<=high)
		if (R[i].key <= R[j].key)
		{
			R1[k] = R[i];
			i++;
			k++;
		}
		else
		{
			R1[k] = R[j];
			j++;
			k++;
		}
	while (i <= mid)
	{
		R1[k] = R[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		R1[k] = R[j];
		j++;
		k++;
	}
	for (k = 0, i = low; i <= high; k++, i++)
	{
		R[i] = R1[k];
	}
	free(R1);
}

void MergePass(RecType R[], int length, int n)
{
	int i;
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)
		Merge(R, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 < n - 1)
		Merge(R, i, i + length - 1, n - 1);
}

void MergeSort(RecType R[], int n)
{
	int length;
	for (length = 1; length < n; length = 2 * length)
		MergePass(R, length, n);
}

void outPut(RecType R[], int n)//输出排序
{
	for (int i = 0; i < n; i++)
	{
		cout << R[i].key << " ";
		if ((i + 11) % 10 == 0)
			cout << endl;
	}
}

void outTimeBin(RecType R[],int n)
{
	time_t start, end;
	start = clock();
	BinInsertSort(R, n);
	end = clock();
	cout << "排序数为" << n << "时，折半排序花费时间" << (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl;
}

void outTimeShell(RecType R[], int n)
{
	time_t start, end;
	start = clock();
	ShellSort(R, n);
	end = clock();
	cout << "排序数为" << n << "时，希尔排序花费时间" << (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl;
}

void outTimeQuick(RecType R[], int n)
{
	time_t start, end;
	start = clock();
	QuickSort(R, 0, n - 1);
	end = clock();
	cout << "排序数为" << n << "时，快速排序花费时间" << (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl;
}

void outTimeMerge(RecType R[], int n)
{
	time_t start, end;
	start = clock();
	MergeSort(R, n);
	end = clock();
	cout << "排序数为" << n << "时，二路归并排序花费时间" << (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl;
}

int main()
{
	RecType R1[100];
	for (int i = 0; i < 100; i++)
		R1[i].key = 100 - i;

	BinInsertSort(R1, 100);
	ShellSort(R1, 100);
	//QuickSort(R1, 0, 99);
	MergeSort(R1, 100);
	outPut(R1, 100);

	RecType * R2 = new RecType[10000];
	for (int i = 0; i < 10000; i++)
		R2[i].key = 10000 - i;
	RecType * R3 = new RecType[100000];
	for (int i = 0; i < 100000; i++)
		R3[i].key = 100000 - i;
	RecType * R4 = new RecType[1000000];
	for (int i = 0; i < 1000000; i++)
		R4[i].key = 1000000 - i;

	outTimeBin(R2, 10000);
	outTimeShell(R2, 10000);
	//outTimeQuick(R2, 10000);
	outTimeMerge(R2, 10000);

	outTimeBin(R3, 100000);
	outTimeShell(R3, 100000);
	//outTimeQuick(R3, 100000);
	outTimeMerge(R3, 100000);

	outTimeBin(R4, 1000000);
	outTimeShell(R4, 1000000);
	//outTimeQuick(R4, 1000000);
	outTimeMerge(R4, 1000000);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
