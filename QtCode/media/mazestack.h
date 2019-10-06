#ifndef MAZESTACK_H
#define MAZESTACK_H

#include"Maze.h"
//定义存储迷宫的栈结构
typedef Maze ElementType;
typedef struct node
{
    ElementType data;
    struct node *next;
}Node;

class MazeStack
{
public:
    MazeStack():bottom(NULL),top(NULL),Size(0){}
    ~MazeStack(){}

    bool isEmpty();//判断栈是否为空
    bool Push(ElementType e);//压栈
    ElementType GetTop();//获取栈顶元素
    ElementType Pop();//出栈

private:
    Node *bottom;//栈底指针
    Node *top;//栈顶指针
    int Size;//栈元素个数
};

#endif // MAZESTACK_H
