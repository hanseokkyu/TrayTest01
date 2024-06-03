// TrayTest01Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "TrayTest01.h"
#include "TrayTest01Dlg.h"
#include "Stitch.h"
#include <MMSystem.h>
#pragma comment(lib, "winmm")


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define TRAY_NOTIFY        (WM_APP + 100)
#define RUNKEY             "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
#define AUTORUN_VALUENAME  "TestTray01_Run"
#define AUTORUN_ADDARGU    "/logon"  
UINT    g_uRestartTb;
UINT ThreadExposure(LPVOID lParam);

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrayTest01Dlg dialog

CTrayTest01Dlg::CTrayTest01Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrayTest01Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTrayTest01Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrayTest01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrayTest01Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTrayTest01Dlg, CDialog)
	//{{AFX_MSG_MAP(CTrayTest01Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_COMMAND(ID_MENUITEM_ABOUT, OnMenuitemAbout)
	ON_COMMAND(ID_MENUITEM_PROGEXIT, OnMenuitemProgexit)
	ON_COMMAND(ID_MENUITEM_SHOWDLG, OnMenuitemShowdlg)
	//}}AFX_MSG_MAP
	ON_MESSAGE(TRAY_NOTIFY, OnTrayIconClick)
	ON_REGISTERED_MESSAGE(g_uRestartTb, OnRestartTraybar)
	//ON_COMMAND(ID_32778, &CTrayTest01Dlg::On32778)
	ON_COMMAND(ID_DUMMY_32776, &CTrayTest01Dlg::OnDummysetting)	//example
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrayTest01Dlg message handlers

BOOL CTrayTest01Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	// TODO: Add extra initialization here

	ShowWindow(SW_SHOWMINIMIZED);
	PostMessage(WM_SHOWWINDOW,FALSE,SW_OTHERUNZOOM);

	// explorer 프로세스가 재시작할때 트레이 아이콘을 다시 그리게 
	// 할 목적으로 메시지 등록
	g_uRestartTb = RegisterWindowMessage(_T("TaskbarCreated")); 

	// argument로 하나 이상의 문자열이 입력되면... 
	if(__argc > 1 && __argv[1])
	{
		CString str = _T("");;
		str=__argv[1];
		// 첫번째로 입력된 문자열이 /logon 이라면...
		// CompareNoCase함수는 영문자 비교시 대소문자에 상관없이 비교함 (즉 a와 A는 같은 문자)
		//if (str.CompareNoCase(AUTORUN_ADDARGU)==0)
		//{
		SetMinimizeToTray();
		//}
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTrayTest01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTrayTest01Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrayTest01Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CTrayTest01Dlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	UnregisterHotKey(this->m_hWnd,100);
	UnregisterHotKey(this->m_hWnd,101);
	UnregisterHotKey(this->m_hWnd,102);
	UnregisterHotKey(this->m_hWnd,103);
	UnregisterHotKey(this->m_hWnd,104);
	UnregisterHotKey(this->m_hWnd,105);

	SetRestoreFromTray();
}

LRESULT CTrayTest01Dlg::OnRestartTraybar(WPARAM wParam, LPARAM lParam) 
{ 
	SetMinimizeToTray();
	
    return 0;
} 

void CTrayTest01Dlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	// 윈도우가 최소화 되면...
	if (nType==SIZE_MINIMIZED)
	{
		// 트레이 모드로...
		SetMinimizeToTray();
	}
}



LRESULT CTrayTest01Dlg::OnTrayIconClick(WPARAM wParam, LPARAM lParam)
{
	switch(lParam)
	{
	case WM_LBUTTONDBLCLK:   // 트레이아이콘 왼쪽버튼 더블클릭시 창이 다시 열린다.
		{ 
			SetRestoreFromTray();
		}
		break;
	case WM_RBUTTONDOWN:     // 트레이아이콘 오른쪽버튼 클릭시 팝업메뉴창 띄운다.
		{
			CPoint ptMouse;
			::GetCursorPos(&ptMouse);

			char   szStr[MAX_PATH*3];
			CMenu menu;
			menu.LoadMenu(IDR_MENU_TRAYPOPUP);			
			CMenu *pMenu = menu.GetSubMenu(0);
			pMenu->CheckMenuItem(ID_MENUITEM_AUTORUN, MF_UNCHECKED);
			if (SHRegReadString(HKEY_LOCAL_MACHINE, (LPCTSTR)RUNKEY, (LPCTSTR)AUTORUN_VALUENAME, _T(""),(TCHAR*)szStr, MAX_PATH*2))
			{
				CString str = _T("");;
				str=szStr;
				str.TrimLeft();
				str.TrimRight();
			}			

			pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
								  ptMouse.x, ptMouse.y, AfxGetMainWnd());
		}
		break;
	}

	return 0;
}

