#pragma once
#ifndef NODE_H
#define NODE_H

//�����ģ�嶨��
template<class T>
class Node 
{
private:
	Node<T> *next;//ָ���̽���ָ��
public:
	T data;//������
	Node(const T &data, Node<T> *next = 0);//���캯��
	void insertAfter(Node<T> *p);//�ڱ����֮�����һ��ͬ����p
	Node<T> *deleteAfter();//ɾ�������ĺ�̽�㣬���������ַ
	Node<T> *nextNode();//��ȡ��̽��ĵ�ַ
	const Node<T> *nextNode() const;//��ȡ��̽��ĵ�ַ
};



#endif // !node_H
