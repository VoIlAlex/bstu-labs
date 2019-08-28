#if !defined(AFX_VIEWDLG_H__80D96AFA_F590_4292_8692_E6FA335C2C8F__INCLUDED_)
#define AFX_VIEWDLG_H__80D96AFA_F590_4292_8692_E6FA335C2C8F__INCLUDED_

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
	CStatic m_wndStatic;
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

#endif // !defined(AFX_VIEWDLG_H__80D96AFA_F590_4292_8692_E6FA335C2C8F__INCLUDED_)
