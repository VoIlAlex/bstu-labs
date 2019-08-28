// projectView.h : interface of the CProjectView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROJECTVIEW_H__EF315D40_7ACE_418B_B2CA_DB90C7E0A4F9__INCLUDED_)
#define AFX_PROJECTVIEW_H__EF315D40_7ACE_418B_B2CA_DB90C7E0A4F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CProjectView : public CView
{
protected: // create from serialization only
	CProjectView();
	DECLARE_DYNCREATE(CProjectView)

// Attributes
public:
	CProjectDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjectView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProjectView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in projectView.cpp
inline CProjectDoc* CProjectView::GetDocument()
   { return (CProjectDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJECTVIEW_H__EF315D40_7ACE_418B_B2CA_DB90C7E0A4F9__INCLUDED_)
