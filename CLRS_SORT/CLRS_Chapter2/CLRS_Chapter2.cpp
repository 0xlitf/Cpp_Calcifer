// CLRS_Chapter2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <math.h>
#include <time.h>
#include "decla.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));

	InsertSort(RandArray());
	RecurInsertSort(RandArray());
	SelectSort(RandArray());
	MergeSort(RandArray(),0,9);
	BubbleSort(RandArray());


	cout << endl << endl << endl;
	system("pause");
	return 0;
}

