// EX5_simple.cpp : Defines the entry point for the application.
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
	HWND                   hWnd;                  //дескриптор окна
	MSG                    lpMsg;                  //структура хранения сообщений 
	WNDCLASS               wcApp;                 //структура описания стиля окна
	wcApp.lpszClassName	   = szWindowStyle;   //имя стиля окна
	wcApp.hInstance	       = hInst;                   //дескриптор приложения 
	wcApp.lpfnWndProc	   = WndProc;            //указатель на обработчик сооб-щений 
	wcApp.hCursor	       = LoadCursor(NULL, IDC_WAIT);   //курсор - "стрелка"
	wcApp.hIcon		       = 0;                          //без использования пиктограммы
	wcApp.lpszMenuName	   = 0;                          //дескриптор меню (без меню)
	wcApp.hbrBackground    = (HBRUSH) GetStockObject (BLACK_BRUSH); //цвет фона 
	wcApp.style		       = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE; //перерисовывать окно 
	wcApp.cbClsExtra	       = 0;                          //число доп. байт для WNDCLASS       
	wcApp.cbWndExtra	       = 0;                          //общее число доп. байт 
	
	if    ( ! RegisterClass (&wcApp) )  //регистрация окна   
		return  0;
	
	hWnd = CreateWindow (szWindowStyle, 
		"New title",  
		/*WS_OVERLAPPEDWINDOW*/WS_OVERLAPPED | WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX 
		| WS_MAXIMIZEBOX | WS_VSCROLL | WS_HSCROLL, //окно перекрывающееся, меню, кнопки
		100,        //координата х - левый верхний угол окна 
		100,        //координата у - левый верхний угол окна
		300,        //ширина окна в единицах устройства
		200,        //высота окна в единицах устройства
		(HWND) NULL,                //указатель на родительское окно
		(HMENU) NULL,              //зависит от стиля окна (указатель меню) 
		hInst,                               //дескриптор приложения 
		NULL );       //адрес дополнительной информации об окне
	ShowWindow (hWnd, SW_SHOWMINIMIZED);       //вывод окна
	UpdateWindow (hWnd);                         //перерисовка окна
	while (GetMessage ( &lpMsg, NULL, 0, 0) ) 
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
				MessageBox(hWnd, "Painting", "Message", MB_OK);
			  //-----Конец фрагмента пользователя	
			  ValidateRect (hWnd,NULL); 
			  EndPaint (hWnd, &ps); 
			  break;
	case WM_DESTROY:      //послать сообщение о завершении приложения
		PostQuitMessage (0);
		break;
	default: 
		return ( DefWindowProc (hWnd, messg, wParam, lParam)); 
	}
	return 0;
}



