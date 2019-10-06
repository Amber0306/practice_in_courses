#include"MazeStack.h"
//这里是栈的基本操作，不再赘述
bool MazeStack::isEmpty()
{
    if(top==bottom)
        return true;
    return false;
}

bool MazeStack::Push(Maze m)
{
    Node *temp;
    temp=top;
    top=new Node();
    if(!top)
        return false;
    top->data=m;
    top->next=temp;
    Size++;
    return true;
}

Maze MazeStack::Pop()
{
    Node temp;
    temp.data=top->data;
    temp.next=top->next;
    delete top;
    top=temp.next;
    Size--;
    return temp.data;
}

Maze MazeStack::GetTop()
{
    return top->data;
}

