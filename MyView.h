
// MyView.h: CMyView 클래스의 인터페이스
//

#pragma once
class Setting;
class CMenuBar;
class DrawView;
class CMyDoc;

class CMyView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMyView() noexcept;
	DECLARE_DYNCREATE(CMyView)

// 특성입니다.
public:
	CMyDoc *GetDocument() const;
	CString strClass;

	Setting *set;
	DrawView *drawView;
	CMenuBar *menuBar;

// 작업입니다.
public:


// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:


// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // MyView.cpp의 디버그 버전
inline CMyDoc* CMyView::GetDocument() const
   { return reinterpret_cast<CMyDoc*>(m_pDocument); }
#endif

