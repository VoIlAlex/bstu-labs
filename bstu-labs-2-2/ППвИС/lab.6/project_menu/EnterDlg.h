#if !defined(AFX_ENTERDLG_H__0C514854_AFF4_4E33_90EC_BCE154B8533C__INCLUDED_)
#define AFX_ENTERDLG_H__0C514854_AFF4_4E33_90EC_BCE154B8533C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnterDlg dialog

extern CString g_sText;

class CEnterDlg : public CDialog
{
// Construction
public:
	CEnterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEnterDlg)
	enum { IDD = IDD_ENTER };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnterDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTERDLG_H__0C514854_AFF4_4E33_90EC_BCE154B8533C__INCLUDED_)
