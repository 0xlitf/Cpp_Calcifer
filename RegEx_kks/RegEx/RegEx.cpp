// RegEx.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>  // regular expression 正则表达式
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
				cout << "合法" << endl;
				kks_name = regex_replace(kks, pattern, string("$1"));
				cout << "kks：" << kks_name << endl;
				cout << endl;
			}
			else
			{
				cout << "您输入的电子邮件地址不合法" << endl << endl;
			}
		}
		return EXIT_SUCCESS;
}

