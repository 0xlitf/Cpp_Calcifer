// Change.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string in_path = "C:\\Users\\Azro\\Desktop\\lost.txt";
	string out_path = "C:\\Users\\Azro\\Desktop\\lost.pic";

	ifstream fin(in_path);
	ofstream fout(out_path);
	char dataline[1024];
	int index = 0;
	int row = 1;
	int list = 3;
	fout << "4764798" << "\n";
	fout << "16777215  8421440" << "\n";
	fout << "  1.000000" << "\n";
	fout << "  5.000000" << "\n" << "\n";
	cout << "out of while" << endl;
	while (fin.getline(dataline, 1024, '\n'))
	{
		string temp = dataline;
		
		int a = temp.find(' ');
		int b = temp.rfind(' ');
		string frontdata(temp);
		string lastdata(temp, b + 1);
		cout << "frontdata:" << frontdata << "  "<< "lastdata:" << lastdata << endl;
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

		fout << "IntermediaRelay" << "\n";
		fout << "1" << "\n";
		fout << lastdata << "\n";
		fout << "0" << "\n";
		fout << "  " << list << "20.0000	  " << row << "30.0000" << "\n";
		fout << "  240.0000	  240.0000" << "\n";
		fout << "0" << "\n\n";

		if (row >= 200)
		{
			row = 1;
			list += 40;
		}
		else
		{
			row += 3;
		}
		index++;
	}
	fout << "##" << endl;





//	cin.get();
	return 0;
}
