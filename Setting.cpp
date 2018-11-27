#include "stdafx.h"
#include "Setting.h"
#include "Shape.h"

Setting::Setting() {

	shape = new Shape*[50];

	count = 0;

	selected_type = 0;
	selected_color = RGB(0, 0, 0);
	selected_thickness = 1;

}

// 도형 선택
void Setting::SelectShape(CPoint pt)
{
	selected_shape = SearchShape(pt);
}

// 도형 추가
void Setting::AddShape(CPoint pt1, CPoint pt2) {

	shape[count++] = new Shape(pt1, pt2, selected_type, selected_thickness, selected_color, -1);
}

// 도형 움직이기
void Setting::MoveShape(CPoint pt1, CPoint pt2)
{
	int index = SearchShape(pt1);

	// 선택한 위치에 아무것도 없을 경우
	if (index == -1) {

		return;
	}

	CPoint mv = pt2 - pt1;

	shape[index]->Move(mv);

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

