// ThicknessDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "ThicknessDlg.h"
#include "afxdialogex.h"

#include "Setting.h"

// ThicknessDlg 대화 상자

IMPLEMENT_DYNAMIC(ThicknessDlg, CDialogEx)

ThicknessDlg::ThicknessDlg(Setting *set, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_THICKNESS_DLG, pParent)
{
	this->set = set;
}

ThicknessDlg::~ThicknessDlg()
{
}

void ThicknessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ThicknessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ThicknessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ThicknessDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ThicknessDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// ThicknessDlg 메시지 처리기


void ThicknessDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	set->SetThickness(1);
}


void ThicknessDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	set->SetThickness(3);
}


void ThicknessDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	set->SetThickness(5);
}
