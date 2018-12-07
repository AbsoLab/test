#pragma once

class Shape;

class Setting
{
public:
	// ������
	Setting();

private:				
	Shape **shape;		// �׸� ������

	int count;			// �׸� ���� ����

	int selected_type;			// ������ Ÿ�� (Ŀ��, �簢��, �� ���)
	int selected_thickness;		// ������ �β� (1~)
	int selected_color;			// ������ ���� (RGB(r,g,b) ����)

	int selected_shape;			// ������ ���� (index)
	CRect* resizeRect;			// ũ�� ���� ��ư


public:
	// �ʵ尪 ��ȯ
	const Shape GetShape(int index);
	const CRect GetResizeRect(int index);
	const int GetCount();
	const int GetType();
	bool IsSelected();

	// �ʵ尪 ����
	void SetSelectedType(int type);
	void SetSelectedThickness(int thickness);
	void SetSelectedColor(int color);
	

public:
	// ���� ����
	void SelectShape(CPoint pt);

	// �巡�� ����
	void Drag(CPoint pt1, CPoint pt2);

	// ���� ��ĥ�ϱ�
	void FillShape();


private:
	// ũ�� ���� ��ư
	CRect* SetResizeRect(int index);

	// ���� �߰�
	void AddShape(CPoint pt1, CPoint pt2);

	// ���� �����̱�
	void MoveShape(CPoint pt1, CPoint pt2, int index);

	// ���� ũ������
	void ResizeShape(CPoint pt, int index);


private:
	// ���� �˻�
	int SearchShape(CPoint pt);

	// ũ������ ��ư �˻�
	int SearchResizing(CPoint pt);
};

