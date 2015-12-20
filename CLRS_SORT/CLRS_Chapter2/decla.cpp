#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <math.h>
#include <time.h>
#include "decla.h"
using namespace std;
int* RandArray(){

	static int v_rand[array_size];
	cout << "***********************************" << endl;
	cout << "RandArray£º" << endl;
	for (int i = 0; i < array_size; i++)
	{
		v_rand[i] = rand() & 0xFF;
		cout << v_rand[i] << " ";
	}
	cout << endl;
	return v_rand;
}

void PrintArray(int* array){
	for (int i = 0; i < array_size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}