// CString_string_char.cpp : 定义控制台应用程序的入口点。
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
	//一、    将CString类转换成char*(LPSTR)类型
	//方法一，使用强制转换。例如： 
	CString str1("This  is a test");
	LPTSTR lpsz1 = (LPTSTR)(LPCTSTR)str1;
	//方法二，使用strcpy。例如：
	CString str2("This  is a test");
	LPTSTR lpsz2 = new TCHAR[str2.GetLength() + 1];
	//_tcscpy(lpsz, theString);
	//方法三，使用CString::GetBuffer。例如：
	CString s(_T("This is a test "));
	LPTSTR p = s.GetBuffer();
	// 在这里添加使用p的代码 
	if (p != NULL) 
		*p = _T('\0');
	s.ReleaseBuffer();
	// 使用完后及时释放，以便能使用其它的CString成员函数
	//CString str = "ABCDEF";
	//char *pBuf = str, GetBuffer(0);
	//str.ReleaseBuffer();


	//二、     string转char*
	//string 是c++标准库里面其中一个，封装了对字符串的操作
		//把string转换为char* 有3种方法：
	//1.data(), 返回没有”\0“的字符串数组
		//如：
	string str3 = "abc";
	char *p3 = const_cast<char*>(str3.data());
	//2.c_str 返回有”\0“的字符串数组
		//如：
	string  str4 = "gdfd";
	const char *p4 = str4.c_str();
	//3.copy
		//比如
	string  str5 = "hello";
	char p5[40];
	str5.copy(p5, 5, 0); //这里5，代表复制几个字符，0代表复制的位置
	*(p5 + 5) = '\0';  //要手动加上结束符
	cout << p5;


	//三、     字符串string转换为其它数据类型
	char* temp = "123456";
	//1）短整型(int)
	int	i = atoi(temp);
	//2）长整型(long)
	long int l = atol(temp);
	//3）浮点(double)
	int	d = atof(temp);
	string s; d = atof(s.c_str());
	//4）BSTR变量
		BSTR bstrValue = ::SysAllocString(L"程序员");
	//...///完成对bstrValue的使用
		SysFreeString(bstrValue);
	//5）CComBSTR变量
		//CComBSTR类型变量可以直接赋值
		CComBSTR  bstrVar1("test");
	CComBSTR bstrVar2(temp);
	//6）_bstr_t变量
		//_bstr_t类型的变量可以直接赋值
		_bstr_t  bstrVar1("test");
	_bstr_t bstrVar2(temp);
	//四、     Char*转换为string
		//如果要把一个char 转换成string, 可以使用 string s(char  *);
	//五、string 转CString
	CString cstr;
	string str;
	cstr.Format("%s", str.c_str());
	//六、char 转CString
	CString cstr2;
	cstr2.Format("%s", char*);
	//七、CString->string
	CString cstr3("123");
	string s(cstr3.GetBuffer());
	//GetBuffer()后一定要ReleaseBuffer(), 否则就没有释放缓冲区所占的空间.
	//八、CString互转int
	//将字符转换为整数，可以使用atoi、_atoi64或atol。
	//而将数字转换为CString变量，可以使用CString的Format函数。如
	CString s;
	int i = 64;
	s.Format("%d", i);



	system("pause");
	return 0;
}

