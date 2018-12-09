#include "stdafx.h"
#include "Setting.h"
#include "Shape.h"

// 생성자
Setting::Setting() {

	shape = new Shape*[50];

	count = 0;

	type = 0;
	color = RGB(0, 0, 0);
	thickness = 1;
	select = -1;
}


// 필드값 반환
const Shape Setting::GetShape(int index)
{
	/*
	if (index >= count) {
		// index out of range
		return;
	}

	*/
	
	return *shape[index];
}

const CRect Setting::GetResizeRect(int index)
{
	if (index >= 4) {

		return NULL;
	}
	return *resizeRect[index];
}

const int Setting::GetCount()
{
	return count;
}

const int Setting::GetType() { 
	
	return type;

}

const int Setting::GetColor()
{
	return color;
}

bool Setting::IsSelected()
{
	if (select == -1) {

		return false;
	}
	
	return true;
}

// 필드값 설정
void Setting::SetType(int type) {

	this->type = type;
}

void Setting::SetThickness(int thickness)
{
	this->thickness = thickness;

	if (select != -1) {

		shape[select]->SetThickness(thickness);
	}
}

void Setting::SetColor(int color)
{
	if (RGB(0, 0, 0) <= color && color <= RGB(255, 255, 255)) {

		this->color = color;
	}

	if (select != -1) {

		shape[select]->SetLineColor(color);
	}
}

void Setting::SetLineOpt(int line_opt)
{
	this->line_opt = line_opt;

	if (select != -1) {

		shape[select]->SetLineOpt(line_opt);
	}
}

void Setting::SetFillOpt(int fill_opt)
{
	this->fill_opt = fill_opt;

	if (select != -1) {

		shape[select]->SetFillOpt(fill_opt);
	}
}



// 도형 선택
void Setting::SelectShape(CPoint pt, int color)
{
	select = SearchShape(pt);

	resizeRect = SetResizeRect(select);

	switch (type) {

	case 10:
		//지우기 동작
		DeleteShape(select);
		select = -1;
		resizeRect = NULL;
		break;

	case 11:
		// 피펫
		this->color = color;
		break;

	case 12:
		// 채우기
		FillShape();
		break;
	}
}

// 드래그 동작
void Setting::Drag(CPoint pt1, CPoint pt2)
{
	if (type == 0) {

		int index;
		
		// 크기 조절 버튼일 경우 (크기조절)
		index = SearchResizing(pt1);

		if (index != -1) {
			
			ResizeShape(pt2, index);

			return;
		}

		
		// 도형일 경우 (이동)
		index = SearchShape(pt1);

		if (index != -1) {
			
			MoveShape(pt1, pt2, index);

			return;
		}

	} else if (0 < type && type < 10) {

		AddShape(pt1, pt2);
	
	} else if (10 < type && type < 100) {
		

	}
}

// 도형 색칠하기
void Setting::FillShape()
{
	if (select == -1) {

		return;
	}

	shape[select]->SetFillColor(color);
}


// 크기조절 버튼
CRect* Setting::SetResizeRect(int index)
{
	// 선택된게 없을 경우
	if (index == -1) {

		return NULL;
	}


	// 테두리 
	CPoint pt[4];

	CRect rt = shape[index]->GetRect();

	pt[0] = rt.TopLeft();
	pt[1] = CPoint(rt.right, rt.top);
	pt[2] = CPoint(rt.left, rt.bottom);
	pt[3] = rt.BottomRight();

	CRect *temp = new CRect[4];

	for (int i = 0; i < 4; i++) {
		temp[i].left = pt[i].x - 4;
		temp[i].right = pt[i].x + 4;
		temp[i].top = pt[i].y - 4;
		temp[i].bottom = pt[i].y + 4;
	}

	return temp;
}

// 도형 추가
void Setting::AddShape(CPoint pt1, CPoint pt2) {

	shape[count++] = new Shape(pt1, pt2, type, color, line_opt, thickness, -1, fill_opt);
}

// 도형 지우기
void Setting::DeleteShape(int index) {

	if (index < 0 || index >= count) {

		return;
	}

	delete(shape[index]);

	for (int i = index; i < count; i++) {

		shape[i] = shape[i + 1];
	}

	shape[count--] = NULL;
}

// 도형 움직이기
void Setting::MoveShape(CPoint pt1, CPoint pt2, int index) {

	shape[index]->Move(pt2 - pt1);
}

// 도형 크기 조절
void Setting::ResizeShape(CPoint pt, int index)
{
	shape[select]->SetSize(pt, index);
}


// 도형 검색
int Setting::SearchShape(CPoint pt)
{
	int index = -1;

	for (int i = 0; i < count; i++) {
		if (shape[i]->IsClicked(pt)) {
			index = i;
		}
	}

	return index;
}

// 크기 조절버튼 검색
int Setting::SearchResizing(CPoint pt)
{
	if (select == -1) {

		return -1;
	}

	for (int i = 0; i < 4; i++) {
		
		if (resizeRect[i].left <= pt.x && pt.x <= resizeRect[i].right) {
			
			if (resizeRect[i].top <= pt.y && pt.y <= resizeRect[i].bottom) {
				
				return i;
			}
		}
	}

	return -1;
}

