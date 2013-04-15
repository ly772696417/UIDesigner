// Splitter.cpp : 实现文件
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



// Splitter 消息处理程序




void Splitter::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CSplitterWnd::OnLButtonDown(nFlags, point);
}
