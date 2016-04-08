#pragma once
#include "afxwin.h"


// CInsertHotels 对话框

class CInsertHotels : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertHotels)

public:
	CInsertHotels(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInsertHotels();

// 对话框数据
	enum { IDD = IDD_Insert_Hotels };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString hotel_city;
	int hotel_price;
	int hotel_num;
	afx_msg void OnBnClickedInsertHotel();
	CEdit hotel_city_ctrl;
	CEdit hotel_price_ctrl;
	CEdit hotel_num_ctrl;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit3();
};
