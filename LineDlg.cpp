// LineDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "LineDlg.h"
#include "afxdialogex.h"
#include "string.h"
#include "Setting.h"

// LineDlg 대화 상자

#define		WM_SOLID_BTN				WM_USER+17
#define		WM_DASH_BTN					WM_USER+18
#define		WM_DOT_BTN					WM_USER+19
#define		WM_DASHDOT_BTN					WM_USER+20
#define		WM_DASHDOTDOT_BTN					WM_USER+21

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
	DDX_Control(pDX, IDC_SLIDER2, Slider);
}


BEGIN_MESSAGE_MAP(LineDlg, CDialogEx)
	ON_COMMAND(WM_SOLID_BTN, OnBnClickedButton1)
	ON_COMMAND(WM_DASH_BTN, OnBnClickedButton2)
	ON_COMMAND(WM_DOT_BTN, OnBnClickedButton3)
	ON_COMMAND(WM_DASHDOT_BTN, OnBnClickedButton4)
	ON_COMMAND(WM_DASHDOTDOT_BTN, OnBnClickedButton5)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER2, &LineDlg::OnNMReleasedcaptureSlider)
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
	set->SetThickness(thickness);

	GetParent()->Invalidate();
	GetParent()->UpdateWindow();

	CDialogEx::OnOK();
}


BOOL LineDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	Slider.SetRange(0, 5);
	Slider.SetRangeMin(0);
	Slider.SetRangeMax(5);
	Slider.SetTicFreq(1);

	image[0].Load(L"Data/FigureImage/SOLID.png");
	image[1].Load(L"Data/FigureImage/DASH.png");
	image[2].Load(L"Data/FigureImage/DOT.png");
	image[3].Load(L"Data/FigureImage/DASHDOT.png");
	image[4].Load(L"Data/FigureImage/DASHDOTDOT.png");

	btn[0].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(5, 8, 0, 0), this, WM_SOLID_BTN);
	btn[0].SetImage(image[0].Detach());
	btn[0].SizeToContent();

	btn[1].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(60, 8, 0, 0), this, WM_DASH_BTN);
	btn[1].SetImage(image[1].Detach());
	btn[1].SizeToContent();

	btn[2].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(115, 8, 0, 0), this, WM_DOT_BTN);
	btn[2].SetImage(image[2].Detach());
	btn[2].SizeToContent();

	btn[3].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(170, 8, 0, 0), this, WM_DASHDOT_BTN);
	btn[3].SetImage(image[3].Detach());
	btn[3].SizeToContent();

	btn[4].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(225, 8, 0, 0), this, WM_DASHDOTDOT_BTN);
	btn[4].SetImage(image[4].Detach());
	btn[4].SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void LineDlg::OnNMReleasedcaptureSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	thickness = Slider.GetPos();
	 *pResult = 0;
}


