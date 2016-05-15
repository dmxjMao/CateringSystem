
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

	CString pwd;//记录登录用户密码
	CString name;//记录登录用户名
	_ConnectionPtr m_pCon;//连接数据库

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCateringSystemApp theApp;