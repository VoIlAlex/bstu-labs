// projectDoc.cpp : implementation of the CProjectDoc class
//

#include "stdafx.h"
#include "project.h"

#include "projectDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProjectDoc

IMPLEMENT_DYNCREATE(CProjectDoc, CDocument)

BEGIN_MESSAGE_MAP(CProjectDoc, CDocument)
	//{{AFX_MSG_MAP(CProjectDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjectDoc construction/destruction

CProjectDoc::CProjectDoc()
{
	// TODO: add one-time construction code here

}

CProjectDoc::~CProjectDoc()
{
}

BOOL CProjectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CProjectDoc serialization

void CProjectDoc::Serialize(CArchive& ar)
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
// CProjectDoc diagnostics

#ifdef _DEBUG
void CProjectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProjectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProjectDoc commands
