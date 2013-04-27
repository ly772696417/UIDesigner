#pragma once

#include "stdafx.h"

#include "D3DInit.h"
#include "DrawLeftScence.h"
#include "DrawRightScence.h"

// LeftView 视图

class LeftView : public CView
{
	DECLARE_DYNCREATE(LeftView)

public:
	DrawLeftScence *m_drawLeftScence;
	HWND hWnd;

public:
	static LeftView *Singleton() { return m_pSingleton;}

private:
	static LeftView *m_pSingleton;

protected:
	LeftView();           // 动态创建所使用的受保护的构造函数
	virtual ~LeftView();

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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
};


