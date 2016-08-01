
// 2016SummerMFCImgToolView.h : CMy2016SummerMFCImgToolView Ŭ������ �������̽�
//

#pragma once


class CMy2016SummerMFCImgToolView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CMy2016SummerMFCImgToolView();
	DECLARE_DYNCREATE(CMy2016SummerMFCImgToolView)

// Ư���Դϴ�.
public:
	CMy2016SummerMFCImgToolDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void SetScrollSizeToFit();
	void ShowImageInfo(CPoint point);

protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy2016SummerMFCImgToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	int m_nZoom;
	afx_msg void OnViewZoom1();
	afx_msg void OnUpdateViewZoom1(CCmdUI *pCmdUI);
	afx_msg void OnViewZoom2();
	afx_msg void OnUpdateViewZoom2(CCmdUI *pCmdUI);
	afx_msg void OnViewZoom3();
	afx_msg void OnUpdateViewZoom3(CCmdUI *pCmdUI);
	afx_msg void OnViewZoom4();
	afx_msg void OnUpdateViewZoom4(CCmdUI *pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 2016SummerMFCImgToolView.cpp�� ����� ����
inline CMy2016SummerMFCImgToolDoc* CMy2016SummerMFCImgToolView::GetDocument() const
   { return reinterpret_cast<CMy2016SummerMFCImgToolDoc*>(m_pDocument); }
#endif

