#include <stdio.h>
#include "stdafx.h"
#include "Setting.h"
#include "Shape.h"

// ������
Setting::Setting() {

	shape = new Shape*[50];

	count = 0;

	type = 0;
	thickness = 1;
	color = RGB(0, 0, 0);
	line_opt = 0;
	fill_opt = 0;

	select = -1;
	resizeRect = NULL;
}

Setting::~Setting()
{
	if (shape != NULL) { delete(shape); }
	if (resizeRect != NULL) { delete(resizeRect); }
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

const int Setting::GetType() { 
	
	return type;

}

const int Setting::GetColor()
{
	return color;
}

const int Setting::GetThick()
{
	return thickness;
}

const int Setting::GetLineOpt()
{
	return line_opt;
}

bool Setting::IsSelected()
{
	if (select == -1) {

		return false;
	}
	
	return true;
}

// �ʵ尪 ����
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



// ���� ����
void Setting::SelectShape(CPoint pt, int color)
{
	select = SearchShape(pt);

	if (resizeRect != NULL) { delete(resizeRect); }
	resizeRect = SetResizeRect(select);

	switch (type) {

	case 10:
		//����� ����
		DeleteShape(select);
		select = -1;
		resizeRect = NULL;
		break;

	case 11:
		// ����
		this->color = color;
		break;

	case 12:
		// ä���
		FillShape(select);
		break;
	}
}

// �巡�� ����
void Setting::Drag(CPoint pt1, CPoint pt2)
{
	if (type == 0) {

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

	} else if (0 < type && type < 10) {

		AddShape(pt1, pt2);
	
	} else if (10 < type && type < 100) {
		

	}
}

// ���� ����
bool Setting::FileOpen(CString path)
{
	char buf[1024];
	char change_path[1024];

	WideCharToMultiByte(CP_ACP, 0, path, -1, change_path, 1024, NULL, NULL);

	FILE *fp;
	
	if ((fp = fopen(change_path, "r")) == NULL) {

		return false;
	}

	count = 0;
	select = -1;

	while (fgets(buf, 1024, fp) != NULL) {

		shape[count++] = new Shape(buf);
	}

	fclose(fp);

	return true;
}

// ���� ����
bool Setting::FileSave(CString path)
{
	char change_path[1024];

	WideCharToMultiByte(CP_ACP, 0, path, -1, change_path, 1024, NULL, NULL);

	FILE *fp;
	
	if ((fp = fopen(change_path, "w")) == NULL) {

		return false;
	}

	for (int i = 0; i < count; i++) {

		fprintf(fp, "%s", shape[i]->ChageFileData());

		if (i + 1 != count) {
			fputs("\n", fp);
		}
	}

	fclose(fp);

	return true;
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

	CRect rt = shape[index]->GetSize();

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

	shape[count++] = new Shape(pt1, pt2, type, color, line_opt, thickness, -1, fill_opt);
}

// ���� �����
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

// ���� �����̱�
void Setting::MoveShape(CPoint pt1, CPoint pt2, int index) {

	shape[index]->Move(pt2 - pt1);
}

// ���� ũ�� ����
void Setting::ResizeShape(CPoint pt, int index)
{
	shape[select]->SetSize(pt, index);
}

// ���� ��ĥ�ϱ�
void Setting::FillShape(int index)
{
	if (index == -1) {

		return;
	}

	shape[index]->SetFillColor(color);
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

