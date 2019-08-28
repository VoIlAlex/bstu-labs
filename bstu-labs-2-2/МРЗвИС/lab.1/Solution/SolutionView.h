// SolutionView.h : interface of the CSolutionView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOLUTIONVIEW_H__0FF2FAAB_1094_41E7_95B3_50025153AE4F__INCLUDED_)
#define AFX_SOLUTIONVIEW_H__0FF2FAAB_1094_41E7_95B3_50025153AE4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSolutionView : public CView
{
protected: // create from serialization only
	CSolutionView();
	DECLARE_DYNCREATE(CSolutionView)

// Attributes
public:
	CSolutionDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSolutionView)
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
	virtual ~CSolutionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSolutionView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SolutionView.cpp
inline CSolutionDoc* CSolutionView::GetDocument()
   { return (CSolutionDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOLUTIONVIEW_H__0FF2FAAB_1094_41E7_95B3_50025153AE4F__INCLUDED_)
