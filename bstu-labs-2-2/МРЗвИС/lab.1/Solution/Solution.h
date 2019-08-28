// Solution.h : main header file for the SOLUTION application
//

#if !defined(AFX_SOLUTION_H__BD47DD1C_0A27_4742_A43E_D359DBEA4B94__INCLUDED_)
#define AFX_SOLUTION_H__BD47DD1C_0A27_4742_A43E_D359DBEA4B94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSolutionApp:
// See Solution.cpp for the implementation of this class
//

class CSolutionApp : public CWinApp
{
public:
	CSolutionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSolutionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSolutionApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOLUTION_H__BD47DD1C_0A27_4742_A43E_D359DBEA4B94__INCLUDED_)
