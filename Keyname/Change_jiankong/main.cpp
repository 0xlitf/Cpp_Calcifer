// Change.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	string in_path = "E:/仙游/盘.txt";
	string out_path = "E:/仙游/sots/jiankong.txt";
	string pic_path = "E:/仙游/sots/jiankong.pic";
	/*string in_path = "E:/响水涧/盘.txt";
	string out_path = "E:/响水涧/sots/jiankong.txt";
	string pic_path = "E:/响水涧/sots/jiankong.pic";*/
	ifstream fin(in_path);
	ofstream fileout(out_path);
	ofstream fout(pic_path);
	char dataline[1024];
	int index = 1;
	int row = 1;
	int list = 3;
	string last;
	fout << "4764798" << "\n";
	fout << "16777215  8421440" << "\n";
	fout << "  1.000000" << "\n";
	fout << "  5.000000" << "\n" << "\n";
	while (fin.getline(dataline, 1024, '\n')){
		string temp = dataline;
		fileout << "AN_File_" << index << " " << "D_File_" << index << " " << temp << endl;
		
		fout << "PingPongSwitch" << "\n";
		fout << "1" << "\n";
		fout << "PingPongSwitch@" << index << "\n";
		fout << "0" << "\n";
		fout << "  " << list << "00.0000	  " << row << "30.0000" << "\n";
		fout << "  240.0000	  240.0000" << "\n";
		fout << "2" << "\n";
		fout << "1" << ' ' << "AN_File_" << index;
		fout << "\n\n\n";

		fout << "SigLight" << "\n";
		fout << "1" << "\n";
		fout << "SigLight@" << index << "\n";
		fout << "0" << "\n";
		fout << "  " << list + 2<< "60.0000	  " << row << "30.0000" << "\n";
		fout << "  240.0000	  240.0000" << "\n";
		fout << "1" << "\n";
		fout << "D_File_" << index << '\n' << '\n' << '\n';


		fout << "Text" << "\n";
		fout << "1" << "\n";
		fout << "Text@" << index << "\n";
		fout << "0" << "\n";
		fout << "  " << list + 7 << "20.0000	  " << row + 2 << "30.0000" << "\n";
		fout << "  240.0000	  240.0000" << "\n";
		fout << "    1.6250" << "\n";
		fout << temp << "\n";
		fout << "65535" << "\n";
		fout << "黑体" << "\n";
		fout << "134" << "\n";
		fout << "0" << "\n" << "\n";



		if (row >= 200)
		{
			row = 1;
			list += 60;
		}
		else
		{
			row += 2;
		}
		index++;
	}


	return 0;
}
