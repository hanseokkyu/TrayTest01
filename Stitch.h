#pragma once
#include "stdafx.h"
#include "afxwin.h"
#include "TrayTest01.h"
#include "TrayTest01Dlg.h"




// CStitch 대화 상자입니다.

class CStitch : public CDialog
{
	DECLARE_DYNAMIC(CStitch)

public:
	LRESULT OnHotKey(WPARAM wParam, LPARAM lParam);
	CStitch(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CStitch();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

	CString str;
	CString str1;
	CString mod[6];
	CString vk[6];
	UINT modifier;
	int modifier_ans[6];
	UINT vkeystr_int;
	int vkeystr_ans[6];



protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

protected:
	HICON m_hIcon;
	HACCEL m_hAccel;
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);


	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo_control;
	CString m_combo_str;
	void OninitThread();
	afx_msg void OnSpeak();
	afx_msg void En_SetFocus();
	afx_msg void HotKey();
	afx_msg void add();
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	


	CButton check_1;
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	CEdit myedit1;
	CEdit myedit2;
	CEdit myedit3;
	CEdit myedit4;
	CEdit myedit5;
	CEdit myedit6;
	CEdit ans1;
	CEdit ans2;
	CEdit ans3;
	CEdit ans4;
	CEdit ans5;
	CEdit ans6;
	CComboBox m_modifier;
	CComboBox m_virkey;
};
