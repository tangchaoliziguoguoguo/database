#pragma once
#include "afxwin.h"


// CInsertCustomer �Ի���

class CInsertCustomer : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertCustomer)

public:
	CInsertCustomer(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInsertCustomer();

// �Ի�������
	enum { IDD = IDD_Insert_Customer };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString Insert_Customer;
	afx_msg void OnEnChangeInsertCustomer();
	afx_msg void OnBnClickedInsert();
	CEdit Insert_Customer_Text;
	virtual BOOL OnInitDialog();
};
