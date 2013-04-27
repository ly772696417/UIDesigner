// LeftView.cpp : ʵ���ļ�
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

void LeftView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	m_drawLeftScence = new DrawLeftScence(this->GetSafeHwnd());

	this->SetTimer(1,100,0);
}

void LeftView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnTimer(nIDEvent);
	m_drawLeftScence->SetPlaneData(RightView::Singleton()->m_drawRightScence->GetPlaneData());
	m_drawLeftScence->Render();
}



