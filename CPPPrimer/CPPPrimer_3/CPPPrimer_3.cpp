// CPPPrimer_3.cpp : 字符串、向量和数组
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned cnt = 42;				//不是常量表达式
//	constexpr unsigned sz = 42;		//常量表达式
	const unsigned num = 42;
//	int a[cnt];
//	int a[sz];
	int a[num];

//	处理每个字符？使用基于范围的for语句：

	/*string str("some string");
	for (char c : str)
	cout << c << endl;
	cin.get();*/

	// Basic 10-element integer array.
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// Range-based for loop to iterate through the array.
	for (int y : x) { // Access by value using a copy declared as a specific type. 
		// Not preferred.
		cout << y << " ";
	}
	cout << endl;

	// The auto keyword causes type inference to be used. Preferred.

	for (auto y : x) { // Copy of 'x', almost always undesirable
		cout << y << " ";
	}
	cout << endl;

	for (auto &y : x) { // Type inference by reference.
		// Observes and/or modifies in-place. Preferred when modify is needed.
		cout << y << " ";
	}
	cout << endl;

	for (const auto &y : x) { // Type inference by reference.
		// Observes in-place. Preferred when no modify is needed.
		cout << y << " ";
	}
	cout << endl;
	cout << "end of integer array test" << endl;
	cout << endl;

	// Create a vector object that contains 10 elements.
	vector<double> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i + 0.1);
	}

	// Range-based for loop to iterate through the vector, observing in-place.
	for (const auto &j : v) {
		cout << j << " ";
	}
	cout << endl;
	cout << "end of vector test" << endl;

	//while (cin >> a)
	//{
	//	cerr << a << endl;
	//}
	//Sleep(3000);

	string str_iterator("iterator首字母大写");
	if (str_iterator.begin() != str_iterator.end())
	{
		auto it = str_iterator.begin();
		*it = toupper(*it);
	}
	cout << "iterator:" << endl
		<< str_iterator << endl;
	for (auto it_for = str_iterator.begin(); it_for != str_iterator.end();it_for++)
	{
		*it_for = toupper(*it_for);
	}
	cout << "iterator元素的移动:" << endl
		<< str_iterator << endl;














	//迭代器

	cin.get();
	return 0;
}

