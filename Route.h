#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CRoute 对话框

class CRoute : public CDialogEx
{
	DECLARE_DYNAMIC(CRoute)

public:
	CRoute(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRoute();

// 对话框数据
	enum { IDD = IDD_Route };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void SetListBox(CString);
	CComboBox cust_ctrl;
	afx_msg void OnCbnSelchangecust();
	CString customer;
	afx_msg void OnBnClickedcheck();
	CListCtrl list;
};
