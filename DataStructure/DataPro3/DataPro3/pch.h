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

#define MaxSize 50
typedef struct
{
	int i, j;  //方块位置
	int pre;//本路径中上一个方块的下标
}Box;       //方块下标

typedef struct
{
	Box data[MaxSize];
	int front, rear;
}QuType;   //顺序队类型

typedef struct
{
	Box data[MaxSize];
	int length;
}PathType;

void mgpath2(int xi, int yi, int xe, int ye, PathType path);
bool mgpath(int xi, int yi, int xe, int ye);
void print(QuType *qu, int front);
void InitQueue(QuType *&q);
void DestroyQueue(QuType *&q);
bool QueueEmpty(QuType *q);
bool enQueue(QuType *&q, Box e);
bool deQueue(QuType *&q, Box &e);
#endif //PCH_H
