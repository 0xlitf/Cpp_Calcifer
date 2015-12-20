#include "stdafx.h"
#include "Pt.h"


CPt::CPt()
{
	m_type = 0;
	m_x = 0;
	m_y = 0;
	m_turn = 1;
	memset(m_pointtype, 0, sizeof(m_pointtype));
}

CPt::CPt(int m_type, int m_x, int m_y)
{
	this->m_type = m_type;
	this->m_x = m_x;
	this->m_y = m_y;
}

CPt::~CPt()
{
}
