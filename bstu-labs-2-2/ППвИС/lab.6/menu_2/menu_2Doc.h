// menu_2Doc.h : interface of the CMenu_2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENU_2DOC_H__4250B81C_C6B5_402C_8F36_D21651DF9DDE__INCLUDED_)
#define AFX_MENU_2DOC_H__4250B81C_C6B5_402C_8F36_D21651DF9DDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMenu_2Doc : public CDocument
{
protected: // create from serialization only
	CMenu_2Doc();
	DECLARE_DYNCREATE(CMenu_2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenu_2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMenu_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMenu_2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENU_2DOC_H__4250B81C_C6B5_402C_8F36_D21651DF9DDE__INCLUDED_)
