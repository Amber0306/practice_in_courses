#include "stdafx.h"
#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

//struct CStu
//{
//	char sNumer[13];
//	char sName[6];
//	float nScores;
//	CStu* next;
//};
	
//CStu * CreateLinkerFromBinaryFile(const char*pBinaryFileName)
//{
//	ifstream in;
//	in.open(pBinaryFileName, ios::binary | ios::in);
//	if (!in.is_open())
//		return NULL;
//	int nCount = 0;
//	in.read((char*)&nCount, sizeof(int));
//	CStu* pH = new CStu;
//	pH->next = NULL;
//	CStu* pT = pH;
//	for (int i = 0; i < nCount; i++)
//	{
//		pT->next = new CStu();
//		pT = pT->next;
//		pT->next = NULL;
//		short nLen = 0;
//		in.read((char*)&nLen, sizeof(nLen));
//		in.read(pT->sNumer, nLen);
//		pT->sNumer[nLen] = '\0';
//
//		in.read((char*)&nLen, sizeof(nLen));
//		in.read(pT->sName, nLen);
//		in.read(pT->sNumer, nLen);
//		pT->sNumer[nLen] = '\0';
//
//		in.read((char*)&nLen, sizeof(nLen));
//		in.read(pT->sName, nLen);
//		pT->sName[nLen] = '\0';
//
//		
//		int flag ;
//		cin >> flag;
//		//flag为几，则进入计算的就是第几门成绩
//
//		float fScores;
//		for (int j = 0; j < 5; j++)
//		{
//			in.read((char*)&fScores, sizeof(float));
//			pT->nScores[flag+1] = (int)fScores;
//		}
//		in.read((char*)&fScores, sizeof(float));
//		in.read((char*)&fScores, sizeof(float));
//	}
//	return pH;
//}

//学生成绩的排序根据总分排
int input(CStu s[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cin >> s[i].sName;
		cin >> s[i].nScores[5];
		if (s[i].nScores < 0)break;
	}
	return i;
}
void output(CStu s[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		cout << s[i].sName << '\t' << s[i].nScores << endl;
}
void sort1(CStu a[], int n)//按分数排序
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].nScores < a[j].nScores)
			{
				CStu t;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			//幻想中是这个样子的，事实上并不成功
			/*if (0 > strcmp(a[i].nScores, a[j].nScores))
			{
				SwapEle((a[i] - 1), a[i], a[j]);
			}*/
		}
	}
}
//构造了整个结构体，效率较低。
//具体应采用后面的方法交换指针 ，调转B和C的位置函数
int queue()
{
	const int maxNum = 100;
	int num;
	CStu s[maxNum];
	num = input(s, maxNum);
	sort1(s, num);
	output(s, num);
	return 0;
}

