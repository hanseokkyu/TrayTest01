// Stitch.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TrayTest01.h"
#include "Stitch.h"
#include "afxdialogex.h"
#include <mmSystem.h>
#pragma comment(lib, "winmm")
#include <sapi.h>
#include <Imm.h>

HHOOK g_hook=NULL;

// CStitch 대화 상자입니다.

IMPLEMENT_DYNAMIC(CStitch, CDialog)

CStitch::CStitch(CWnd* pParent /*=NULL*/)
	: CDialog(CStitch::IDD, pParent)
	, m_combo_str(_T(""))
{

}

CStitch::~CStitch()
{
}



BOOL CStitch::OnInitDialog()
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
	SetIcon(m_hIcon, FALSE);

	m_combo_control.AddString(_T("Korea"));
	m_combo_control.AddString(_T("china"));
	m_combo_control.AddString(_T("japan"));

	m_combo_control.SetCurSel(0);
	//SetHook();

	//OninitThread();

	 

	m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_ACCELERATOR1));

	CRect rect;
	GetClientRect(&rect);
	CPoint pos;
	pos.x = GetSystemMetrics(SM_CXSCREEN)/1.3f - rect.Width()/30.0f;
	pos.y = GetSystemMetrics(SM_CXSCREEN)/2.2f - rect.Height()/2.0f;
	SetWindowPos(NULL,pos.x,pos.y,0,0,SWP_NOSIZE);


	return TRUE;
}

BOOL CStitch::PreTranslateMessage(MSG* pMsg)
{
	if(::TranslateAccelerator(this->m_hWnd, m_hAccel, pMsg)) return TRUE;

	if(pMsg->message == WM_KEYDOWN)
	{

        if(GetKeyState(VK_SHIFT) & 0x8000 && pMsg->wParam == 90)
		{
			modifier=MOD_SHIFT;
            if(pMsg->wParam == 90)
			{
				vkeystr_int=0x5A;
				str1.Format(_T("Shift+Z"));
				
			}
            else if(pMsg->wParam == 88)
			{
				vkeystr_int=0x58;
				str1.Format(_T("Shift+X"));
				
			}
			else if(pMsg->wParam == 67)
			{
				vkeystr_int=0x43;
				str1.Format(_T("Shift+C"));
				
			}
			else if(pMsg->wParam == 86)
			{
				vkeystr_int=0x56;
				str1.Format(_T("Shift+V"));
				
			}
        }

		if(GetKeyState(VK_CONTROL) & 0x8000)
		{
			modifier=MOD_CONTROL;
            if(pMsg->wParam == 90)
			{
				vkeystr_int=0x5A;
				str1.Format(_T("MOD_CONTROL+Z"));
			}
            else if(pMsg->wParam == 88)
			{
				vkeystr_int=0x58;
				str1.Format(_T("MOD_CONTROL+X"));
			}
			else if(pMsg->wParam == 67)
			{
				vkeystr_int=0x43;
				str1.Format(_T("MOD_CONTROL+C"));
			}
			else if(pMsg->wParam == 86)
			{
				vkeystr_int=0x56;
				str1.Format(_T("MOD_CONTROL+V"));
			}
		}

		if(GetKeyState(VK_SPACE) & 0x8000)
		{
			modifier=MOD_ALT;
           if(pMsg->wParam == 90)
			{
				vkeystr_int=0x5A;
				str1.Format(_T("VK_SPACE+Z"));
			}
            else if(pMsg->wParam == 88)
			{
				vkeystr_int=0x58;
				str1.Format(_T("VK_SPACE+X"));
			}
			else if(pMsg->wParam == 67)
			{
				vkeystr_int=0x43;
				str1.Format(_T("VK_SPACE+C"));
			}
			else if(pMsg->wParam == 86)
			{
				vkeystr_int=0x56;
				str1.Format(_T("VK_SPACE+V"));
			}
		}
			
		if(GetKeyState(VK_MENU) & 0x8000)
		{
			modifier=MOD_ALT;
            if(pMsg->wParam == 90)
			{
				vkeystr_int=0x5A;
				str1.Format(_T("MOD_ALT+Z"));
			}
            else if(pMsg->wParam == 88)
			{
				vkeystr_int=0x58;
				str1.Format(_T("MOD_ALT+X"));
			}
			else if(pMsg->wParam == 67)
			{
				vkeystr_int=0x43;
				str1.Format(_T("MOD_ALT+C"));
			}
			else if(pMsg->wParam == 86)
			{
				vkeystr_int=0x56;
				str1.Format(_T("MOD_ALT+V"));
			}
        }
		if(RegisterHotKey(m_hWnd,count,modifier,vkeystr_int))
			{
				add();
				HotKey();
			}
    }

	return CDialog::PreTranslateMessage(pMsg);
}

void CStitch::add()
{
	if(count == 100)
	{
		myedit1.SetWindowTextW(str1);
	}
	else if(count == 101)
	{
		myedit2.SetWindowTextW(str1);
	}
	else if(count == 102)
	{
		myedit3.SetWindowTextW(str1);
	}
	else if(count == 103)
	{
		myedit4.SetWindowTextW(str1);
	}
	else if(count == 104)
	{
		myedit5.SetWindowTextW(str1);
	}
	else if(count == 105)
	{
		myedit6.SetWindowTextW(str1);
	}
	
}


