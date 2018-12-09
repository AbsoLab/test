#pragma once

class Setting;

// ThicknessDlg 대화 상자

class ThicknessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ThicknessDlg)

public:
	ThicknessDlg(Setting *set, CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ThicknessDlg();

	Setting *set;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THICKNESS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
