#pragma once


// CBoard

class CBoard : public CWnd
{
	DECLARE_DYNAMIC(CBoard)

public:
	CBoard();
	virtual ~CBoard();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


