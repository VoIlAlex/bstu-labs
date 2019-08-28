#include <afxwin.h>

class CMyWnd : public CFrameWnd
{
public:
	CMyWnd();

	DECLARE_MESSAGE_MAP();
};

class CMyApp : public CWinApp
{
public:
	BOOL InitInstance();
};

CMyWnd::CMyWnd()
{
	Create(NULL, _T("Title"));
}

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMyWnd;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CMyApp app;