CStu* Search(CStu* head, int key)//查找关键词小于key的结点前驱
{
	CStu* p = head;
	while (p->next != NULL)
	{
		if (p->next->nScores[5] < key)
		{
			return p;
		}
		p = p->next;
	}
	return p;
}
void InsertCStu(CStu*p, CStu*newp)//在P后插入结点newp
{
	newp->next = p->next;
	p->next = newp;
}
void DelCStu(CStu*p)//删除P结点的一个后继节点
{
	CStu* q;
	if (p->next != NULL) 
	{
		q = p->next;
		p->next = q->next;
		delete q;
	}
}
void DelList(CStu* head)//销毁整个链表
{
	CStu* p = head;
	while (head->next != NULL)
	{
		head = head->next;
		delete p;
		p = head;
	}
	delete head;
}
void DisList(CStu* head)//显示链表各元素
{
	CStu* p = head;
	while (p->next != NULL)
	{
		cout << p->next->sName << '\t' << p->next->nScores << endl;
		p = p->next;
	}
}
//构造链表，手动输入
int List()
{
	int flag;
	cin >> flag;
	//flag为几，则进入计算的就是第几门成绩

	CStu* newp, *head, *p;
	char sName[6];
	float nScores, low = 60;
	if((newp =new CStu)== NULL)
	{
		cout << "new CStu fail! " << endl;
	    exit(0);
	}
	head = newp;
	head->next = NULL;
	cout << "Input name and score(- 1 to exit):" << endl;
	cin >> sName >> nScores;
	while (nScores > 0)
	{
		if ((newp = new CStu) == NULL)
		{
			cout << "new CStu fail! " << endl;
			exit(0);
		}
		strcpy_s(newp->sName, sName);
		newp->nScores[flag+1] = nScores;
		newp->next = NULL;
		p = Search(head, nScores);
		InsertCStu(p, newp);
		cin >> sName >> nScores;
	}
	cout << "Before delete:" << endl;
	DisList(head);
	for (p = Search(head, low); p->next != NULL; p = Search(head, low))
	{
		DelCStu(p);
	}
	cout << "After delete:" << endl;
	DisList(head);
	DelList(head);
	return 0;
}
//调转B和C的位置
void SwapEle(CStu* pA, CStu* pB, CStu* pC)
{
	CStu* pD = pC->next;
	pA->next = pC;
	pB->next = pD;
	pC->next = pB;
}
//翻转链表
void ReverseLinker(CStu* pH)
{
	if ((pH == NULL) || (pH->next) == NULL)
	{
		return;
	}
	CStu* pre, *cur, *nex;
	//cur记录当前位置，pre记录前一个位置，nex记录下一个位置，均为反转前
	cur = pH->next;
	pre = NULL;
	//反转之后，头结点变为尾结点，其next值为null
	while (cur != NULL)
	{
		nex = cur->next;
		cur->next = pre;
		//nex->next = cur;
		pre = cur;
		cur = nex;
	}
	pH->next = pre;//cur已经为空，所以pre为尾结点。pH->next 指向它
	return;
}
//复制一个链表
CStu* CopyLinker(CStu* pH)
{
	CStu* pStu = pH;
	CStu* pCopyHead = NULL; 
	CStu* pCopyStu = NULL;

	int flag;
	cin >> flag;
	//flag为几，则进入复制的就是第几门成绩（并没有复制所有成绩。如需复制，则再加入一个for循环）

	if (pStu != NULL)
	{
		pCopyHead = new CStu();
		pCopyHead->sName[6] = pStu->sName[6];
		pCopyHead->sNumer[13] = pStu->sNumer[13];
		pCopyHead->nScores[flag+1] = pStu->nScores[flag+1];
		pCopyHead->next = NULL;
		pCopyStu = pCopyHead;
		pStu = pStu->next;
	}
	while (pStu != NULL)
	{
		CStu* pTempStu = new CStu();
		pTempStu->sName[6] = pStu->sName[6];
		pTempStu->sNumer[13] = pStu->sNumer[13];
		pTempStu->nScores[flag+1] = pStu->nScores[flag+1];
		pTempStu->next = NULL;
		pCopyStu->next = pTempStu;
		pCopyStu = pCopyStu->next;
		pStu = pStu->next;
	}
	return pCopyHead;
}

CStu* CreateLinker()
{
	int len = 20;//结点个数
	char val[6]="0";//临时保存结点的值
	//头结点
	CStu* pHead = new CStu;
	if ((pHead = new CStu) == NULL)
	{
		cout << "new CStu fail! " << endl;
		exit(0);
	}
	//尾结点
	CStu* pTail = pHead;
	pTail->next = NULL;
	//输入结点值

	//创建临时结点
	CStu* pT = new CStu;
	if ((pT = new CStu) == NULL)
	{
		cout << "new CStu fail! " << endl;
		exit(0);
	}

	//带入数据
	pTail->next = pT;
	pT->next = NULL;
	pTail = pT;
	return pHead;
}

CStu* SortByName(CStu* head)
{
	CStu* f = NULL;
	CStu* t = NULL;
	CStu* max;
	CStu* maxbf = NULL;
	CStu* p;
	CStu* q = head->next;

	while (q != NULL)
	{
		for (p = q, max = q; p->next != NULL; p = p->next)
		{
			if (0 > strcmp(p->next->sName, max->sName))
			{
				maxbf = p;
				max = p->next;
			}
		}

		if (f == NULL)
		{
			f = max;
			t = max;
		}
		else 
		{
			t->next = max;
			t = max;
		}

		if (max == q)
		{
			q = q->next;
		}
		else
		{
			maxbf->next = max->next;
		}
	}
	t->next = NULL;
	head->next = f;
	return head;
}

