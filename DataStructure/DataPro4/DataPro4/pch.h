
#ifndef PCH_H
#define PCH_H
#define N 50             //叶子结点总数
#define M 2*N-1       //树中叶子结点数
// TODO: 添加要在此处预编译的标头

typedef struct
{
	int data;//结点值
	int weight;//权重与结点值相同
	int parent;//双亲结点
	int lchild;//左孩子结点
	int  rchild;//有孩子结点
}HTNode;


typedef struct
{
	char cd[N];//存放当前的哈夫曼码
	int start;//表示cd[start...n0]部分是哈夫曼码
}HCode;


void CreateHT(HTNode ht[], int n0);
void CreateHCode(HTNode ht[], HCode hcd[], int n0);
void DisplayHCode(HTNode ht[], HCode hcd[], int n);
#endif //PCH_H
