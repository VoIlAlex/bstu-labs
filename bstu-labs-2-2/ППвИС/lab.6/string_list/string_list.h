// string_list.h : main header file for the STRING_LIST application
//

#if !defined(AFX_STRING_LIST_H__4A321946_9D4B_4C2D_9D97_17BFD3CE183D__INCLUDED_)
#define AFX_STRING_LIST_H__4A321946_9D4B_4C2D_9D97_17BFD3CE183D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CString_listApp:
// See string_list.cpp for the implementation of this class
//

class CString_listApp : public CWinApp
{
public:
	CString_listApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CString_listApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CString_listApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STRING_LIST_H__4A321946_9D4B_4C2D_9D97_17BFD3CE183D__INCLUDED_)
