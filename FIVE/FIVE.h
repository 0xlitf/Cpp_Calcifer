
// FIVE.h : FIVE Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CFIVEApp:
// �йش����ʵ�֣������ FIVE.cpp
//

class CFIVEApp : public CWinApp
{
public:
	CFIVEApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFIVEApp theApp;
