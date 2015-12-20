
// FIVEView.h : CFIVEView 类的接口
//

#pragma once
#include "atltypes.h"
#include "afxcoll.h"


class CFIVEView : public CView
{
protected: // 仅从序列化创建
	CFIVEView();
	DECLARE_DYNCREATE(CFIVEView)

	// 特性
public:
	CFIVEDoc* GetDocument() const;
	int a[15][15];
	// 操作
public:

	// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// 实现
public:
	virtual ~CFIVEView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:

public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	CPoint m_ptOrigin;
	float m_x;
	float m_y;
	CPtrArray m_ptrArray;
public:
	int m_type;
	int m_turn;
	int m_coordinatex;
	int m_coordinatey;
};

#ifndef _DEBUG  // FIVEView.cpp 中的调试版本
inline CFIVEDoc* CFIVEView::GetDocument() const
{
	return reinterpret_cast<CFIVEDoc*>(m_pDocument);
}
#endif

