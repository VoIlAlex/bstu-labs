#if !defined(AFX_VIEWDLG_H__A25A5B3B_E6B2_45EA_919E_F7A08ADBC5CE__INCLUDED_)
#define AFX_VIEWDLG_H__A25A5B3B_E6B2_45EA_919E_F7A08ADBC5CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CViewDlg dialog

class CViewDlg : public CDialog
{
// Construction
public:
	CViewDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CViewDlg)
	enum { IDD = IDD_VIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CViewDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWDLG_H__A25A5B3B_E6B2_45EA_919E_F7A08ADBC5CE__INCLUDED_)
