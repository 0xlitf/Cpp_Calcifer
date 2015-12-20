#include "stdafx.h"
#include "Deal.h"
using namespace std;
string in_path = "C:/Users/Azro/Desktop/lost.txt";
string out_path = "C:/Users/Azro/Desktop/lost.pic";
string compare1_path = "C:/Users/Azro/Desktop/lost.txt";
string compare2_path = "C:/Users/Azro/Desktop/lost.pic";
ifstream compare1(compare1_path);
ifstream compare2(compare2_path);
ifstream fin(in_path);
ofstream fout(out_path);
Deal::Deal()
{
}
Deal::~Deal()
{
}
void Deal::do_it(){
	deal();
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
void Deal::deal(){
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
		int a = temp.find('|');
		int b = temp.rfind('|');
		string last(temp, a + 1, b - a - 1);
		switch (dataline[0])
		{
		case 'N':
			cout<<last;
			Deal::Light(last,index,list,row);
			cout << "done"<<"\n";
			Deal::Text(last, index, list, row);
			break;
		case 'P':
			Deal::Slip(last, index, list, row);
			Deal::Text(last, index, list, row);
			break;
		case 'M':
			Deal::Slip(last, index, list, row);
			Deal::Text(last, index, list, row);
		case 'B':
			break;
		case 'G':
			Deal::GS(last, index, list, row);
			Deal::Text(last, index, list, row);
			break;
		default:
			Deal::Meter(last, index, list, row);
			Deal::Text(last, index, list, row);
			break;
		}

		if (row >= 200)
		{
			row = 1;
			list += 20;
		}
		else
		{
			row += 3;
		}
		index++;
	}
	fout << "##" << endl;
}
void Deal::to_light(){
	//处理光字牌灯
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

void Deal::to_kks(){
	char m_compare1[1024];
	char m_compare2[1024];
	while (compare1.getline(m_compare1, 1024, '\n')){
		string m_C1 = m_compare1;
		cout << "in while1\n";
		cout << "m_compare1:" << m_compare1 << endl;
		cout << "m_C1:" << m_C1 << endl;
		string m_kks(m_C1, 2);
		cout << "m_kks:" << m_kks<<endl;
		while (compare2.getline(m_compare2, 1024, '\n')){
			string m_C2 = m_compare2;
			cout << "in while2\n";
			cout << "m_C2:" << m_C2 << endl;
			auto n_kks = m_kks.find(m_C2);
			cout << "n_kks:" << n_kks<<endl;
			if (n_kks == 0)
				{
				cout << "in if\n";
				cout << "m_C2:" << m_C2;
				fout << "m_C2:"<< m_C2 << '\n';

				}
				
		}
	}
}