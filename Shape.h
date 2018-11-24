#pragma once

class Shape {

protected:
	CRect size;			// Shape�� ũ��

	int type;
	int option;

	int fill_color;		// ä��� ����
	int line_color;		// �׵θ� ����
	int thickness;		// �׵θ� �β�

public:
	Shape(CPoint pt1, CPoint pt2, int type, int thickness, int line_color, int fill_color);

	CRect GetRect();
	void SetSize(int width, int height);
	void Move(CPoint pt);

	int GetThickness();
	void SetThickness(int thickness);
	int GetFillColor();
	void SetFillColor(int color);
	int GetLineColor();
	void SetLineColor(int color);

};

