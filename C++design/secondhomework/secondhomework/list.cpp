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
//		//flagΪ������������ľ��ǵڼ��ųɼ�
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

//ѧ���ɼ�����������ܷ���
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
void sort1(CStu a[], int n)//����������
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
			//��������������ӵģ���ʵ�ϲ����ɹ�
			/*if (0 > strcmp(a[i].nScores, a[j].nScores))
			{
				SwapEle((a[i] - 1), a[i], a[j]);
			}*/
		}
	}
}
//�����������ṹ�壬Ч�ʽϵ͡�
//����Ӧ���ú���ķ�������ָ�� ����תB��C��λ�ú���
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

CStu* Search(CStu* head, int key)//���ҹؼ���С��key�Ľ��ǰ��
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
void InsertCStu(CStu*p, CStu*newp)//��P�������newp
{
	newp->next = p->next;
	p->next = newp;
}
void DelCStu(CStu*p)//ɾ��P����һ����̽ڵ�
{
	CStu* q;
	if (p->next != NULL) 
	{
		q = p->next;
		p->next = q->next;
		delete q;
	}
}
void DelList(CStu* head)//������������
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
void DisList(CStu* head)//��ʾ�����Ԫ��
{
	CStu* p = head;
	while (p->next != NULL)
	{
		cout << p->next->sName << '\t' << p->next->nScores << endl;
		p = p->next;
	}
}
//���������ֶ�����
int List()
{
	int flag;
	cin >> flag;
	//flagΪ������������ľ��ǵڼ��ųɼ�

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
//��תB��C��λ��
void SwapEle(CStu* pA, CStu* pB, CStu* pC)
{
	CStu* pD = pC->next;
	pA->next = pC;
	pB->next = pD;
	pC->next = pB;
}
//��ת����
void ReverseLinker(CStu* pH)
{
	if ((pH == NULL) || (pH->next) == NULL)
	{
		return;
	}
	CStu* pre, *cur, *nex;
	//cur��¼��ǰλ�ã�pre��¼ǰһ��λ�ã�nex��¼��һ��λ�ã���Ϊ��תǰ
	cur = pH->next;
	pre = NULL;
	//��ת֮��ͷ����Ϊβ��㣬��nextֵΪnull
	while (cur != NULL)
	{
		nex = cur->next;
		cur->next = pre;
		//nex->next = cur;
		pre = cur;
		cur = nex;
	}
	pH->next = pre;//cur�Ѿ�Ϊ�գ�����preΪβ��㡣pH->next ָ����
	return;
}
//����һ������
CStu* CopyLinker(CStu* pH)
{
	CStu* pStu = pH;
	CStu* pCopyHead = NULL; 
	CStu* pCopyStu = NULL;

	int flag;
	cin >> flag;
	//flagΪ��������븴�Ƶľ��ǵڼ��ųɼ�����û�и������гɼ������踴�ƣ����ټ���һ��forѭ����

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
	int len = 20;//������
	char val[6]="0";//��ʱ�������ֵ
	//ͷ���
	CStu* pHead = new CStu;
	if ((pHead = new CStu) == NULL)
	{
		cout << "new CStu fail! " << endl;
		exit(0);
	}
	//β���
	CStu* pTail = pHead;
	pTail->next = NULL;
	//������ֵ

	//������ʱ���
	CStu* pT = new CStu;
	if ((pT = new CStu) == NULL)
	{
		cout << "new CStu fail! " << endl;
		exit(0);
	}

	//��������
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

//���ܷ�����
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

//����������
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
	if (nFlag == 0)//���nFlag����0���Ͱ���������
		SortByName(pH);
	else if (nFlag == -1)//���nFlag����-1���Ͱ�ѧ������
		SortByNumer(pH);
	else if (nFlag > 0 && nFlag <= (sizeof(pH->nScores) / sizeof(float)))
		SortByScore(pH, nFlag);//���nFlag����n���Ͱ���n�ſγ�����
	else
		SortBySumScore(pH);//���ܷ�����
}


////�Դ˾�����ͨ��ѧ������
//CStu* SortByNumer(CStu* head)
//{
//	CStu* f = NULL;//����ĵ�һ����㣨������������
//	CStu* t = NULL;//��������һ����㣨�Ҳ²⣩
//	CStu* max;//�Ƚϵ��еĽϴ�ֵ
//	CStu* maxbf = NULL;//���յ����ֵ
//	CStu* p;//�൱��һ����ʱ�Ľ�㣬���ڱȽϼ�������������
//	CStu* q = head->next;//��ʼ�ĵ�һ����㣬�������������
//
//	while (q != NULL)
//	{
//		for (p = q, max = q; p->next != NULL; p = p->next)
//		{
//		  //��q��q�ĺ�һ������о�����ַ������бȽ�
//		  //��ʱq����ڽ��p��ǰһ��λ��
//			if (0 > strcmp(p->next->sNumer, max->sNumer))
//			{//�˲�����м��൱�ڷ��ظ�������ʱp->next->sNumer�������ֵС��max->sNumer
//				//Ҳ����maxΪ����ַ����Ľϴ���
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
//		//���ϵ�if���
//		if (max == q)
//		{
//			q = q->next;//���q��ֵΪ�Ƚϵ��еĽϴ�ģ�������˳��
//		}
//		else
//		{
//			maxbf->next = max->next;//���q��ֵ���ǲ���Ƚϵ����ߵ��еĽϴ�ģ�
//			                        //�򽫴˽��������ս�������ֵ�ĺ���
//		}
//	}
//	t->next = NULL;//βָ�����ָΪ��
//	head->next = f;//ͷָ��ָ�������һ����㣬��һ�����Ϊ���ֵ
//	return head;//���������ͷָ��
//}