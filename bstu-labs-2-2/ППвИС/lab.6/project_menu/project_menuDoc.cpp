// project_menuDoc.cpp : implementation of the CProject_menuDoc class
//

#include "stdafx.h"
#include "project_menu.h"

#include "project_menuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProject_menuDoc

IMPLEMENT_DYNCREATE(CProject_menuDoc, CDocument)

BEGIN_MESSAGE_MAP(CProject_menuDoc, CDocument)
	//{{AFX_MSG_MAP(CProject_menuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProject_menuDoc construction/destruction

CProject_menuDoc::CProject_menuDoc()
{
	// TODO: add one-time construction code here

}

CProject_menuDoc::~CProject_menuDoc()
{
}

BOOL CProject_menuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CProject_menuDoc serialization

void CProject_menuDoc::Serialize(CArchive& ar)
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
// CProject_menuDoc diagnostics

#ifdef _DEBUG
void CProject_menuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProject_menuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProject_menuDoc commands
