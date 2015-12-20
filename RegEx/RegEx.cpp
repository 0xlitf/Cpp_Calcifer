// RegEx.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <regex>
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <regex>
using namespace std;
enum MyEnum {
	a,b,c
};
int main()
{
	cout << "e:" << ' ' << endl;
	system("pause");
	return 0;
}

/*
正则表达式语法
正则表达式的特性分成很多种类，下面的内容是perl类型的Regex。
============================================================================================
特殊含义的字符
.  ：任意单个字符
[] ：字符集
{} ：计数
() ：子模式
\  ：下一个字符具有特殊含义
*  ：0个或多个
+  ：一个或多个
?  ：0个或一个
|  ：或
^  ：行的开始；否定
$  ：行的结束
===========================================================================================
字符集
\d ：一个十进制数字
\l ：一个小写字母
\s ：一个空白符（空格符，制表符等）
\u ：一个大写字母
\w ：一个字母（a～z或A～Z）或数字（0～9）或下划线（_）
\D ：除了\d之外的字符
\L ：除了\l之外的字符
\S ：除了\s之外的字符
\U ：除了\u之外的字符
\W ：除了\w之外的字符
===========================================================================================
重复
{n}  ：严格重复n次
{n,} ：重复n次或更多次
{n,m}：重复至少n次，至多m次
*    ：{0,}
+    ：{1,}
?    ：{0,1}
===========================================================================================
子模式
为了指定模式中的子模式，用括号将其括起来
（\d*:）?（\d+）：它表示字符串前半部分可以为空，若非空，则是任意长度的数字后接一个冒号，后半部分是一个或多个数字的序列。
===========================================================================================
可选项
| 表示二选一的概念。
Subject：（FW：| Re：）：表示匹配Subject:Fw：或者是Subject:Re:
===========================================================================================
正则表达式错误
当我们将一个模式富裕regex时，它会对模式进行检查，如果发现模式不合法或过于复杂，无法用于匹配时，它会抛出一个bad_expression异常。
===========================================================================================
*/
