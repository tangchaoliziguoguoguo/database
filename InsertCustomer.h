#pragma once
#include "afxwin.h"


// CInsertCustomer 对话框

class CInsertCustomer : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertCustomer)

public:
	CInsertCustomer(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInsertCustomer();

// 对话框数据
	enum { IDD = IDD_Insert_Customer };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Insert_Customer;
	afx_msg void OnEnChangeInsertCustomer();
	afx_msg void OnBnClickedInsert();
	CEdit Insert_Customer_Text;
	virtual BOOL OnInitDialog();
};
