#include "stdafx.h"
#include "Deal.h"
#include <regex>
using namespace std;
string in_path = "E:/仙游/三维场景/KeyError最终版.ini";
string out_path = "E:/仙游/三维场景/KeyError.pic";
string compare1_path = "C:/Users/Azro/Desktop/响水涧连片.txt";
string compare2_path = "C:/Users/Azro/Desktop/仙游kks.txt";
/*
string in_path = "E:/响水涧/KeyError.ini";
string out_path = "E:/响水涧/KeyError.pic";
string compare1_path = "C:/Users/Azro/Desktop/响水涧连片.txt";
string compare2_path = "C:/Users/Azro/Desktop/响水涧kks.txt";
*/
ifstream fin(in_path);
ifstream compare1(compare1_path);
ofstream fout(out_path);
Deal::Deal()
{
}
Deal::~Deal()
{
}
void Deal::do_it(){
};
void Deal::Light(string light, int index, int list, int row){
	fout << "SigLight" << "\n";
	fout << "1" << "\n";
	fout << "SigLight@" << index << "\n";
	fout << "0" << "\n";
	fout << "  " << list << "20.0000	  " << row << "30.0000" << "\n";
	fout << "  240.0000	  240.0000" << "\n";
	fout << "1" << "\n";
	fout << light << '\n' << '\n' << '\n';
}
void Deal::Slip(string slip, int index, int list, int row){
	fout << "Slip" << "\n";
	fout << "1" << "\n";
	fout << "Slip@" << index << "\n";
	fout << "0" << "\n";
	fout << "  " << list << "20.0000	  " << row << "30.0000" << "\n";
	fout << "  240.0000	  240.0000" << "\n";
	fout << "2" << "\n";
	fout << "0 " << slip << "\n" << "\n" << '\n';
}
void Deal::Meter(string meter, int index, int list, int row){
	fout << "LinearMeter" << "\n";
	fout << "1" << "\n";
	fout << meter << "\n";
	fout << "0" << "\n";
	fout << "  " << list << "20.0000	  " << row << "30.0000" << "\n";
	fout << "  240.0000	  240.0000" << "\n";
	fout << "2" << "\n";
	fout << "SUM" << "\n";
	fout << "NORMAL" << "\n";
	fout << "NORMAL" << "\n";
	fout << "NORMAL" << "\n" << "\n";
}
void Deal::GS(string gs, int index, int list, int row){
	fout << "GeneralStartRelay" << "\n";
	fout << "1" << "\n";
	fout << "GeneralStartRelay@" << index << "\n";
	fout << "0" << "\n";
	fout << "  " << list << "20.0000	  " << row << "30.0000" << "\n";
	fout << "  240.0000	  240.0000" << "\n";
	fout << "2" << "\n";
	fout << gs << "\n";
	fout << "0" << "\n" << "\n" << '\n';
}
void Deal::Text(string text, int index, int list, int row){
	fout << "Text" << "\n";
	fout << "1" << "\n";
	fout << "Text@" << index << "\n";
	fout << "0" << "\n";
	fout << "  " << list + 4 << "20.0000	  " << row + 2 << "30.0000" << "\n";
	fout << "  240.0000	  240.0000" << "\n";
	fout << "    1.6250" << "\n";
	fout << text << "\n";
	fout << "65535" << "\n";
	fout << "黑体" << "\n";
	fout << "134" << "\n";
	fout << "0" << "\n" << "\n";
}
void Deal::Button(string botton, int index, int list, int row){
	fout << "PingPongSwitch" << "\n";
	fout << "1" << "\n";
	fout << "PingPongSwitch@" << index << "\n";
	fout << "0" << "\n";
	fout << "  " << list << "20.0000	  " << row << "30.0000" << "\n";
	fout << "  240.0000	  240.0000" << "\n";
	fout << "2" << "\n";
	fout << "1"<< ' '<<botton;
	fout << "\n\n\n";
}
void Deal::deal(){
	char dataline[1024];
	int index = 0;
	int row = 1;
	int list = 3;
	string last;
	cout << "deal" << endl;
	fout << "4764798" << "\n";
	fout << "16777215  8421440" << "\n";
	fout << "  1.000000" << "\n";
	fout << "  5.000000" << "\n" << "\n";
	while (fin.getline(dataline, 1024, '\n'))
	{
		string temp = dataline;
		char dataline_kks[1024];
		int a = temp.find('|');
		int b = temp.rfind('|');
		string last(temp, a + 1, b - a - 1);
		string kname(temp, a + 1, b - a - 1);
		string kks_name;
		regex pattern(".*([0-9A-Za-z]{11}).*");
		if (regex_match(last, pattern))
		{
			kks_name = regex_replace(last, pattern, string("$1"));
		}
		ifstream compare2(compare2_path);
		string kks;
		string last_text;
		last_text = last;
		string out_m_dataline_kks;
		while (compare2.getline(dataline_kks, 1024, '\n')){
			string m_dataline_kks = dataline_kks;
			string str_in_kks(dataline_kks, 0, 11);
			if (kks_name == str_in_kks)
			{
				out_m_dataline_kks = m_dataline_kks;
				string name_kks(m_dataline_kks, 12);
				last_text = kname + " "+ name_kks;
				kks = str_in_kks + "|开|关";
			}
		}
		string printtext;
		if (out_m_dataline_kks.length() >= 12)
		{
			string ptext(out_m_dataline_kks, 12);
			printtext = ptext;
			printtext += " ";
		}
		switch (dataline[0])
		{
		case 'N':
			Deal::Light(last,index,list,row);
			Deal::Text(last_text, index, list, row);
			break;
		case 'P':
			fout << "Slip" << "\n";
			fout << "1" << "\n";
			fout << "Slip@" << index << "\n";
			fout << "0" << "\n";
			fout << "  " << list << "20.0000	  " << row << "30.0000" << "\n";
			fout << "  240.0000	  240.0000" << "\n";
			fout << "2" << "\n";
			fout << "0 " << last << "\n" << printtext << kks << "" << "\n" << '\n';
			
			fout << "Text" << "\n";
			fout << "1" << "\n";
			fout << "Text@" << index << "\n";
			fout << "0" << "\n";
			fout << "  " << list + 4 << "20.0000	  " << row + 2 << "30.0000" << "\n";
			fout << "  240.0000	  240.0000" << "\n";
			fout << "    1.6250" << "\n";
			fout  << last_text << "\n";
			fout << "65535" << "\n";
			fout << "黑体" << "\n";
			fout << "134" << "\n";
			fout << "0" << "\n" << "\n";
			break;
		case 'M':
			Deal::Slip(last, index, list, row);
			Deal::Text(last_text, index, list, row);
			break;
		case 'E':
			Deal::Meter(last, index, list, row);
			Deal::Text(last_text, index, list, row);
			break;
		case 'G':
			Deal::GS(last, index, list, row);
			Deal::Text(last_text, index, list, row);
			break;
		case 'B':
			Deal::Button(last, index, list, row);
			Deal::Text(last_text, index, list, row);
			break;
		default:
			Deal::Text(last_text, index, list, row);
			break;
		}
		if (row >= 400)
		{
			row = 1;
			list += 40;
		}
		else
		{
			row += 3;
		}
		index++;
		cout << index <<endl;
	}
	fout << "##" << endl;
}
void Deal::to_light(){
	char dataline[1024];
	int index = 0;
	int row = 1;
	int list = 3;
	string last;
	fout << "4764798" << "\n";
	fout << "16777215  8421440" << "\n";
	fout << "  1.000000" << "\n";
	fout << "  5.000000" << "\n" << "\n";
	while (fin.getline(dataline, 1024, '\n'))
	{
		string temp = dataline;
		int a = temp.find(' ');
//		int b = temp.rfind(' ');
		string last(temp, 0, a);
		if (dataline[0]=='G'){
			Deal::Light(last, index, list, row);
			Deal::Text(temp, index, list, row);
		}
		else if (!(dataline[0] == NULL))
		{
			Deal::Text(temp, index, list, row);
		}

		if (row >= 200)
		{
			row = 1;
			list += 45;
		}
		else
		{
			row += 2;
		}
		index++;
	}
	fout << "##" << endl;
}
