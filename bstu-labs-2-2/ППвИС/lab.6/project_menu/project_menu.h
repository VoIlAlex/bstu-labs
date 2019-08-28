// project_menu.h : main header file for the PROJECT_MENU application
//

#if !defined(AFX_PROJECT_MENU_H__E04899FD_CCBE_47BF_A341_323C3080E891__INCLUDED_)
#define AFX_PROJECT_MENU_H__E04899FD_CCBE_47BF_A341_323C3080E891__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CProject_menuApp:
// See project_menu.cpp for the implementation of this class
//

class CProject_menuApp : public CWinApp
{
public:
	CProject_menuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProject_menuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CProject_menuApp)
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

#endif // !defined(AFX_PROJECT_MENU_H__E04899FD_CCBE_47BF_A341_323C3080E891__INCLUDED_)
