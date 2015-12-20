// Change_DelayTime.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <regex>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdlib.h>
using namespace std;
string in_path = "D:/新源项目/G1_GenSig_3S.pic";
string out_path = "D:/新源项目/G1_GenSig_3S_Done.pic";
ifstream fin(in_path);
ofstream fout(out_path);
vector<string> v_str;
int lBase = 43;
int rBase = 21;
int _tmain(int argc, _TCHAR* argv[])
{
	char dataline[1024];
	while (fin.getline(dataline, 1024, '\n')) {
		v_str.push_back(dataline);
	}
	regex partern("([0-9][0-9]):([0-9][0-9])");
	for (auto i = 0; i < v_str.size(); i++) {
		if (regex_search(v_str[i], partern)) {
			cout << "in if" << endl;
			const char* lChar;
			char* rChar;
			string lStr, rStr;
			int lNum, rNum;
			lStr = regex_replace(v_str[i], partern, string("$1"));
			rStr = regex_replace(v_str[i], partern, string("$2"));
			lChar = lStr.data();
			rChar = const_cast<char*>(rStr.data());
			lNum = atoi(lStr.data());
			rNum = atoi(rStr.data());

			//cout <<"lStr:" << lStr<<" rStr:"<<rStr << endl;
			//cout << "lNum:" << lNum << " rNum:" << rNum << endl;
			int DelayTime = ((lNum - lBase) * 60 + (rNum - rBase))*12;
			cout << "DelayTime" << DelayTime << endl;
			char cDelayTime[50];
			_itoa_s(DelayTime, cDelayTime, 10);
			string sDelayTime = cDelayTime;
			v_str[i] = "("+ sDelayTime +")" + v_str[i];
		}
		
	}
	for (auto i = 0; i < v_str.size(); i++) {
		fout << v_str[i] << endl;

	}
	//	system("pause");
	return 0;
}
