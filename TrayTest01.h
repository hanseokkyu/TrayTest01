// TrayTest01.h : main header file for the TRAYTEST01 application
//

#if !defined(AFX_TRAYTEST01_H__BCE1D05B_BBD1_4623_A72E_4E29558BB147__INCLUDED_)
#define AFX_TRAYTEST01_H__BCE1D05B_BBD1_4623_A72E_4E29558BB147__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTrayTest01App:
// See TrayTest01.cpp for the implementation of this class
//

class CTrayTest01App : public CWinApp
{
public:
	CTrayTest01App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrayTest01App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTrayTest01App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAYTEST01_H__BCE1D05B_BBD1_4623_A72E_4E29558BB147__INCLUDED_)
