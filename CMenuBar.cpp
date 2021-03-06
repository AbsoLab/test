// CMenuBar.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "CMenuBar.h"

#include "MainFrm.h"
#include "Setting.h"

#include "TypeDlg.h"
#include "LineDlg.h"
#include "ColorDlg.h"


#define		WM_OPEN_BTN			WM_USER+0
#define		WM_SAVE_BTN			WM_USER+1
#define		WM_CURSOR_BTN		WM_USER+2
#define		WM_FIGURE_BTN		WM_USER+3
#define		WM_ERASE_BTN		WM_USER+4
#define		WM_PIPETTE_BTN		WM_USER+5
#define		WM_FILL_BTN			WM_USER+6
#define		WM_LINE_BTN			WM_USER+7
#define		WM_TOP_BTN			WM_USER+8
#define		WM_BOT_BTN			WM_USER+9
#define		WM_COLOR_BTN		WM_USER+10

// CMenuBar

IMPLEMENT_DYNAMIC(CMenuBar, CWnd)

CMenuBar::CMenuBar(Setting *set)
{
	this->set = set;

	p_openDlg = NULL;
	p_saveDlg = NULL;
	p_typeDlg = NULL;
	p_lineDlg = NULL;
	p_colorDlg = NULL;
}

CMenuBar::~CMenuBar()
{
	if (p_openDlg != NULL) { delete(p_openDlg); }
	if (p_saveDlg != NULL) { delete(p_saveDlg); }
	if (p_typeDlg != NULL) { delete(p_typeDlg); }
	if (p_lineDlg != NULL) { delete(p_lineDlg); }
	if (p_colorDlg != NULL) { delete(p_colorDlg); }
}


BEGIN_MESSAGE_MAP(CMenuBar, CWnd)
	ON_WM_CREATE()
	ON_COMMAND(WM_OPEN_BTN, OnOpenBtnClick)
	ON_COMMAND(WM_SAVE_BTN, OnSaveBtnClick)
	ON_COMMAND(WM_CURSOR_BTN, OnCursorBtnClick)
	ON_COMMAND(WM_FIGURE_BTN, OnFigureBtnClick)
	ON_COMMAND(WM_ERASE_BTN, OnEraseBtnClick)
	ON_COMMAND(WM_PIPETTE_BTN, OnPipetteBtnClick)
	ON_COMMAND(WM_FILL_BTN, OnFillBtnClick)
	ON_COMMAND(WM_LINE_BTN, OnLineBtnClick)
	ON_COMMAND(WM_TOP_BTN, OnTopBtnClick)
	ON_COMMAND(WM_BOT_BTN, OnBottomBtnClick)
	ON_COMMAND(WM_COLOR_BTN, OnColorBtnClick)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()

BOOL CMenuBar::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	toolTip.RelayEvent(pMsg);
	
	return CWnd::PreTranslateMessage(pMsg);
}

