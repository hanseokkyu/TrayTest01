// TrayTest01Dlg.h : header file
//

#if !defined(AFX_TRAYTEST01DLG_H__56EF3085_9E42_4829_B6FD_ECD3F0E86A9F__INCLUDED_)
#define AFX_TRAYTEST01DLG_H__56EF3085_9E42_4829_B6FD_ECD3F0E86A9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTrayTest01Dlg dialog

class CTrayTest01Dlg : public CDialog
{
// Construction
public:
	BOOL SHRegReadString(HKEY hKey, LPCTSTR lpKey, LPCTSTR lpValue, LPCTSTR lpDefault, LPTSTR lpRet, DWORD nSize);
	BOOL SHRegWriteString(HKEY hKey, LPCTSTR lpKey, LPCTSTR lpValue, LPCTSTR lpData);
	BOOL SHRegDeleteValue(HKEY hKey, LPCTSTR lpKey, LPCTSTR lpValue);
	void SetRestoreFromTray();
	void SetMinimizeToTray();
	CTrayTest01Dlg(CWnd* pParent = NULL);	// standard constructor

	CString str;
	CString str1;
	UINT modifier;
	UINT vkeystr_int;




// Dialog Data
	//{{AFX_DATA(CTrayTest01Dlg)
	enum { IDD = IDD_TRAYTEST01_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrayTest01Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	LRESULT OnTrayIconClick(WPARAM wParam, LPARAM lParam);
	LRESULT OnRestartTraybar(WPARAM wParam, LPARAM lParam);


	// Generated message map functions
	//{{AFX_MSG(CTrayTest01Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMenuitemAbout();
	afx_msg void OnMenuitemProgexit();
	afx_msg void OnMenuitemShowdlg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void On32778();		//example
	afx_msg void OnDummysetting();
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAYTEST01DLG_H__56EF3085_9E42_4829_B6FD_ECD3F0E86A9F__INCLUDED_)
