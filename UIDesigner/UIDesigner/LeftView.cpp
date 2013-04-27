// LeftView.cpp : 实现文件
//

#include "stdafx.h"
#include "UIDesigner.h"

#include "LeftView.h"
#include "RightView.h"


LeftView *LeftView::m_pSingleton = NULL;

// LeftView

IMPLEMENT_DYNCREATE(LeftView, CView)

LeftView::LeftView()
{
	m_pSingleton = this;
}

LeftView::~LeftView()
{
}

BEGIN_MESSAGE_MAP(LeftView, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// LeftView 绘图

void LeftView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
}


// LeftView 诊断

#ifdef _DEBUG
void LeftView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void LeftView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// LeftView 消息处理程序

void LeftView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	m_drawLeftScence = new DrawLeftScence(this->GetSafeHwnd());

	this->SetTimer(1,100,0);
}

void LeftView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnTimer(nIDEvent);
	m_drawLeftScence->SetPlaneData(RightView::Singleton()->m_drawRightScence->GetPlaneData());
	m_drawLeftScence->Render();
}



