#pragma once

class Shape {

protected:
	CRect size;			// Shape의 크기

	int type;
	int option;

	int fill_color;		// 채우기 색깔
	int line_color;		// 테두리 색깔
	int thickness;		// 테두리 두께

public:
	Shape(CPoint pt1, CPoint pt2, int type, int thickness, int line_color, int fill_color);

	CRect GetRect();
	void SetSize(int width, int height);
	void Move(CPoint pt);
	bool IsClicked(CPoint pt);

	int GetThickness();
	void SetThickness(int thickness);
	int GetFillColor();
	void SetFillColor(int color);
	int GetLineColor();
	void SetLineColor(int color);

};

