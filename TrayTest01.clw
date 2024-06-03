; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTrayTest01Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TrayTest01.h"

ClassCount=3
Class1=CTrayTest01App
Class2=CTrayTest01Dlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TRAYTEST01_DIALOG
Resource4=IDR_MENU_TRAYPOPUP

[CLS:CTrayTest01App]
Type=0
HeaderFile=TrayTest01.h
ImplementationFile=TrayTest01.cpp
Filter=N

[CLS:CTrayTest01Dlg]
Type=0
HeaderFile=TrayTest01Dlg.h
ImplementationFile=TrayTest01Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENUITEM_SHOWDLG

[CLS:CAboutDlg]
Type=0
HeaderFile=TrayTest01Dlg.h
ImplementationFile=TrayTest01Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TRAYTEST01_DIALOG]
Type=1
Class=CTrayTest01Dlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[MNU:IDR_MENU_TRAYPOPUP]
Type=1
Class=?
Command1=ID_MENUITEM_SHOWDLG
Command2=ID_MENUITEM_ABOUT
Command3=ID_MENUITEM_AUTORUN
Command4=ID_MENUITEM_PROGEXIT
CommandCount=4