// CMenuBar 메시지 처리기
int CMenuBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	image[0].Load(L"Data/ButtonImage/Open.png");
	image[1].Load(L"Data/ButtonImage/Save.png");
	image[2].Load(L"Data/ButtonImage/Cursor.png");
	image[3].Load(L"Data/ButtonImage/Figure.png");
	image[4].Load(L"Data/ButtonImage/Erase.png");
	image[5].Load(L"Data/ButtonImage/Pipette.png");
	image[6].Load(L"Data/ButtonImage/Fill.png");
	image[7].Load(L"Data/ButtonImage/Line.png");
	image[8].Load(L"Data/ButtonImage/Top.png");
	image[9].Load(L"Data/ButtonImage/Bottom.png");


	btn[0].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(5, 8, 0, 0), this, WM_OPEN_BTN);
	btn[0].SetImage(image[0].Detach());
	btn[0].SizeToContent();

	btn[1].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(60, 8, 0, 0), this, WM_SAVE_BTN);
	btn[1].SetImage(image[1].Detach());
	btn[1].SizeToContent();

	btn[2].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(115, 8, 0, 0), this, WM_CURSOR_BTN);
	btn[2].SetImage(image[2].Detach());
	btn[2].SizeToContent();

	btn[3].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(170, 8, 0, 0), this, WM_FIGURE_BTN);
	btn[3].SetImage(image[3].Detach());
	btn[3].SizeToContent();

	btn[4].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(225, 8, 0, 0), this, WM_ERASE_BTN);
	btn[4].SetImage(image[4].Detach());
	btn[4].SizeToContent();
	
	btn[5].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(280, 8, 0, 0), this, WM_PIPETTE_BTN);
	btn[5].SetImage(image[5].Detach());
	btn[5].SizeToContent();

	btn[6].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(335, 8, 0, 0), this, WM_FILL_BTN);
	btn[6].SetImage(image[6].Detach());
	btn[6].SizeToContent();

	btn[7].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(390, 8, 0, 0), this, WM_LINE_BTN);
	btn[7].SetImage(image[7].Detach());
	btn[7].SizeToContent();

	btn[8].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(445, 8, 0, 0), this, WM_TOP_BTN);
	btn[8].SetImage(image[8].Detach());
	btn[8].SizeToContent();

	btn[9].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(500, 8, 0, 0), this, WM_BOT_BTN);
	btn[9].SetImage(image[9].Detach());
	btn[9].SizeToContent();

	btn[10].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(555, 8, 596, 49), this, WM_COLOR_BTN);
	btn[10].SetFaceColor(RGB(0, 0, 0), TRUE);


	toolTip.Create(this);
	toolTip.SetTipBkColor(RGB(255, 255, 0));
	toolTip.SetTipTextColor(RGB(255, 0, 0));

	toolTip.AddTool(&btn[0], L"열기");
	toolTip.AddTool(&btn[1], L"저장");
	toolTip.AddTool(&btn[2], L"커서");
	toolTip.AddTool(&btn[3], L"도형");
	toolTip.AddTool(&btn[4], L"지우개");
	toolTip.AddTool(&btn[5], L"피펫");
	toolTip.AddTool(&btn[6], L"채우기");
	toolTip.AddTool(&btn[7], L"선종류");
	toolTip.AddTool(&btn[8], L"맨위로");
	toolTip.AddTool(&btn[9], L"맨아래로");
	toolTip.AddTool(&btn[10], L"색깔");

	return 0;
}

void CMenuBar::OnOpenBtnClick()
{
	CString path;
	p_openDlg = new CFileDialog(TRUE, L"mdt", NULL, OFN_FILEMUSTEXIST, L"MyData(*.mdt)|*.mdt|모든파일(*.*)|*.*||", this);

	if (p_openDlg->DoModal() == IDOK) {

		path = p_openDlg->GetPathName();
		set->FileOpen(path);
	}

	GetParent()->Invalidate();
	GetParent()->UpdateWindow();
}

void CMenuBar::OnSaveBtnClick()
{
	CString path;
	p_saveDlg = new CFileDialog(FALSE, L"mdt", L"*.mdt", OFN_OVERWRITEPROMPT, L"MyData(*.mdt)|*.mdt|모든파일(*.*)|*.*||", this);

	if (p_saveDlg->DoModal() == IDOK) {

		path = p_saveDlg->GetPathName();
		set->FileSave(path);
	}
}

void CMenuBar::OnCursorBtnClick()
{
	// 일반 커서 선택
	set->SetType(0);
}

void CMenuBar::OnFigureBtnClick()
{
	// 도형 선택 다이얼로그 띄우기
	p_typeDlg = new TypeDlg(set);
	p_typeDlg->DoModal();
}

void CMenuBar::OnEraseBtnClick()
{
	// 지우기 선택
	set->SetType(10);
}

void CMenuBar::OnPipetteBtnClick()
{
	// 피펫 선택
	set->SetType(11);
}

void CMenuBar::OnFillBtnClick()
{
	// 채우기 선택
	set->SetType(12);
}

void CMenuBar::OnTopBtnClick()
{
	// 선택된 도형 맨 위로
	set->SetTop();

	GetParent()->Invalidate();
	GetParent()->UpdateWindow();
}

void CMenuBar::OnBottomBtnClick()
{
	// 선택된 도형 맨 밑으로
	set->SetBottom();

	GetParent()->Invalidate();
	GetParent()->UpdateWindow();
}

void CMenuBar::OnLineBtnClick()
{
	// 선 종류 선택 다이얼로그 띄우기
	p_lineDlg = new LineDlg(set);
	p_lineDlg->DoModal();
}

void CMenuBar::OnColorBtnClick()
{
	// 컬러 선택 다이얼로그 띄우기
	p_colorDlg = new CColorDialog();
	
	if (p_colorDlg->DoModal() == IDOK) {

		set->SetColor(p_colorDlg->GetColor());
		SetColorBtnBk();

		GetParent()->Invalidate();
		GetParent()->UpdateWindow();
	}
}

void CMenuBar::SetColorBtnBk()
{
	btn[10].SetFaceColor(set->GetColor());
}