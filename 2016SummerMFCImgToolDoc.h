
// 2016SummerMFCImgToolDoc.h : CMy2016SummerMFCImgToolDoc Ŭ������ �������̽�
//

#include "./IppImage/IppDib.h"
#pragma once


class CMy2016SummerMFCImgToolDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMy2016SummerMFCImgToolDoc();
	DECLARE_DYNCREATE(CMy2016SummerMFCImgToolDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMy2016SummerMFCImgToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// ��Ʈ�� ��ü
	IppDib m_Dib;
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	afx_msg void OnWindowDuplicate();
	afx_msg void OnEditCopy();
	afx_msg void OnImageInverse();
	afx_msg void OnBrighrnessContrast();
	afx_msg void OnGammaCorrection();
};
