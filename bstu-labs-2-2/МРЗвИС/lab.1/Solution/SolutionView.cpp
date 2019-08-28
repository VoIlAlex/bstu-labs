// SolutionView.cpp : implementation of the CSolutionView class
//

#include "stdafx.h"
#include "Solution.h"

#include "SolutionDoc.h"
#include "SolutionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSolutionView

IMPLEMENT_DYNCREATE(CSolutionView, CView)

BEGIN_MESSAGE_MAP(CSolutionView, CView)
	//{{AFX_MSG_MAP(CSolutionView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSolutionView construction/destruction

CSolutionView::CSolutionView()
{
	// TODO: add construction code here

}

CSolutionView::~CSolutionView()
{
}

BOOL CSolutionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSolutionView drawing

void CSolutionView::OnDraw(CDC* pDC)
{
	CSolutionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSolutionView printing

BOOL CSolutionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSolutionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSolutionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSolutionView diagnostics

#ifdef _DEBUG
void CSolutionView::AssertValid() const
{
	CView::AssertValid();
}

void CSolutionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSolutionDoc* CSolutionView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSolutionDoc)));
	return (CSolutionDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSolutionView message handlers
