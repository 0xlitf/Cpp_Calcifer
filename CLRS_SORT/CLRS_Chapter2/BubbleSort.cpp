#include "stdafx.h"
#include "decla.h"
#include <iostream>
void BubbleSort(int *array)
{
	std::cout << "BubbleSort£º" << std::endl;
	int i, j;
	int temp;
	for (i = 0; i<array_size - 1; ++i)
	{
		for (j = array_size - 1; j>i; --j)
		{
			if (array[j - 1] > array[j])
			{

				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
		PrintArray(array);
	}
}