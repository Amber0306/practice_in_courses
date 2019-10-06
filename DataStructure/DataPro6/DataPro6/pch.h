// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#ifndef PCH_H
#define PCH_H

// TODO: 添加要在此处预编译的标头

#define MAXL 1000000
typedef int KeyType;
typedef char InfoType;
typedef struct
{
	KeyType key;
	InfoType data;
}Rectype;

void swap(Rectype &x, Rectype &y);
void CreateList(Rectype R[], KeyType keys[], int n);
void DisplayList(Rectype R[], int n);

void GiveRandom(KeyType a[], int n);

void disppart(Rectype R[], int s, int t);
int partition(Rectype R[], int s, int t);
void QuikSort(Rectype R[], int s, int t);
void BinInsertSort(Rectype R[], int n);
void Merge(Rectype R[], int low, int mid, int high);
void MergePass(Rectype R[], int length, int n);
void MergeSort(Rectype R[], int n);


#endif //PCH_H
