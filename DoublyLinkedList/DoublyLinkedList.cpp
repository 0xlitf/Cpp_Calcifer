// DoublyLinkedList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
template<class T>
class Node {
public:
	Node(){ pNext = pPrev = NULL; };
	Node(T& data){
		m_data = data;
		pNext = pPrev = NULL;
	};
	~Node(){};
	void SetData(T& data){ m_data = data; }
	T& GetData(){ return m_data; }
	void SetPrev(Node* prev){ pPrev = prev; }
	Node* GetPrev(){ return pPrev; }
	void SetNext(Node* next){ pNext = next; }
	Node* GetNext(){ return pNext; }

private:
	T m_data;
	Node* pNext;
	Node* pPrev;
};

template<class T>
class List {
public:
	List(){};
	~List(){};
	void Add();
	void Del();
	void Find();
	T* GetHead(){ return head; }
private:
	T* head;
	T* tail;
};
int i;
int _tmain(int argc, _TCHAR* argv[])
{

	Node<int> node;
	List<Node<int>> list;
	cout << i << endl;
	cout << node.GetData() << endl;
	return 0;
}

