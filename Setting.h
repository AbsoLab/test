#pragma once

class Shape;

class Setting
{
public:
	// 생성자
	Setting();

private:				
	Shape **shape;		// 그린 도형들

	int count;			// 그린 도형 개수

	int selected_type;			// 선택한 타입 (커서, 사각형, 원 등등)
	int selected_thickness;		// 선택한 두께 (1~)
	int selected_color;			// 선택한 색깔 (RGB(r,g,b) 형태)

	int selected_shape;			// 선택한 도형 (index)
	CRect* resizeRect;			// 크기 조정 버튼

public:
	// 필드값 반환
	const Shape GetShape(int index);
	const CRect GetResizeRect(int index);
	const int GetCount();
	bool IsSelected();

	// 필드값 설정
	void SetSelectedType(int type);
	void SetSelectedThickness(int thickness);
	void SetSelectedColor(int color);
	
public:
	// 도형 선택
	void SelectShape(CPoint pt);

	// 드래그 동작
	void Drag(CPoint pt1, CPoint pt2);

private:
	// 크기 조절 버튼
	CRect* SetResizeRect(int index);

	// 도형 추가
	void AddShape(CPoint pt1, CPoint pt2);

	// 도형 움직이기
	void MoveShape(CPoint pt1, CPoint pt2, int index);

	// 도형 크기조절
	void ResizeShape(CPoint pt, int index);


private:
	// 도형 검색
	int SearchShape(CPoint pt);

	// 크기조절 버튼 검색
	int SearchResizing(CPoint pt);
};

