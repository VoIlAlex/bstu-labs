// project_menuView.h : interface of the CProject_menuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROJECT_MENUVIEW_H__34969ACA_3FD3_4951_9743_B1BA9564B7FE__INCLUDED_)
#define AFX_PROJECT_MENUVIEW_H__34969ACA_3FD3_4951_9743_B1BA9564B7FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CProject_menuView : public CView
{
protected: // create from serialization only
	CProject_menuView();
	DECLARE_DYNCREATE(CProject_menuView)

// Attributes
public:
	CProject_menuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProject_menuView)
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
	virtual ~CProject_menuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProject_menuView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in project_menuView.cpp
inline CProject_menuDoc* CProject_menuView::GetDocument()
   { return (CProject_menuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJECT_MENUVIEW_H__34969ACA_3FD3_4951_9743_B1BA9564B7FE__INCLUDED_)
