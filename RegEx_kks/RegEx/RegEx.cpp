// RegEx.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>  // regular expression ������ʽ
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
		string kks;
		string kks_name;

		regex pattern(".*([0-9A-Za-z]{11}).*");
		while (cin >> kks)
		{
			if (regex_match(kks, pattern))
			{
				cout << "�Ϸ�" << endl;
				kks_name = regex_replace(kks, pattern, string("$1"));
				cout << "kks��" << kks_name << endl;
				cout << endl;
			}
			else
			{
				cout << "������ĵ����ʼ���ַ���Ϸ�" << endl << endl;
			}
		}
		return EXIT_SUCCESS;
}

