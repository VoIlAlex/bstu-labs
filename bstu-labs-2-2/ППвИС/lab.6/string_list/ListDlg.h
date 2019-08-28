#if !defined(AFX_LISTDLG_H__8E3C363A_10B8_41EC_8B88_A860AECEBA1E__INCLUDED_)
#define AFX_LISTDLG_H__8E3C363A_10B8_41EC_8B88_A860AECEBA1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListDlg dialog

class CListDlg : public CDialog
{
// Construction
public:
	CListDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CListDlg)
	enum { IDD = IDD_DIALOG1 };
	CListBox	m_wndList;
	CEdit	m_wndEdit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CListDlg)
	afx_msg void OnAdd();
	afx_msg void OnEdit();
	afx_msg void OnRemove();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTDLG_H__8E3C363A_10B8_41EC_8B88_A860AECEBA1E__INCLUDED_)
