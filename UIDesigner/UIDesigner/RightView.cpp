// RightView.cpp : 实现文件
//

#include "stdafx.h"
#include "UIDesigner.h"
#include "RightView.h"


// RightView

RightView *RightView::m_pSingleton = NULL;

IMPLEMENT_DYNCREATE(RightView, CView)

RightView::RightView()
{
	m_pSingleton = this;
}

RightView::~RightView()
{
}

BEGIN_MESSAGE_MAP(RightView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// RightView 绘图

void RightView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
}


// RightView 诊断

#ifdef _DEBUG
void RightView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void RightView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// RightView 消息处理程序


void RightView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);

	m_clickPoint = point;
}


void RightView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);

	m_clickPoint = CPoint(-1,-1);
}


void RightView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);

	m_movePoint = point;
}


void RightView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	m_drawRightScence = new DrawRightScence(this->GetSafeHwnd());

	m_clickPoint = CPoint(-1,-1);
	this->SetTimer(1,100,0);
}


void RightView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnTimer(nIDEvent);
	m_drawRightScence->Render(m_movePoint,m_clickPoint);
}
