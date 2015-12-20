#pragma once
class CPt
{
public:
	int m_type, m_x, m_y, m_turn;
	int m_pointtype[20][20];
	CPt();
	CPt(int m_type, int m_x, int m_y);
	~CPt();
private:

};

