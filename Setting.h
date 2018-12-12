#pragma once

class Shape;

class Setting
{
public:
	Setting();
	~Setting();

private:				
	Shape **shape;			// 그린 도형들
	CRect* resizeRect;		// 크기 조정 버튼

	int count;				// 그린 도형 개수

	int type;				// 선택된 도구
	int thickness;			// 선택된 두께 (1~)
	int color;				// 선택된 색깔 (RGB(r,g,b) 형태)
	int line_opt;			// 테두리 옵션
	int fill_opt;			// 채우기 옵션

	int select;				// 선택한 도형 (index)

	/* type
	 * 0  : 기본 커서
	 * 1~ : 삼각형, 사각형, 오각형, 육각형, 팔각형, 원
	 * 10~: 지우개, 피펫, 채우기
	 */

public:
	// 필드값 반환
	const Shape GetShape(int index);
	const CRect GetResizeRect(int index);
	const int GetCount();
	const int GetType();
	const int GetColor();
	bool IsSelected();

	// 필드값 설정
	void SetType(int type);
	void SetThickness(int thickness);
	void SetColor(int color);
	void SetLineOpt(int line_opt);
	void SetFillOpt(int fill_opt);
	

public:
	// 도형 선택
	void SelectShape(CPoint pt, int color);

	// 드래그 동작
	void Drag(CPoint pt1, CPoint pt2);

	// 파일 열기
	bool FileOpen(CString path);

	// 파일 저장
	bool FileSave(CString path);

private:
	// 크기 조절 버튼
	CRect* SetResizeRect(int index);

	// 도형 추가
	void AddShape(CPoint pt1, CPoint pt2);

	// 도형 삭제
	void DeleteShape(int index);

	// 도형 움직이기
	void MoveShape(CPoint pt1, CPoint pt2, int index);

	// 도형 크기조절
	void ResizeShape(CPoint pt, int index);

	// 도형 색칠
	void FillShape(int index);


private:
	// 도형 검색
	int SearchShape(CPoint pt);

	// 크기조절 버튼 검색
	int SearchResizing(CPoint pt);
};

