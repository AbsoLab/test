// TypeDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "TypeDlg.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "Setting.h"

#define		WM_TRI_BTN				WM_USER+11
#define		WM_RECT_BTN				WM_USER+12
#define		WM_PENTA_BTN			WM_USER+13
#define		WM_HEXA_BTN				WM_USER+14
#define		WM_OCTA_BTN				WM_USER+15
#define		WM_CIRCLE_BTN			WM_USER+16
#define		WM_LINE_BTN				WM_USER+17

// TypeDlg 대화 상자

IMPLEMENT_DYNAMIC(TypeDlg, CDialogEx)

TypeDlg::TypeDlg(Setting *set, CWnd* pParent /*=nullptr*/) : CDialogEx(IDD_TYPE_DLG, pParent)
{
	this->set = set;
	select = -1;
}

TypeDlg::~TypeDlg()
{
}

void TypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TypeDlg, CDialogEx)
	ON_COMMAND(WM_RECT_BTN, OnBnClickedRectBtn)
	ON_COMMAND(WM_CIRCLE_BTN, OnBnClickedCircleBtn)
	ON_COMMAND(WM_TRI_BTN, OnBnClickedTriBtn)
	ON_COMMAND(WM_PENTA_BTN, OnBnClickedPentaBtn)
	ON_COMMAND(WM_HEXA_BTN, OnBnClickedHexaBtn)
	ON_COMMAND(WM_OCTA_BTN, OnBnClickedOctaBtn)
	ON_COMMAND(WM_LINE_BTN, OnBnClickedLineBtn)
END_MESSAGE_MAP()


// TypeDlg 메시지 처리기

BOOL TypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	image[0].Load(L"Data/FigureImage/Tool_triangle.png");
	image[1].Load(L"Data/FigureImage/Tool_rect.png");
	image[2].Load(L"Data/FigureImage/Tool_pentagon.png");
	image[3].Load(L"Data/FigureImage/Tool_hexagon.png");
	image[4].Load(L"Data/FigureImage/Tool_octagon.png");
	image[5].Load(L"Data/FigureImage/Tool_circle.png");
	image[6].Load(L"Data/FigureImage/Line.png");

	btn[0].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(5, 8, 0, 0), this, WM_TRI_BTN);
	btn[0].SetImage(image[0].Detach());
	btn[0].SizeToContent();

	btn[1].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(60, 8, 0, 0), this, WM_RECT_BTN);
	btn[1].SetImage(image[1].Detach());
	btn[1].SizeToContent();

	btn[2].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(115, 8, 0, 0), this, WM_PENTA_BTN);
	btn[2].SetImage(image[2].Detach());
	btn[2].SizeToContent();

	btn[3].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(170, 8, 0, 0), this, WM_HEXA_BTN);
	btn[3].SetImage(image[3].Detach());
	btn[3].SizeToContent();

	btn[4].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(225, 8, 0, 0), this, WM_OCTA_BTN);
	btn[4].SetImage(image[4].Detach());
	btn[4].SizeToContent();

	btn[5].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(280, 8, 0, 0), this, WM_CIRCLE_BTN);
	btn[5].SetImage(image[5].Detach());
	btn[5].SizeToContent();
	
	btn[6].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(335, 8, 0, 0), this, WM_LINE_BTN);
	btn[6].SetImage(image[6].Detach());
	btn[6].SizeToContent();



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void TypeDlg::OnBnClickedLineBtn()
{
	select = 2;
}

void TypeDlg::OnBnClickedRectBtn()
{
	select = 4;
}

void TypeDlg::OnBnClickedCircleBtn()
{
	select = 9;
}

void TypeDlg::OnBnClickedTriBtn()
{
	select = 3;
}

void TypeDlg::OnBnClickedPentaBtn()
{
	select = 5;
}

void TypeDlg::OnBnClickedHexaBtn()
{
	select = 6;
}

void TypeDlg::OnBnClickedOctaBtn()
{
	select = 8;
}

void TypeDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (select != -1) {

		set->SetType(select);
	}

	CDialogEx::OnOK();
}
