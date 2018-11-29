#pragma once

class Shape {

public:
	// ������
	Shape(CPoint pt1, CPoint pt2, int type, int thickness, int line_color, int fill_color);

private:
	CRect size;			// Shape�� ũ��

	int type;
	int option;

	int fill_color;		// ä��� ����
	int line_color;		// �׵θ� ����
	int thickness;		// �׵θ� �β�


public:
	// �ʵ尪 ��ȯ
	const CRect GetRect();
	const int GetType();
	const int GetThickness();
	const int GetFillColor();
	const int GetLineColor();

	// �ʵ尪 ����
	void SetThickness(int thickness);
	void SetFillColor(int color);
	void SetLineColor(int color);

public:
	// ũ�� �缳��
	void SetSize(CPoint pt, int index);

	// ��ġ ����
	void Move(CPoint pt);

	// ������ ��ġ�� ���� �ȿ� �ִ��� Ȯ��
	bool IsClicked(CPoint pt);

	// LT RB ����
	void SortPosition();
};

