; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEnterDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "project_menu.h"
LastPage=0

ClassCount=7
Class1=CProject_menuApp
Class2=CProject_menuDoc
Class3=CProject_menuView
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_MAINFRAME
Resource2=IDR_MENU1
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX
Class6=CEnterDlg
Resource4=IDD_ENTER
Class7=CViewDlg
Resource5=IDD_VIEW

[CLS:CProject_menuApp]
Type=0
HeaderFile=project_menu.h
ImplementationFile=project_menu.cpp
Filter=N

[CLS:CProject_menuDoc]
Type=0
HeaderFile=project_menuDoc.h
ImplementationFile=project_menuDoc.cpp
Filter=N

[CLS:CProject_menuView]
Type=0
HeaderFile=project_menuView.h
ImplementationFile=project_menuView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=project_menu.cpp
ImplementationFile=project_menu.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=IDM_ENTER
Command2=IDM_VIEW
CommandCount=2

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CEnterDlg]
Type=0
HeaderFile=EnterDlg.h
ImplementationFile=EnterDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CEnterDlg
VirtualFilter=dWC

[DLG:IDD_ENTER]
Type=1
Class=CEnterDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552

[DLG:IDD_VIEW]
Type=1
Class=CViewDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CViewDlg]
Type=0
HeaderFile=ViewDlg.h
ImplementationFile=ViewDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CViewDlg

