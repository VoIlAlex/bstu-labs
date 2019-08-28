// project.h : main header file for the PROJECT application
//

#if !defined(AFX_PROJECT_H__1CAD4794_A098_4FB9_8AF5_332B5CAE5F8A__INCLUDED_)
#define AFX_PROJECT_H__1CAD4794_A098_4FB9_8AF5_332B5CAE5F8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CProjectApp:
// See project.cpp for the implementation of this class
//

class CProjectApp : public CWinApp
{
public:
	CProjectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CProjectApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJECT_H__1CAD4794_A098_4FB9_8AF5_332B5CAE5F8A__INCLUDED_)
