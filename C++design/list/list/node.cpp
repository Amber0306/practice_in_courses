#include"node.h"
#include<iostream>

//������ʵ�ֲ���
//���캯����ʼ�����ݺ�ָ���Ա
template<class T>
Node <T>::Node(const T &data, Node<T> *next = 0) :data(data), next(next) {}

//���غ�̵Ľ���ָ��
template<class T>
Node <T> *Node <T>::nextNode()
{
	return next;
}

//���غ�̽���ָ��
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