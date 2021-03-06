#pragma once


// TypeDlg 대화 상자

class Setting;

class TypeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TypeDlg)

public:
	TypeDlg(Setting *set, CWnd* pParent = nullptr);
	virtual ~TypeDlg();

	Setting *set;
	CMFCButton btn[7];		// 도형 선택 버튼
	CImage image[7];		// 버튼의 이미지

	int select;				// 사용자 선택

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TYPE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	afx_msg void OnBnClickedLineBtn();
	afx_msg void OnBnClickedRectBtn();
	afx_msg void OnBnClickedCircleBtn();
	afx_msg void OnBnClickedTriBtn();
	afx_msg void OnBnClickedPentaBtn();
	afx_msg void OnBnClickedHexaBtn();
	afx_msg void OnBnClickedOctaBtn();
};
