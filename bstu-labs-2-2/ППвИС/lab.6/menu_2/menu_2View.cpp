// menu_2View.cpp : implementation of the CMenu_2View class
//

#include "stdafx.h"
#include "menu_2.h"

#include "menu_2Doc.h"
#include "menu_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenu_2View

IMPLEMENT_DYNCREATE(CMenu_2View, CView)

BEGIN_MESSAGE_MAP(CMenu_2View, CView)
	//{{AFX_MSG_MAP(CMenu_2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenu_2View construction/destruction

CMenu_2View::CMenu_2View()
{
	// TODO: add construction code here

}

CMenu_2View::~CMenu_2View()
{
}

BOOL CMenu_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMenu_2View drawing

void CMenu_2View::OnDraw(CDC* pDC)
{
	CMenu_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMenu_2View printing

BOOL CMenu_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenu_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenu_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMenu_2View diagnostics

#ifdef _DEBUG
void CMenu_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMenu_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenu_2Doc* CMenu_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenu_2Doc)));
	return (CMenu_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenu_2View message handlers
