
// UIDesigner.h : UIDesigner Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CUIDesignerApp:
// �йش����ʵ�֣������ UIDesigner.cpp
//

class CUIDesignerApp : public CWinApp
{
public:
	CUIDesignerApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUIDesignerApp theApp;
