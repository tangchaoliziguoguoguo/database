#pragma once
#include "afxwin.h"


// CInsertResv 对话框

class CInsertResv : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertResv)

public:
	CInsertResv(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInsertResv();

// 对话框数据
	enum { IDD = IDD_Insert_Resv };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit resv_custname_ctrl;
	CString resv_custname;
	CEdit resv_num_ctrl;
	CString resv_num;
	CEdit resv_type_ctrl;
	int resv_type;
	CEdit resv_ctrl;
	CString resv;
	afx_msg void OnBnClickedInsertResv();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedUpdate();
};
