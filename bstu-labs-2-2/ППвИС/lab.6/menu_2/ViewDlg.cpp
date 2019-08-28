// ViewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "menu_2.h"
#include "ViewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewDlg dialog


CViewDlg::CViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CViewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CViewDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CViewDlg, CDialog)
	//{{AFX_MSG_MAP(CViewDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewDlg message handlers
