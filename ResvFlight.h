#pragma once
#include "afxwin.h"


// CResvFlight 对话框

class CResvFlight : public CDialogEx
{
	DECLARE_DYNAMIC(CResvFlight)

public:
	CResvFlight(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CResvFlight();

// 对话框数据
	enum { IDD = IDD_Resv_Flight };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit flight_num_ctrl;
	CString flight_num;
	CString resv_num;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedResv();
	CComboBox customer_ctrl;
	CString customer;
	CEdit resv_num_ctrl;
	CEdit route_ctrl;
	CEdit date_ctrl;
};
