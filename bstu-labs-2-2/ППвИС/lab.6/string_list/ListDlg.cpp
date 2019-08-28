// ListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "string_list.h"
#include "ListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListDlg dialog


CListDlg::CListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListDlg)
	//}}AFX_DATA_INIT
}


void CListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListDlg)
	DDX_Control(pDX, IDC_LIST1, m_wndList);
	DDX_Control(pDX, IDC_EDIT1, m_wndEdit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CListDlg, CDialog)
	//{{AFX_MSG_MAP(CListDlg)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListDlg message handlers

void CListDlg::OnAdd() 
{
	char szBuffer[100];
	m_wndEdit.GetWindowText(szBuffer, 100);
	m_wndList.AddString(szBuffer);
}

void CListDlg::OnEdit() 
{
	int nSel =  m_wndList.GetCurSel();
	m_wndList.DeleteString(nSel);
	char szBuffer[100];
	m_wndEdit.GetWindowText(szBuffer, 100);
	m_wndList.InsertString(nSel, szBuffer);
}

void CListDlg::OnRemove() 
{
	int nSel = m_wndList.GetCurSel();
	m_wndList.DeleteString(nSel);
}
