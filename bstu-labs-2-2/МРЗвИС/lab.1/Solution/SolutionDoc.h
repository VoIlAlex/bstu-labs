// SolutionDoc.h : interface of the CSolutionDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOLUTIONDOC_H__3E1F5298_F131_4188_A9D1_B6DFBAFFB14B__INCLUDED_)
#define AFX_SOLUTIONDOC_H__3E1F5298_F131_4188_A9D1_B6DFBAFFB14B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSolutionDoc : public CDocument
{
protected: // create from serialization only
	CSolutionDoc();
	DECLARE_DYNCREATE(CSolutionDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSolutionDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSolutionDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSolutionDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOLUTIONDOC_H__3E1F5298_F131_4188_A9D1_B6DFBAFFB14B__INCLUDED_)
