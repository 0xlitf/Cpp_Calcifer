#ifndef DECLA_H
#define DECLA_H

#define ITEMMAX INT_MAX
typedef int Item;

const int array_size = 10;
int* RandArray();
void InsertSort(int *array);
void BubbleSort(int *array);
void RecurInsertSort(int *array);
void SelectSort(int *array);
void Merge(int *array, int p, int q, int r);
void MergeSort(int *array, int p, int q);



void PrintArray(int *array);
#endif