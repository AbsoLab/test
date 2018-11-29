#include "stdafx.h"
#include "Setting.h"
#include "Shape.h"

// ������
Setting::Setting() {

	shape = new Shape*[50];

	count = 0;

	selected_type = 0;
	selected_color = RGB(0, 0, 0);
	selected_thickness = 1;
	selected_shape = -1;
}


// �ʵ尪 ��ȯ
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

// �ʵ尪 ����
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



// ���� ����
void Setting::SelectShape(CPoint pt)
{
	selected_shape = SearchShape(pt);

	resizeRect = SetResizeRect(selected_shape);
}

// �巡�� ����
void Setting::Drag(CPoint pt1, CPoint pt2)
{
	if (selected_type == 0) {

		int index;
		
		// ũ�� ���� ��ư�� ��� (ũ������)
		index = SearchResizing(pt1);

		if (index != -1) {
			
			ResizeShape(pt2, index);

			return;
		}

		
		// ������ ��� (�̵�)
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

// ���� ��ĥ�ϱ�
void Setting::FillShape()
{
	if (selected_shape == -1) {

		return;
	}

	shape[selected_shape]->SetFillColor(selected_color);
}


// ũ������ ��ư
CRect* Setting::SetResizeRect(int index)
{
	// ���õȰ� ���� ���
	if (index == -1) {

		return NULL;
	}


	// �׵θ� 
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

// ���� �߰�
void Setting::AddShape(CPoint pt1, CPoint pt2) {

	shape[count++] = new Shape(pt1, pt2, selected_type, selected_thickness, selected_color, -1);
}

// ���� �����̱�
void Setting::MoveShape(CPoint pt1, CPoint pt2, int index) {

	shape[index]->Move(pt2 - pt1);
}

// ���� ũ�� ����
void Setting::ResizeShape(CPoint pt, int index)
{
	shape[selected_shape]->SetSize(pt, index);
}


// ���� �˻�
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

// ũ�� ������ư �˻�
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

