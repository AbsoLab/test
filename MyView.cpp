
// MyView.cpp: CMyView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "My.h"
#endif

#include "MyDoc.h"
#include "MyView.h"

#include "MainFrm.h"

#include "DrawView.h"
#include "CMenuBar.h"

#include "Setting.h"
#include "Shape.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMyView 생성/소멸

CMyView::CMyView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

	set = new Setting();
	drawView = NULL;
	menuBar = NULL;
}

CMyView::~CMyView()
{
	delete(drawView);
	delete(menuBar);
	delete(set);
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	return CView::PreCreateWindow(cs);
}

// CMyView 그리기
void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);


	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMyView 진단

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG


int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	
	CRect rt;
	GetClientRect(&rt);

	menuBar = new CMenuBar(set);
	menuBar->Create(
		NULL, L"menu",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		CRect(0, 0, rt.Width(), 60),
		this, NULL, NULL
	);

	drawView = new DrawView(set);
	drawView->Create(
		NULL, L"drawView",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		CRect(0, 60, 800, 600),
		this, NULL, NULL
	);

	return 0;
}

void CMyView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	// 메뉴바 크기 조정
	if (menuBar != NULL) {
		CRect rt;
		GetClientRect(&rt);

		menuBar->MoveWindow(0, 0, rt.Width(), 60);
	}
}
