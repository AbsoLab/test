#pragma once

class Shape {

protected:
	CRect size;			// Shape의 크기
	int fill_color;		// 채우기 색깔
	int line_color;		// 테두리 색깔
	int thickness;	// 테두리 두께

public:
	Shape(int left, int top, int right, int bottom);

	void SetSize(int width, int height);
	void Move(int x, int y);

	void SetThickness(int thickness);
	void SetFillColor(int color);
	void SetLineColor(int color);

};

