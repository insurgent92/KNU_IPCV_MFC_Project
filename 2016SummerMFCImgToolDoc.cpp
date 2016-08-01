
// 2016SummerMFCImgToolDoc.cpp : CMy2016SummerMFCImgToolDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2016SummerMFCImgTool.h"
#endif

#include "2016SummerMFCImgToolDoc.h"
#include "FileNewDlg.h"

#include <propkey.h>

#include "IppImage/IppConvert.h"
#include "IppImage/IppImage.h"
#include "IppImage/IppEnhance.h"
#include "BrightnessContrastDlg.h"
#include "GammaCorrectionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy2016SummerMFCImgToolDoc

IMPLEMENT_DYNCREATE(CMy2016SummerMFCImgToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy2016SummerMFCImgToolDoc, CDocument)
	ON_COMMAND(ID_WINDOW_DUPLICATE, &CMy2016SummerMFCImgToolDoc::OnWindowDuplicate)
	ON_COMMAND(ID_EDIT_COPY, &CMy2016SummerMFCImgToolDoc::OnEditCopy)
	ON_COMMAND(ID_IMAGE_INVERSE, &CMy2016SummerMFCImgToolDoc::OnImageInverse)
	ON_COMMAND(ID_BRIGHRNESS_CONTRAST, &CMy2016SummerMFCImgToolDoc::OnBrighrnessContrast)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CMy2016SummerMFCImgToolDoc::OnGammaCorrection)
END_MESSAGE_MAP()


// CMy2016SummerMFCImgToolDoc ����/�Ҹ�
#define CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)\
	IppByteImage img; \
	IppDibToImage(m_Dib, img);

#define CONVERT_IMAGE_TO_DIB \
	IppDib dib; \
	IppImageToDib(img, dib);

CMy2016SummerMFCImgToolDoc::CMy2016SummerMFCImgToolDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMy2016SummerMFCImgToolDoc::~CMy2016SummerMFCImgToolDoc()
{
}

BOOL CMy2016SummerMFCImgToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	BOOL ret = TRUE;

	if (theApp.m_pNewDib == nullptr){
	CFileNewDlg dlg;

	if (dlg.DoModal() == IDOK)	 {
		if (dlg.m_nType == 0)
			ret = m_Dib.CreateGrayBitmap(dlg.m_nWidth, dlg.m_nHeight);
		else
			ret = m_Dib.CreateRgbBitmap(dlg.m_nWidth, dlg.m_nHeight);
	}
	else
		ret = FALSE;
	}
	else{
		m_Dib = *(theApp.m_pNewDib);
		theApp.m_pNewDib = NULL;
	}

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return ret;
}




// CMy2016SummerMFCImgToolDoc serialization

void CMy2016SummerMFCImgToolDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMy2016SummerMFCImgToolDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CMy2016SummerMFCImgToolDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy2016SummerMFCImgToolDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy2016SummerMFCImgToolDoc ����

#ifdef _DEBUG
void CMy2016SummerMFCImgToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy2016SummerMFCImgToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy2016SummerMFCImgToolDoc ���


BOOL CMy2016SummerMFCImgToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return m_Dib.Save(CT2A(lpszPathName));
}


BOOL CMy2016SummerMFCImgToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	BOOL res = m_Dib.Load(CT2A(lpszPathName));

	if (res)
		AfxPrintInfo(_T("[���� ����] ���� ���: %s, ����ũ��: %d �ȼ�, ����ũ��: %d�ȼ�, ����� : %d"), lpszPathName, m_Dib.GetWidth(), m_Dib.GetHeight(), 0x01 << m_Dib.GetBitCount());

	return res;
}


void CMy2016SummerMFCImgToolDoc::OnWindowDuplicate()
{
	AfxNewBitmap(m_Dib);
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMy2016SummerMFCImgToolDoc::OnEditCopy()
{
	if (m_Dib.IsValid())
		m_Dib.CopyToClipboard();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMy2016SummerMFCImgToolDoc::OnImageInverse()
{
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
	IppInverse(img);
	CONVERT_IMAGE_TO_DIB(img, dib);

	AfxPrintInfo(_T("[����] �Է� ���� : %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CMy2016SummerMFCImgToolDoc::OnBrighrnessContrast()
{
	CBrightnessContrastDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		IppBrightness(img, dlg.m_nBrightness);
		IppContrast(img, dlg.m_nContrast);
		CONVERT_IMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[���/��Ϻ� ����] �Է� ���� : %s, ��� : %d, ��Ϻ� : %d%%"), GetTitle(), dlg.m_nBrightness, dlg.m_nContrast);
		AfxNewBitmap(dib);

	}
}


void CMy2016SummerMFCImgToolDoc::OnGammaCorrection()
{
	CGammaCorrectionDlg dlg;

	if (dlg.DoModal() == IDOK){
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		IppGammaCorrection(img, dlg.m_fGamma);
		CONVERT_IMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[���� ����] �Է� ����: %s, ���� : %4.2f"), GetTitle(), dlg.m_fGamma);
		AfxNewBitmap(dib);
	}
}
