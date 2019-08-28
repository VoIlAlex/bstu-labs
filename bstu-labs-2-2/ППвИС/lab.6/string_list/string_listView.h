// string_listView.h : interface of the CString_listView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRING_LISTVIEW_H__CA245203_D049_4591_9065_B4F32A9DFD88__INCLUDED_)
#define AFX_STRING_LISTVIEW_H__CA245203_D049_4591_9065_B4F32A9DFD88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CString_listView : public CView
{
protected: // create from serialization only
	CString_listView();
	DECLARE_DYNCREATE(CString_listView)

// Attributes
public:
	CString_listDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CString_listView)
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
	virtual ~CString_listView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CString_listView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in string_listView.cpp
inline CString_listDoc* CString_listView::GetDocument()
   { return (CString_listDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STRING_LISTVIEW_H__CA245203_D049_4591_9065_B4F32A9DFD88__INCLUDED_)
