// SinglyLinkedList.cnextnext : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
struct Node {
	Node* next;
	int data;
};

class SL_List {
public:
	SL_List();
	SL_List(int&);
	~SL_List();
	void append(int);
	void print();
	void pop(int m);
	void SL_List::LoopReverse();
	void SL_List::insert(int n, int num);
	void sort();
	void selectsort();
	int length();
private:
	Node* head;
	Node* tail;

};

SL_List::SL_List()
{

	head = 0;
	tail = 0;
}

SL_List::SL_List(int& num)
{
	Node* node = new Node;
	node->next = 0;
	node->data = num;
	head = node;
	tail = node;
}

void SL_List::pop(int m){
	if (0 == m) {
		head = head->next;
	}
	else {
		Node* p = head;
		for (int i = 0; i < m - 1; ++i) {
			p = head->next;
		}
		p->next = p->next->next;
	}
}

SL_List::~SL_List()
{
}

void SL_List::print(){
	Node* n;
	int i = 0;
	for (n = head; n != NULL; n = n->next, ++i) {
		//cout << "第" << i << "个节点的元素是：" << n->data << endl;
		cout << n->data << " ";
	}
	cout << endl;
	//cout << "元素个数：" << i << endl;
	//cout << "第" << i << "个节点的元素是：" << n->data << endl;
}

void SL_List::append(int num){
	if (head == NULL) {
		Node* node = new Node;
		node->data = num;
		node->next = NULL;
		head = node;
		tail = head;
	}
	else {
		Node* node = new Node;
		node->data = num;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}

}

void SL_List::insert(int n, int num){
	Node* p = new Node;
	Node* tmp = head;
	p->data = num;

	if (0 == n) {
		p->next = head;
		head = p;
	}
	else {
		for (int i = 0; i < n - 1; ++i) {
			tmp->next = tmp->next->next;
			cout << tmp->data << endl;
		}
		p->next = tmp->next;
		tmp->next = p;
	}
}
void SL_List::LoopReverse(){
	Node* prev = NULL;
	Node* nx;
	while (head != NULL) {
		nx = head->next;
		head->next = prev;
		prev = head;
		head = nx;
	}
	tail = head;
	head = prev;
}

void SL_List::sort(){
	Node* r = NULL;
	Node* p = head;
	Node* q = p->next;
	Node* t = tail;
	int tmp;
	while (head != t) {
		for (; p->next != t;) {
			if (p->data > q->data) {
				tmp = q->data;
				q->data = p->data;
				p->data = tmp;
			}
			r = p;
			p = p->next;
			q = q->next;
		}
		t = p;
		p = head;
		q = p->next;
		r = NULL;
	}
}

void SL_List::selectsort(){
	Node* p;
	Node* q;
	int tmp;
	for (p = head; p->next != tail;p=p->next)
	{
		for (q = p; q->next != tail; q = q->next)
		{
			if (p->data > q->next->data)
			{
				tmp = p->data;
				p->data = q->next->data;
				q->next->data = tmp;
			}
		}
	}
	cout << "end selectsort" << endl;
}

int SL_List::length(){
	int i = 0;
	Node* h = NULL;
	for (h = head; h != NULL; h = h->next) {
		++i;
	}
	return i;
}


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	SL_List list;
	cout << "初始：" << endl;
	for (int i = 0; i < 10; ++i) {
		list.append(rand() % 100);
	}
	list.print();

	cout << "删除：" << endl;
	list.pop(0);
	list.print();

	cout << "逆序：" << endl;
	list.LoopReverse();
	list.print();

	cout << "插入：" << endl;
	list.insert(1, 5);
	list.print();

	cout << "排序：" << endl;
	//list.sort();
	list.selectsort();
	list.print();


	
	cout << endl;
	system("pause");
	return 0;
}