//按总分排序
void SortBySumScore(CStu *pH)
{
	for (int i = 0; i < 6; i++)
	{
		CStu *pB = pH;
		CStu *pT = pB->next;
		float sum1 = 0.0f;
		float sum2 = 0.0f;

		while (pT->next != NULL)
		{
			for (int j = 0; j < sizeof(pT->nScores) / sizeof(float); j++)
			{
				sum1 = 0.0f;
				sum2 = 0.0f;
				sum1 += pB->next->nScores[j];
				sum2 += pT->next->nScores[j];
			}
			if (sum1 > sum2)
			{
				
				pB->next = pT->next;
				pT->next = pT->next->next;
				pB->next->next = pT;
			}
			else {
				pT = pT->next;

			}
			pB = pB->next;
		}

	}

}

//按分数排序
void SortByScore(CStu *pH, int n)
{
	for (int i = 0; i < 6; i++)
	{
		CStu *pB = pH;
		CStu *pT = pB->next;
		float sum1 = 0.0f;
		float sum2 = 0.0f;

		while (pT->next != NULL)
		{
			if (pB->next->nScores[n - 1] > pT->next->nScores[n - 1])
			{
				SwapEle(pB, pB->next,pB->next->next);
			}
			else {
				pT = pT->next;

			}
			pB = pB->next;
		}

	}
}



void SortByNumer(CStu *pH)
{
	for (int i = 0; i < 6; i++)
	{
		CStu *pB = pH;
		CStu *pT = pB->next;

		while (pT->next != NULL)
		{
			if (1 == strcmp(pB->next->sNumer, pT->next->sNumer))
			{
				SwapEle(pB,pB->next,pB->next->next);
			}
			else {
				pT = pT->next;
			}
			pB = pB->next;
		}
	}
}



void Sort(CStu * pH, int nFlag)
{
	if (nFlag == 0)//如果nFlag等于0，就按名字排序
		SortByName(pH);
	else if (nFlag == -1)//如果nFlag等于-1，就按学号排序
		SortByNumer(pH);
	else if (nFlag > 0 && nFlag <= (sizeof(pH->nScores) / sizeof(float)))
		SortByScore(pH, nFlag);//如果nFlag等于n，就按第n门课程排序
	else
		SortBySumScore(pH);//按总分排序
}


////以此举例，通过学号排序
//CStu* SortByNumer(CStu* head)
//{
//	CStu* f = NULL;//结果的第一个结点（可能是这样）
//	CStu* t = NULL;//结果的最后一个结点（我猜测）
//	CStu* max;//比较当中的较大值
//	CStu* maxbf = NULL;//最终的最大值
//	CStu* p;//相当于一个临时的结点，用于比较及遍历整个链表
//	CStu* q = head->next;//开始的第一个结点，后遍历整个链表
//
//	while (q != NULL)
//	{
//		for (p = q, max = q; p->next != NULL; p = p->next)
//		{
//		  //将q与q的后一个结点中具体的字符串进行比较
//		  //此时q结点在结点p的前一个位置
//			if (0 > strcmp(p->next->sNumer, max->sNumer))
//			{//此步骤进行即相当于返回负数，此时p->next->sNumer所代表的值小于max->sNumer
//				//也即是max为结点字符串的较大者
//				maxbf = p;
//				max = p->next;
//			}
//		}
//		if (f == NULL)
//		{
//			f = max;
//			t = max;
//		}
//		else
//		{
//			t->next = max;
//			t = max;
//		}
//		//以上的if语句
//		if (max == q)
//		{
//			q = q->next;//如果q的值为比较当中的较大的，则往后顺延
//		}
//		else
//		{
//			maxbf->next = max->next;//如果q的值不是参与比较的两者当中的较大的，
//			                        //则将此结点放在最终结果中最大值的后面
//		}
//	}
//	t->next = NULL;//尾指针最后指为空
//	head->next = f;//头指针指向链表第一个结点，第一个结点为最大值
//	return head;//返回排序后头指针
//}