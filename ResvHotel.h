#pragma once
#include "afxwin.h"


// CResvHotel 对话框

class CResvHotel : public CDialogEx
{
	DECLARE_DYNAMIC(CResvHotel)

public:
	CResvHotel(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CResvHotel();

// 对话框数据
	enum { IDD = IDD_Resv_Hotel };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit city_ctrl;
	CString city;
	CComboBox customer_ctrl;
	CString customer;
	CString resv_num;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CEdit resv_num_ctrl;
};
