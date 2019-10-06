#ifndef PCH_H
#define PCH_H

// TODO: 添加要在此处预编译的标头

#define MaxSize 100
typedef char Elemtype;
typedef struct node
{
	Elemtype data;
	struct node * lchild;
	struct node * rchild;
}BTNode;//声明二叉链结点类型

void CreateBTree(BTNode * &b, const char *str);
void DisplayBTree(BTNode *b);
void DestroyBTree(BTNode * &b);

void PreOrder(BTNode *b);
void PreOrder1(BTNode *b);

#endif //PCH_H
