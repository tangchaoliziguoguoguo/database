
// db_lab2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cdb_lab2App:
// �йش����ʵ�֣������ db_lab2.cpp
//

class Cdb_lab2App : public CWinApp
{
public:
	Cdb_lab2App();

	CString username;
	

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cdb_lab2App theApp;