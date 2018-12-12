// LineDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "LineDlg.h"
#include "afxdialogex.h"

#include "Setting.h"

// LineDlg 대화 상자

IMPLEMENT_DYNAMIC(LineDlg, CDialogEx)

LineDlg::LineDlg(Setting *set, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LINE_DLG, pParent)
{
	this->set = set;
}

LineDlg::~LineDlg()
{
}

void LineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LineDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LineDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &LineDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &LineDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &LineDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &LineDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &LineDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// LineDlg 메시지 처리기


void LineDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_SOLID;
}


void LineDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_DASH;
}


void LineDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_DOT;
}


void LineDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_DASHDOT;
}


void LineDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_DASHDOTDOT;
}


void LineDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_NULL;
}


void LineDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	set->SetLineOpt(line_opt);

	GetParent()->Invalidate();
	GetParent()->UpdateWindow();

	CDialogEx::OnOK();
}
