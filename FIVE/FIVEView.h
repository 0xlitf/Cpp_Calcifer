
// FIVEView.h : CFIVEView ��Ľӿ�
//

#pragma once
#include "atltypes.h"
#include "afxcoll.h"


class CFIVEView : public CView
{
protected: // �������л�����
	CFIVEView();
	DECLARE_DYNCREATE(CFIVEView)

	// ����
public:
	CFIVEDoc* GetDocument() const;
	int a[15][15];
	// ����
public:

	// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// ʵ��
public:
	virtual ~CFIVEView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // FIVEView.cpp �еĵ��԰汾
inline CFIVEDoc* CFIVEView::GetDocument() const
{
	return reinterpret_cast<CFIVEDoc*>(m_pDocument);
}
#endif

