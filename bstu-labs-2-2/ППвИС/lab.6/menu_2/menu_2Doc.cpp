// menu_2Doc.cpp : implementation of the CMenu_2Doc class
//

#include "stdafx.h"
#include "menu_2.h"

#include "menu_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenu_2Doc

IMPLEMENT_DYNCREATE(CMenu_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMenu_2Doc, CDocument)
	//{{AFX_MSG_MAP(CMenu_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenu_2Doc construction/destruction

CMenu_2Doc::CMenu_2Doc()
{
	// TODO: add one-time construction code here

}

CMenu_2Doc::~CMenu_2Doc()
{
}

BOOL CMenu_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMenu_2Doc serialization

void CMenu_2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMenu_2Doc diagnostics

#ifdef _DEBUG
void CMenu_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMenu_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenu_2Doc commands
