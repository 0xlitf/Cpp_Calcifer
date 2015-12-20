
// FIVEView.cpp : CFIVEView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "FIVE.h"
#include "Pt.h"
#endif

#include "FIVEDoc.h"
#include "FIVEView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFIVEView

IMPLEMENT_DYNCREATE(CFIVEView, CView)

BEGIN_MESSAGE_MAP(CFIVEView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CFIVEView 构造/析构

CFIVEView::CFIVEView()
{
	// TODO:  在此处添加构造代码
	m_ptOrigin = 0;
	m_x = 0;
	m_y = 0;
	m_turn = 1;
	m_type = 0;
	m_coordinatex = 0;
	m_coordinatey = 0;
	memset(a, 0, sizeof(a));
}

CFIVEView::~CFIVEView()
{
}

BOOL CFIVEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFIVEView 绘制

void CFIVEView::OnDraw(CDC* pDC)
{
	CFIVEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	for (int i = 50; i < 651; i += 50)
	{
		pDC->MoveTo(50, i);
		pDC->LineTo(650, i);
		pDC->MoveTo(i, 50);
		pDC->LineTo(i, 650);
	}
	for (int m = 1; m <= 13; m++)
	{
		for (int n = 1; n <= 13; n++)
		{
			switch (a[m][n])
			{
			case 1:
				if (!(m_coordinatex == 0))
				{
					CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(BLACK_BRUSH));
					pDC->SelectObject(pBrush);
					pDC->Ellipse(m * 50 - 25, n * 50 - 25, m * 50 + 25, n * 50 + 25);
				}
				break;
			case 2:
				if (!(m_coordinatex == 0))
				{
					CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH));
					pDC->SelectObject(pBrush);
					pDC->Ellipse(m * 50 - 25, n * 50 - 25, m * 50 + 25, n * 50 + 25);
				}
				break;
			}
		}
	}
}

// CFIVEView 诊断

#ifdef _DEBUG
void CFIVEView::AssertValid() const
{
	CView::AssertValid();
}

void CFIVEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFIVEDoc* CFIVEView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFIVEDoc)));
	return (CFIVEDoc*)m_pDocument;
}
#endif //_DEBUG


// CFIVEView 消息处理程序


void CFIVEView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m_ptOrigin = point;
	float m_deltax, m_deltay;
	m_deltax = m_ptOrigin.x % 50;
	m_deltay = m_ptOrigin.y % 50;
	if (m_deltax<25)
	{
		m_x = m_ptOrigin.x - m_deltax;
	}
	else
	{
		m_x = m_ptOrigin.x - m_deltax + 50;
	}
	if (m_deltay<25)
	{
		m_y = m_ptOrigin.y - m_deltay;
	}
	else
	{
		m_y = m_ptOrigin.y - m_deltay + 50;
	}
	m_coordinatex = m_x / 50;
	m_coordinatey = m_y / 50;
	if (a[m_coordinatex][m_coordinatey] == 0)
	{

		if (m_turn == 1)
		{
			CClientDC dc(this);
			CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(BLACK_BRUSH));
			dc.SelectObject(pBrush);
			dc.Ellipse(m_x - 25, m_y - 25, m_x + 25, m_y + 25);
			m_turn = 2;

			a[m_coordinatex][m_coordinatey] = 1;

			CPt pt(m_type, m_x, m_y);
			m_ptrArray.Add(&pt);
		}
		else
		if (m_turn == 2)
		{
			CClientDC dc(this);
			CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH));
			dc.SelectObject(pBrush);
			dc.Ellipse(m_x - 25, m_y - 25, m_x + 25, m_y + 25);
			m_turn = 1;
			a[m_coordinatex][m_coordinatey] = 2;
		}
	}

	CView::OnLButtonDown(nFlags, point);
}


void CFIVEView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	int i, j;
	for (i = 1; i < 14; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i][j + 2] == 1 && a[i][j + 3] == 1 && a[i][j + 4] == 1)
			{
				MessageBox(_T("黑方胜利"));
				memset(a, 0, sizeof(a));
				Invalidate();
			}
		}
	}
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 14; j++)
		{
			if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i + 2][j] == 1 && a[i + 3][j] == 1 && a[i + 4][j] == 1)
			{
				MessageBox(_T("黑方胜利"));
				memset(a, 0, sizeof(a));
				Invalidate();
			}
		}
	}
	for (i = 5; i < 14; i++)
	{
		for (j = 13; j >4; j--)
		{
			if (a[i][j] == 1 && a[i + 1][j - 1] == 1 && a[i + 2][j - 2] == 1 && a[i + 3][j - 3] == 1 && a[i + 4][j - 4] == 1)
			{
				MessageBox(_T("黑方胜利"));
				memset(a, 0, sizeof(a));
				Invalidate();
			}
		}
	}
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (a[i][j] == 1 && a[i + 1][j + 1] == 1 && a[i + 2][j + 2] == 1 && a[i + 3][j + 3] == 1 && a[i + 4][j + 4] == 1)
			{
				MessageBox(_T("黑方胜利"));
				memset(a, 0, sizeof(a));
				Invalidate();
			}
		}
	}
	for (i = 1; i < 14; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (a[i][j] == 2 && a[i][j + 1] == 2 && a[i][j + 2] == 2 && a[i][j + 3] == 2 && a[i][j + 4] == 2)
			{
				MessageBox(_T("白方胜利"));
				memset(a, 0, sizeof(a));
				Invalidate();
			}
		}
	}
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 14; j++)
		{
			if (a[i][j] == 2 && a[i + 1][j] == 2 && a[i + 2][j] == 2 && a[i + 3][j] == 2 && a[i + 4][j] == 2)
			{
				MessageBox(_T("白方胜利"));
				memset(a, 0, sizeof(a));
				Invalidate();
			}
		}
	}
	for (i = 5; i < 14; i++)
	{
		for (j = 13; j >4; j--)
		{
			if (a[i][j] == 2 && a[i + 1][j - 1] == 2 && a[i + 2][j - 2] == 2 && a[i + 3][j - 3] == 2 && a[i + 4][j - 4] == 2)
			{
				MessageBox(_T("白方胜利"));
				memset(a, 0, sizeof(a));
				Invalidate();
			}
		}
	}
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (a[i][j] == 2 && a[i + 1][j + 1] == 2 && a[i + 2][j + 2] == 2 && a[i + 3][j + 3] == 2 && a[i + 4][j + 4] == 2)
			{
				MessageBox(_T("白方胜利"));
				memset(a, 0, sizeof(a));
				Invalidate();
			}
		}
	}

	CView::OnLButtonUp(nFlags, point);

}
