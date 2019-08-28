// project_menuView.cpp : implementation of the CProject_menuView class
//

#include "stdafx.h"
#include "project_menu.h"

#include "project_menuDoc.h"
#include "project_menuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProject_menuView

IMPLEMENT_DYNCREATE(CProject_menuView, CView)

BEGIN_MESSAGE_MAP(CProject_menuView, CView)
	//{{AFX_MSG_MAP(CProject_menuView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProject_menuView construction/destruction

CProject_menuView::CProject_menuView()
{
	// TODO: add construction code here

}

CProject_menuView::~CProject_menuView()
{
}

BOOL CProject_menuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CProject_menuView drawing

void CProject_menuView::OnDraw(CDC* pDC)
{
	CProject_menuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CProject_menuView printing

BOOL CProject_menuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProject_menuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProject_menuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CProject_menuView diagnostics

#ifdef _DEBUG
void CProject_menuView::AssertValid() const
{
	CView::AssertValid();
}

void CProject_menuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProject_menuDoc* CProject_menuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProject_menuDoc)));
	return (CProject_menuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProject_menuView message handlers
