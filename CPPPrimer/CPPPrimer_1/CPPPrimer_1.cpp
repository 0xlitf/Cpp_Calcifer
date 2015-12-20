// CPPPrimer_1.cpp : 定义控制台应用程序的入口点。
//开始

#include "stdafx.h"
#include <iostream>
//#include <string>
//using namespace std;

//CPPPrimer_1.1 编写一个简单的C++程序
//一个函数的定义包含四个部分：返回类型（return type），函数名（function name），
//一个括号包围的形参列表（parameter list，允许为空），
//以及函数体（function body）。
//main函数的返回类型必须为int。
//在大多数系统中，main函数的返回值被用来指示状态。
//返回值0表明成功，非0的返回值的含义由系统决定，通常用来指出错误类型。

int _tmain(int argc, _TCHAR* argv[])
{
	int variable1 = 0, variable2 = 0;
	std::cin >> variable1 >> variable2;
	std::string d("d");
	std::cout << "" << std::endl;
	std::cin.get();
	return 0;
}
//CPPPrimer_1.2 初识输入输出
//iostream库包含两个基础类型，istream和ostream，分别表示输入流和输出流。
//一个流就是一个字符序列，是从IO设备读出或写入IO设备的。
//cin是一个istream对象，
//cout、cerr、clog是ostream对象。
//输出运算符（<<）接受两个运算对象：左侧的运算对象必须是一个ostream对象，右侧的运算对象是要打印的值。
//此运算符将给定的值写到给定的ostream对象中。输出运算符的计算结果就是其左侧的运算对象。
//endl是一个被称为操纵符（manipulater）的特殊值。
//写入endl的结果是结束当前行，并将与设备关联的缓冲区（buffer）中的内容刷到设备中。
//缓冲刷新操作可以保证到目前为止程序所产生的所有输出都真正写入输出流中，而不是仅停留在内存中等待写入流。

//CPPPrimer_1.3 注释简介
//C++中有两种注释：单行注释和界定符对注释。
//单行注释以双斜线（//）开始，以换行符结束。
//界定符对不可嵌套。

//CPPPrimer_1.4 控制流
//提供了多种不同的控制流语句，允许改变程序的执行路径。
//while语句，
//for语句，
//if语句，

//CPPPrimer_1.5 类简介
//(.)运算符，
//调用运算符（()）来调用一个函数，调用运算符是一对圆括号，里面放置实参（argument）列表（可能为空）。

