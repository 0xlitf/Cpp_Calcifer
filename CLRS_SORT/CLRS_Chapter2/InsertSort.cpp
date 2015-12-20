#include "stdafx.h"
#include "decla.h"
#include <iostream>

void InsertSort(int *array){
	int i, j, key;
	std::cout << "InsertSort£º"<< std::endl;
	for (j = 1; j < array_size;j++)
	{
		key = array[j];
		i = j - 1;
		while (i >= 0 && array[i] > key)
		{
			array[i + 1] = array[i];
			--i;
		}
		array[i + 1] = key;
		PrintArray(array);
	}
}
void RecurInsertSort(int *array)
{
	
	static int RecurInsertSort_if_flag = 1;
	while (RecurInsertSort_if_flag == 1)
	{
		std::cout << "RecurInsertSort£º" << std::endl;
		++RecurInsertSort_if_flag;
	}
	int i;
	int key;
	static int p = 0, q = array_size;
	if (p < q)
	{
		--q;
		RecurInsertSort(array);
		key = array[q];
		for (i = q - 1; i >= 0 && array[i] >= key; --i)
			array[i + 1] = array[i];
		array[i + 1] = key;
	}
	PrintArray(array);
}