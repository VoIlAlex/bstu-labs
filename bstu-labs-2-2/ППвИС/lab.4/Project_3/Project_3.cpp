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
#include <utility>

// Constants

const int STR_SIZE = 1024;

////


// global variables

char g_szClassName[STR_SIZE] = "WndClass";
char g_szWindowName[STR_SIZE] = "Title";
HINSTANCE g_hInstance;

////

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DlgNumberListProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

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
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);
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
		case IDM_RUN:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_PHONE_NUMBERS), hWnd, (DLGPROC)DlgNumberListProc);
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

// To get selected item from list box
int GetSelected(HWND hDlg, int idList);


// To get item <i> from given list box 
std::pair<std::string, std::string> GetItem(HWND hDlg, int idList, int i);


// To amend or add new item to list
void AddOfAmendItem(HWND, int idList, int idEdit, std::string, std::string);

// TODO: change
LRESULT CALLBACK DlgNumberListProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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
		return TRUE;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hWnd, 0);
			break;
		case IDCANCEL:
			EndDialog(hWnd, 0);
			break;
		case IDC_ADD:
			{
				char szBuffer[STR_SIZE] = "";
				GetDlgItemText(hWnd, IDC_AMEND, szBuffer, STR_SIZE);
				SendDlgItemMessage(hWnd, IDC_NUMBER_LIST, LB_ADDSTRING, 0, (LPARAM)szBuffer);
			}
			break;
		case IDC_DELETE:
			{
				int nSelected = SendDlgItemMessage(hWnd, IDC_NUMBER_LIST, LB_GETCURSEL, 0, 0);
				if(nSelected == LB_ERR)
				{
					MessageBox(hWnd, "There are no selected items", "", MB_OK);
					break;
				}
				SendDlgItemMessage(hWnd, IDC_NUMBER_LIST, LB_DELETESTRING, nSelected, 0);
			}
			break;
		case IDC_AMEND:
			{
				int nSelected = SendDlgItemMessage(hWnd, IDC_NUMBER_LIST, LB_GETCURSEL, 0, 0);
				if(nSelected == LB_ERR)
				{
					MessageBox(hWnd, "There are no selected items", "", MB_OK);
					break;
				}
				char szBuffer[STR_SIZE] = "";
				GetDlgItemText(hWnd, IDC_AMEND, szBuffer, STR_SIZE);
				SendDlgItemMessage(hWnd, IDC_NUMBER_LIST, LB_DELETESTRING, nSelected, 0);
				SendDlgItemMessage(hWnd, IDC_NUMBER_LIST, LB_INSERTSTRING, nSelected, (LPARAM)szBuffer);
			}
			break;
		}
	}
	return 0;
}

// finds list item with given name <sItem>
int FindItem(HWND hDlg, int idList, std::string sItem)
{
	int nCount = SendDlgItemMessage(hDlg, idList, 0, 0);
	int id = LB_ERR;
	for(int i = 0; i < nCount; i++)
	{
		std::pair<std::string, std::string> item = GetItem(hDlg, idList, i);
		if(item.first == sItem)
		{
			id = i;
			break;
		}
	}
	return id;
}

int GetSelected(HWND hDlg, int idList)
{
	int nSelected = SendDlgItemMessage(hDlg, idList, LB_GETCURSEL, 0, 0);
	return nSelected;
}

std::pair<std::string, std::string> GetItem(HWND hDlg, int idList, int i)
{
	char szBuffer[STR_SIZE] = "";
	SendDlgItemMessage(hDlg, idList, LB_GETTEXT, i, szBuffer);
	std::stringstream ss{szBuffer};
	std::pair<std::string, std::string> result;
	ss >> result.first;
	ss >> result.second;
	return result;
	
}

void AddOfAmendItem(HWND, int idList, int idEdit, std::string sName, std::string sPhone)
{
	int i =
}