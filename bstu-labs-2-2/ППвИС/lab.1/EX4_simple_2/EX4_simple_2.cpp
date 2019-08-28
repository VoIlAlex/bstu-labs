// EX4_simple_2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

char szMy[] = "My";


LRESULT CALLBACK prosidurka(HWND hWnd, 
					 UINT msg,
					 WPARAM wParam,
					 LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	HWND hWnd;
	MSG msg;

 	WNDCLASS wcMy;
	wcMy.lpszClassName = szMy;
	wcMy.cbClsExtra = 0;
	wcMy.cbWndExtra = 0;
	wcMy.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcMy.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcMy.hIcon = 0;
	wcMy.hInstance = hInstance;
	wcMy.lpfnWndProc = prosidurka;
	wcMy.lpszMenuName = 0;
	wcMy.style = CS_HREDRAW | CS_VREDRAW;

	if(!RegisterClass(&wcMy))
		return 0;

	hWnd = CreateWindow(szMy, "My-test",
						WS_OVERLAPPEDWINDOW,
						0, 0, 500, 200, 
						(HWND) NULL,
						(HMENU) NULL,
						hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while(GetMessage(&msg, hWnd, NULL,NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK prosidurka(HWND hWnd, 
					 UINT msg,
					 WPARAM wParam,
					 LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	switch(msg)
	{
	case WM_PAINT:
		BeginPaint(hWnd, &ps);
		//MessageBox(hWnd, "Ne nu", "My", MB_OK);
		ValidateRect(hWnd, NULL);
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



