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
		string email_address;
		string user_name, domain_name;

		regex pattern("([0-9A-Za-z\\-_\\.]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)");
		// ������ʽ��ƥ�����
		// ��1�飨���û�������ƥ�����0��9��A��Z��a��z���»��ߡ��㡢���ַ�֮��
		// �������ַ����ظ�һ�������
		// �м䣬һ����@������
		// �ڶ��飨����������ƥ�����0��9��a��z֮�е������ַ��ظ�һ������ϣ�
		// ����һ���㣬����a��z֮�е������ַ��ظ�2��3�飨��com��cn�ȣ���
		// �ڶ����ڲ���һ�飬һ���㣬����a��z֮�е������ַ��ظ�2�飨��cn��fr�ȣ�
		// �ڲ�һ�����ظ���λ�һ��


		// �����ļ���β����Windows��Ctrl+Z��UNIX��Ctrl+D������ѭ��
		while (cin >> email_address)
		{
			if (regex_match(email_address, pattern))
			{
				cout << "������ĵ����ʼ���ַ�Ϸ�" << endl;

				// ��ȡ��һ��
				user_name = regex_replace(email_address, pattern, string("$1"));

				// ��ȡ�ڶ���
				domain_name = regex_replace(email_address, pattern, string("$2"));

				cout << "�û�����" << user_name << endl;
				cout << "������" << domain_name << endl;
				cout << endl;
			}
			else
			{
				cout << "������ĵ����ʼ���ַ���Ϸ�" << endl << endl;
			}
		}
		return EXIT_SUCCESS;
}

