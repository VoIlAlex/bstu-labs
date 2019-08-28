// string_listDoc.cpp : implementation of the CString_listDoc class
//

#include "stdafx.h"
#include "string_list.h"

#include "string_listDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CString_listDoc

IMPLEMENT_DYNCREATE(CString_listDoc, CDocument)

BEGIN_MESSAGE_MAP(CString_listDoc, CDocument)
	//{{AFX_MSG_MAP(CString_listDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CString_listDoc construction/destruction

CString_listDoc::CString_listDoc()
{
	// TODO: add one-time construction code here

}

CString_listDoc::~CString_listDoc()
{
}

BOOL CString_listDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CString_listDoc serialization

void CString_listDoc::Serialize(CArchive& ar)
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
// CString_listDoc diagnostics

#ifdef _DEBUG
void CString_listDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CString_listDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CString_listDoc commands
