// OnlyStackClass_OnlyHeapClass.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>  
using namespace std;

class OnlyHeap {
public:
	OnlyHeap()
	{
		cout << "construct" << endl;
	}
	void distory() const
	{
		delete this;
	}

private:
	~OnlyHeap()
	{
		cout << "destruct" << endl;
	}
};

class OnlyStack {
public:

	OnlyStack()
	{
		cout << "����" << endl;
	}
	~OnlyStack()
	{
		cout << "����" << endl;
	}
private:
	void* operator new (size_t t);
	void  operator delete(void *ptr);
};

int _tmain(int argc, _TCHAR* argv[])
{
	OnlyStack os;
	OnlyHeap oh;
	OnlyStack* s = new OnlyStack;
	OnlyHeap* h = new OnlyHeap;

	return 0;
}

