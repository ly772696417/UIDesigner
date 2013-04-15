// LeftView.cpp : 实现文件
//

#include "stdafx.h"
#include "UIDesigner.h"

#include "LeftView.h"


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
