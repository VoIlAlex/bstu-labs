#include <Windows.h>
#include "resource.h"
#define OKBOX(msg) MessageBox(NULL, msg, "Message", MB_OK)

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

HINSTANCE g_hInst;

int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpCmdLine,
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
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "MyClass";
	wc.lpszMenuName = 0;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	if(!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("Error while class registration!"), TEXT("Error"), MB_OK);
		return -1;
	}

	HWND hWnd = CreateWindow(
		TEXT("MyClass"),
		TEXT("Window"),
		WS_OVERLAPPEDWINDOW,
		0, 0, 600, 400,
		NULL, NULL,
		hInstance,
		NULL);

	if(!hWnd)
	{
		MessageBox(NULL, TEXT("Error while window creation!"), TEXT("Error"), MB_OK);
		return -1;
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	switch(msg)
	{
	case WM_CREATE:
		
		
		return TRUE;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_INITDIALOG:
		return TRUE;
		break;
	case WM_COMMAND:
		switch(wParam)
		{
		case IDOK:
			EndDialog(hDlg, 1);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		case IDC_SPIN:
			MessageBox(hDlg, TEXT("Spin was pressed!"), TEXT("Caption"), MB_OK);
			break;
		}
	}
	return 0;
}