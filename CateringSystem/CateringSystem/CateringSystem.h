
// CateringSystem.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCateringSystemApp:
// See CateringSystem.cpp for the implementation of this class
//

class CCateringSystemApp : public CWinApp
{
public:
	CCateringSystemApp();

	CString pwd;//��¼��¼�û�����
	CString name;//��¼��¼�û���
	_ConnectionPtr m_pCon;//�������ݿ�

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCateringSystemApp theApp;