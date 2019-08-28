// Inbox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
const int STRING_SIZE = 100;

char szWndClass[STRING_SIZE];
char szWndTitle[STRING_SIZE];


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, 
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nShowCmd)
{
	LoadString(hInstance, IDS_CLASSNAME, szWndClass, STRING_SIZE);
	LoadString(hInstance, IDS_TITLE, szWndTitle, STRING_SIZE);
	
	
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = 0;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = szWndClass;
	wc.lpszMenuName = (LPCSTR)IDR_MENU;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	
	if(!RegisterClass(&wc))
		return -1;
	
	HWND hWnd = CreateWindow(szWndClass, szWndTitle, 
		WS_OVERLAPPEDWINDOW,
		0,0,600,400, NULL, NULL, hInstance, NULL);
	
	
	ShowWindow(hWnd, nShowCmd);
	UpdateWindow(hWnd);
	
	MSG msg;
	
	while(GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}

enum Mode
{
	FUNC_CHOOSING,
		X2,
		XP2
};


void OutputFunction(HDC hdc, Mode mode)
{
	char szX[10] = "";
	char szY[10] = "";
	
	TextOut(hdc, 10, 10, "X", 1);
	TextOut(hdc, 30, 10, "Y", 1);
	
	for(int i = 0; i < 10; i++)
	{
		wsprintf(szX, "%d", i);
		switch(mode)
		{
		case X2:
			wsprintf(szY, "%d", i * i);
			break;
		case XP2:
			wsprintf(szY, "%d", 2 + i);
			break;
		default:
			wsprintf(szY, "%d", i);
		}
		TextOut(hdc, 10, 30+20*i, szX, 10); 
		TextOut(hdc, 30, 30+20*i, szY, 10);
	}
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	char szChoosingMsg[] = "Please choose function in File pop-menu";
	static Mode mode = FUNC_CHOOSING;
	switch(msg)
	{
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
			
			
			
			
		case IDM_X2: 
			if(mode==X2)
			{
				MessageBox(hWnd, "Function is already choosen", "Warning!", MB_OK);
				break;
			}
			mode = X2;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case IDM_XP2:
			if(mode==XP2)
			{
				MessageBox(hWnd, "Function is already choosen", "Warning!", MB_OK);
				break;
			}
			mode = XP2;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case IDM_STOP:
			if(mode==FUNC_CHOOSING)
			{
				MessageBox(hWnd, "There are now function choosen", "Warning!", 
					MB_OK);
				break;
			}
			mode = FUNC_CHOOSING;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			if(mode == FUNC_CHOOSING)
			{
				TextOut(hdc, 5, 5, szChoosingMsg, sizeof(szChoosingMsg));
			}
			else
			{
				OutputFunction(hdc, mode);
			}
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

