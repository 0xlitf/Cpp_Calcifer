// ColorConsole.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

using namespace std;

void SetColor(unsigned short ForeColor = 4, unsigned short BackGroundColor = 0)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor | BackGroundColor);
};


int _tmain(int argc, _TCHAR* argv[])
{
	SetColor();
	std::cout << "Hello world " << endl;
	SetColor(40, 30);
	std::cout << "Hello world!" << endl;

	return 0;
}

