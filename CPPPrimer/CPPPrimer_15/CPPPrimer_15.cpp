// CPPPrimer_15.cpp : 面向对象程序设计
//

#include "stdafx.h"
#include <windows.h>

class MyClass
{
public:
	MyClass();
	MyClass(MyClass&& mc);
	~MyClass();

private:

};

MyClass::MyClass()
{
	MyClass o;
	MyClass& ref =  o;
}

MyClass::~MyClass()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0;
	int &b = a;


	//int &&c = b;

	Sleep(10000);
	return 0;
}

/*

CPPPrimer_15	面向对象程序设计
15.1 OOP:概述
	面向对象程序设计（object-oriented programming）的核心思想是数据抽象、继承和动态绑定。
	通过使用数据抽象，我们可以将类的接口与实现分离；
	使用继承，可以定义相似的类型并对其相似关系建模；
	使用动态绑定，可以在一定程序上忽略相似类型的区别，而以同意的方式使用它们的对象。

	继承
		通过继承（inheritance）联系在一起的类构成一种层次关系。
		通常在层次关系的根部有一个基类（base class），
		其他类则直接或间接的从基类继承而来，这些继承得到的类成为派生类（derived class）。
		基类负责定义在层次关系中所有类共同拥有的成员，而每个派生类定义各自特有的成员。
		
		C++中，基类将类型相关的函数与派生类不做改变直接继承的函数区分对待。
		对于某些函数，基类希望它的派生类各自定义适合自身的版本，此时基类就将这些函数声明成虚函数（virtual function）。
		派生类必须通过使用类派生列表（class derivation list）明确指出它是从哪个（哪些）基类继承而来的。
		类派生列表的形式是：首先是一个冒号，后面紧跟以逗号分隔的基类列表。

		派生类必须在其内部对所有重新定义的虚函数进行生命。派生类可以再这样的函数之前加上virtual关键字，蛋不是非得这么做。

	动态绑定
		通过使用类型绑定（dynamic binding），我们能用同一段代码分别处理Quote和Bulk_quote对象。
		int print(Base &base)
		{
			
		}
		我们既能用基类对象调用该函数，也能使用派生类的对象调用它，实际传入的对象类型将决定执行虚函数的哪个版本。
		因此在上述过程中函数的运行版本由实参决定，即在运行时选择函数的版本，所以动态绑定有时又被称为运行时绑定。

		在C++语言中，当我们使用基类的引用或指针调用一个虚函数时将发生动态绑定。

15.2 定义基类和派生类
	定义基类和派生类的方式在很多方面都与我们已知的定义其他类的方式类似，但是也有一些不同之处。
	15.2.1 定义基类
		作为继承关系中根节点的类通常都会定义一个虚席构函数。
		基类通常都应该定义一个虚席构函数，即使该函数不执行任何实际操作也是如此。

		成员函数与继承
			派生类可以继承其基类的成员，然后当遇到与类型相关的操作时，派生类必须对其重新定义。
			换句话说，派生类需要对这些操作提供自己的新定义以覆盖（override）从基类而来的旧定义。

			在C++中基类必须将它的两种成员函数区分开来：
			一种是基类希望其派生类进行覆盖的函数；
			另一种是基类希望派生类直接继承而不要改变的函数。

			对于前者，基类通常将其定义成虚函数（virtual）。
			当我们使用指针或引用调用虚函数时，该调用将被动态绑定。

			根据引用或指针所绑定的对象不同，该调用可能执行基类的版本，也可能执行某个派生类的版本。

			基类通过在其成员函数的声明语句之前加上关键字virtual使得该函数执行动态绑定。
			任何构造函数之外的非静态函数都可以是虚函数。
			关键字virtual只能出现在类内部的声明语句之前而不能用于类外部的函数定义。
			如果基类把一个函数声明成虚函数，则该函数在派生类中隐式的也是虚函数。

			成员函数如果没被声明成虚函数，则其解析过程发生在编译时而非运行时。

			访问控制与继承
			派生类可以继承定义在基类中的成员，但是派生类的成员函数不一定有权访问从基类继承而来的成员。
			和其他使用基类的代码一样，派生类能访问公有成员，而不能访问私有成员。
			不过在某些时候，基类中还有这样一种成员，基类希望它的派生类有权访问该成员，同时禁止其他用户访问。
		15.2.2 定义派生类
			派生类必须通过类派生列表（class derivation lst）明确指出它是从哪个基类继承而来的。
			类派生列表的形式是：首先是一个冒号，后面紧跟以逗号分隔的基类列表，
			其中每个基类前面可以有一下三个访问说明符中的一个：public、protected或者private。

			如果一个派生是公有的，则基类的公有成员也是派生类接口的组成部分。
			此外，我们能将公有派生类型的对象绑定到基类的引用或指针上。
			
			大多数类都只继承自一个类，这种形式的继承被称作“单继承”。

			派生类中的虚函数
			派生类经常（但不总是）覆盖它继承的虚函数。
			如果派生类没有覆盖其基类中的某个虚函数，则该函数的行为类似于其他的普通成员，
			派生类会直接继承其在基类中的版本。

			派生类对象及派生类向基类的类型转换
			一个派生类对象包含多个组成部分：一个含有派生类自己定义的（非静态）成员的子对象，
			以及一个与该派生类继承的基类对应的子对象，如果有多个基类，那么这样的子对象也有多个。

			在一个对象中，继承自基类的部分和派生类自定义的部分不一定是连续存储的。

			因为在派生类对象中含有与其基类对应的组成部分，所以雾霾能把派生类的对象当成基类对象来使用，
			而且我们也能将基类的指针或引用绑定到派生类对象的基类部分上。

			这种转换通常称为派生类到基类的（derived-to-base）类型转换。
			和其他类型转换一样，编译器会隐式的执行派生类到基类的转换。

			这种隐式特性意味着我们可以把派生类对象或者派生类对象的引用用在需要基类引用的地方；
			同样的，我们也可以把派生类对象的指针用在需要基类指针的地方。

			派生类构造函数
				尽管在派生类对象中含有从基类继承而来的成员，但是派生类并不能直接初始化这些成员。
				和其他创建了基类对象的代码一样，派生类也必须使用基类的构造函数来初始化它的基类部分。

				每个类控制它自己的成员初始化过程。

				除非我们特别指出，否则派生类对象的基类部分会像数据成员一样执行默认初始化。
				如果想使用其他的基类构造函数，我们需要以类名加圆括号内的实参列表的形式为构造函数提供初始值。
				这些实参将帮助编译器决定到底该选用哪个构造函数来初始化派生类对象的基类部分。

				首先初始化基类的部分，然后按照声明的顺序依次初始化派生类的成员。

			派生类使用基类的成员
				派生类可以访问基类的公有成员和受保护成员。

				关键概念：遵循基类的接口
					必须明确一点：每个类负责定义各自的接口。
					想要与类的对象交互必须使用该类的接口，即使这个对象是派生类的基类部分也是如此。
					因此，派生类对象不能直接初始化基类的成员。
					尽管从语法上来说我们可以在派生类函数体内给它公有或受保护的基类成员赋值，但是最好不要这么做。
					和使用基类的其他场合一样，派生类应该遵循基类的接口，并且通过调用基类的构造函数来初始化那些从基类中继承而来的成员。

				继承与静态成员
					如果基类定义了一个静态成员，则在整个继承体系中只存在该成员的唯一定义。
					不论从积累中派生出来多少个派生类，对于每个静态成员来说都只存在唯一的实例。

					静态成员遵循通用的访问控制规则，如果基类中的成员是private的，则派生类无权访问它。
					假设某静态成员是可访问的，则我们既能通过基类使用它也能通过派生类使用它。

				派生类的声明
					派生类的声明与其他类差别不大，生命中包含类名但是不包含它的派生列表：
					class A : class B;//派生列表不能出现在声明中
					class A;//正确：声明派生类的正确方式
					一条声明语句的目的是令程序知晓某个名字的存在以及该名字表示一个什么样的实体，如一个类，
					一个函数或一个变量等。
					派生列表以及与定义有关的其他细节必须与类的主体一起出现。
				被用作基类的类
					如果我们想将某个类用作基类，则该类必须已经定义而非仅仅声明。
					这一规定的原因显而易见：派生类中包含并且可以使用它从基类继承而来的成员，
					为了使用这些成员，派生类当然要知道他们是什么。
					因此该规定还有一层隐含的意思，即一个类不能派生它本身。
					一个类是基类，同时它可以是一个派生类，分为直接基类（direct base），和间接基类（indirect base）。
					直接基类出现在派生列表中，而间接基类由派生类通过其直接基类继承而来。

					每个类都会继承直接基类的所有成员。对于一个最终的派生类来说，它会继承其直接基类的成员；
					该直接基类的成员又含有其基类的成员；
					依次类推直至继承链的顶端。
					因此，最终的派生类将包含它的直接基类的子对象以及每个间接基类的子对象。
				防止继承的发生
					有时我们会定义这样一个类，我们不希望其他类继承它，或者不想考虑它是否适合作为一个基类。
					C++11提供一种防止继承发生的方法，即在类名后跟一个关键字final：
					class A final{};
					class B{};
					class C final:B{};

			15.2.3 类型转换与继承
				通常情况系，如果我们想把引用或指针绑定到一个对象上，则引用或指针的类型应与对象的类型一致，
				或者对象的类型含有一个可接受的const类型转换规则。
				存在继承关系的类是一个重要的例外：我们可以讲基类的指针或引用绑定到派生类对象上。
				可以将基类的指针或引用绑定到派生类对象上有一层极为重要的含义：
				当使用基类的引用或指针时，实际上我们并不清楚该引用或指针所绑定对象的真实类型。
				该对象可能是基类的对象，也可能是派生类的对象。

				静态类型与动态类型
					当我们使用存在继承关系的类型时，必须将一个变量或其他表达式的静态类型（static type）与
					该表达式表示对象的动态类型（dynamic type）区分开来。
					如果表达式既不是引用也不是指针，则它的动态类型永远与静态类型一直。
				不存在从基类想派生类的隐式类型转换
					之所以存在派生类向基类的类型转换是因为每个派生类对象都包含一个基类部分，
					而基类的引用或指针可以绑定到该基类的部分。一个基类的对象既可以以独立的形式存在，
					也可以作为派生类对象的一部分存在。如果基类对象不是派生类对象的一部分，则它只含有基类定义的成员，
					而不含有派生类定义的成员。
					因为一个基类的对象可能是派生类对象的一部分，也可能不是，所以不存在从基类向派生类的自动类型转换。
				在对象之间不存在类型转换
					派生类向基类的自动类型转换只对指针或引用类型有效，在派生类类型和基类类型之间不存在这样的转换。
					很多时候，我们确实希望将派生类对象转换成它的吉利类型，但是这种转换的实际发生过程往往与我们期望的有锁差别。

					当我们初始化或赋值一个类类型的对象时，实际上是在调用某个函数。
					当执行初始化时，我们调用构造函数；而当执行赋值操作时，我们调用赋值运算符。

				关键概念：存在继承关系的类型之间的转换规则
					要想理解在具有继承关系的类之间发生的类型转换，有三点非常重要：
						从派生类向基类的类型转换只对指针或引用类型有效
						基类想派生类不存在隐式类型转换
						和任何其他成员一样，派生类向基类的类型转换也可能由于访问受限而变得不可行。
					尽管自动类型转换只对指针或引用类型有效，但是继承体系中的大多数类仍然（显示或隐式地）定义了拷贝控制成员。
					因此，我们通常能够将一个派生类对象拷贝、移动或赋值给一个基类对象。
					不过需要注意的是，这种操作只处理派生类对象的基类部分。

15.3 虚函数
	如前所述，在C++中，当我们使用基类的引用或指针调用一个虚成员函数时会执行动态绑定。
	因为我们知道运行时才能知道到底调用了哪个版本的虚函数，所以所有虚函数都必须有定义。
	通常情况下，如果我们不适用某个函数，则无需为该函数提供定义。
	但是我们必须为每一个虚函数都提供定义，而不管它是否被用到了，
	这是因为连编译器也无法确定到底会使用哪个虚函数。
		
		对虚函数的调用可能在运行时才被解析
			当某个虚函数通过指针或引用调用时，编译器产生的代码知道运行时才能确定应该调用哪个版本的函数，
			被调用的函数是与绑定到指针或引用上的对象的动态类型相匹配的那一个。
			
			必须要搞清楚的一点是，动态绑定只有当我们通过指针或引用调用虚函数时才会发生。
			当我们通过一个具有普通类型（非引用非指针）的表达式调用虚函数时，在编译时就将调用的版本确定下来。

			关键概念：C++的多态性
				OOP的核心思想是多态性（polymorphism）。
				我们把具有继承关系的多个类型成为多态类型，因为我们能使用这些类型的“多种形式”而无需在意它们的差异。
				引用或指针的静态类型与动态类型不同这一事实正视C++语言支持多态性的根本所在。

				当我们使用基类的引用或指针调用基类中定义的一个函数时，我们并不知道该函数真正作用的对象是什么类型，
				因为它可能是一个基类的对象也可能是一个派生类的对象。

				另一方面，对非虚函数的调用在编译时就行绑定。
				类似的，通过对象进行的函数（虚函数或非虚函数）调用也在编译时绑定。
				对象的类型是确定不变的，我们无论如何都不可能令对象的动态类型与静态类型不一致。
				因此，通过对象进行的函数调用将在编译时绑定到该对象所属类中的函数版本上。

				当且晋档对通过指针或引用调用虚函数时，才会在运行时解析该调用，
				也只有在这种情况下对象的动态类型才有可能与静态类型不同。

			派生类中的虚函数
				当我们在派生类中覆盖了某个虚函数时，可以再一次使用virtual关键字指出该函数的性质。
				然而这么做并非必须，因为一旦某个函数被声明成虚函数，则在所有派生类中它都是虚函数。

				一个派生类的函数如果覆盖了某个继承而来的虚函数，则它的形参类型必须与被它覆盖的基类函数完全一致。

				同样，派生类中虚函数的返回类型也必须与基类函数匹配。
				该规则存在一个例外，当类的虚函数返回类型是类本身的指针或引用时，上述规则无效。
				也就是说，如果D由B派生得到，则基类的虚函数可以返回B*而派生类的对应函数可以返回D*，
				只不过这样的返回类型要求从D到B的类型转换是可访问的。

			final和override说明符
				派生类如果定义了一个函数与基类中虚函数的名字相同但是形参列表不同，这仍然是合法的行为。
				编译器将认为新定义的这个函数与基类中原有的函数是相互独立的。
				这时，派生类的函数并没有覆盖掉基类中的版本。
				可以用override和final说明符防止此类错误。

			虚函数与默认实参
				和其他函数一样，虚函数也可以拥有默认实参。如果某次函数调用使用了默认实参，则该实参值由本次调用的静态类型决定。
				换句话说，如果我们通过基类的引用或指针调用函数，则使用基类中定义的默认实参，即使实际运行的是派生类中的函数版本也是如此。
				此时，传入派生类函数的将是基类函数定义的默认实参。如果派生类函数依赖不同的实参，则程序结果将与我们的预期不符。

			回避虚函数的机制
				在某些情况下，我们希望对虚函数的调用不要进行动态绑定，而是强迫其执行虚函数的某个特定版本。
				使用作用域运算符可以实现这一目的。
				通常情况下，只有成员函数（或友元）中的代码才需要使用作用域运算符来回避虚函数的机制。

				什么时候我们需要回避虚函数的默认机制呢？通常是当一个派生类的虚函数调用它覆盖的基类的虚函数版本时。
				在此情况下，基类的版本通常完成继承层次中所有类型都要做的共同任务，而派生类中定义的版本需要执行一些与派生类本身密切相关的操作。

				如果一个派生类虚函数需要调用它的基类版本，但是没有使用作用域运算符，则在运行时该调用将被解析为对派生类版本自身的调用，从而导致无限递归。

15.4 抽象基类
	纯虚函数
		纯虚（pure virtual）函数和普通的虚函数不一样，一个纯虚函数无需定义。
		我们通过在函数体的位置（即在声明语句的分号之前）书写=0就可以将一个虚函数说明为纯虚函数。
		其中，=0只能出现在类内部的虚函数声明语句处。

		值得注意的是，我们也可以为纯虚函数提供定义，不过函数体必须定义在类的外部。
		也就是说，我们不能在类的内部为一个=0的函数提供函数体。
	含有纯虚函数的类是抽象基类
		含有（或者未经覆盖直接继承）纯虚函数的类是抽象基类（abstract base class）。
		抽象基类负责定义接口，而后续的其他类可以覆盖该接口。
		我们不能（直接）创建一个抽象基类的对象。

	派生类构造函数只初始化它的直接基类
		关键概念：重构
		...

15.5 访问控制与继承
	每个类分别控制自己的成员初始化过程，与之类似，每个类还分别控制着其成员对于派生类来说是否可访问（accessible）。

	受保护的成员
		一个类使用protected关键字来声明那些它希望与派生类分享但是不想被其他公共访问使用的函数。
		protected说明符可以看做是public和private中和后的产物。
		和稀有成员类似，受保护的成员对于类的用户来说是不可访问的。
		和公有成员类似，受保护的成员对于派生类的成员和友元来说是可访问的。
		此外，protected还有另外一条重要的性质“
		派生类的成员或友元只能通过派生类对象来访问基类的受保护成员。
		派生类对于一个基类对象中的受保护成员没有任何访问权限。

	公有、私有和受保护继承
		某个类对其继承而来的成员的访问权限受到两个因素影响：
		一是基类中该成员的访问说明符，二是在派生类的派生列表中的访问说明符。

		派生类访问说明符还可以控制继承自派生类的新类的访问权限。

	派生类向基类转换的可访问性
		派生类向基类的转换是否可访问由使用该转换的代码决定，同时派生类的派生访问说明符也会有影响。
		假定D继承自B：
			只有当D公有地继承B时，用户代码才能使用派生类向基类的转换；
			如果D继承B的方式是受保护的或者私有的，则用户代码不能使用该转换。
			不论D以什么方式继承B，D的成员函数和友元都能使用派生类向基类的转换；
			派生类向其直接基类的类型转换对于派生类的成员和友元来说永远是可访问的。
			如果D继承B的方式是公有的或者受保护的，则D的派生类的成员和友元可以使用D向B的类型转换；
			反之，如果D继承B的方式是私有的，则不能使用。

		友元与继承
			就像友元关系不能传递一样，友元关系同样也不能继承，基类的友元在访问派生类成员时不具有特殊性，
			类似的，派生类的友元也不嗯呢该随意访问基类的成员。
		改变个别成员的可访问性
			有时我们需要改变派生类继承的某个名字的访问级别，通过使用using声明可以达到这一目的：
			class Base {
			public:
				std::size_t size() const { return n;}
			protected:
				std::size_t n;
			};
			class Derived : private Base {
			public:
				using Base::size;
			protected:
				using Base::n;
			};
			因为Derived使用了私有继承，所以继承而来的成员size和n（在某人情况下）是Derived的私有成员。
			然而，我们使用using声明语句改变了这些成员的可访问性。

		默认的继承保护级别
			class和struct的区别。

15.6 继承中的类作用域
	每个类定义自己的作用域，在这个作用域内我们定义类的成员。当存在继承关系时，派生类的作用域嵌套在其基类的作用域之内。
	如果一个名字在派生类的作用域内无法正确解析，则编译器将继续在外层的基类作用域中寻找该名字的定义。
		通过作用域运算符来使用隐藏的成员
			我们可以通过作用域运算符来使用一个被隐藏的基类成员。
			作用域运算符覆盖掉原有的查找规则。
			除了覆盖继承而来的虚函数之外，派生类最好不要重用其他定义在基类中的名字。
		关键概念：名字查找与继承
		理解函数调用的解析过程对于理解C++的继承至关重要，嘉定我们调用p->mem()，则依次执行以下4个步骤：
		>首先确定p的静态类型。因为我们调用的是一个成员，所以该类型必然是类类型。
		>在p的静态类型对应的类中查找mem。如果找不到，则依次在直接基类中不断查找直至到达继承链的顶端。
		如果找遍了该类及其基类仍然找不到，则编译器将报错。
		>一旦找到了mem，就进行常规的类型检查以曲儿对于当前找到的mem，本次调用是否合法。
		>假设调用合法，则编译器将根据调用的是否是虚函数而产生不能的代码：
			如果mem是虚函数且我们是通过引用或指针进行的调用，则编译器产生的代码将在运行时确定到底运行该虚函数的哪个版本，一句是对象的动态类型。
			反之，如果mem不是虚函数或者我们是通过对象（而非引用或指针）进行的调用，则编译器将产生一个常规函数调用。
		一如往常，名字查找先于类型检查
			...
		虚函数与作用域
			假定基类与派生类的虚函数接受的实参不同，则我们就无法通过基类的引用或指针调用派生类的虚函数了。
		覆盖重载的函数
			和其他函数一样，成员函数无论是否是虚函数都能被重载。
			派生类可以覆盖重载函数的0个或多个实例。
			如果派生类希望所有的重载版本对于它来说都是可见的，那么它就需要覆盖所有的版本，或者一个也不覆盖。
			有时一个类仅需覆盖重载集合中的一些而非全部函数，此时，如果我们不得不覆盖基类中每一个版本的话，显然操作将极其烦琐。
			一种好的解决方案是为重载的成员提供一条using声明语句，这样我们就无需覆盖基类中的每一个重载版本了。
			using声明语句指定一个名字而不指定形参列表，所以一条基类成员函数的using声明语句就可以把该函数的所有重载实例添加到派生类作用域中。
			此时，派生类只需要定义其特有的函数就可以了，而无需为继承而来的其他函数重新定义。
			类内using声明的一般规则同样适用于重载函数的名字：
			基类函数的每个实例在派生类中都必须是可访问的。对于派生类没有重新定义的重载版本的访问实际上是对using声明点的访问。

15.7 构造函数与拷贝控制
	和其他类一样，位于继承体系中的类也需要控制当其对象执行一系列操作时发生声明样的行为，
	这些操作包括创建、拷贝、移动、赋值和销毁，如果一个类（基类或派生类）没有定义拷贝控制操作，则编译器将为它合成一个版本。
	当然，这个合成的版本也可以定义成被删除的函数。

	15.7.1 虚析构函数
		继承关系对基类拷贝控制最直接的影响是基类通常应该定义一个虚席构函数，这样我们就能动态分配继承体系中的对象了。
		当我们delete一个动态分配的对象的指针时将执行析构函数。
		如果该指针指向继承体系中的某个类型，则有可能出现指针的静态类型与被删除对象的动态类型不符的情况。
		如果基类的析构函数不是虚函数，则delete一个指向派生类对象的基类指针将产生未定义的行为。

		之前介绍过一条经验准则，即如果一个类需要析构函数，那么它也同样需要拷贝和赋值操作。
		基类的析构函数并不遵循上述准则，它是一个重要的例外。
		一个基类总是需要析构函数，而且它能将析构函数设定为虚函数。
		此时，该析构函数为了成为虚函数而令内容为空，我们显然无法由此推断该基类还需要复制运算符或拷贝构造函数。

	虚析构函数将组织合成移动操作
		基类需要一个虚析构函数这一事实还会对基类和派生类的定义产生另外一个间接影响：
		如果一个类定义了析构函数，即使它通过=default的形式使用了合成的版本，编译器也不会为这个类合成移动操作。

		15.7.2 合成拷贝控制与继承
			基类或派生类的合成拷贝控制成员的行为与其他合成的构造函数、赋值运算符或析构函数类似：
			他们对类本身的成员一次进行初始化、赋值或销毁的操作。
			此外，这些合成的成员还负责使用直接基类中对应的操作对一个对象的直接基类部分进行初始化、赋值或销毁的操作。

			派生类中删除的拷贝控制与基类的关系
				就像其他任何类的情况一样，基类或派生类也能出于同样的原因将其合成的默认构造函数或者任何一个拷贝控制成员定义成被删除的函数。
				此外，某些定义基类的方式也可能导致有的派生类成员成为被删除的函数：
						>如果基类中的默认构造函数、拷贝构造函数、拷贝赋值运算符或析构函数是被删除的，原因是编译器不能使用基类成员来执行派生类对象基类部分的构造、赋值或销毁操作。
						>如果在积累中有一个不可访问或删除掉的析构函数，则派生类中合成的默认和拷贝构造函数将是被删除的，因为编译器无法销毁派生类对象的基类部分。
						>和过去一样，编译器将不会合成一个删除掉的移动操作。当我们使用=default请求一个移动操作时，如果基类中的对应操作是删除的或不可访问的，
							那么派生类中该函数将是被删除的，原因是派生类对象的基类部分不可移动。
							同样，如果基类的析构函数是删除的或不可访问的，则派生类的移动构造函数也将是被删除的。
			移动操作与继承
				大多数基类都会定义一个虚析构函数。
				因此在默认情况下，基类通常不含有合成的移动操作，俄日企鹅在它的派生类中也没有合成的移动操作。
				因为基类缺少移动操作会组织派生类拥有自己的合成移动操作，所以当我们确实需要执行移动操作时应该首先在基类中进行定义。

		15.7.3 派生类的拷贝控制成员
			派生类构造函数再起初始化阶段中不但要初始化派生类自己的成员吗，还负责初始化派生类对象的基类部分。
			因此，派生类的拷贝和移动构造函数再拷贝和移动自有成员的同时，也要拷贝和移动基类部分的成员。
			类似的，派生类赋值运算符也必须为其基类部分的成员赋值。
			和构造函数机器赋值运算符不同的是，析构函数只负责销毁派生类自己分配的资源。
			对象的成员是被隐式销毁的；类似的，派生类对象的基类部分也是自动销毁的。
			当派生类定义了拷贝或移动操作时，该操作负责拷贝或移动包括基类部分成员在内的整个对象。

			定义派生类的拷贝或移动构造函数
				当为派生类定义拷贝或移动构造函数时，我们通常使用对应的基类构造函数初始化对象的基类部分：
				...
			派生类赋值运算符
				与拷贝和移动构造函数一样，派生类的赋值运算符也必须显式的为其基类部分赋值：
				...
			派生类析构函数
				在析构函数体执行完成后，对象的成员会被隐式销毁，
				类似的，对象的基类部分也是隐式销毁的。
				因此，和析构函数及赋值运算符不同的是，派生类析构函数只负责销毁由派生类自己分配的资源：
			在构造函数和析构函数中调用虚函数
				派生类对象的基类部分将首先被构建。
				当执行基类的构造函数时，该对象的派生类部分是未被初始化的状态。类似的，销毁派生类对象的次序正好相反，
				因此当执行基类的构造函数时，派生类部分已经被销毁掉了。
				由此可知，当我们执行上述基类成员的时候，该对象出于未完成的状态。

				为了能够正确地处理这种未完成状态，编译器认为对象的类型在构造或析构的过程中仿佛发生了改变一样。
				也就是说当我们构建一个对象时，需要把对象的类和构造函数的类看做是同一个；
				对虚函数的调用绑定正好符合这种把对象的类和构造函数的类看出是同一个的要求；
				对于析构函数也是同样的道理。
				上述的绑定不但对直接调用虚函数有效，对间接调用也是有效的，这里的间接调用是指通过构造函数（或析构函数）调用另一个函数。

				如果构造函数或析构函数调用了某个虚函数，则我们应该执行与构造函数或析构函数所属类型相对应的虚函数版本。

			15.7.4 继承的构造函数
				在C++11新标准中，派生类能够重用其直接基类定义的构造函数。
				尽管如我们所知，这些构造函数并非以常规的方式继承而来，但是为了方便，姑且称其为：继承”的。
				一个类只初始化它的直接基类，出于同样的原因，一个类也值继承其直接基类的构造函数。
				类不能继承默认、拷贝和移动构造函数。
				如果派生类没有直接定义这些构造函数，则编译器将为派生类合成他们。

				通常情况下，using声明语句只是令某个名字在当前作用域内可见。
				而当作用域构造函数时，using声明语句将令编译器产生代码。
				对于基类的每个构造函数，编译器都生成一个阈值对应的派生类构造函数。
				换句话说，对于基类的每个构造函数，编译器都在派生类中生成一个形参列表完全相同的构造函数。

				继承的构造函数的特点
					和普通成员的using声明不一样，一个构造函数的using声明不会改变该构造函数的访问级别。
					例如，不管using声明出现在哪，基类的私有构造函数再派生类中还是一个私有构造函数；
					受保护的构造函数和公有构造函数也是同样的规则。

					而且，一个using声明语句不能指定explicit或constexpr。
					如果基类的构造函数是explicit或者constexpr，则继承的构造函数也拥有相同的属性。

					当一个基类构造函数含有默认实参时，这些实参并不会被继承。
					相反，派生类将获得多个继承的构造函数，其中每个构造函数分别省略掉一个含有默认实参的形参。
					例如，如果基类由一个接受两个形参的构造函数，其中第二个形参含有默认是残，则派生类将获得两个构造函数：
					一个构造函数接受两个形参（没有默认实参），另一个构造函数只接受一个形参，它对应于基类中最左侧的没有默认值的那个形参。

					如果基类含有几个构造函数，则出了两个例外情况，大多数时候派生类会继承所有这些构造函数。
					第一个例外是派生类可以继承一部分构造函数，而为其他构造函数定义自己的版本。
					如果派生类定义的构造函数与基类的构造函数具有相同的参数列表，则该构造函数将不会被继承。
					定义在拍摄内格雷中的构造函数将替换继承而来的构造函数。
					第二个例外是默认、拷贝和移动构造函数不会被继承。
					这些构造函数按照正常规则被合成。
					继承的构造函数不会被作为用户定义的构造函数来使用，因此，
					如果一个类只含有继承的构造函数，则它也拥有一个合成的默认构造函数。

15.8 容器与继承
	当我们使用容器存放继承体系中的对象时，通常必须采取间接存储的方式。
	因为不允许在容器中保存不同类型的元素，所以我们不能把具有继承关系的多种类型的对象直接存放在容器当中。

	当派生类对象被赋值给基类对象时，其中的派生类部分将被“切掉”，因此容器和存在继承关系的类型无法兼容。

	在容器中放置（智能）指针而非对象
		当我们希望在容器中存放具有继承关系的对象时，我们实际上存放的通常是基类的指针（更好的选择是智能指针）。
		和往常一样，这些指针所指对象的的动态类型可能是基类类型，也可能是派生类类型。

		15.8.1 编写Basket类
			...
			实在看不懂，写不下去了...

			对于C++面向对象的编程来说，一个悖论是我们无法直接使用对象进行面向对象编程。
			相反，我们必须使用指针和引用。
			因为指针会增加程序的复杂性，所以我们经常定义一些辅助的类来处理这种复杂情况。

15.9 文本查询程序再探
	15.9.1 面向对象的解决方案

	15.9.2 Query_base类和Query类

	15.9.3 派生类

	15.9.4 eval函数






*/