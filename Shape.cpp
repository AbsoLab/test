#include "stdafx.h"
#include "Shape.h"


// 생성자
Shape::Shape(CPoint pt1, CPoint pt2, int type, int thickness, int line_color, int fill_color) {

	size = CRect(pt1, pt2);
	
	this->type = type;
	this->thickness = thickness;
	this->line_color = line_color;
	this->fill_color = fill_color;
}

// 크기를 반환
CRect Shape::GetRect() { 
	
	return size;
}

// 크기 변경
void Shape::SetSize(int width, int height) {

	size.right = size.left + width;
	size.bottom = size.top + height;
}

// 위치 변경
void Shape::Move(CPoint pt) {

	size.left += pt.x;
	size.right += pt.x;
	size.top += pt.y;
	size.bottom += pt.y;
}

// 선택한 위치가 도형 안에 있는지 확인
bool Shape::IsClicked(CPoint pt)
{
	if (size.left <= pt.x && pt.x <= size.right) {

		if (size.top <= pt.y && pt.y <= size.bottom) {

			return true;
		}
	}

	return false;
}



// 테두리 두께
int Shape::GetThickness() {

	return thickness;
}

void Shape::SetThickness(int thickness) {

	this->thickness = thickness;
}


// 채우기 색
int Shape::GetFillColor() {

	return fill_color;
}

void Shape::SetFillColor(int fill_color) {

	this->fill_color = fill_color;
}


// 테두리 색
int Shape::GetLineColor() {

	return line_color;
}

void Shape::SetLineColor(int line_color) {

	this->line_color = line_color;
}

