#include "stdafx.h"
#include "resource.h"
#include <string>

// Constants

const int STR_SIZE = 1024;

////


// global variables

char g_szClassName[STR_SIZE] = "WndClass";
char g_szWindowName[STR_SIZE] = "Title";
HINSTANCE g_hInstance;
HWND g_hMainWnd;

////

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK Input(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

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
	wcex.lpfnWndProc = WndProc;
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

	g_hMainWnd= hWnd;
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

// custom window message
#define DO_INCREMENT 12345


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static std::string sLastString;
	static int count = 0;
	WORD wmId = LOWORD(wParam);
	WORD wmEvent = HIWORD(wParam);
	switch(msg)
	{
	case WM_COMMAND:
		switch(wmId)
		{
		case IDM_INPUT:
			DialogBox(hWnd, MAKEINTRESOURCE(IDD_INPUT), hWnd, (DLGPROC)Input);
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
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case DO_INCREMENT:
		sLastString = (char*)lParam;
		count++;
		break;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}

LRESULT CALLBACK Input(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
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
		case IDC_INPUT:
		{
			char szBuffer[STR_SIZE] = "";
			GetDlgItemText(hDlg, IDC_EDIT1, szBuffer, STR_SIZE);
			if (strlen(szBuffer) == 0)
			{
				MessageBox(hDlg, "No text", "", MB_OK);
				break;
			}
			SendMessage(g_hMainWnd, DO_INCREMENT, 0, (LPARAM)szBuffer);
			break;
		}
			
		}
	}
	}
	return 0;

}