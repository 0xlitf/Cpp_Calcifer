#include "stdafx.h"
#include "redirect.h"
#include <QtWidgets/QApplication>
#include <string>
#include <time.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <conio.h>   
#include <iostream>   
#include <io.h>   
#include <fcntl.h>  
int main(int argc, char *argv[])
{
	//#include <conio.h>   �ض��������5��ͷ�ļ�
	//#include <iostream>   
	//#include <io.h>   
	//#include <fcntl.h>   
	//#include <windows.h>
	AllocConsole();// Ϊһ�����̶�λһ��console �������win32 ����Ļ�����������ó���   
	//Retrieves a handle to the specified standard device (standard input, standard output, or standard error).   
	HANDLE hin = ::GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hout = ::GetStdHandle(STD_OUTPUT_HANDLE);
	//Associates a C run-time file descriptor with an existing operating-system file handle.   
	int hcin = _open_osfhandle((intptr_t)hin, _O_TEXT);//��ʱhcin�ͳ���һ��file descriptor��
	//When a program opens a file, the operating system returns a corresponding file descriptor that the program refers to   
	//in order to process the file. A file descriptor is a low positive integer. The first three file descriptors (0,1, and 2,)   
	//are associated with the standard input (stdin), the standard output (stdout), and the standard error (stderr), respectively.   
	//Thus, the function scanf() uses stdin and the function printf() uses stdout. You can override the default setting and   
	//re-direct the process's I/O to different files by using different file descriptors:
	//#include <cstdio>   
	//fprintf(stdout, "writing to stdout"); //write to stdout instead of a physical file   
	FILE * fpin = _fdopen(hcin, "r");
	*stdin = *fpin;                                                  //stdin ��ָ�����ļ�ָ��
	int hcout = _open_osfhandle((intptr_t)hout, _O_TEXT);
	FILE * fpout = _fdopen(hcout, "wt");
	*stdout = *fpout;
	std::ios_base::sync_with_stdio();// ��iostream��ͬc runtime lib ��stdioͬ������׼��ͬ���� 
	printf("hello,world\n");
	std::cout << "test\n";
	

	QApplication a(argc, argv);
	Redirect w;
	w.show();
	std::cout << "show\n";
	return a.exec();
}