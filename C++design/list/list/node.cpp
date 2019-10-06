#include"node.h"
#include<iostream>

//结点类的实现部分
//构造函数初始化数据和指针成员
template<class T>
Node <T>::Node(const T &data, Node<T> *next = 0) :data(data), next(next) {}

//返回后继的结点的指针
template<class T>
Node <T> *Node <T>::nextNode()
{
	return next;
}

//返回后继结点的指针
template<class T>
Node <T> *Node <T>::nextNode()const
{
	return next;
}

//
template<class T>
void insertAfter(Node<T> *p)
{

}

//
template<class T>
Node<T> *deleteAfter()
{

}