// LineDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "LineDlg.h"
#include "afxdialogex.h"
#include "string.h"
#include "Setting.h"

// LineDlg 대화 상자

#define		WM_SOLID_BTN			WM_USER+21
#define		WM_DASH_BTN				WM_USER+22
#define		WM_DOT_BTN				WM_USER+23
#define		WM_DASHDOT_BTN			WM_USER+24
#define		WM_DASHDOTDOT_BTN		WM_USER+25
#define		WM_NOLINE_BTN			WM_USER+26

IMPLEMENT_DYNAMIC(LineDlg, CDialogEx)

LineDlg::LineDlg(Setting *set, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LINE_DLG, pParent)
{
	this->set = set;

	line_opt = set->GetLineOpt();
	thickness = set->GetThick();
}

void LineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, slider);
}


BEGIN_MESSAGE_MAP(LineDlg, CDialogEx)
	ON_COMMAND(WM_SOLID_BTN, OnBnClickedSolid)
	ON_COMMAND(WM_DASH_BTN, OnBnClickedDash)
	ON_COMMAND(WM_DOT_BTN, OnBnClickedDot)
	ON_COMMAND(WM_DASHDOT_BTN, OnBnClickedDashDot)
	ON_COMMAND(WM_DASHDOTDOT_BTN, OnBnClickedDashDotDot)
	ON_COMMAND(WM_NOLINE_BTN, OnBnClickedNoLine)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnNMReleasedcaptureSlider)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// LineDlg 메시지 처리기

BOOL LineDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	image[0].Load(L"Data/LineImage/Solid.png");
	image[1].Load(L"Data/LineImage/Dash.png");
	image[2].Load(L"Data/LineImage/Dot.png");
	image[3].Load(L"Data/LineImage/DashDot.png");
	image[4].Load(L"Data/LineImage/DashDotDot.png");
	image[5].Load(L"Data/LineImage/Null.png");

	btn[0].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(40, 8, 0, 0), this, WM_SOLID_BTN);
	btn[0].SetImage(image[0].Detach());
	btn[0].SizeToContent();

	btn[1].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(239, 8, 0, 0), this, WM_DASH_BTN);
	btn[1].SetImage(image[1].Detach());
	btn[1].SizeToContent();

	btn[2].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(40, 60, 0, 0), this, WM_DOT_BTN);
	btn[2].SetImage(image[2].Detach());
	btn[2].SizeToContent();

	btn[3].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(239, 60, 0, 0), this, WM_DASHDOT_BTN);
	btn[3].SetImage(image[3].Detach());
	btn[3].SizeToContent();

	btn[4].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(40, 112, 0, 0), this, WM_DASHDOTDOT_BTN);
	btn[4].SetImage(image[4].Detach());
	btn[4].SizeToContent();

	btn[5].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(239, 112, 0, 0), this, WM_NOLINE_BTN);
	btn[5].SetImage(image[5].Detach());
	btn[5].SizeToContent();

	// 슬라이더 설정
	slider.SetRange(1, 5);
	slider.SetRangeMin(1);
	slider.SetRangeMax(5);
	slider.SetTicFreq(1);
	slider.SetLineSize(1);
	slider.SetPageSize(1);

	slider.SetPos(thickness);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void LineDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	CDC *pDC = GetDC();
	CRect rt;
	btn[line_opt].GetWindowRect(&rt);

	CPen pen, *oldPen;
	pen.CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	oldPen = pDC->SelectObject(&pen);

	pDC->Rectangle(rt.left -5, rt.top-5, rt.right+5, rt.bottom+5);

	pDC->SelectObject(oldPen);

	ReleaseDC(pDC);
}

void LineDlg::OnBnClickedSolid() { line_opt = PS_SOLID; }
void LineDlg::OnBnClickedDash() { line_opt = PS_DASH; }
void LineDlg::OnBnClickedDot() { line_opt = PS_DOT; }
void LineDlg::OnBnClickedDashDot() { line_opt = PS_DASHDOT; }
void LineDlg::OnBnClickedDashDotDot() { line_opt = PS_DASHDOTDOT; }
void LineDlg::OnBnClickedNoLine() { line_opt = PS_NULL; }

void LineDlg::OnOK()
{
	set->SetLineOpt(line_opt);
	set->SetThickness(thickness);

	GetParent()->Invalidate();
	GetParent()->UpdateWindow();

	CDialogEx::OnOK();
}

void LineDlg::OnNMReleasedcaptureSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	thickness = slider.GetPos();
	*pResult = 0;
}

