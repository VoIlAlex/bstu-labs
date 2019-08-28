// EnterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "menu_2.h"
#include "EnterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnterDlg dialog


CEnterDlg::CEnterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnterDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEnterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnterDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
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
	char szBuffer[100];
	GetDlgItemText(IDC_EDIT1, szBuffer, 100);
	
	m_sText = szBuffer;

	//CDialog::OnOK();
}


CString CEnterDlg::GetText() const
{
	return m_sText;
}