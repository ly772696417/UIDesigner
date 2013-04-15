#pragma once


// Splitter

class Splitter : public CSplitterWnd
{
	DECLARE_DYNAMIC(Splitter)

public:
	Splitter();
	virtual ~Splitter();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


