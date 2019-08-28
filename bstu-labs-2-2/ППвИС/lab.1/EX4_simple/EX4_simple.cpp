// EX4_simple.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

LRESULT CALLBACK	    WndProc (HWND, UINT, WPARAM, LPARAM);
char   szWindowStyle [ ] = "myWindowStyle";

//===============================
//    ГЛАВНАЯ ФУНКЦИЯ 
int  WINAPI  WinMain   (HINSTANCE hInst,  //дескриптор приложения
						HINSTANCE hPreInst,  //всегда NULL
						LPSTR          lpszCmdLine,  //командная строка
						int                 nCmdShow) //окно при первом выводе
{    	
	HWND                               hWnd;                  //дескриптор окна
	MSG                                  lpMsg;                  //структура хранения сообщений 
	WNDCLASS                      wcApp;                 //структура описания стиля окна
	wcApp.lpszClassName		= szWindowStyle;   //имя стиля окна
	wcApp.hInstance			= hInst;                   //дескриптор приложения 
	wcApp.lpfnWndProc	    = WndProc;            //указатель на обработчик сооб-щений 
	wcApp.hCursor			= LoadCursor(NULL, IDC_ARROW);   //курсор - "стрелка"
	wcApp.hIcon				= 0;                          //без использования пиктограммы
	wcApp.lpszMenuName		= 0;                          //дескриптор меню (без меню)
	wcApp.hbrBackground		= (HBRUSH) GetStockObject (WHITE_BRUSH); //цвет фона 
	wcApp.style				= CS_HREDRAW | CS_VREDRAW; //перерисовывать окно
	wcApp.cbClsExtra	    = 0;                          //число доп. байт для WNDCLASS       
	wcApp.cbWndExtra	    = 0;                          //общее число доп. байт 
	
	if    ( ! RegisterClass (&wcApp) )  //регистрация окна   
		return  0;
	
	hWnd = CreateWindow (szWindowStyle, 
		"ТИПОВОЙ КАРКАС Windows-приложения … ",  
		WS_OVERLAPPEDWINDOW, //окно перекрывающееся, меню, кнопки
		CW_USEDEFAULT,        //координата х - левый верхний угол окна 
		CW_USEDEFAULT,        //координата у - левый верхний угол окна
		500,        //ширина окна в единицах устройства
		400,        //высота окна в единицах устройства
		(HWND) NULL,                //указатель на родительское окно
		(HMENU) NULL,              //зависит от стиля окна (указатель меню) 
		hInst,                               //дескриптор приложения 
		NULL );       //адрес дополнительной информации об окне
	ShowWindow (hWnd, nCmdShow);       //вывод окна
	UpdateWindow (hWnd);                         //перерисовка окна
	while (GetMessage ( &lpMsg, NULL, 0, 0)) 
	{
		TranslateMessage (&lpMsg);         //преобразование виртуальных клавиш
		DispatchMessage (&lpMsg);         //передача сообщения обработчику
	}
	return ( lpMsg.wParam );
}

//================================
//    ФУНКЦИЯ-ОБРАБОТЧИК ГЛАВНОГО ОКНА. (имя выбирает пользователь)
LRESULT CALLBACK  WndProc (HWND  hWnd,               //дескриптор окна
						   UINT    messg,              //код сообщения
						   WPARAM  wParam,  LPARAM    lParam) 
{	
	HDC                   hdc;             //дескриптор контекста устройства 
	PAINTSTRUCT ps;                //структура для клиентской области окна
	switch (messg) 
	{                                         
	case WM_PAINT:                     //перерисовать окно
		      hdc = BeginPaint (hWnd, &ps);            
			  //-----Начало фрагмента пользователя
			  //-----Конец фрагмента пользователя	
			  ValidateRect (hWnd,NULL); 
			  EndPaint (hWnd, &ps); 
			  break;
	case WM_DESTROY:      //послать сообщение о завершении приложения
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

