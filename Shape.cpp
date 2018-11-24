#include "stdafx.h"
#include "Shape.h"


// ������
Shape::Shape(CPoint pt1, CPoint pt2, int type, int thickness, int line_color, int fill_color) {

	size = CRect(pt1, pt2);
	
	this->type = type;
	this->thickness = thickness;
	this->line_color = line_color;
	this->fill_color = fill_color;
}


CRect Shape::GetRect() { 
	
	return size;
}

// ũ�� ����
void Shape::SetSize(int width, int height) {

	size.right = size.left + width;
	size.bottom = size.top + height;
}

// ��ġ ����
void Shape::Move(CPoint pt) {

	size.left += pt.x;
	size.right += pt.x;
	size.top += pt.y;
	size.bottom += pt.y;
}


// �׵θ� �β�
int Shape::GetThickness() {

	return thickness;
}

void Shape::SetThickness(int thickness) {

	this->thickness = thickness;
}


// ä��� ��
int Shape::GetFillColor() {

	return fill_color;
}

void Shape::SetFillColor(int fill_color) {

	this->fill_color = fill_color;
}


// �׵θ� ��
int Shape::GetLineColor() {

	return line_color;
}

void Shape::SetLineColor(int line_color) {

	this->line_color = line_color;
}

