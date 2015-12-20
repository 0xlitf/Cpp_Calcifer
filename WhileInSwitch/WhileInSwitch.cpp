// _Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <regex>
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <iostream>  
#include <time.h>  
#include <math.h>  
#include <stdlib.h>  
#include <string.h>
#include <stdio.h>

using namespace std;
void fuck(){
	cout << "fuck" << endl;
}


int _tmain(int argc, _TCHAR* argv[]);
int _tmain(int argc, _TCHAR* argv[])
{
	int i = 2;
	switch (i) {//执行i次循环
		while (i > 0) {
		case 0:fuck(); i--;
		case 5:fuck(); i--;
		case 4:fuck(); i--;
		case 3:fuck(); i--;
		case 2:fuck(); i--;
		case 1:fuck(); i--;
		}
	}
	system("pause");
	return 0;
}