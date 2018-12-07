// DrawView.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "DrawView.h"

#include "Setting.h"
#include "Shape.h"

// DrawView

IMPLEMENT_DYNAMIC(DrawView, CWnd)

DrawView::DrawView(Setting *set)
{
	this->set = set;
}

DrawView::~DrawView()
{
}


BEGIN_MESSAGE_MAP(DrawView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_SETCURSOR()
	ON_WM_SIZE()
END_MESSAGE_MAP()

BOOL DrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.style |= WS_SIZEBOX;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

	return CWnd::PreCreateWindow(cs);
}

// DrawView 메시지 처리기

void DrawView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CWnd::OnPaint()을(를) 호출하지 마십시오.
	CDC *pDC = GetDC();

	if (set != NULL) {

		// 도형 그리기
		int count = set->GetCount();

		for (int i = 0; i < count; i++) {

			Shape shape = set->GetShape(i);
			CRect rt = shape.GetRect();

			CPen pen, *oldPen;
			pen.CreatePen(PS_SOLID, shape.GetThickness(), shape.GetLineColor());	// 색깔을 객체에서 받아올 수 있는 함수 제작
			oldPen = pDC->SelectObject(&pen);

			int fill_color = shape.GetFillColor();
			int type = shape.GetType();

			if (fill_color != -1) {	// -1일 경우 채우기 색 없음

				CBrush br, *oldBr;
				br.CreateSolidBrush(fill_color);
				oldBr = pDC->SelectObject(&br);

				pDC->Rectangle(rt);

				pDC->SelectObject(oldPen);
				pDC->SelectObject(oldBr);

				pen.DeleteObject();
				br.DeleteObject();

			}
			else {

				if (type == 1) {

					pDC->Rectangle(rt);
				}
				else if (type == 2) {

					pDC->Ellipse(rt);
				}
				pDC->SelectObject(oldPen);

				pen.DeleteObject();

			}
		}

		// 크기 변경 버튼 그리기
		if (set->IsSelected()) {

			for (int i = 0; i < 4; i++) {

				CRect resizeRect = set->GetResizeRect(i);

				CPen pen, *oldPen;;
				pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
				oldPen = pDC->SelectObject(&pen);

				pDC->Rectangle(resizeRect);
				pDC->SelectObject(oldPen);
				pen.DeleteObject();
			}
		}
	}
}

void DrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	mouse_down_pos = point;

	CWnd::OnLButtonDown(nFlags, point);
}

void DrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	mouse_up_pos = point;

	set->Drag(mouse_down_pos, mouse_up_pos);
	set->SelectShape(point);


	GetParent()->Invalidate();
	GetParent()->UpdateWindow();

	CWnd::OnLButtonUp(nFlags, point);
}

BOOL DrawView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (set->GetType()) {

	case 0:
		SetCursor(AfxGetApp()->LoadCursor(MAKEINTRESOURCE(IDC_MOVE)));
		break;

	case 1:
		SetCursor(AfxGetApp()->LoadCursor(MAKEINTRESOURCE(IDC_ADD_RECT)));
		break;

	case 2:
		SetCursor(AfxGetApp()->LoadCursor(MAKEINTRESOURCE(IDC_ADD_CIR)));
		break;

	case 3:
		break;
	}

	return TRUE;
}

void DrawView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	GetParent()->Invalidate();
	GetParent()->UpdateWindow();
}
