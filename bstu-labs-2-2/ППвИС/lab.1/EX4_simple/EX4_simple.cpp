// EX4_simple.cpp : Defines the entry point for the application.
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
	HWND                               hWnd;                  //���������� ����
	MSG                                  lpMsg;                  //��������� �������� ��������� 
	WNDCLASS                      wcApp;                 //��������� �������� ����� ����
	wcApp.lpszClassName		= szWindowStyle;   //��� ����� ����
	wcApp.hInstance			= hInst;                   //���������� ���������� 
	wcApp.lpfnWndProc	    = WndProc;            //��������� �� ���������� ����-����� 
	wcApp.hCursor			= LoadCursor(NULL, IDC_ARROW);   //������ - "�������"
	wcApp.hIcon				= 0;                          //��� ������������� �����������
	wcApp.lpszMenuName		= 0;                          //���������� ���� (��� ����)
	wcApp.hbrBackground		= (HBRUSH) GetStockObject (WHITE_BRUSH); //���� ���� 
	wcApp.style				= CS_HREDRAW | CS_VREDRAW; //�������������� ����
	wcApp.cbClsExtra	    = 0;                          //����� ���. ���� ��� WNDCLASS       
	wcApp.cbWndExtra	    = 0;                          //����� ����� ���. ���� 
	
	if    ( ! RegisterClass (&wcApp) )  //����������� ����   
		return  0;
	
	hWnd = CreateWindow (szWindowStyle, 
		"������� ������ Windows-���������� � ",  
		WS_OVERLAPPEDWINDOW, //���� ���������������, ����, ������
		CW_USEDEFAULT,        //���������� � - ����� ������� ���� ���� 
		CW_USEDEFAULT,        //���������� � - ����� ������� ���� ����
		500,        //������ ���� � �������� ����������
		400,        //������ ���� � �������� ����������
		(HWND) NULL,                //��������� �� ������������ ����
		(HMENU) NULL,              //������� �� ����� ���� (��������� ����) 
		hInst,                               //���������� ���������� 
		NULL );       //����� �������������� ���������� �� ����
	ShowWindow (hWnd, nCmdShow);       //����� ����
	UpdateWindow (hWnd);                         //����������� ����
	while (GetMessage ( &lpMsg, NULL, 0, 0)) 
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
			  //-----����� ��������� ������������	
			  ValidateRect (hWnd,NULL); 
			  EndPaint (hWnd, &ps); 
			  break;
	case WM_DESTROY:      //������� ��������� � ���������� ����������
		MessageBox(hWnd, "Window has been destroyed", "Message", MB_OK);
		PostQuitMessage (0);
		break;
	case WM_LBUTTONDBLCLK:
		MessageBox(hWnd, "Double click occurred", "Message", MB_OK);
		break;
	default: 
		return ( DefWindowProc (hWnd, messg, wParam, lParam)); 
	}
	return 0;
}

