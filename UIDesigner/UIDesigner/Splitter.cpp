// Splitter.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UIDesigner.h"
#include "Splitter.h"


// Splitter

IMPLEMENT_DYNAMIC(Splitter, CSplitterWnd)

Splitter::Splitter()
{

}

Splitter::~Splitter()
{
}


BEGIN_MESSAGE_MAP(Splitter, CSplitterWnd)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// Splitter ��Ϣ�������




void Splitter::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CSplitterWnd::OnLButtonDown(nFlags, point);
}
