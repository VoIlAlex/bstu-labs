// inbox.cpp : Defines the entry point for the application.
//

// CallWindowProc

#include "stdafx.h"
#include "resource.h"
#include <commdlg.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>

// Constants

const int STR_SIZE = 1024;

////


// global variables

char g_szClassName[STR_SIZE] = "WndClass";
char g_szWindowName[STR_SIZE] = "Title";
HINSTANCE g_hInstance;
HWND g_hWnd;
////

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc2(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DlgSurnameList(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK InputProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	g_hInstance = hInstance;
 	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hInstance = hInstance;
	wcex.lpfnWndProc = WndProc2;
	wcex.lpszClassName = g_szClassName;
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	

	if(!RegisterClassEx(&wcex))
	{
		return -1;
	}

	HWND hWnd = CreateWindowEx( /*WS_EX_CONTEXTHELP*/0,
			g_szClassName,
			g_szWindowName,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			NULL, NULL, hInstance, NULL 
		);
	
	if(!hWnd)
	{
		return -2;
	}
	g_hWnd = hWnd;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;

	while(GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	WORD wmId = LOWORD(wParam);
	WORD wmEvent = HIWORD(wParam);
	switch(msg)
	{
	case WM_COMMAND:
		switch(wmId)
		{
		case ID_INPUT:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_SURNAMES), hWnd, (DLGPROC)InputProc);
			break;
		}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_DROPFILES:
		MessageBox(hWnd, "All done!", "Title", MB_OK);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}

#define DO_INC 12345

LRESULT CALLBACK WndProc2(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static std::string sLastString;
	static int count = 0;
	WORD wmId = LOWORD(wParam);
	WORD wmEvent = HIWORD(wParam);
	switch(msg)
	{
	case DO_INC:
		sLastString = (char*)lParam;
		count++;
		InvalidateRect(hWnd, NULL, TRUE);
		break;

	case WM_COMMAND:
		switch(wmId)
		{
		case ID_INPUT:
			DialogBox(0, MAKEINTRESOURCE(IDD_INPUT2), hWnd, (DLGPROC)InputProc);
			break;
		}
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		std::string sLine1 = "Last string: " + sLastString;
		char szLine2[STR_SIZE];
		memset(szLine2, 0, STR_SIZE);
		wsprintf(szLine2, "Count: %d", count);  
		TextOut(hdc, 10, 10, sLine1.c_str(), sLine1.length());
		TextOut(hdc, 10, 40, szLine2, STR_SIZE);
		EndPaint(hWnd, &ps);
		
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}


LRESULT CALLBACK DlgSurnameList(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_KEYDOWN:
		switch(LOWORD(wParam))
		{
		case VK_RETURN:
			SendMessage(hWnd, WM_COMMAND, IDC_ADD, 0);
			break;
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}
	case WM_INITDIALOG:
		{
			std::ifstream fin("db.txt");
			if(!fin)
			{
				MessageBox(hWnd, "Cannot open db", "", MB_OK);
				EndDialog(hWnd, 0);
				return FALSE;
			}
			std::string sBuffer;
			while(std::getline(fin, sBuffer))
				SendDlgItemMessage(hWnd, IDC_SURNAMES, LB_ADDSTRING, 0, (LPARAM)sBuffer.c_str());
			return TRUE;
		}
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			PostQuitMessage(0);
			break;
		case IDCANCEL:
			EndDialog(hWnd, 0);
			break;
		case IDC_ADD:
			{
				char szBuffer[STR_SIZE] = "";
				GetDlgItemText(hWnd, IDC_EDIT, szBuffer, STR_SIZE);
				SendDlgItemMessage(hWnd, IDC_SURNAMES, LB_ADDSTRING, 0, (LPARAM)szBuffer);
			}
			break;
		case IDC_DELETE:
			{
				int nSelected = SendDlgItemMessage(hWnd, IDC_SURNAMES, LB_GETCURSEL, 0, 0);
				if(nSelected == LB_ERR)
				{
					MessageBox(hWnd, "There are no selected items", "", MB_OK);
					break;
				}
				SendDlgItemMessage(hWnd, IDC_SURNAMES, LB_DELETESTRING, nSelected, 0);
			}
			break;
		case IDC_CHANGE:
			{
				int nSelected = SendDlgItemMessage(hWnd, IDC_SURNAMES, LB_GETCURSEL, 0, 0);
				if(nSelected == LB_ERR)
				{
					MessageBox(hWnd, "There are no selected items", "", MB_OK);
					break;
				}
				char szBuffer[STR_SIZE] = "";
				GetDlgItemText(hWnd, IDC_EDIT, szBuffer, STR_SIZE);
				SendDlgItemMessage(hWnd, IDC_SURNAMES, LB_DELETESTRING, nSelected, 0);
				SendDlgItemMessage(hWnd, IDC_SURNAMES, LB_INSERTSTRING, nSelected, (LPARAM)szBuffer);
			}
			break;
		}
	}
	return 0;
}

LRESULT CALLBACK InputProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch(msg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
	{
		switch(LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		case ID_INPUT:
		{
			char szBuffer[STR_SIZE] = "";
			GetDlgItemText(hDlg, IDC_EDIT1, szBuffer, STR_SIZE);
			if (strlen(szBuffer) == 0)
			{
				MessageBox(hDlg, "No text", "", MB_OK);
				break;
			}
			SendMessage(g_hWnd, DO_INC, 0, (LPARAM)szBuffer);
			break;
		}
			
		}
	}
	}
	return 0;
}