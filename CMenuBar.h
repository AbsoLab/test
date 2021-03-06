#pragma once

// CMenuBar
class Setting;
class TypeDlg;
class LineDlg;
class ColorDlg;

class CMenuBar : public CWnd
{
	DECLARE_DYNAMIC(CMenuBar)

private:
	Setting *set;				// setting 객체

	CMFCButton btn[11];			// 버튼들
	CImage image[11];			// 각 버튼의 이미지
	CToolTipCtrl toolTip;		// 버튼 툴팁

	CFileDialog *p_openDlg;		// 파일 열기 대화상자
	CFileDialog *p_saveDlg;		// 파일 저장 대화상자
	TypeDlg *p_typeDlg;			// 도형 선택 대화상자
	LineDlg *p_lineDlg;			// 선 종류 설정 대화상자
	CColorDialog *p_colorDlg;	// 색깔 선택 대화상자

public:
	CMenuBar(Setting *set);
	~CMenuBar();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	// 버튼 동작
	void OnOpenBtnClick();
	void OnSaveBtnClick();
	void OnCursorBtnClick();
	void OnFigureBtnClick();
	void OnEraseBtnClick();
	void OnPipetteBtnClick();
	void OnLineBtnClick();
	void OnFillBtnClick();
	void OnTopBtnClick();
	void OnBottomBtnClick();
	void OnColorBtnClick();
	
	void SetColorBtnBk();
};


