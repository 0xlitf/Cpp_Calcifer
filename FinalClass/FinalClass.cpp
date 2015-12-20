// FinalClass.cpp : 定义控制台应用程序的入口点。
//
//实例化有两种方法
//1、用static的函数返回实例化的对象指针
//2、用friend的全局函数返回实例化的指针，这个方法就是有点不面向对象

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

