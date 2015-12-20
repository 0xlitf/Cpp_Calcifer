// Change_text_2_pic.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <string>
using namespace std;
//C:\\Users\\Azro\\Desktop\\new\\		E:\\仙游\\sots\\

ifstream fin("text.txt");	
ofstream fout("text.pic");
char dataline[1024];
int index = 0;
int row = 1;
int list = 1;
string last;
int _tmain(int argc, _TCHAR* argv[])
{
	fout << "4764798" << "\n";
	fout << "16777215  8421440" << "\n";
	fout << "  1.000000" << "\n";
	fout << "  5.000000" << "\n" << "\n";
	while (fin.getline(dataline, 1024, '\n'))
	{
		string temp = dataline;
		fout << "Text" << "\n";
		fout << "1" << "\n";
		fout << "Text@" << index << "\n";
		fout << "0" << "\n";
		fout << "  " << list + 4 << "20.0000	  " << row + 2 << "30.0000" << "\n";
		fout << "  240.0000	  240.0000" << "\n";
		fout << "    1.6250" << "\n";
		fout << temp << "\n";
		fout << "65535" << "\n";
		fout << "黑体" << "\n";
		fout << "134" << "\n";
		fout << "0" << "\n" << "\n";
		if (row >= 1+(50-1)*2)
		{
			row = 1;
			list += 90;
		}
		else
		{
			row += 2;
		}
		index++;
	}
	fout << "##" << endl;
	return 0;
}