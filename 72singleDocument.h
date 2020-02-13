
// 72singleDocument.h: 72singleDocument 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMy72singleDocumentApp:
// 有关此类的实现，请参阅 72singleDocument.cpp
//

class CMy72singleDocumentApp : public CWinApp
{
public:
	CMy72singleDocumentApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy72singleDocumentApp theApp;
