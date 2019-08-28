#include <afxwin.h>
#include <vector>
#include <utility>

class CLine
{
	std::pair<CPoint, CPoint> pts;
public:
	CLine(CPoint ptFirst, CPoint ptSecond)
	{
		pts.first = ptFirst;
		pts.second = ptSecond;
	}
	void Draw(CDC &dc)
	{
		dc.MoveTo(pts.first.x, pts.first.y);
		dc.LineTo(pts.second.x, pts.second.y);
	}
};

class CMainWindow : public CFrameWnd
{
	std::vector<CLine> vecLines;
	CPoint ptLast;
public:
	CMainWindow();

	// Painting
	afx_msg void OnLButtonDown(UINT uFlags, CPoint pt);
	// Erasing
	afx_msg void OnRButtonDown(UINT uFlags, CPoint pt);
	afx_msg void OnPaint();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

afx_msg void CMainWindow::OnLButtonDown(UINT uFlags, CPoint pt)
{
	if(ptLast != CPoint())
	{
		CLine line(ptLast, pt);
		vecLines.push_back(line);
	}
	ptLast = pt;
	Invalidate();
}

afx_msg void CMainWindow::OnRButtonDown(UINT uFlags, CPoint pt)
{
	vecLines.clear();
	ptLast = CPoint;
	Invalidate();
}

afx_msg void CMainWindow::OnPaint()
{
	CPaintDC dc(this);
	for(int i = 0; i < vecLines.size(); i++)
	{
		vecLines[i].Draw(dc);
	}
}


CMainWindow::CMainWindow()
{
	Create(NULL, _T("Hello world"));
}

class CMyApp : public CWinApp
{

public:
	BOOL InitInstance();
};

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMainWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}



CMyApp app;