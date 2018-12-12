#pragma once

class Shape;

class Setting
{
public:
	Setting();
	~Setting();

private:				
	Shape **shape;			// �׸� ������
	CRect* resizeRect;		// ũ�� ���� ��ư

	int count;				// �׸� ���� ����

	int type;				// ���õ� ����
	int color;				// ���õ� ���� (RGB(r,g,b) ����)
	int thickness;			// ���õ� �β� (1~)
	int line_opt;			// �׵θ� �ɼ�
	int fill_opt;			// ä��� �ɼ�

	int select;				// ������ ���� (index)

	/* type
	 * 0  : �⺻ Ŀ��
	 * 1~ : �ﰢ��, �簢��, ������, ������, �Ȱ���, ��
	 * 10~: ���찳, ����, ä���
	 */

public:
	// �ʵ尪 ��ȯ
	const Shape GetShape(int index);
	const CRect GetResizeRect(int index);
	const int GetCount();
	const int GetType();
	const int GetColor();
	const int GetThick();
	const int GetLineOpt();
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

	// ���� ����
	bool FileOpen(CString path);

	// ���� ����
	bool FileSave(CString path);

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

	// ���� ��ĥ
	void FillShape(int index);


private:
	// ���� �˻�
	int SearchShape(CPoint pt);

	// ũ������ ��ư �˻�
	int SearchResizing(CPoint pt);
};

