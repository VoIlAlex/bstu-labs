// project_menuDoc.h : interface of the CProject_menuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROJECT_MENUDOC_H__E0793369_5119_4919_8C58_E2D112D7EC57__INCLUDED_)
#define AFX_PROJECT_MENUDOC_H__E0793369_5119_4919_8C58_E2D112D7EC57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CProject_menuDoc : public CDocument
{
protected: // create from serialization only
	CProject_menuDoc();
	DECLARE_DYNCREATE(CProject_menuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProject_menuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProject_menuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProject_menuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJECT_MENUDOC_H__E0793369_5119_4919_8C58_E2D112D7EC57__INCLUDED_)
