// OverloadNew.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void* operator new(size_t size, char* file, int line)
{
	cout << "内存分配来自：" << file << ",行：" << line << endl;
	return malloc(size);
}

void operator delete(void* ptr)
{
	free(ptr);
}

//#define new new(__FILE__,__LINE__)

class A {
public:
	A(){}
	~A(){}

	int data[1000];
};

int _tmain(int argc, _TCHAR* argv[])
{

	A* p = new(__FILE__, __LINE__) A();
	//A* p = new A();


	return 0;
}