void CTrayTest01Dlg::SetMinimizeToTray()
{
	NOTIFYICONDATA nid;

	ShowWindow(SW_SHOWMINIMIZED);
	PostMessage(WM_SHOWWINDOW, FALSE, SW_OTHERUNZOOM);
	
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = 0;
	Shell_NotifyIcon(NIM_DELETE, &nid);

	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hIcon = AfxGetApp()->LoadIcon(IDI_TRAYICON01);
	nid.hWnd = this->m_hWnd;
	CString str = _T("");;
	GetWindowText(str);
	_tcscpy(nid.szTip, str.GetBuffer(str.GetLength()+1));
	str.ReleaseBuffer();
	nid.uID = 0;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.uCallbackMessage = TRAY_NOTIFY;
	Shell_NotifyIcon(NIM_ADD, &nid);
}

void CTrayTest01Dlg::SetRestoreFromTray()
{
	NOTIFYICONDATA nid;

	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = 0;
	Shell_NotifyIcon(NIM_DELETE, &nid);

	ShowWindow(SW_RESTORE);
	SetForegroundWindow();
}


BOOL CTrayTest01Dlg::SHRegReadString(HKEY hKey, LPCTSTR lpKey, 
									 LPCTSTR lpValue, LPCTSTR lpDefault, 
									 LPTSTR lpRet, DWORD nSize) 
{
	HKEY  key;
	DWORD dwDisp;
	DWORD Size;

	if (RegCreateKeyEx(hKey, lpKey,0,NULL,
		REG_OPTION_NON_VOLATILE, KEY_READ,NULL,&key,&dwDisp)
		!=ERROR_SUCCESS)
		return FALSE;

	Size=nSize;

	if (RegQueryValueEx(key, lpValue, 0, NULL,(LPBYTE)lpRet, &Size)
		!=ERROR_SUCCESS) {
		_tcscpy(lpRet, lpDefault);
		return FALSE;
	}

	RegCloseKey(key);

	return TRUE;
}


BOOL CTrayTest01Dlg::SHRegWriteString(HKEY hKey, LPCTSTR lpKey, LPCTSTR lpValue, LPCTSTR lpData)
{
	HKEY  key;
	DWORD dwDisp;

	if (RegCreateKeyEx(hKey, lpKey,0,NULL,
		REG_OPTION_NON_VOLATILE, KEY_WRITE,NULL,&key,&dwDisp)
		!=ERROR_SUCCESS) 
		return FALSE;

	if (RegSetValueEx(key, lpValue,0,REG_SZ,(LPBYTE)lpData,_tcslen(lpData)+1)
		!=ERROR_SUCCESS) 
		return FALSE;

	RegCloseKey(key);

	return TRUE;
}

BOOL CTrayTest01Dlg::SHRegDeleteValue(HKEY hKey, LPCTSTR lpKey, LPCTSTR lpValue)
{
    HKEY  key;
    
    if (RegOpenKeyEx(hKey, lpKey, 0, KEY_ALL_ACCESS, &key)!=ERROR_SUCCESS) 
		return FALSE;

    if (RegDeleteValue(key, lpValue)!=ERROR_SUCCESS) 
		return FALSE;

    RegCloseKey(key);

	return TRUE;
}



void CTrayTest01Dlg::OnMenuitemAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();	
}

void CTrayTest01Dlg::OnMenuitemProgexit() 
{
	// TODO: Add your command handler code here
	DestroyWindow();
}

void CTrayTest01Dlg::OnMenuitemShowdlg() 
{
	// TODO: Add your command handler code here
	SetRestoreFromTray();
}



//void CTrayTest01Dlg::On32778()   //example
//{
//	// TODO: ??? ?? ??? ??? ?????.
//	CStitch dlg;
//	dlg.DoModal();
//}

void CTrayTest01Dlg::OnDummysetting()
{
	CStitch dlg;
	dlg.DoModal();
}