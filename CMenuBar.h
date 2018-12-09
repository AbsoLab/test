#pragma once

// CMenuBar
class Setting;

class CMenuBar : public CWnd
{
	DECLARE_DYNAMIC(CMenuBar)

private:
	Setting *set;			// setting 객체

	CMFCButton btn[10];		// 버튼들
	CImage image[10];		// 각 버튼의 이미지

	CToolTipCtrl toolTip;

public:
	CMenuBar(Setting *set);
	virtual ~CMenuBar();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	// 버튼 동작
	void OnOpenBtnClick();
	void OnSaveBtnClick();
	void OnCursorBtnClick();
	void OnFigureBtnClick();
	void OnEraseBtnClick();
	void OnPipetteBtnClick();
	void OnLineBtnClick();
	void OnThicknessBtnClick();
	void OnFillBtnClick();
	void OnColorBtnClick();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


