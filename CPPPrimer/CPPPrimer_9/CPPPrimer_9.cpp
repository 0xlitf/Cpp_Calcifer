// CPPPrimer_9.cpp : 顺序容器
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

/*

CPPPrimer_9 顺序容器
	一个容器就是一些特定类型对象的集合。
	顺序容器（sequential container）为程序员提供了控制元素存储和访问顺序的能力。
	这种顺序不依赖于元素的值，而是与元素加入容器时的位置相对应。

9.1 顺序容器概述
	顺序容器类型
	vector	可变大小数组。支持快速随机访问。在尾部之外的位置插入或删除元素很慢。
	deque	双端队列。支持快速随机访问。在头尾位置插入/删除速度很快。
	list	双向链表。只支持单向顺序访问。在链表任何位置进行插入/删除操作速度都很快。
	forward_list	单向链表。只支持单向顺序访问。在链表任何位置都进行插入/删除操作速度都很快。
	array	固定大小数组。支持快速随机访问。不能添加或删除元素。
	string	与vector相似的容器，但专门用于保存字符。随机访问快。在尾部插入/删除速度快。

9.2 容器库概览
	容器类型上的操作形成了一种层次：
	某些操作是所有容器类型都提供的。
	另外一些操作仅针对顺序容器、关联容器或无需容器。
	还有一些操作只适用于一小部分容器。

	9.21 迭代器
		与容器一样，迭代器有着公共的接口：如果一个迭代器提供某个操作，
		那么所有提供相同操作的迭代器对这个操作的实现方式都是相同的。
		
		迭代器范围
			迭代器范围的概念是标准库的基础。
			一个迭代器范围（iterator range）由一对迭代器表示，
			两个迭代器分别指向同一个容器中的元素或者是尾元素之后的位置（one past the last element）。

			虽然第二个迭代器常常被称为last，但这种叫法有些误导，因为第二个迭代器从来都不会指向范围中的最后一个元素，
			而是指向尾元素之后的位置， 迭代器范围中的元素包含first所表示的元素以及从first开始直至last（但不包含last）
			之间的所有元素。
			这种元素范围被称为左闭合区间（left-inclusive interval），其标准数学描述为
			[begin, end)
			表示范围自begin开始，于end之前结束。迭代器begin和end必须指向相同的容器。
			end可以与begin指向相同的位置，但不能指向begin之前的位置。

		使用左闭合范围蕴含的编程假定
			标准库使用左闭合范围是因为这种范围有三种方便的性质。
			假定begin和end构成一个合法的迭代器范围，则
			·如果begin与end相等，则范围为空
			·如果begin和end不等，则范围至少包含一个元素，且begin指向该范围中的第一个元素
			·我们可以对begin递增若干次，使得begin==end
			这些性质意味着我们可以像下面的代码一样用一个循环来处理一个元素范围，而这是安全的：
			while (begin!=end) {
			*begin = val;//正确，范围非空，因此begin指向第一个元素
			++begin;
			}
			给定构成一个合法范围的迭代器begin和end，若begin==end，则范围为空。
			在此情况下，我们应该退出循环。
			如果范围不为空，begin指向非空范围的一个元素。
			因此，在while循环体中，可以安全的解引用begin，因为begin必然指向一个元素。
			最后，由于每次循环对begin递增一次，我们确定循环最终会结束。



	9.22 容器类型成员
	    每个容器都定义了多个类型，我们已经使用过其中三种，size_type、iterator、const_iterator。
		除了已经使用过的迭代器类型，大多数容器还提供反向迭代器。
		简单的说，反向迭代器就是一种反向遍历容器的迭代器，与正向迭代器相比，各种操作的含义也都发生了颠倒。
		例如，对一个反向迭代器执行++操作，会得到上一个元素。

		剩下的就是类型别名了，通过类型别名，我们可以在不了解容器中元素类型的情况下使用它。
		如果需要元素类型，可以使用容器的value_type。
		如果需要元素类型的一个引用，可以使用reference或const-reference。
		这些元素相关的类型别名在泛型编程中非常有用。

		为了使用这些类型，我们必须显式使用其类名：
		//iter是通过list<string>::iterator定义的一个迭代器类型
		list<string>::iterator iter;
		//count是通过vector<int>定义的一个difference_type类型
		vetor<int>:::difference_type count;

	9.23 begin和end成员操作
	    begin和end有多个版本：带r的版本返回反向迭代器；以c开头的版本则返回const迭代器：
		list<string> a = {"Milton", "Shakespeare", "Austen"};
		auto it1 = a.begin();//iterator
		auto it2 = a.rbegin();//reverse_iterator
		auto it3 = a.cbegin();//const_iterator
		auto it4 = a.crbegin();//const_reverse_iterator
		不以c开头的函数都是被重载过的。
		也就是说，实际上有两个名为begin的成员。
		一个是const成员，返回容器的const_iterator类型。
		另一个是非常量成员，返回容器的iterator类型。



	9.24 容器定义和初始化
	    每个容器类型都定义了一个默认构造函数。
		除array之外，其他容器的默认构造函数都会创建一个指定类型的空容器，且都可以接受指定容器大小和元素初始值的参数。
		C c; //
		C c1(c2); //
		C c1=c2; //
		C c{a,b,c...}; //
		C c={a,b,c...}; //
		C c(b,e); //
		// 只有顺序容器（不包括array）的构造函数才能接受大小参数
		C seq(n); //
		C seq(n,t); //



	9.25 赋值和swap
	    赋值运算符将其左边容器中的全部元素替换为右边容器中元素的拷贝：
		c1 = c2; //将c1的内容替换为c2中元素的拷贝
		c1 = {a,b,c}; //赋值后，c1大小为3
		与内置数组不同，标准库array类型允许赋值。
		赋值号左右两边的运算对象必须具有相同的类型。




	9.26 容器大小操作
	    每个容器类型都有三个与大小相关的操作。
		成员函数size返回容器中元素的数目；
		empty当size为0时返回布尔值true，
		否则返回false；
		max_size返回一个大于或等于该类型容器所能容纳的最大元素数的值。



	9.27 关系运算符
	    每个容器类型都支持相等运算符（==和！=）；
		除了无序关联容器外的所有容器都支持关系运算符（>、>=、<、<=）。
		关系运算符左右两边的运算对象必须是相同类型的容器，
		且必须保存相同类型的元素。

9.3 顺序容器操作
    9.31 向顺序容器添加元素

	9.32 访问元素

	9.33 删除元素

	9.34 特殊的forward_list操作

	9.35 改变容器大小

	9.36 容器操作可能使迭代器失效

9.4 vector对象是如何增长的
    为了支持快速随机访问，vector将元素连续存储——每个元素紧挨着前一个元素存储。
	vector和string的实现通常会分配比新的空间需求更大的内存空间。


9.5 额外的string操作
    9.51 构造string的其他方法


	9.52 改变string的其他方法

	9.53 string搜索操作

	9.54 compare函数

	9.55 数值转换
9.6 容器适配器
    除了顺序容器外，标准库还定义了三个顺序容器适配器：stack、queue和priority_queue。
	适配器（adaptor）是标准库中的一个通用概念。容器、迭代器和函数都有适配器。
	本质上，一个适配器是一种机制，能使某种事物的行为看起来像一种不同的类型。

	http://blog.csdn.net/thefutureisour/article/details/7751846

	首先，我们要明白适配器是干什么的？其实就是一个接口转换装置，是得我们能用特定的方法去操作一些我们本来无法操作的东西。举一个例子，比如你的一个设备支持串口线，而你的电脑支持的是usb口，这时候，我们没有必要重新买一个支持usb的设备，只需要一根串口转usb口的小玩意，让你的设备能够连接到usb插口上，而它就是适配器。
	那么C++中的容器适配器是干什么的呢？可以做一个类比，我们已有的容器（比如vector、list、deque）就是设备，这个设备支持的操作很多，比如插入，删除，迭代器访问等等。而我们希望这个容器表现出来的是栈的样子：先进后出，入栈出栈等等，此时，我们没有必要重新动手写一个新的数据结构，而是把原来的容器重新封装一下，改变它的接口，就能把它当做栈使用了。
	言归正传，理解了什么是适配器以后，其实问题就很简单的。C++中定义了3种容器适配器，它们让容器提供的接口变成了我们常用的的3种数据结构：栈（先进后出）队列（先进先出）和优先级队列（按照优先级（“<”号）排序，而不是按照到来的顺序排序）。
	至于具体是怎么变的，我们可以先了解一个大概：默认情况下，栈和队列都是基于deque实现的，而优先级队列则是基于vector实现的。当然，我们也可以指定自己的实现方式。但是由于数据结构的关系，我们也不能胡乱指定。栈的特点是后进先出，所以它关联的基本容器可以是任意一种顺序容器，因为这些容器类型结构都可以提供栈的操作有求，它们都提供了push_back、pop_back和back操作。 队列queue的特点是先进先出，适配器要求其关联的基础容器必须提供pop_front操作，因此其不能建立在vector容器上；对于优先级队列，由于它要求支持随机访问的功能，所以可以建立在vector或者deque上，不能建立在list上。

	让我们看看这三种关联容器提供的接口：
	栈支持的操作有：
	1.empty()  堆栈为空则返回真
	2.pop()  移除栈顶元素
	3.push()  在栈顶增加元素
	4.size()  返回栈中元素数目
	5.top()  返回栈顶元素
	队列支持的操作有：
	1.back()  返回一个引用，指向最后一个元素
	2.empty()  如果队列空则返回真
	3.front()  返回第一个元素
	4.pop()  删除第一个元素
	5.push()  在末尾加入一个元素
	6.size()  返回队列中元素的个数
	优先级队列支持的操作有：
	1.empty()  如果优先队列为空，则返回真
	2.pop()  删除第一个元素
	3.push()  加入一个元素
	4.size()  返回优先队列中拥有的元素的个数
	5.top()  返回优先队列中有最高优先级的元素

	举个例子：
	[cpp] view plaincopy

	int main()
	{
	const stack<int>::size_type stk_size = 10;
	//创建一个空栈
	stack<int> intStack;
	//改变栈的实现方式为vector
	//stack<int,vector<int> > intStack;
	int ix = 0;

	while(intStack.size() != stk_size)
	intStack.push(ix++);

	int error_cnt = 0;
	while(intStack.empty() == false)
	{
	//top操作返回栈顶元素，但并不删除
	int value = intStack.top();
	if(value != --ix)
	{
	cout<<"opps! expected "<<ix<<" received "<<value<<endl;
	++error_cnt;

	}
	//删除栈顶元素
	intStack.pop();
	}

	cout<<"our program ran with "<<error_cnt<<" errors! "<<endl;
	return 0;
	}




	最后我们可以窥探一下stl中的源码：
	[cpp] view plaincopy

	template<class _Ty,
	class _Container = deque<_Ty> >
	class stack
	{   // LIFO queue implemented with a container
	public:
	typedef stack<_Ty, _Container> _Myt;
	typedef _Container container_type;
	typedef typename _Container::value_type value_type;
	typedef typename _Container::size_type size_type;
	typedef typename _Container::reference reference;
	typedef typename _Container::const_reference const_reference;

	stack()
	: c()
	{   // construct with empty container
	}

	stack(const _Myt& _Right)
	: c(_Right.c)
	{   // construct by copying _Right
	}

	explicit stack(const _Container& _Cont)
	: c(_Cont)
	{   // construct by copying specified container
	}

	_Myt& operator=(const _Myt& _Right)
	{   // assign by copying _Right
	c = _Right.c;
	return (*this);
	}

	stack(_Myt&& _Right)
	: c(_STD move(_Right.c))
	{   // construct by moving _Right
	}

	explicit stack(_Container&& _Cont)
	: c(_STD move(_Cont))
	{   // construct by copying specified container
	}

	_Myt& operator=(_Myt&& _Right)
	{   // assign by moving _Right
	c = _STD move(_Right.c);
	return (*this);
	}

	void push(value_type&& _Val)
	{   // insert element at beginning
	c.push_back(_STD move(_Val));
	}

	template<class _Valty>
	void emplace(_Valty&& _Val)
	{   // insert element at beginning
	c.emplace_back(_STD forward<_Valty>(_Val));
	}

	void swap(_Myt&& _Right)
	{   // exchange contents with movable _Right
	c.swap(_STD move(_Right.c));
	}

	bool empty() const
	{   // test if stack is empty
	return (c.empty());
	}

	size_type size() const
	{   // test length of stack
	return (c.size());
	}

	reference top()
	{   // return last element of mutable stack
	return (c.back());
	}

	const_reference top() const
	{   // return last element of nonmutable stack
	return (c.back());
	}

	void push(const value_type& _Val)
	{   // insert element at end
	c.push_back(_Val);
	}

	void pop()
	{   // erase last element
	c.pop_back();
	}

	const _Container& _Get_container() const
	{   // get reference to container
	return (c);
	}

	void swap(_Myt& _Right)
	{   // exchange contents with _Right
	c.swap(_Right.c);
	}

	protected:
	_Container c;   // the underlying container
	};


	从中我们可以清楚的看到：栈在默认情况下，是基于deque实现的，它使用封装的顺序容器的操作来实现的自己的操作。

















*/