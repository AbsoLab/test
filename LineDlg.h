#pragma once

class Setting;

// LineDlg 대화 상자

class LineDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LineDlg)

public:
	LineDlg(Setting *set, CWnd* pParent = nullptr);   // 표준 생성자입니다.
	
	Setting *set;
	
	CMFCButton btn[6];		// 도형 선택 버튼
	CImage image[6];		// 버튼의 이미지
	CSliderCtrl slider;		// 두께 조절 슬라이더
	
	int line_opt;			// 선 종류
	int thickness;			// 선 두께

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	afx_msg void OnBnClickedSolid();
	afx_msg void OnBnClickedDash();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedDashDot();
	afx_msg void OnBnClickedDashDotDot();
	afx_msg void OnBnClickedNoLine();
	afx_msg void OnNMReleasedcaptureSlider(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnPaint();
};