void CStitch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO1, m_combo_control);
	DDX_CBString(pDX, IDC_COMBO1, m_combo_str);
	DDX_Control(pDX, IDC_EDIT1, myedit1);
	DDX_Control(pDX, IDC_EDIT2, myedit2);
	DDX_Control(pDX, IDC_EDIT3, myedit3);
	DDX_Control(pDX, IDC_EDIT4, myedit4);
	DDX_Control(pDX, IDC_EDIT5, myedit5);
	DDX_Control(pDX, IDC_EDIT6, myedit6);
	DDX_Control(pDX, IDC_EDIT7, ans1);
	DDX_Control(pDX, IDC_EDIT8, ans2);
	DDX_Control(pDX, IDC_EDIT9, ans3);
	DDX_Control(pDX, IDC_EDIT10, ans4);
	DDX_Control(pDX, IDC_EDIT11, ans5);
	DDX_Control(pDX, IDC_EDIT12, ans6);

}


BEGIN_MESSAGE_MAP(CStitch, CDialog)

	ON_WM_HOTKEY()
END_MESSAGE_MAP()




//void CStitch::OnBnClickedButton2()
//{
//
//	str = _T("");
//	GetDlgItemText(IDC_EDIT3, str);
//
//	SetDlgItemText(IDC_EDIT4, str);
//
//	OnSpeak();
//	//AfxMessageBox(_T(str));
//}

void CStitch::OnSpeak()    // 말하기
{

	UpdateData();
	ISpVoice * pVoice = NULL;

    if (FAILED(CoInitialize(NULL)))
	{
		AfxMessageBox(_T("Error to intiliaze COM"));
        return;
	}

    HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
    if( SUCCEEDED( hr ) )
    {
        hr = pVoice->Speak(str.AllocSysString(), 0, NULL);
        pVoice->Release();
        pVoice = NULL;
    }
    CoUninitialize();
}

void CStitch::En_SetFocus()
{
	HIMC himc=ImmGetContext(GetDlgItem(IDC_EDIT1)->GetSafeHwnd());
	ImmSetConversionStatus(himc, IME_CMODE_NATIVE,IME_SMODE_CONVERSATION);
	ImmReleaseContext(GetDlgItem(IDC_EDIT1)->GetSafeHwnd(),himc);
}


void CStitch::HotKey()
{
	RegisterHotKey(m_hWnd,count,modifier,vkeystr_int);
	RegisterHotKey(m_hWnd,count,modifier,vkeystr_int);
	RegisterHotKey(m_hWnd,count,modifier,vkeystr_int);
	RegisterHotKey(m_hWnd,count,modifier,vkeystr_int);
	RegisterHotKey(m_hWnd,count,modifier,vkeystr_int);
	RegisterHotKey(m_hWnd,count,modifier,vkeystr_int);
	count++;
}


//void CStitch::OnBnClickedButton1()
//{
//	// TODO: Add your control notification handler code here
//	m_modifier.GetLBText(m_modifier.GetCurSel(),modifierstring);
//	
//	if(modifierstring=="MOD_ALT")
//		modifier=MOD_ALT;
//	else if (modifierstring=="MOD_CONTROL")
//		modifier=MOD_CONTROL;
//	else if(modifierstring=="MOD_SHIFT")
//		modifier=MOD_SHIFT;
//	else if(modifierstring=="MOD_WIN")
//		modifier=MOD_WIN;
//
//	m_virkey.GetLBText(m_virkey.GetCurSel(),vkeystr);
//	if(vkeystr=="A")
//		vkeystr_int=0x41;
//	else if (vkeystr=="B")
//		vkeystr_int=0x42;
//	else if(vkeystr=="C")
//		vkeystr_int=0x43;
//	else if(vkeystr=="D")
//		vkeystr_int=0x44;
//	if(RegisterHotKey(m_hWnd,count,modifier,vkeystr_int))
//	{	
//		num++;
//		modifier_ans[num] = modifier;
//		vkeystr_ans[num] = vkeystr_int;
//		mod[num] = modifierstring;
//		vk[num] = vkeystr;
//		count++;
//		HotKey();
//	}
//	else
//		MessageBox(_T("RegisterHotKey failed"));
//}

void CStitch::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	if (nHotKeyId == 100) {
		str = _T("");
		GetDlgItemText(IDC_EDIT7, str);
		ans1.SetWindowTextW(str);
		//myedit1.SetWindowTextW(str1);
		OnSpeak();
	}
	else if (nHotKeyId == 101) {
		str = _T("");
		GetDlgItemText(IDC_EDIT8, str);
		ans2.SetWindowTextW(str);
		//myedit2.SetWindowTextW(str1);
		OnSpeak();
	}
	else if (nHotKeyId == 102) {
		str = _T("");
		GetDlgItemText(IDC_EDIT9, str);
		ans3.SetWindowTextW(str);
		//myedit3.SetWindowTextW(str1);
		OnSpeak();
	}
	else if (nHotKeyId == 103) {
		str = _T("");
		GetDlgItemText(IDC_EDIT10, str);
		ans4.SetWindowTextW(str);
		//myedit4.SetWindowTextW(str1);
		OnSpeak();
	}
	else if (nHotKeyId == 104) {
		str = _T("");
		GetDlgItemText(IDC_EDIT11, str);
		ans5.SetWindowTextW(str);
		//myedit5.SetWindowTextW(str1);
		OnSpeak();
	}
	else if (nHotKeyId == 106) {
		str = _T("");
		GetDlgItemText(IDC_EDIT12, str);
		ans6.SetWindowTextW(str);
		//myedit6.SetWindowTextW(str1);
		OnSpeak();
	}
	CDialog::OnHotKey(nHotKeyId, nKey1, nKey2);
}


