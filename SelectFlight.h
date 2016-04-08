#pragma once
#include "afxwin.h"


// CSelectFlight 对话框

class CSelectFlight : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectFlight)

public:
	CSelectFlight(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectFlight();

// 对话框数据
	enum { IDD = IDD_SELECT_FLIGHT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString num;
	CString from_city;
	CString ariv_city;
	afx_msg void OnBnClickedSelectNum();
	afx_msg void OnBnClickedSelectCity();
	CComboBox date_ctrl;
	virtual BOOL OnInitDialog();
};
