// string_listView.cpp : implementation of the CString_listView class
//

#include "stdafx.h"
#include "string_list.h"

#include "string_listDoc.h"
#include "string_listView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CString_listView

IMPLEMENT_DYNCREATE(CString_listView, CView)

BEGIN_MESSAGE_MAP(CString_listView, CView)
	//{{AFX_MSG_MAP(CString_listView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CString_listView construction/destruction

CString_listView::CString_listView()
{
	// TODO: add construction code here

}

CString_listView::~CString_listView()
{
}

BOOL CString_listView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CString_listView drawing

void CString_listView::OnDraw(CDC* pDC)
{
	CString_listDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CString_listView printing

BOOL CString_listView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CString_listView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CString_listView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CString_listView diagnostics

#ifdef _DEBUG
void CString_listView::AssertValid() const
{
	CView::AssertValid();
}

void CString_listView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CString_listDoc* CString_listView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CString_listDoc)));
	return (CString_listDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CString_listView message handlers
