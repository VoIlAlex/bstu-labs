#if !defined(AFX_MYDLG_H__E3CFEDF2_4793_4642_978F_D3385D4A284D__INCLUDED_)
#define AFX_MYDLG_H__E3CFEDF2_4793_4642_978F_D3385D4A284D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

/**My**/

UINT FirstThread(LPVOID pParam);
UINT SecondThread(LPVOID pParam);

/******/


class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);   // standard constructor

	enum {nMax1 = 1000000, nMax2=500000};

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual void OnOK();
	afx_msg void OnStop();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_nTimer;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDLG_H__E3CFEDF2_4793_4642_978F_D3385D4A284D__INCLUDED_)
