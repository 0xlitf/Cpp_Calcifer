
// FIVE.h : FIVE 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CFIVEApp:
// 有关此类的实现，请参阅 FIVE.cpp
//

class CFIVEApp : public CWinApp
{
public:
	CFIVEApp();


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFIVEApp theApp;
