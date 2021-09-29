
// MFCProjectShapesDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCProjectShapes.h"
#include "MFCProjectShapesDlg.h"
#include "afxdialogex.h"
#include "Triangle.h"
#include "MyEllipse.h"
#include "MagenDavid.h"
#include "Rectangle.h"
#include "Level.h"
#include "Game Looper.h"
#include <time.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCProjectShapesDlg dialog



CMFCProjectShapesDlg::CMFCProjectShapesDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECTSHAPES_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCProjectShapesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCProjectShapesDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RECTANGLE, &CMFCProjectShapesDlg::OnClickedRectangle)
	ON_BN_CLICKED(IDC_ELLIPSE, &CMFCProjectShapesDlg::OnBnClickedEllipse)
	ON_BN_CLICKED(IDC_TRIANGLE, &CMFCProjectShapesDlg::OnBnClickedTriangle)
	ON_BN_CLICKED(IDC_STAR_OF_DAVID, &CMFCProjectShapesDlg::OnBnClickedStarOfDavid)
	ON_BN_CLICKED(IDC_START, &CMFCProjectShapesDlg::OnBnClickedStart)
END_MESSAGE_MAP()


// CMFCProjectShapesDlg message handlers

BOOL CMFCProjectShapesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCProjectShapesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		Level Level;
		dc.SelectStockObject(DC_BRUSH);
		for (int i = 0; i < figures.GetSize(); i++) {
			figures[i]->draw(&dc);
		}
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCProjectShapesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCProjectShapesDlg::OnClickedRectangle()
{
	// TODO: Add your control notification handler code here
	typeArr[0] = 1;
}


void CMFCProjectShapesDlg::OnBnClickedEllipse()
{
	// TODO: Add your control notification handler code here
	typeArr[1] = 1;
}


void CMFCProjectShapesDlg::OnBnClickedTriangle()
{
	// TODO: Add your control notification handler code here
	typeArr[2] = 1;
}


void CMFCProjectShapesDlg::OnBnClickedStarOfDavid()
{
	// TODO: Add your control notification handler code here
	typeArr[3] = 1;
}


void CMFCProjectShapesDlg::OnBnClickedStart()
{
	// TODO: Add your control notification handler code here
	//Start of the game
	srand(time(NULL));
	for (int j = 0; j < 2; j++) { // 2 sets of figures min - 2, max - 8;
		for (int i = 0; i <= 3; i++) //creating array of relevant figures
		{

			switch (i) {
			case 0:
				if (typeArr[i]) {
					figures.Add(new MyRectangle(CPoint(rand() % 200, rand() % 400), 20, RGB(rand() % 255, rand() % 255, rand() % 255), 0, 0.5));
				}
			case 1:
				if (typeArr[i]) {
					figures.Add(new MyEllipse(CPoint(rand() % 200, rand() % 400), 20, RGB(rand() % 255, rand() % 255, rand() % 255), 0, 0.5));
				}
			case 2:
				if (typeArr[i]) {
					figures.Add(new Triangle(CPoint(rand() % 200, rand() % 400), 20, RGB(rand() % 255, rand() % 255, rand() % 255), 0));
				}
			case 3:
				if (typeArr[i]) {
					figures.Add(new MagenDavid(CPoint(rand() % 200, rand() % 400), 20, RGB(rand() % 255, rand() % 255, rand() % 255), 0));
				}
			}
		}
	}
	GameLooper GameLooper;
	while (true) {
		

	}


}
