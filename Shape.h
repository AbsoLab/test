#pragma once

class Shape {

public:
	// 생성자
	Shape(CPoint pt1, CPoint pt2, int type, int thickness, int line_color, int fill_color);

private:
	CRect size;			// Shape의 크기

	int type;
	int option;

	int fill_color;		// 채우기 색깔
	int line_color;		// 테두리 색깔
	int thickness;		// 테두리 두께


public:
	// 필드값 반환
	const CRect GetRect();
	const int GetThickness();
	const int GetFillColor();
	const int GetLineColor();

	// 필드값 설정
	void SetThickness(int thickness);
	void SetFillColor(int color);
	void SetLineColor(int color);

public:
	// 크기 재설정
	void SetSize(CPoint pt, int index);

	// 위치 변경
	void Move(CPoint pt);

	// 선택한 위치가 도형 안에 있는지 확인
	bool IsClicked(CPoint pt);

	// LT RB 정렬
	void SortPosition();
};

