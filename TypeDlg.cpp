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

TypeDlg::TypeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TYPE_DLG, pParent)
{
	set = ((CMainFrame*)AfxGetMainWnd())->set;
}

TypeDlg::~TypeDlg()
{
}

void TypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RECT_BTN, RectBtn);
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


BOOL TypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	RectBtn.LoadBitmaps(IDB_BITMAP1, IDB_BITMAP2, IDB_BITMAP1, IDB_BITMAP2);
	RectBtn.SizeToContent();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
