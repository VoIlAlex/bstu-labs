// maindlg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <locale>

LRESULT CALLBACK MainDlgProc(HWND hDlg,
							 UINT msg,
							 WPARAM wParam,
							 LPARAM lParam);

const int STR_SIZE = 100;


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	DialogBox(NULL, (LPCTSTR)IDD_MAINDLG, NULL, (DLGPROC)MainDlgProc);
 	MSG msg;

	while(GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK MainDlgProc(HWND hDlg,
							 UINT msg,
							 WPARAM wParam,
							 LPARAM lParam)
{
	std::locale loc;
	int i;
	char szText[STR_SIZE] = "";
	switch(msg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDCANCEL:
			if(MessageBox(hDlg, "Do you really want to close the application?", "Confirmation", MB_OKCANCEL) == IDOK)
				PostQuitMessage(0);
			break;
		case IDOK:
			GetDlgItemText(hDlg, IDC_INPUT, szText, STR_SIZE);
			for(i = 0; szText[i]!='\0'; i++)
				szText[i] = std::toupper(szText[i], loc);
			SetDlgItemText(hDlg, IDC_OUTPUT, szText);
			break;
		default: 
			break;
		}
	}
	return 0;
}
