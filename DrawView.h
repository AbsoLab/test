#pragma once

class Setting;
class Shape;

// DrawView

class DrawView : public CWnd
{
	DECLARE_DYNAMIC(DrawView)

	CPoint mouse_down_pos;
	CPoint mouse_up_pos;

	Setting *set;

public:
	DrawView(Setting *set);
	~DrawView();
	BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	DECLARE_MESSAGE_MAP()

private:
	void DrawResizeBtn(CDC *pDC);
	void DrawShape(Shape shape, CDC *pDC);

// 메시지 처리
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	
	afx_msg void OnSize(UINT nType, int cx, int cy);
};