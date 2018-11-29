// ColorDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "ColorDlg.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "Setting.h"

// ColorDlg 대화 상자

IMPLEMENT_DYNAMIC(ColorDlg, CColorDialog)

ColorDlg::ColorDlg(CWnd* pParent /*=nullptr*/)
	: CColorDialog()
{
	set = ((CMainFrame*)AfxGetMainWnd())->set; 
}

ColorDlg::~ColorDlg()
{
}

void ColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CColorDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ColorDlg, CColorDialog)
	
END_MESSAGE_MAP()


// ColorDlg 메시지 처리기

BOOL ColorDlg::OnColorOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	set->SetSelectedColor(GetColor());

	return CColorDialog::OnColorOK();
}
