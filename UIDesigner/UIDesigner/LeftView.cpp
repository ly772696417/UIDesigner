// LeftView.cpp : ʵ���ļ�
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


// LeftView ��ͼ

void LeftView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
}


// LeftView ���

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


// LeftView ��Ϣ�������
