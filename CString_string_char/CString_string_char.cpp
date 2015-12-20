// CString_string_char.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <afx.h>
#include <cstring>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <comutil.h>
#include <dcommon.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//һ��    ��CString��ת����char*(LPSTR)����
	//����һ��ʹ��ǿ��ת�������磺 
	CString str1("This  is a test");
	LPTSTR lpsz1 = (LPTSTR)(LPCTSTR)str1;
	//��������ʹ��strcpy�����磺
	CString str2("This  is a test");
	LPTSTR lpsz2 = new TCHAR[str2.GetLength() + 1];
	//_tcscpy(lpsz, theString);
	//��������ʹ��CString::GetBuffer�����磺
	CString s(_T("This is a test "));
	LPTSTR p = s.GetBuffer();
	// ���������ʹ��p�Ĵ��� 
	if (p != NULL) 
		*p = _T('\0');
	s.ReleaseBuffer();
	// ʹ�����ʱ�ͷţ��Ա���ʹ��������CString��Ա����
	//CString str = "ABCDEF";
	//char *pBuf = str, GetBuffer(0);
	//str.ReleaseBuffer();


	//����     stringתchar*
	//string ��c++��׼����������һ������װ�˶��ַ����Ĳ���
		//��stringת��Ϊchar* ��3�ַ�����
	//1.data(), ����û�С�\0�����ַ�������
		//�磺
	string str3 = "abc";
	char *p3 = const_cast<char*>(str3.data());
	//2.c_str �����С�\0�����ַ�������
		//�磺
	string  str4 = "gdfd";
	const char *p4 = str4.c_str();
	//3.copy
		//����
	string  str5 = "hello";
	char p5[40];
	str5.copy(p5, 5, 0); //����5�������Ƽ����ַ���0�����Ƶ�λ��
	*(p5 + 5) = '\0';  //Ҫ�ֶ����Ͻ�����
	cout << p5;


	//����     �ַ���stringת��Ϊ������������
	char* temp = "123456";
	//1��������(int)
	int	i = atoi(temp);
	//2��������(long)
	long int l = atol(temp);
	//3������(double)
	int	d = atof(temp);
	string s; d = atof(s.c_str());
	//4��BSTR����
		BSTR bstrValue = ::SysAllocString(L"����Ա");
	//...///��ɶ�bstrValue��ʹ��
		SysFreeString(bstrValue);
	//5��CComBSTR����
		//CComBSTR���ͱ�������ֱ�Ӹ�ֵ
		CComBSTR  bstrVar1("test");
	CComBSTR bstrVar2(temp);
	//6��_bstr_t����
		//_bstr_t���͵ı�������ֱ�Ӹ�ֵ
		_bstr_t  bstrVar1("test");
	_bstr_t bstrVar2(temp);
	//�ġ�     Char*ת��Ϊstring
		//���Ҫ��һ��char ת����string, ����ʹ�� string s(char  *);
	//�塢string תCString
	CString cstr;
	string str;
	cstr.Format("%s", str.c_str());
	//����char תCString
	CString cstr2;
	cstr2.Format("%s", char*);
	//�ߡ�CString->string
	CString cstr3("123");
	string s(cstr3.GetBuffer());
	//GetBuffer()��һ��ҪReleaseBuffer(), �����û���ͷŻ�������ռ�Ŀռ�.
	//�ˡ�CString��תint
	//���ַ�ת��Ϊ����������ʹ��atoi��_atoi64��atol��
	//��������ת��ΪCString����������ʹ��CString��Format��������
	CString s;
	int i = 64;
	s.Format("%d", i);



	system("pause");
	return 0;
}

