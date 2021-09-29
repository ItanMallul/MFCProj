
// MFCProjectShapesDlg.h : header file
//

#pragma once
#include "Figure.h"


// CMFCProjectShapesDlg dialog
class CMFCProjectShapesDlg : public CDialogEx
{
// Construction
public:
	CMFCProjectShapesDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECTSHAPES_DIALOG };
#endif
	
	int* typeArr = new int[4];
	CTypedPtrArray< CObArray, Figure*> figures;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedRectangle();
	afx_msg void OnBnClickedEllipse();
	afx_msg void OnBnClickedTriangle();
	afx_msg void OnBnClickedStarOfDavid();
	afx_msg void OnBnClickedStart();
};
