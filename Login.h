#pragma once
#include "afxwin.h"


// CLogin �Ի���

class CLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLogin();

// �Ի�������
	enum { IDD = IDD_login };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CEdit name_ctrl;
	afx_msg void OnBnClickedlogin();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedsign();
};
