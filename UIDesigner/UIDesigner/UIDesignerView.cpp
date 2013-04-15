
// UIDesignerView.cpp : CUIDesignerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "UIDesigner.h"
#endif

#include "UIDesignerDoc.h"
#include "UIDesignerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUIDesignerView

IMPLEMENT_DYNCREATE(CUIDesignerView, CView)

BEGIN_MESSAGE_MAP(CUIDesignerView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CUIDesignerView ����/����

CUIDesignerView::CUIDesignerView()
{
	// TODO: �ڴ˴���ӹ������

}

CUIDesignerView::~CUIDesignerView()
{
}

BOOL CUIDesignerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CUIDesignerView ����

void CUIDesignerView::OnDraw(CDC* /*pDC*/)
{
	CUIDesignerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CUIDesignerView ��ӡ

BOOL CUIDesignerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CUIDesignerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CUIDesignerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CUIDesignerView ���

#ifdef _DEBUG
void CUIDesignerView::AssertValid() const
{
	CView::AssertValid();
}

void CUIDesignerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUIDesignerDoc* CUIDesignerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUIDesignerDoc)));
	return (CUIDesignerDoc*)m_pDocument;
}
#endif //_DEBUG


// CUIDesignerView ��Ϣ�������
