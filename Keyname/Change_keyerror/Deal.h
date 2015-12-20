#pragma once


#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Deal
{
public:
	void do_it();
	void deal();
	void to_light();
	void Deal::to_kks();
	Deal();
	~Deal();
private:
	void Light(string light, int index, int list, int row);
	void Slip(string slip, int index, int list, int row);
	void Meter(string meter, int index, int list, int row);
	void GS(string gs, int index, int list, int row);
	void Text(string text, int index, int list, int row);
	void Button(string button, int index, int list, int row);
};

