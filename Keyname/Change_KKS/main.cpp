// Change.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Deal.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	string compare1_path = "C:/Users/Azro/Desktop/仙游连片.txt";
	ifstream compare1(compare1_path);
	string out_path = "C:/Users/Azro/Desktop/仙游kks输出.txt";
	ofstream out(out_path);
	int index = 0;
	int row = 1;
	int list = 3;
		char m_compare1[1024];
		char m_compare2[1024];
		while (compare1.getline(m_compare1, 1024, '\n')){
			string m_C1 = m_compare1;
			string m_kks(m_C1, 2);
			string compare2_path = "C:/Users/Azro/Desktop/仙游kks.txt";
			ifstream compare2(compare2_path);
			while (compare2.getline(m_compare2, 1024, '\n')){
				string m_C2 = m_compare2;
				auto n_kks = m_kks.find(m_C2);
				string z(m_C2, 0, 11);
				string y(m_C2, 12);
				if (m_kks == z)
				{
					cout << index << m_C2 << endl;
					out << "Slip" << "\n";
					out << "1" << "\n";
					out << "Slip@" << index << "\n";
					out << "0" << "\n";
					out << "  " << list << "20.0000	  " << row << "30.0000" << "\n";
					out << "  240.0000	  240.0000" << "\n";
					out << "2" << "\n";
					out << m_compare1[0] <<" "<< z << "\n" << y <<m_kks<<"|开|关"<< "\n" << '\n'; 

					out << "Text" << "\n";
					out << "1" << "\n";
					out << "Text@" << index << "\n";
					out << "0" << "\n";
					out << "  " << list + 4 << "20.0000	  " << row + 2 << "30.0000" << "\n";
					out << "  240.0000	  240.0000" << "\n";
					out << "    1.6250" << "\n";
					out << y << "\n";
					out << "65535" << "\n";
					out << "黑体" << "\n";
					out << "134" << "\n";
					out << "0" << "\n" << "\n";
				}
			}
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
	return 0;
}