#pragma once

class Shape {

public:
	// ������
	Shape(CPoint pt1, CPoint pt2, int type, int line_color, int line_opt, int thickness, int fill_color, int fill_opt);
	Shape(char* str);

private:
	CRect size;			// Shape�� ũ��

	int type;			// Ÿ�� (�簢, ��, �ﰢ, ����, ����, �Ȱ�)

	int line_color;		// �׵θ� ����
	int line_opt;		// �׵θ� ����
	int thickness;		// �׵θ� �β�

	int fill_color;		// ä��� ����
	int fill_opt;		// ä��� �ɼ�

public:
	// �ʵ尪 ��ȯ
	const CRect GetRect();
	const int GetType();
	const int GetLineColor();
	const int GetLineOpt();
	const int GetThickness();
	const int GetFillColor();
	const int GetFillOpt();

	// �ʵ尪 ����
	void SetLineColor(int color);
	void SetLineOpt(int line_opt);
	void SetThickness(int thickness);
	void SetFillColor(int color);
	void SetFillOpt(int fill_opt);

public:
	// ũ�� �缳��
	void SetSize(CPoint pt, int index);

	// ��ġ ����
	void Move(CPoint pt);

	// ������ ��ġ�� ���� �ȿ� �ִ��� Ȯ��
	bool IsClicked(CPoint pt);

	// LT RB ����
	void SortPosition();

	// ������ ����� ���ڿ�
	const char* ChageFileData();
};
