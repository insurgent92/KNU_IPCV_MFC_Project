
// 2016SummerMFCImgTool.h : 2016SummerMFCImgTool ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy2016SummerMFCImgToolApp:
// �� Ŭ������ ������ ���ؼ��� 2016SummerMFCImgTool.cpp�� �����Ͻʽÿ�.
//

class IppDib;

class CMy2016SummerMFCImgToolApp : public CWinAppEx
{
public:
	CMy2016SummerMFCImgToolApp();

public:
	IppDib* m_pNewDib;

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI *pCmdUI);
};

extern CMy2016SummerMFCImgToolApp theApp;

void AfxNewBitmap(IppDib& dib);
void AfxPrintInfo(CString message);
void AfxPrintInfo(LPCTSTR lpszFormat, ...);
