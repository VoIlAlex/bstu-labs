// menu_2.h : main header file for the MENU_2 application
//

#if !defined(AFX_MENU_2_H__613D603C_6E16_41EF_A690_4C958EF97CCA__INCLUDED_)
#define AFX_MENU_2_H__613D603C_6E16_41EF_A690_4C958EF97CCA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMenu_2App:
// See menu_2.cpp for the implementation of this class
//

class CMenu_2App : public CWinApp
{
	CString m_sText;
public:
	CMenu_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenu_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMenu_2App)
	afx_msg void OnAppAbout();
	afx_msg void OnEnter();
	afx_msg void OnView();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENU_2_H__613D603C_6E16_41EF_A690_4C958EF97CCA__INCLUDED_)
