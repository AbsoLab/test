#include "stdafx.h"
#include "Shape.h"

// 생성자
Shape::Shape(CPoint pt1, CPoint pt2, int type, int thickness, int line_color, int fill_color) {
	
	size = CRect(pt1, pt2);
	SortPosition();

	this->type = type;
	this->thickness = thickness;
	this->line_color = line_color;
	this->fill_color = fill_color;
}

// 필드값 반환
const CRect Shape::GetRect() { 
	
	return size;
}

const int Shape::GetThickness() {

	return thickness;
}

const int Shape::GetFillColor() {

	return fill_color;
}

const int Shape::GetLineColor() {

	return line_color;
}

// 필드값 설정
void Shape::SetThickness(int thickness) {

	this->thickness = thickness;
}

void Shape::SetFillColor(int fill_color) {

	this->fill_color = fill_color;
}

void Shape::SetLineColor(int line_color) {

	this->line_color = line_color;
}


// 크기 재설정
void Shape::SetSize(CPoint pt, int index) {
	
	/* index
	 * 0 : LeftTop
	 * 1 : RightTop
	 * 2 : LeftBottom
	 * 3 : RightBottom
	*/ 

	switch (index) {

	case 0:
		size.left = pt.x;
		size.top = pt.y;
		break;

	case 1:
		size.right = pt.x;
		size.top = pt.y;
		break;

	case 2:
		size.left = pt.x;
		size.bottom = pt.y;
		break;

	case 3:
		size.right = pt.x;
		size.bottom = pt.y;
		break;
	}

	SortPosition();
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

// LT RB 크기순으로 조정
void Shape::SortPosition()
{
	CPoint pt1 = size.TopLeft();
	CPoint pt2 = size.BottomRight();

	if (pt1.x > pt2.x) {
		int temp = pt1.x;
		pt1.x = pt2.x;
		pt2.x = temp;
	}
	if (pt1.y > pt2.y) {
		int temp = pt1.y;
		pt1.y = pt2.y;
		pt2.y = temp;
	}

	size = CRect(pt1, pt2);
}
