#pragma once
#include "afxwin.h"


// CLogin 对话框

class CLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLogin();

// 对话框数据
	enum { IDD = IDD_login };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CEdit name_ctrl;
	afx_msg void OnBnClickedlogin();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedsign();
};
