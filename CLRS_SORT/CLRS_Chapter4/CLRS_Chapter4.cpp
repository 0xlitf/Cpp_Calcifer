// CLRS_Chapter4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CheckArray.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	time_t start, end, t;
	time(&start);
	srand((unsigned)time(&t));
	Initial();
	//	PrintArrayData();
	printf("find result: %d\nanswer: %d\n", CheckData(), Answer());
	time(&end);
	printf("total time: %d\n", end - start);
	system("pause");
	return 0;
}

