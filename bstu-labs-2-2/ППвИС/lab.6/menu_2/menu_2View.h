// menu_2View.h : interface of the CMenu_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENU_2VIEW_H__8D00637F_3238_4104_8D44_32D59C3F7038__INCLUDED_)
#define AFX_MENU_2VIEW_H__8D00637F_3238_4104_8D44_32D59C3F7038__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMenu_2View : public CView
{
protected: // create from serialization only
	CMenu_2View();
	DECLARE_DYNCREATE(CMenu_2View)

// Attributes
public:
	CMenu_2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenu_2View)
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
	virtual ~CMenu_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMenu_2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in menu_2View.cpp
inline CMenu_2Doc* CMenu_2View::GetDocument()
   { return (CMenu_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENU_2VIEW_H__8D00637F_3238_4104_8D44_32D59C3F7038__INCLUDED_)
