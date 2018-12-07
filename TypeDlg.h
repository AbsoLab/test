#pragma once


// TypeDlg 대화 상자

class Setting;

class TypeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TypeDlg)

public:
	TypeDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~TypeDlg();

	Setting *set;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TYPE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCursorBtn();
	afx_msg void OnBnClickedRectBtn();
	afx_msg void OnBnClickedCircleBtn();
	virtual BOOL OnInitDialog();
	CBitmapButton RectBtn;
};
