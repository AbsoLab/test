#include "stdafx.h"
#include "Shape.h"


// 생성자
Shape::Shape(CPoint pt1, CPoint pt2, int type, int line_color, int line_opt, int thickness, int fill_color, int fill_opt) {
	
	size = CRect(pt1, pt2);
	SortPosition();

	this->type = type;
	this->line_color = line_color;
	this->line_opt = line_opt;
	this->thickness = thickness;
	this->fill_color = fill_color;
	this->fill_opt = fill_color;
}

Shape::Shape(char *str)
{
	char* token[10];

	token[0] = strtok(str, ":");
	for (int i = 1; i < 10; i++) {

		token[i] = strtok(NULL, ":");
	}

	size = CRect(atoi(token[0]), atoi(token[1]), atoi(token[2]), atoi(token[3]));
	SortPosition();

	type = atoi(token[4]);
	line_color = atoi(token[5]);
	line_opt = atoi(token[6]);
	thickness = atoi(token[7]);
	fill_color = atoi(token[8]);
	fill_opt = atoi(token[9]);
}

// 필드값 반환
const CRect Shape::GetRect() { 
	
	return size;
}

const int Shape::GetType()
{
	return type;
}

const int Shape::GetLineColor() {

	return line_color;
}

const int Shape::GetLineOpt()
{
	return line_opt;
}

const int Shape::GetThickness() {

	return thickness;
}

const int Shape::GetFillColor() {

	return fill_color;
}

const int Shape::GetFillOpt()
{
	return fill_opt;
}

// 필드값 설정
void Shape::SetLineColor(int line_color) {

	this->line_color = line_color;
}

void Shape::SetLineOpt(int line_opt)
{
	this->line_opt = line_opt;
}

void Shape::SetThickness(int thickness) {

	this->thickness = thickness;
}

void Shape::SetFillColor(int fill_color) {

	this->fill_color = fill_color;
}

void Shape::SetFillOpt(int fill_opt)
{
	this->fill_opt = fill_opt;
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

const char* Shape::ChageFileData()
{
	char str[1024];
	sprintf(str, "%d:%d:%d:%d:%d:%d:%d:%d:%d:%d",
		size.left, size.top, size.right, size.bottom,
		type, line_color, line_opt, thickness, fill_color, fill_opt);

	return str;
}
