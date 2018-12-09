#pragma once

class Shape;

class Setting
{
public:
	// ������
	Setting();

private:				
	Shape **shape;				// �׸� ������

	int count;					// �׸� ���� ����

	int type;			// ������ Ÿ��

	int thickness;		// ������ �β� (1~)
	int color;			// ������ ���� (RGB(r,g,b) ����)
	int line_opt;		// �׵θ� �ɼ�
	int fill_opt;		// ä��� �ɼ�

	int select;			// ������ ���� (index)
	CRect* resizeRect;			// ũ�� ���� ��ư

	/* type
	 * 0  : �⺻ Ŀ��
	 * 1~ : �簢��, ��, �ﰢ��, ������, ������, �Ȱ���
	 * 10~: ���찳, ����, ä���
	 */

public:
	// �ʵ尪 ��ȯ
	const Shape GetShape(int index);
	const CRect GetResizeRect(int index);
	const int GetCount();
	const int GetType();
	const int GetColor();
	bool IsSelected();

	// �ʵ尪 ����
	void SetType(int type);
	void SetThickness(int thickness);
	void SetColor(int color);
	void SetLineOpt(int line_opt);
	void SetFillOpt(int fill_opt);
	

public:
	// ���� ����
	void SelectShape(CPoint pt, int color);

	// �巡�� ����
	void Drag(CPoint pt1, CPoint pt2);

	// ���� ��ĥ�ϱ�
	void FillShape();


private:
	// ũ�� ���� ��ư
	CRect* SetResizeRect(int index);

	// ���� �߰�
	void AddShape(CPoint pt1, CPoint pt2);

	// ���� ����
	void DeleteShape(int index);

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

