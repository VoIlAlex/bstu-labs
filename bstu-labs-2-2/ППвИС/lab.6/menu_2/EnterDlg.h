#if !defined(AFX_ENTERDLG_H__26694FA6_354C_4C36_A61E_16B6BFA907E3__INCLUDED_)
#define AFX_ENTERDLG_H__26694FA6_354C_4C36_A61E_16B6BFA907E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnterDlg dialog

class CEnterDlg : public CDialog
{
private:
	CString m_sText;

// Construction
public:
	CEnterDlg(CWnd* pParent = NULL);   // standard constructor
	CString GetText() const;
// Dialog Data
	//{{AFX_DATA(CEnterDlg)
	enum { IDD = IDD_ENTER };
		// NOTE: the ClassWizard will add data members here
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

#endif // !defined(AFX_ENTERDLG_H__26694FA6_354C_4C36_A61E_16B6BFA907E3__INCLUDED_)
