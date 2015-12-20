#include "stdafx.h"
#include "decla.h"
#include <iostream>
void SelectSort(int *array)
{

	std::cout << "SelectSort£º" << std::endl;
	int i, j, k;
	int key;
	for (i = 0; i < array_size - 1; ++i)
	{
		k = i;
		key = array[i];
		for (j = i + 1; j < array_size; ++j)
		{
			if (array[j] < array[k])
				k = j;
		}
		array[i] = array[k];
		array[k] = key;
		PrintArray(array);
	}
}