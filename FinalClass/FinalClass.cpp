// FinalClass.cpp : �������̨Ӧ�ó������ڵ㡣
//
//ʵ���������ַ���
//1����static�ĺ�������ʵ�����Ķ���ָ��
//2����friend��ȫ�ֺ�������ʵ������ָ�룬������������е㲻�������

#include "stdafx.h"
class FinalClass {
public:
	FinalClass();

private:
	
	~FinalClass();
};

FinalClass::FinalClass()
{
}

FinalClass::~FinalClass()
{
}

class DeriveClass :public FinalClass {
public:
	DeriveClass();
	~DeriveClass();

private:

};

int _tmain(int argc, _TCHAR* argv[])
{
	FinalClass* a = new FinalClass;
	//delete a;
	DeriveClass dc;
	return 0;
}

