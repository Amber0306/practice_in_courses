#include "pch.h"
#include <iostream>

using namespace std;
int main()
{
	cout << "请输入字符串：" << endl;
	cin >> str;
	len = strlen(str);
	cnt_char = len;//字符个数
	initial();
	while (cnt_csm < len)
	{
		cout << "######################################" << endl;
		schedule();
		execute();
		display();
		cout << "######################################" << endl;
		cout << endl;
	}
	cout << "结束^_^" << endl;
	free();
}


