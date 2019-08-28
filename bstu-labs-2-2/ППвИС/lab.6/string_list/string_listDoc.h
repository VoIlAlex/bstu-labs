// string_listDoc.h : interface of the CString_listDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRING_LISTDOC_H__84C87116_B138_41E1_A8C4_F0756C7E9CA9__INCLUDED_)
#define AFX_STRING_LISTDOC_H__84C87116_B138_41E1_A8C4_F0756C7E9CA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CString_listDoc : public CDocument
{
protected: // create from serialization only
	CString_listDoc();
	DECLARE_DYNCREATE(CString_listDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CString_listDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CString_listDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CString_listDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STRING_LISTDOC_H__84C87116_B138_41E1_A8C4_F0756C7E9CA9__INCLUDED_)
