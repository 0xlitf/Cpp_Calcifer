// CPPPrimer_19.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
namespace a {}
int _tmain(int argc, _TCHAR* argv[])
{
	{
		int i = 1;
		std::cout << "i:" << i << std::endl;
	}
	{
		int i = 1;
		std::cout << "i:" << i << std::endl;
	}

	return 0;
}

/*
19.1 控制内存分配
    19.1.1 重载new和delete

	19.1.2 定位new表达式

19.2 运行时类型识别
    19.2.1 dynamic_cast运算符

	19.2.2 typeid运算符

	19.2.3 使用RTTI

	19.2.4 type_info类

19.3 枚举类型
    
19.4 类成员指针
    19.4.1 数据成员指针

	19.4.2 成员函数指针

	19.4.3 将成员函数用作可调用对象

19.5 嵌套类
    
19.6 union：一种节省空间的类
    
19.7 局部类

19.8 固有的不可移植的特性
    19.8.1 位域

	19.8.2 volatile限定符

	19.8.3 链接只是：extern "C"



*/