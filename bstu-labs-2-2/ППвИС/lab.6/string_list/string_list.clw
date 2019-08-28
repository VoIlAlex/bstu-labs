; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CListDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "string_list.h"
LastPage=0

ClassCount=6
Class1=CString_listApp
Class2=CString_listDoc
Class3=CString_listView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CListDlg
Resource3=IDD_DIALOG1

[CLS:CString_listApp]
Type=0
HeaderFile=string_list.h
ImplementationFile=string_list.cpp
Filter=N

[CLS:CString_listDoc]
Type=0
HeaderFile=string_listDoc.h
ImplementationFile=string_listDoc.cpp
Filter=N

[CLS:CString_listView]
Type=0
HeaderFile=string_listView.h
ImplementationFile=string_listView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=IDM_RUN




[CLS:CAboutDlg]
Type=0
HeaderFile=string_list.cpp
ImplementationFile=string_list.cpp
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
Command17=IDM_RUN
CommandCount=17

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

[DLG:IDD_DIALOG1]
Type=1
Class=CListDlg
ControlCount=6
Control1=IDCANCEL,button,1342242816
Control2=IDC_LIST1,listbox,1352728835
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_ADD,button,1342242816
Control5=IDC_REMOVE,button,1342242816
Control6=IDC_EDIT,button,1342242816

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

[CLS:CListDlg]
Type=0
HeaderFile=ListDlg.h
ImplementationFile=ListDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_REMOVE
VirtualFilter=dWC

