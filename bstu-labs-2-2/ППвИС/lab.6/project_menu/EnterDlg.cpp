// EnterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "project_menu.h"
#include "EnterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnterDlg dialog
CString g_sText;

CEnterDlg::CEnterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnterDlg)
	//}}AFX_DATA_INIT
}


void CEnterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnterDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnterDlg, CDialog)
	//{{AFX_MSG_MAP(CEnterDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnterDlg message handlers

void CEnterDlg::OnOK() 
{
	// TODO: Add extra validation here
	GetDlgItemText(IDC_EDIT1, g_sText);

	CDialog::OnOK();
}
