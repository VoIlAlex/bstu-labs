#include <Windows.h>
#include "resource.h"

#define STR_SIZE 256


TCHAR szWindowTitle[STR_SIZE] = "Title";
TCHAR szClassName[STR_SIZE] = "MyClass";

HINSTANCE g_hInst;

LRESULT __stdcall WndMain(HWND hWnd,
				 UINT msg,
				 WPARAM wParam,
				 LPARAM lParam);
INT_PTR __stdcall DlgInput(HWND hWnd,
				 UINT msg,
				 WPARAM wParam,
				 LPARAM lParam);
void ErrorMessage(TCHAR * szMsg);

int APIENTRY WinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPSTR szCmdLine,
					 int nCmdShow)
{
	g_hInst = hInstance;
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = 0;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndMain;
	wc.lpszClassName = szClassName;
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if(!RegisterClass(&wc))
	{
		ErrorMessage("RegisterClass");
		exit(0);
	}
	HWND hWnd = CreateWindow( szClassName,
		szWindowTitle,
		WS_OVERLAPPEDWINDOW,
		0, 0, CW_USEDEFAULT, CW_USEDEFAULT,
		0,0, hInstance, 0);

	if(!hWnd)
	{
		ErrorMessage("CreateWindow");
		exit(0);
	}

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

LRESULT __stdcall WndMain(HWND hWnd,
				 UINT msg,
				 WPARAM wParam,
				 LPARAM lParam)
{
	switch(msg)
	{
	case WM_COMMAND:
		{
			WORD id = LOWORD(wParam);
			switch(id)
			{
			case IDM_INPUT:
				DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, (DLGPROC) DlgInput);
				break;
			}
		}
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
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

void ErrorMessage(TCHAR * szMsg)
{
	MessageBox(NULL, szMsg, "Error", MB_OK);
}

LRESULT __stdcall DlgInput(HWND hWnd,
				 UINT msg,
				 WPARAM wParam,
				 LPARAM lParam)
{
	switch(msg)
	{
	case WM_INITDIALOG:
		return TRUE;

	}
}