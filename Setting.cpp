#include "stdafx.h"
#include "Setting.h"
#include "Shape.h"

// 생성자
Setting::Setting() {

	shape = new Shape*[50];

	count = 0;

	selected_type = 0;
	selected_color = RGB(0, 0, 0);
	selected_thickness = 1;
	selected_shape = -1;
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

bool Setting::IsSelected()
{
	if (selected_shape == -1) {

		return false;
	}
	
	return true;
}

// 필드값 설정
void Setting::SetSelectedType(int type)
{
	/* 0 : CURSOR
	 * 1 : Rectangle
	 * 2 : Circle
	 * 3 : 
	 * 4 :
	 */

	if (0 <= type && type <= 5) {

		selected_type = type;
	}
}

void Setting::SetSelectedThickness(int thickness)
{
	if (1 <= thickness && thickness <= 5) {

		selected_thickness = thickness;
	}
}

void Setting::SetSelectedColor(int color)
{
	if (RGB(0, 0, 0) <= color && color <= RGB(255, 255, 255)) {

		selected_color = color;
	}
}



// 도형 선택
void Setting::SelectShape(CPoint pt)
{
	selected_shape = SearchShape(pt);

	resizeRect = SetResizeRect(selected_shape);
}

// 드래그 동작
void Setting::Drag(CPoint pt1, CPoint pt2)
{
	if (selected_type == 0) {

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

	}
	else {

		AddShape(pt1, pt2);
	}
}

// 도형 색칠하기
void Setting::FillShape()
{
	if (selected_shape == -1) {

		return;
	}

	shape[selected_shape]->SetFillColor(selected_color);
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

	shape[count++] = new Shape(pt1, pt2, selected_type, selected_thickness, selected_color, -1);
}

// 도형 움직이기
void Setting::MoveShape(CPoint pt1, CPoint pt2, int index) {

	shape[index]->Move(pt2 - pt1);
}

// 도형 크기 조절
void Setting::ResizeShape(CPoint pt, int index)
{
	shape[selected_shape]->SetSize(pt, index);
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
	if (selected_shape == -1) {

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

