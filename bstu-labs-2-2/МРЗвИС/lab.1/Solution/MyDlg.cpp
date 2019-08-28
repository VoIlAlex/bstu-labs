// MyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Solution.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog


/**My**/

int m_nCount1 = 0;
int m_nCount2 = 0;

UINT FirstThread(LPVOID pParam)
{
	volatile int nTmp;
	for(m_nCount1 = 0; m_nCount1 < CMyDlg::nMax1;
		::InterlockedIncrement((LPLONG)&m_nCount1))
	{
		for(nTmp = 0; nTmp <= 1000; nTmp++) {}	
	}
	m_nCount1 = 0;
	return 0;
}
UINT SecondThread(LPVOID pParam)
{
	volatile int nTmp;
	for(m_nCount2 = 0; m_nCount1 < CMyDlg::nMax2;
		::InterlockedIncrement((LPLONG)&m_nCount2))
	{
		for(nTmp = 0; nTmp <= 1000; nTmp++) {}	
	}
	m_nCount2 = 0;
	return 0;
}

/******/


CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

//DEL void CMyDlg::OnOK() 
//DEL {
//DEL 	// TODO: Add extra validation here
//DEL 	
//DEL 	CDialog::OnOK();
//DEL }

void CMyDlg::OnOK() 
{
	m_nTimer = SetTimer(1, 100, NULL);
	ASSERT (m_nTimer!=0);
	GetDlgItem(IDOK)->EnableWindow(FALSE);
	AfxBeginThread(FirstThread, GetSafeHwnd(), THREAD_PRIORITY_NORMAL);
	AfxBeginThread(SecondThread, GetSafeHwnd(), THREAD_PRIORITY_NORMAL);
	//CDialog::OnOK();
}


void CMyDlg::OnStop() 
{
	if(m_nCount1 == 0 && m_nCount2 == 0)
	{
		CDialog::OnCancel();
	}
	else 
	{
		m_nCount1 = nMax1;
		m_nCount2 = nMax2;
		GetDlgItem(IDOK)->EnableWindow(TRUE);
	}
}

void CMyDlg::OnTimer(UINT nIDEvent) 
{
	CProgressCtrl* pBar1 = (CProgressCtrl*) GetDlgItem(IDC_PROGRESS1);
	CProgressCtrl* pBar2 = (CProgressCtrl*) GetDlgItem(IDC_PROGRESS2);
	pBar1->SetPos(m_nCount1*100/nMax1);
	pBar2->SetPos(m_nCount2*100/nMax2);
	if(m_nCount1 == 0 && m_nCount2 == 0)
	{
		GetDlgItem(IDOK)->EnableWindow(TRUE);
	}
	CDialog::OnTimer(nIDEvent);
}
