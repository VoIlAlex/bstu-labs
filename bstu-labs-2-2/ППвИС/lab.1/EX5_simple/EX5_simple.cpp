// EX5_simple.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

LRESULT CALLBACK	    WndProc (HWND, UINT, WPARAM, LPARAM);
char   szWindowStyle [ ] = "myWindowStyle";

//===============================
//    ������� ������� 
int  WINAPI  WinMain   (HINSTANCE hInst,  //���������� ����������
						HINSTANCE hPreInst,  //������ NULL
						LPSTR          lpszCmdLine,  //��������� ������
						int                 nCmdShow) //���� ��� ������ ������
{    	
	HWND                   hWnd;                  //���������� ����
	MSG                    lpMsg;                  //��������� �������� ��������� 
	WNDCLASS               wcApp;                 //��������� �������� ����� ����
	wcApp.lpszClassName	   = szWindowStyle;   //��� ����� ����
	wcApp.hInstance	       = hInst;                   //���������� ���������� 
	wcApp.lpfnWndProc	   = WndProc;            //��������� �� ���������� ����-����� 
	wcApp.hCursor	       = LoadCursor(NULL, IDC_WAIT);   //������ - "�������"
	wcApp.hIcon		       = 0;                          //��� ������������� �����������
	wcApp.lpszMenuName	   = 0;                          //���������� ���� (��� ����)
	wcApp.hbrBackground    = (HBRUSH) GetStockObject (BLACK_BRUSH); //���� ���� 
	wcApp.style		       = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE; //�������������� ���� 
	wcApp.cbClsExtra	       = 0;                          //����� ���. ���� ��� WNDCLASS       
	wcApp.cbWndExtra	       = 0;                          //����� ����� ���. ���� 
	
	if    ( ! RegisterClass (&wcApp) )  //����������� ����   
		return  0;
	
	hWnd = CreateWindow (szWindowStyle, 
		"New title",  
		/*WS_OVERLAPPEDWINDOW*/WS_OVERLAPPED | WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX 
		| WS_MAXIMIZEBOX | WS_VSCROLL | WS_HSCROLL, //���� ���������������, ����, ������
		100,        //���������� � - ����� ������� ���� ���� 
		100,        //���������� � - ����� ������� ���� ����
		300,        //������ ���� � �������� ����������
		200,        //������ ���� � �������� ����������
		(HWND) NULL,                //��������� �� ������������ ����
		(HMENU) NULL,              //������� �� ����� ���� (��������� ����) 
		hInst,                               //���������� ���������� 
		NULL );       //����� �������������� ���������� �� ����
	ShowWindow (hWnd, SW_SHOWMINIMIZED);       //����� ����
	UpdateWindow (hWnd);                         //����������� ����
	while (GetMessage ( &lpMsg, NULL, 0, 0) ) 
	{
		TranslateMessage (&lpMsg);         //�������������� ����������� ������
		DispatchMessage (&lpMsg);         //�������� ��������� �����������
	}
	return ( lpMsg.wParam );
}

//================================
//    �������-���������� �������� ����. (��� �������� ������������)
LRESULT CALLBACK  WndProc (HWND  hWnd,               //���������� ����
						   UINT    messg,              //��� ���������
						   WPARAM  wParam,  LPARAM    lParam) 
{	
	HDC                   hdc;             //���������� ��������� ���������� 
	PAINTSTRUCT ps;                //��������� ��� ���������� ������� ����
	switch (messg) 
	{                                         
	case WM_PAINT:                     //������������ ����
		      hdc = BeginPaint (hWnd, &ps);            
			  //-----������ ��������� ������������
				MessageBox(hWnd, "Painting", "Message", MB_OK);
			  //-----����� ��������� ������������	
			  ValidateRect (hWnd,NULL); 
			  EndPaint (hWnd, &ps); 
			  break;
	case WM_DESTROY:      //������� ��������� � ���������� ����������
		PostQuitMessage (0);
		break;
	default: 
		return ( DefWindowProc (hWnd, messg, wParam, lParam)); 
	}
	return 0;
}



