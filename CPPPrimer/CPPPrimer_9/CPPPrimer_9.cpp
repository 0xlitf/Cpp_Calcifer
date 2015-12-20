// CPPPrimer_9.cpp : ˳������
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

/*

CPPPrimer_9 ˳������
	һ����������һЩ�ض����Ͷ���ļ��ϡ�
	˳��������sequential container��Ϊ����Ա�ṩ�˿���Ԫ�ش洢�ͷ���˳���������
	����˳��������Ԫ�ص�ֵ��������Ԫ�ؼ�������ʱ��λ�����Ӧ��

9.1 ˳����������
	˳����������
	vector	�ɱ��С���顣֧�ֿ���������ʡ���β��֮���λ�ò����ɾ��Ԫ�غ�����
	deque	˫�˶��С�֧�ֿ���������ʡ���ͷβλ�ò���/ɾ���ٶȺܿ졣
	list	˫������ֻ֧�ֵ���˳����ʡ��������κ�λ�ý��в���/ɾ�������ٶȶ��ܿ졣
	forward_list	��������ֻ֧�ֵ���˳����ʡ��������κ�λ�ö����в���/ɾ�������ٶȶ��ܿ졣
	array	�̶���С���顣֧�ֿ���������ʡ�������ӻ�ɾ��Ԫ�ء�
	string	��vector���Ƶ���������ר�����ڱ����ַ���������ʿ졣��β������/ɾ���ٶȿ졣

9.2 ���������
	���������ϵĲ����γ���һ�ֲ�Σ�
	ĳЩ�����������������Ͷ��ṩ�ġ�
	����һЩ���������˳����������������������������
	����һЩ����ֻ������һС����������

	9.21 ������
		������һ�������������Ź����Ľӿڣ����һ���������ṩĳ��������
		��ô�����ṩ��ͬ�����ĵ����������������ʵ�ַ�ʽ������ͬ�ġ�
		
		��������Χ
			��������Χ�ĸ����Ǳ�׼��Ļ�����
			һ����������Χ��iterator range����һ�Ե�������ʾ��
			�����������ֱ�ָ��ͬһ�������е�Ԫ�ػ�����βԪ��֮���λ�ã�one past the last element����

			��Ȼ�ڶ�����������������Ϊlast�������ֽз���Щ�󵼣���Ϊ�ڶ�������������������ָ��Χ�е����һ��Ԫ�أ�
			����ָ��βԪ��֮���λ�ã� ��������Χ�е�Ԫ�ذ���first����ʾ��Ԫ���Լ���first��ʼֱ��last����������last��
			֮�������Ԫ�ء�
			����Ԫ�ط�Χ����Ϊ��պ����䣨left-inclusive interval�������׼��ѧ����Ϊ
			[begin, end)
			��ʾ��Χ��begin��ʼ����end֮ǰ������������begin��end����ָ����ͬ��������
			end������beginָ����ͬ��λ�ã�������ָ��begin֮ǰ��λ�á�

		ʹ����պϷ�Χ�̺��ı�̼ٶ�
			��׼��ʹ����պϷ�Χ����Ϊ���ַ�Χ�����ַ�������ʡ�
			�ٶ�begin��end����һ���Ϸ��ĵ�������Χ����
			�����begin��end��ȣ���ΧΪ��
			�����begin��end���ȣ���Χ���ٰ���һ��Ԫ�أ���beginָ��÷�Χ�еĵ�һ��Ԫ��
			�����ǿ��Զ�begin�������ɴΣ�ʹ��begin==end
			��Щ������ζ�����ǿ���������Ĵ���һ����һ��ѭ��������һ��Ԫ�ط�Χ�������ǰ�ȫ�ģ�
			while (begin!=end) {
			*begin = val;//��ȷ����Χ�ǿգ����beginָ���һ��Ԫ��
			++begin;
			}
			��������һ���Ϸ���Χ�ĵ�����begin��end����begin==end����ΧΪ�ա�
			�ڴ�����£�����Ӧ���˳�ѭ����
			�����Χ��Ϊ�գ�beginָ��ǿշ�Χ��һ��Ԫ�ء�
			��ˣ���whileѭ�����У����԰�ȫ�Ľ�����begin����Ϊbegin��Ȼָ��һ��Ԫ�ء�
			�������ÿ��ѭ����begin����һ�Σ�����ȷ��ѭ�����ջ������



	9.22 �������ͳ�Ա
	    ÿ�������������˶�����ͣ������Ѿ�ʹ�ù��������֣�size_type��iterator��const_iterator��
		�����Ѿ�ʹ�ù��ĵ��������ͣ�������������ṩ�����������
		�򵥵�˵���������������һ�ַ�����������ĵ��������������������ȣ����ֲ����ĺ���Ҳ�������˵ߵ���
		���磬��һ�����������ִ��++��������õ���һ��Ԫ�ء�

		ʣ�µľ������ͱ����ˣ�ͨ�����ͱ��������ǿ����ڲ��˽�������Ԫ�����͵������ʹ������
		�����ҪԪ�����ͣ�����ʹ��������value_type��
		�����ҪԪ�����͵�һ�����ã�����ʹ��reference��const-reference��
		��ЩԪ����ص����ͱ����ڷ��ͱ���зǳ����á�

		Ϊ��ʹ����Щ���ͣ����Ǳ�����ʽʹ����������
		//iter��ͨ��list<string>::iterator�����һ������������
		list<string>::iterator iter;
		//count��ͨ��vector<int>�����һ��difference_type����
		vetor<int>:::difference_type count;

	9.23 begin��end��Ա����
	    begin��end�ж���汾����r�İ汾���ط������������c��ͷ�İ汾�򷵻�const��������
		list<string> a = {"Milton", "Shakespeare", "Austen"};
		auto it1 = a.begin();//iterator
		auto it2 = a.rbegin();//reverse_iterator
		auto it3 = a.cbegin();//const_iterator
		auto it4 = a.crbegin();//const_reverse_iterator
		����c��ͷ�ĺ������Ǳ����ع��ġ�
		Ҳ����˵��ʵ������������Ϊbegin�ĳ�Ա��
		һ����const��Ա������������const_iterator���͡�
		��һ���Ƿǳ�����Ա������������iterator���͡�



	9.24 ��������ͳ�ʼ��
	    ÿ���������Ͷ�������һ��Ĭ�Ϲ��캯����
		��array֮�⣬����������Ĭ�Ϲ��캯�����ᴴ��һ��ָ�����͵Ŀ��������Ҷ����Խ���ָ��������С��Ԫ�س�ʼֵ�Ĳ�����
		C c; //
		C c1(c2); //
		C c1=c2; //
		C c{a,b,c...}; //
		C c={a,b,c...}; //
		C c(b,e); //
		// ֻ��˳��������������array���Ĺ��캯�����ܽ��ܴ�С����
		C seq(n); //
		C seq(n,t); //



	9.25 ��ֵ��swap
	    ��ֵ�����������������е�ȫ��Ԫ���滻Ϊ�ұ�������Ԫ�صĿ�����
		c1 = c2; //��c1�������滻Ϊc2��Ԫ�صĿ���
		c1 = {a,b,c}; //��ֵ��c1��СΪ3
		���������鲻ͬ����׼��array��������ֵ��
		��ֵ���������ߵ����������������ͬ�����͡�




	9.26 ������С����
	    ÿ���������Ͷ����������С��صĲ�����
		��Ա����size����������Ԫ�ص���Ŀ��
		empty��sizeΪ0ʱ���ز���ֵtrue��
		���򷵻�false��
		max_size����һ�����ڻ���ڸ����������������ɵ����Ԫ������ֵ��



	9.27 ��ϵ�����
	    ÿ���������Ͷ�֧������������==�ͣ�=����
		����������������������������֧�ֹ�ϵ�������>��>=��<��<=����
		��ϵ������������ߵ���������������ͬ���͵�������
		�ұ��뱣����ͬ���͵�Ԫ�ء�

9.3 ˳����������
    9.31 ��˳���������Ԫ��

	9.32 ����Ԫ��

	9.33 ɾ��Ԫ��

	9.34 �����forward_list����

	9.35 �ı�������С

	9.36 ������������ʹ������ʧЧ

9.4 vector���������������
    Ϊ��֧�ֿ���������ʣ�vector��Ԫ�������洢����ÿ��Ԫ�ؽ�����ǰһ��Ԫ�ش洢��
	vector��string��ʵ��ͨ���������µĿռ����������ڴ�ռ䡣


9.5 �����string����
    9.51 ����string����������


	9.52 �ı�string����������

	9.53 string��������

	9.54 compare����

	9.55 ��ֵת��
9.6 ����������
    ����˳�������⣬��׼�⻹����������˳��������������stack��queue��priority_queue��
	��������adaptor���Ǳ�׼���е�һ��ͨ�ø���������������ͺ���������������
	�����ϣ�һ����������һ�ֻ��ƣ���ʹĳ���������Ϊ��������һ�ֲ�ͬ�����͡�

	http://blog.csdn.net/thefutureisour/article/details/7751846

	���ȣ�����Ҫ�����������Ǹ�ʲô�ģ���ʵ����һ���ӿ�ת��װ�ã��ǵ����������ض��ķ���ȥ����һЩ���Ǳ����޷������Ķ�������һ�����ӣ��������һ���豸֧�ִ����ߣ�����ĵ���֧�ֵ���usb�ڣ���ʱ������û�б�Ҫ������һ��֧��usb���豸��ֻ��Ҫһ������תusb�ڵ�С���⣬������豸�ܹ����ӵ�usb����ϣ�����������������
	��ôC++�е������������Ǹ�ʲô���أ�������һ����ȣ��������е�����������vector��list��deque�������豸������豸֧�ֵĲ����ܶ࣬������룬ɾ�������������ʵȵȡ�������ϣ������������ֳ�������ջ�����ӣ��Ƚ��������ջ��ջ�ȵȣ���ʱ������û�б�Ҫ���¶���дһ���µ����ݽṹ�����ǰ�ԭ�����������·�װһ�£��ı����Ľӿڣ����ܰ�������ջʹ���ˡ�
	�Թ������������ʲô���������Ժ���ʵ����ͺܼ򵥵ġ�C++�ж�����3�������������������������ṩ�Ľӿڱ�������ǳ��õĵ�3�����ݽṹ��ջ���Ƚ���������У��Ƚ��ȳ��������ȼ����У��������ȼ�����<���ţ����򣬶����ǰ��յ�����˳�����򣩡�
	���ھ�������ô��ģ����ǿ������˽�һ����ţ�Ĭ������£�ջ�Ͷ��ж��ǻ���dequeʵ�ֵģ������ȼ��������ǻ���vectorʵ�ֵġ���Ȼ������Ҳ����ָ���Լ���ʵ�ַ�ʽ�������������ݽṹ�Ĺ�ϵ������Ҳ���ܺ���ָ����ջ���ص��Ǻ���ȳ��������������Ļ�����������������һ��˳����������Ϊ��Щ�������ͽṹ�������ṩջ�Ĳ����������Ƕ��ṩ��push_back��pop_back��back������ ����queue���ص����Ƚ��ȳ���������Ҫ��������Ļ������������ṩpop_front����������䲻�ܽ�����vector�����ϣ��������ȼ����У�������Ҫ��֧��������ʵĹ��ܣ����Կ��Խ�����vector����deque�ϣ����ܽ�����list�ϡ�

	�����ǿ��������ֹ��������ṩ�Ľӿڣ�
	ջ֧�ֵĲ����У�
	1.empty()  ��ջΪ���򷵻���
	2.pop()  �Ƴ�ջ��Ԫ��
	3.push()  ��ջ������Ԫ��
	4.size()  ����ջ��Ԫ����Ŀ
	5.top()  ����ջ��Ԫ��
	����֧�ֵĲ����У�
	1.back()  ����һ�����ã�ָ�����һ��Ԫ��
	2.empty()  ������п��򷵻���
	3.front()  ���ص�һ��Ԫ��
	4.pop()  ɾ����һ��Ԫ��
	5.push()  ��ĩβ����һ��Ԫ��
	6.size()  ���ض�����Ԫ�صĸ���
	���ȼ�����֧�ֵĲ����У�
	1.empty()  ������ȶ���Ϊ�գ��򷵻���
	2.pop()  ɾ����һ��Ԫ��
	3.push()  ����һ��Ԫ��
	4.size()  �������ȶ�����ӵ�е�Ԫ�صĸ���
	5.top()  �������ȶ�������������ȼ���Ԫ��

	�ٸ����ӣ�
	[cpp] view plaincopy

	int main()
	{
	const stack<int>::size_type stk_size = 10;
	//����һ����ջ
	stack<int> intStack;
	//�ı�ջ��ʵ�ַ�ʽΪvector
	//stack<int,vector<int> > intStack;
	int ix = 0;

	while(intStack.size() != stk_size)
	intStack.push(ix++);

	int error_cnt = 0;
	while(intStack.empty() == false)
	{
	//top��������ջ��Ԫ�أ�������ɾ��
	int value = intStack.top();
	if(value != --ix)
	{
	cout<<"opps! expected "<<ix<<" received "<<value<<endl;
	++error_cnt;

	}
	//ɾ��ջ��Ԫ��
	intStack.pop();
	}

	cout<<"our program ran with "<<error_cnt<<" errors! "<<endl;
	return 0;
	}




	������ǿ��Կ�̽һ��stl�е�Դ�룺
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


	�������ǿ�������Ŀ�����ջ��Ĭ������£��ǻ���dequeʵ�ֵģ���ʹ�÷�װ��˳�������Ĳ�����ʵ�ֵ��Լ��Ĳ�����

















*/