#include "stdafx.h"
#include "Shape.h"


// ������
Shape::Shape(int left, int top, int right, int bottom) {

	size = CRect(left, top, right, bottom);
	line_color = 1;
	fill_color = -1;	// ä���� ����
	thickness = 1;
}


// ���� ����
void Shape::SetSize(int width, int height) {

	size.right = size.left + width;
	size.bottom = size.top + height;
}

// ���� ��ġ ����
void Shape::Move(int x, int y) {

	size.left += x;
	size.right += x;
	size.top += y;
	size.bottom += y;
}

// �β� ����
void Shape::SetThickness(int thickness) {

	this->thickness = thickness;
}

// ä��� ��
void Shape::SetFillColor(int fill_color) {

	this->fill_color = fill_color;
}

// �׵θ� ��
void Shape::SetLineColor(int line_color) {

	this->line_color = line_color;
}

