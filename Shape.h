#pragma once

class Shape {

public:
	// 생성자
	Shape(CPoint pt1, CPoint pt2, int type, int line_color, int line_opt, int thickness, int fill_color, int fill_opt);
	Shape(char* str);

private:
	CRect size;			// 도형의 크기
	CPoint *vertex;		// 도형의 꼭짓점 좌표
	int type;			// 타입 (사각, 원, 삼각, 오각, 육각, 팔각)

	int line_color;		// 테두리 색깔
	int line_opt;		// 테두리 종류
	int thickness;		// 테두리 두께

	int fill_color;		// 채우기 색깔
	int fill_opt;		// 채우기 옵션

public:
	// 필드값 반환
	const CRect GetSize();
	CPoint* GetVertex();
	const int GetType();
	const int GetLineColor();
	const int GetLineOpt();
	const int GetThickness();
	const int GetFillColor();
	const int GetFillOpt();

	// 필드값 설정
	void SetLineColor(int color);
	void SetLineOpt(int line_opt);
	void SetThickness(int thickness);
	void SetFillColor(int color);
	void SetFillOpt(int fill_opt);

public:
	// 크기 재설정
	void SetSize(CPoint pt, int index);

	// 위치 변경
	void Move(CPoint pt);

	// 선택한 위치가 도형 안에 있는지 확인
	bool IsClicked(CPoint pt);

	// LT RB 정렬
	void SortPosition();

	// 데이터 저장용 문자열
	const char* ChageFileData();

private:
	// 다각형의 꼭짓점의 좌표 설정
	void SetInitPoint();
};
