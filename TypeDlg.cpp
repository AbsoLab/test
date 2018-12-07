// TypeDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "TypeDlg.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "Setting.h"

// TypeDlg 대화 상자

IMPLEMENT_DYNAMIC(TypeDlg, CDialogEx)

TypeDlg::TypeDlg(Setting *set, CWnd* pParent /*=nullptr*/) : CDialogEx(IDD_TYPE_DLG, pParent)
{
	this->set = set;
}

TypeDlg::~TypeDlg()
{
}

void TypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TypeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CURSOR_BTN, &TypeDlg::OnBnClickedCursorBtn)
	ON_BN_CLICKED(IDC_RECT_BTN, &TypeDlg::OnBnClickedRectBtn)
	ON_BN_CLICKED(IDC_CIRCLE_BTN, &TypeDlg::OnBnClickedCircleBtn)
END_MESSAGE_MAP()


// TypeDlg 메시지 처리기


void TypeDlg::OnBnClickedCursorBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	set->SetSelectedType(0);
}


void TypeDlg::OnBnClickedRectBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	set->SetSelectedType(1);
}


void TypeDlg::OnBnClickedCircleBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	set->SetSelectedType(2);
}
