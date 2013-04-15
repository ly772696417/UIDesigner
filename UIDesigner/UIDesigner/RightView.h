#pragma once

#include "stdafx.h"

#include "D3DInit.h"

// RightView 视图

class RightView : public CView
{
	DECLARE_DYNCREATE(RightView)

public:
	D3DInit *m_pD3DInit;

	CPoint m_movePoint;
	CPoint m_clickPoint;
	HWND m_hWnd;

public:
	static RightView *Singleton() { return m_pSingleton;}

private:
	static RightView *m_pSingleton;

protected:
	RightView();           // 动态创建所使用的受保护的构造函数
	virtual ~RightView();

public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


