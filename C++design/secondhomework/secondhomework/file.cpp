#include"stdafx.h"
#include<fstream>
#include<iostream>
#include<stdlib.h>

using namespace std;
//struct CStu
//{
//	char sNumer[13];
//	char sName[6];
//	int * nScores;
//	CStu* next;
//};

//将链表输出到文件
void TxtOutFromLinker(CStu *pH)
{
	CStu *pB = pH;
	CStu *pT = pH->next;
	ofstream out;
	out.open("C:\\Users\\GUO\\Desktop\\123.txt");
	if (!out.is_open())
	{
		return;
	}
	while (pT != NULL)
	{
		out << pT->sNumer << "\t" << pT->sName << "\t";
		for (int i = 0; i < 5; i++)
			out << pT->nScores[i] << "\t";
		out << endl;
		pT = pT->next;
	}

	out.close();
}

//读取链表并转化为二进制文件
CStu * CreateLinkerFromBinaryFile(const char*pBinaryFileName)
{
	ifstream in;
	in.open(pBinaryFileName, ios::binary | ios::in);
	if (!in.is_open())
		return NULL;
	int nCount = 0;
	in.read((char*)&nCount, sizeof(int));
	CStu* pH = new CStu;
	pH->next = NULL;
	CStu* pT = pH;
	for (int i = 0; i < nCount; i++)
	{
		pT->next = new CStu();
		pT = pT->next;
		pT->next = NULL;
		short nLen = 0;
		in.read((char*)&nLen, sizeof(nLen));
		in.read(pT->sNumer, nLen);
		pT->sNumer[nLen] = '\0';

		in.read((char*)&nLen, sizeof(nLen));
		in.read(pT->sName, nLen);
		in.read(pT->sNumer, nLen);
		pT->sNumer[nLen] = '\0';

		in.read((char*)&nLen, sizeof(nLen));
		in.read(pT->sName, nLen);
		pT->sName[nLen] = '\0';

		float fScores;
		for (int j = 0; j < 5; j++)
		{
			in.read((char*)&fScores, sizeof(float));
			*(pT->nScores )= (int)fScores;
		}
		in.read((char*)&fScores, sizeof(float));
		in.read((char*)&fScores, sizeof(float));
	}
	return pH;
}

int filein()
{
	const char* name[2] = { "guoziqi1","guoziqi2" };
	float score[2] = { 96.97 };
	fstream txtfile, binfile;
	txtfile.open("C:\\Users\\GUO\\Desktop\\123.txt");
	binfile.open("C:\\Users\\GUO\\Desktop\\123.txt");
	if (!txtfile) {
		cerr << " 123.txt open or create error! " << endl;
		exit(1);
	}
	if (!binfile) {
		cerr << " 123.dat open or create error! " << endl;
		exit(1);
	}
	for (int i = 0; i < 3; i++)
	{
		txtfile << name[i] << '\t' << score[i] << endl;
		binfile.write(name[i], 8 * sizeof(char));
		binfile.write((char*)&score[i], sizeof(float));
	}
	txtfile.close();
	binfile.close();
	return 0;
}

int txtFileOut()
{
	char name[8], score[6];
	fstream txtfile;
	txtfile.open("C:\\Users\\GUO\\Desktop\\123.txt");
	if (!txtfile) {
		cerr << " 123.txt open or create error! " << endl;
		exit(1);
	}
	while (!txtfile.eof())
	{
		txtfile >> name >> score;
		cout << name << "   " << score << endl;
	}
	txtfile.close();
	return 0;
}

int binFileOut()
{
	char name[8];
	float score;
	fstream binfile;
	binfile.open("C:\\Users\\GUO\\Desktop\\123.dat",ios::binary);
	if (!binfile) {
		cerr << " 123.dat open or create error! " << endl;
		exit(1);
	}
	while (!binfile.eof())
	{
		binfile.read(reinterpret_cast<char*>(name), 8 * sizeof(char));
		binfile.read(reinterpret_cast<char*>(&score), sizeof(float));
		cout << name << "  " << score << endl;
	}
	binfile.close();
	return 0;
}