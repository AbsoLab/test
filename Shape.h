#pragma once

class Shape {

protected:
	CRect size;			// Shape�� ũ��
	int fill_color;		// ä��� ����
	int line_color;		// �׵θ� ����
	int thickness;	// �׵θ� �β�

public:
	Shape(int left, int top, int right, int bottom);

	void SetSize(int width, int height);
	void Move(int x, int y);

	void SetThickness(int thickness);
	void SetFillColor(int color);
	void SetLineColor(int color);

};

