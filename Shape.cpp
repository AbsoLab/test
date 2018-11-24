#include "stdafx.h"
#include "Shape.h"


// 생성자
Shape::Shape(int left, int top, int right, int bottom) {

	size = CRect(left, top, right, bottom);
	line_color = 1;
	fill_color = -1;	// 채우지 않음
	thickness = 1;
}


// 도형 변경
void Shape::SetSize(int width, int height) {

	size.right = size.left + width;
	size.bottom = size.top + height;
}

// 도형 위치 변경
void Shape::Move(int x, int y) {

	size.left += x;
	size.right += x;
	size.top += y;
	size.bottom += y;
}

// 두께 조절
void Shape::SetThickness(int thickness) {

	this->thickness = thickness;
}

// 채우기 색
void Shape::SetFillColor(int fill_color) {

	this->fill_color = fill_color;
}

// 테두리 색
void Shape::SetLineColor(int line_color) {

	this->line_color = line_color;
}