/*
3.1 命名空间的using声明
		using std::cin;
		位于头文件的代码一般来说不应使用using声明。

3.2 标准库类型string
	标准库类型string表示可变长的字符序列，使用string类型必须首先包含string头文件。
	作为标准库的一部分，string定义在命名空间std中。

	3.21 定义和初始化string对象
	一个类可以定义很多种初始化对象的方式，只不过这些方式之间必须有所区别：
	或者是初始值的数量不同，或者是初始值的类型不同。
	string s1;//默认初始化，s1是一个空串
	string s2 = s1;		string s2（s1）；//s2是s1的副本
	string s3 = "hiya";//s3是该字符串字面值的副本
	string s4(10,'c');//s4的内容是10个c
	string s5("hiya);
	如果使用等号（=）初始化一个变量，实际上执行的是拷贝初始化；
	如果不适用等号，则执行的是直接初始化。
	可以创建一个临时对象用于拷贝：
	string s7 = string(10,'c');

	3.22 string对象上的操作
	os<<s 将s写到输出流os中，返回os
	is>>s 从is中读取字符串赋给s，字符串以空白分隔，返回is，输入aa a，输出aa
	getline(is,s) 从is读取一行赋给s，返回is
	s.empty() s为空返回true，否则返回false
	s.size()返回s中字符的个数
	s[n] 返回s中第n个字符的引用，位置n从0计起
	s1+s2 返回s1和s2连接后的结果
	s1=s2 用s2的副本代替s1中原有的字符
	s1==s2 
	s1!=s2
	<,<=,>,>= 利用字符在字典中的顺序进行比较，且对字母的大小写敏感

	1、cout对应于标准输出流
	cerr对应于标准错误流
	2、cout可以重定向，cerr不可以。
	3、cout要分配缓冲，cerr不用，所以从理论上来说，cerr输出要比cout要快。
	4、cout和cerr默认都是标准输出设备：显示器.

	size函数返回一个string::size_type类型的值，string类以及其他大多数标准库类型都定义了几种配套的类型，
	这些配套类型体现了标准库类型与机器无关的特性。
	string::size_type是一个无符号类型的值，而且能够放下任何string对象的大小。

	cctype头文件中的函数
	isalnum(c)
	isalpha(c)
	...

	
3.3 标准库类型vector
	标准库类型vector表示对象的集合，其中所有对象的类型都相同。
	集合中的每个对象都有一个与之对应的索引，索引用于访问对象。
	由于vector：容纳着“其他对象，所以它也被称作容器（container）。
	要想使用vector必须包含适当的头文件，#include <vector>	using std::vector;
	C++既有类模板（class template），也有函数模板，vector是一个类模板。
	模板本身不是类或函数，相反可以将模板看做为编译器生成类或者函数编写的一份说明。
	编译器根据模板创建类或者函数的过程称为实例化（instantiation），
	当使用模板时，需要指出编译器应把类或者函数实例化成何种类型。

	3.31 定义和初始化vector对象
	和任何一种类类型一样，vector模板控制着定义和初始化向量的方法。

	 vector<T> v1					v1是一个空vector，它潜在的元素是T类型的，执行默认初始化
	 vector<T> v2(v1)				v2中包含有v1所有元素的副本
	 vector<T> v3 = v1				等价于v3(v1)
	 vector<T> v4(n,val)			v4包含n个重复的元素，每个元素的值都是val
	 vector<T> v5(n)				v5包含了n个重复的执行了值初始化的对象
	 vector<T> v6{a,b,c...}			v6包含了初始值个数的元素，每个元素被赋予相应的初始值
	 vector<T> v7 = {a,b,c...}		等价于v6
	 最常见的方式是先定义一个空vector，然后当运行时获取到元素的值后再逐一添加。
	 vector<string> v5{"hi"}		//列表初始化，v5有一个元素
	 vector<string> v6("hi")		//错误，不能使用字符串字面值构建vector对象
	 vector<string> v7{10}					//v7有10个默认初始化的元素
	 vector<string> v8{10,"hi"}				//v8有10个值为“hi”的元素
	 要想列表初始化vector对象，花括号里的值必须与元素类型相同。
	 显然不能用int初始化string对象，所以v7和v8提供的值不能作为元素的初始值。
	 确认无法执行列表初始化后，编译器会尝试用默认值初始化vector对象。
	 3.32 向vector对象中添加元素
	 push_back负责把一个值当成vector对象的为元素压到vector对象的尾端。
	 vector<int> v2;
	 for (int i = 0; i != 100; ++i)
	 v2.push_back(i);
	 其他vector操作：
	 v.empty()			如果v中不含有任何元素返回true，否则返回false
	 v.size()			返回v中元素的个数
	 v.push_back(t)		向v尾端添加一个值为t的元素
	 v[n]				返回v中第n个位置上元素的引用
	 v1 = v2			用v2中元素的拷贝替换v1中的元素
	 v1 = {a,b,c,...}	用列表中元素的拷贝替换v1中的元素
	 v1 == v2			v1和v2相等当且仅当他们的元素数量相同且对应位置的元素值都相同
	 v1 != v2			
	 <,<=,>,>=			以字典顺序进行比较
	 vector对象（以及string对象）的下表运算符可用于访问已存在的元素，而不能用于添加元素。
	 只能对确知已存在的元素执行下标操作。
	 确保下标合法的一种有效手段就是尽可能的使用范围for语句。


3.4 迭代器介绍
	可以使用下标运算符来访问string对象的字符或vector对象的元素。还有另外一种更通用的机制也可以实现同样的目的。
	string对象不属于容器类型，但是string支持很多与容器类型累死的操作。
	vector支持下标运算符，这和sgring一样；string支持迭代器，这也和vector是一样的。
	累死于指针类型，迭代器也提供了对对象的间接访问。就迭代器而言，其对象是容器中的元素或者string对象中的字符。
	使用迭代器可以访问某个元素，迭代器也能从一个元素移动到另外一个元素。
	迭代器有有效和无效之分，这一点和指针差不多。
	有效的迭代器或者指向某个元素，或者指向容器中尾元素的下一位置；其他所有情况都属于无效。
	3.41 使用迭代器
	和指针不一样的是，获取迭代器不是使用取地址符，有迭代器的类型同时拥有返回迭代器的成员。
	比如，这些类型都拥有名为begin和end的成员，其中begin成员负责返回指向第一个元素（或第一个字符）的迭代器。

	end成员负责返回指向容器（或string对象）“尾元素的下一位置（one past the end）”的迭代器，也就是说该迭代器只是的是容器的一个本不存在的“尾后（off the end）”元素。
	这样的迭代器没什么实际含义，仅是个标记而已，表示我们已经处理完了容器中的所有元素。
	end成员返回的迭代器常被称作尾后迭代器（off-the-end iterator）或者简称为尾迭代器（end iterator）。
	特殊情况下如果容器为空，则begin和end返回的是同一个迭代器，都是尾后迭代器。

	标准容器迭代器的运算符
	*iter			返回迭代器iter所指元素的引用
	iter->men		解引用iter并获取该元素的名为men的成员，等价于（*iter）.men
	++iter			令iter只是容器中的下一个元素
	--iter			令iter只是容器中的上一个元素
	iter1 == iter2	判断两个迭代器是否相等（不相等），如果两个迭代器只是的是同一个元素或者他们是
	iter1 != iter2	同一个容器的尾后迭代器，则相等，反之，不相等

	迭代器类型
	就像不知道string和vector的size_type成员到底是什么类型一样，一般来说我们也不知道（其实是无需知道）迭代器的精确类型。
	而实际上，那些拥有迭代器的标准库类型使用iterator和const_iterator来表示迭代器的类型：
	vector<int>::iterator it;//可读可写
	string::iterator it2;//可读可写
	vector<int>::const_iterator it3;//可读不可写
	string::const_iterator it4;//可读不可写

	cbegin cend，和begin end的类似，不论vector对象本身是否为常量，返回值都是const_iterator
	迭代器解引用时：
	(*it).empty()//正确
	*it.enpty()//错误

	某些对vector的操作会使迭代器失效。

	3.42 迭代器运算
	string和vector的迭代器提供了更多额外的运算符，一方面可使得的带起的每次移动跨过多个元素，另外也支持迭代器进行关系运算。
	P99：
	iter + n
	iter - n
	iter1 += n
	iter1 -= n
	iter1 - iter2
	>,>=,<,<=




3.5 数组
	3.51 定义和初始化内置数组
	数组的声明形如a[d]，其中a是数组的名字，d是数组的维度。维度说明了数组中元素的个数，因此必须大于0.
	数组中元素的个数也属于数组类型的一部分，编译时维度应该是已知的。
	也就是说维度必须是一个常量表达式。
	unsigned cnt = 42;				//不是常量表达式
	constexpr unsigned sz = 42;		//常量表达式
	默认情况下数组元素被默认初始化。

	定义数组时必须制定数组的类型，不允许用auto关键字由初始值的列表推断类型。
	另外和vector一样，数组的元素应为对象，因此不存在引用的数组。

	显式初始化数组元素
	可以对数组的元素进行列表初始化，此时允许忽略数组的维度。
	如果在声明时没有指明维度，编译器会根据初始值的数量计算并推测出来；
	相反，如果指明了维度，那么初始值的总数量不应该超出指定的大小。
	如果维度比提供的初始值数量大，则用提供的初始值初始化靠前的元素，剩下的元素被初始化为默认值。
	const unsigned sz = 3;
	int ial[sz] = {0, 1, 2};//含有3个元素的数组
	int a2[] = {0, 1, 2};//维度是3的数组
	int a3[5] = {0, 1, 2};//其余两个元素是0
	string a4[3] = {"hi","bye"};//最后一个元素为空
	int a5[2] = {0, 1, 2};//错误，初始值过多

	字符数组的特殊性
	字符数组有一种额外的初始化方式，我们可以用字符串字面值对此类数组初始化。当使用这种方式时。
	一定要注意字符串字面值的结尾处还有一个空字符，这个控制符也会像字符串的其他字符一样被拷贝到字符数组中去。
	char a1[] = {'C','+','+'};//列表初始化，没有空字符
	char a2[] = {'C','+','+','\0};//列表初始化，含有显式的空字符
	char a3[] = "C++";//自动添加表示字符串结束的空字符
	const char a4[6] = "cccccc";//错误，没有空间存放空字符

	不允许拷贝和赋值
	不能将数组的内容拷贝给其他数组作为其初始值，也不能用数组为其他数组赋值：
	int a[] = {0,1,2};//含有3个整数的数组
	int a2[] = a;//错误，不允许初始化
	a2 = a;//错误，不允许赋值

	理解复杂的数组声明
	和vector一样，数组能存放大多数类型的对象。
	例如可以定义一个存放指针的数组。
	有因为数组本身就是对象，所以允许定义数组的指针以及数组的引用。
	这几种情况中，定义存放指针的数组比较简单和直接，但是定义数组的指针或数组的引用就复杂了很多。
	int *ptrs[10];//ptrs是含有10个整型指针的数组
	int &refs[10];//错误，不存在引用的数组
	int (*Parray)[10] = &arr;//Parray指向一个含有10个整数的数组
	int (&arrRef)[10] = arr;//Parray引用一个含有10个整数的数组
	默认情况下，类型修饰符从右向左依次绑定。对于ptrs来说，从右向左理解其含义比较简单：
	首先知道我们定义的是一个大小为10个数组，它的名字是ptrs，然后知道数组中存放的是指向int的指针。

	但是对于Parray来说，从右向左理解就不太合理了。
	因为数组的维度是紧跟着被声明的名字的，所以就数组而言，由内向外阅读要比从右向左好多了。
	首先是圆括号括起来的部分，*Parray意味着Parray是个指针，接着观察右边，可知道Parray是个指向大小为10的数组的指针，
	最后观察左边，知道数组中的元素是int。这样最终的含义就明白无误了，Parray是一个指针，它指向一个int数组，数组中包含
	10个元素。
	对修饰符的数量并没有特殊限制：
	int *(&arry)[10] = ptrs;//arry是数组的引用，该数组含有10个指针
	3.52 访问数组元素
	与标准库类型vector和string一样，数组的元素也能使用范围for语句或下边运算符来访问。
	在使用数组下标的时候，通常将其定义为size_t类型。
	size_t是一种机器相关的无符号类型，它被设计的足够大以便能表示内存中任意对象的大小。
	在cstddef头文件中定义了size_t类型。
	3.53 指针和数组
	使用数组的时候，编译器一般会把数组转换成指针。
	通常情况下，使用取地址符来获取指向某个对象的指针，取地址符可以用于任何对象。
	数组的元素也是对象，对数组使用下标运算符得到该数组指定位置的元素。
	因此像其他对象一样，对数组的元素使用取地址符就能得到指向该元素的指针：
	string nums[] = {"1","2","3"};
	string *p = &nums[0];
	数组还有一个特性：在很多用到数组名字的地方，编译器都会自动的将其替换为一个指向数组手元素的指针：
	string *p2 = nums;//等价于p2 = &nums[0]
	数组的操作其实是指针的操作。
	当使用数组作为一个auto变量的初始值时，推断得到的类型是指针而非数组：
	int ia[] = {0,1,2,3,4,5,6,7,8,9};//ia是含有10个元素的数组
	auto = ia2(ia);//ia2是一个整型指针，指向ia的第一个元素
	ia2 = 42;//错误，ia2是一个指针，不能用int值给指针赋值
	必须指出，使用decltype关键字时，上述转换不会发生，decltype(ia)返回的类型是由10个整数构成的数组：
	ia3是一个含有10个整数的数组
	decltype9ia0 ia3 = {0,1,2,3,4,5,6,7,8,9};//
	ia3 = p;//错误，不能用整型指针给数组赋值
	ia3[4] = i;//正确

	指针也是迭代器
	设法获取数组尾元素之后的那个并不存在的元素的地址：
	int *e = &arr[10];//指向arr尾元素的下一位置的指针
	这个不存在元素的唯一用处就是提供其地址用于初始化e。
	因此不能对尾后指针执行解引用或递增操作。

	标准库函数 begin和end
	尽管能计算得到尾后指针，但这种用法极易出错。
	这两个函数与容器中的两个同名成员工恩给你类似，不过数组毕竟不是类类型，因此这两个函数不是成员函数。
	正确的使用形式是将数组作为他们的参数：
	int ua[] = {0,1,2,3,4,5,6,7,8,9};// 
	int *beg = begin(ia);//指向ia首元素的指针
	int *last = end(ia);//指向尾元素下一位置的指针
	这两个函数定义在iterator头文件中

	指针运算
	指向数组元素的指针可以执行所有迭代器运算。
	这些运算，包括解引用、递增、比较、与整数相加、两个指针相减等，用在指针和用在迭代器上意义完全一致。

	和迭代器意义，两个指针相减的结果是他们之间的距离。
	参与运算的两个指针必须指向同一个数组当中的元素：
	auto n = end(arr) - begin (arr);
	两指针相减的结果的类型是一种名为ptrdiff_t的标准库类型，和size_t一样，
	ptrdiff_t也是一种定义在cstddef头文件中的机器相关的类型。因为差值可能为负，所以他是带符号类型。
	上述指针运算同样适用于空指针，和所指对象并非数组的指针。
	在后一种情况下，两个指针必须指向通一个对象或该对象的下一位置。
	如果p是空指针，允许给p加上或减去一个值为0的整型常量表达式。两个空指针也允许彼此相减，结果是0。

	解引用和指针运算的交互
	解引用必要时要加上括号。

	下标和指针
	对数组执行下标运算其实是对指向元数组元素的指针执行下标运算：
	int i = ia[2];//ia转换成指向数组首元素的指针
					//ia[2]得到（ia + 2）所指的元素
	int *p = ial;  //p指向ia的首元素
	i = *(p + 2);	//等价于i = ia[2]
	只要指针指向的是数组中的元素（或者数组中尾元素的下一位置），都可以执行下标运算：
	int *p = &ia[2]; //p是指向索引为2的元素
	int j = p[1];//p[1]等价于*（p + 1），就是ia[3]表示的那个元素
	int k = p[-2];//p[-2]是ia[0]表示的那个元素
	标准库类型限定使用的下标必须是无符号类型，而内置的下标运算无此要求。
	内置的下标运算符可以处理负值，结果地址必须指向原来的指针所指同一数组中的元素。

	3.54 C风格字符串
	3.55 与旧代码的接口
	使用数组初始化vector对象
	允许使用数组来初始化vector对象，只需指明要拷贝区域的首元素地址和尾后地址就可以了。
	int int_arr[] = {0,1,2,3,4,5};
	vector<int> ivec(begin(int_arr), end(int_arr));
	用于初始化vector对象的值也可能仅是数组的一部分：
	vector<int> subVec(int_arr + 1, int_arr +4);

3.6 多维数组
	严格来说C++中没有多维数组，通常所说的多维数组其实是数组的数组。
	可使用范围for语句来处理多维数组。
	size_t cnt = 0;
	for (auto &row : ia)
		for (auto &col : row){
			col = cnt;
			++cnt;
			}
	因为要改变元素的值，所以得把控制变量row和col声明成引用类型。
	第一个for循环遍历ia的所有元素，这些元素是大小为4的数组，因此row的类型就应该是含有4个证书的数组的引用。
	第二个for循环遍历那些4元素数组中的某一个，因此col的类型是整数的引用。
	每次迭代把cnt的值赋给ia的当前元素，然后将cnt加1。
	上面的例子中，因为要改变数组元素的值么所以我们选用引用类型座位循环控制变量，但其实还有一个深层次的原因促使我们这样做。
	考虑如下的循环：
	for (const auto &row : ia)
		for (auto col : row)
		这个循环中没有任何写操作，可是还是将外层循环的控制变量声明成了引用类型，这是为了避免数组被自动转换成指针。
		假设不用引用类型：
		for (auto row : ia)
			for (auto col : row)
			程序将无法通过编译。
			这是因为像之前一样第一个循环遍历ia的所有元素，注意这些元素实际上是大小为4的数组。
			因为row不是引用类型，所以编译器初始化row时会自动将这些数组形式的元素转换成指向该数组内首元素的指针。
			这样得到的row的类型就是int*，显然内层循环就不合法了，编译器将试图在一个int*内遍历。

	指针和多维数组
	int ia[3][4];//
	int (*p)[4] = ia;//p指向含有4个整数的数组
	p = &ia[2];//p指向ia的尾元素
	圆括号必不可少：
	int *ip[4];//整型指针的数组
	int (*ip)[4];//指向含有4个整数的数组

	类型别名可以简化多维数组的指针


*/