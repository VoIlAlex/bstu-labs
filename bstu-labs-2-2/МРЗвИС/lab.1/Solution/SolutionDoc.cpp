// SolutionDoc.cpp : implementation of the CSolutionDoc class
//

#include "stdafx.h"
#include "Solution.h"

#include "SolutionDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSolutionDoc

IMPLEMENT_DYNCREATE(CSolutionDoc, CDocument)

BEGIN_MESSAGE_MAP(CSolutionDoc, CDocument)
	//{{AFX_MSG_MAP(CSolutionDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSolutionDoc construction/destruction

CSolutionDoc::CSolutionDoc()
{
	// TODO: add one-time construction code here

}

CSolutionDoc::~CSolutionDoc()
{
}

BOOL CSolutionDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSolutionDoc serialization

void CSolutionDoc::Serialize(CArchive& ar)
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
// CSolutionDoc diagnostics

#ifdef _DEBUG
void CSolutionDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSolutionDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSolutionDoc commands
