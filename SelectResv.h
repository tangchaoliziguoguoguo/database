#pragma once
#include "afxwin.h"


// CSelectResv 对话框

class CSelectResv : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectResv)

public:
	CSelectResv(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectResv();

// 对话框数据
	enum { IDD = IDD_Select_Resv };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString num;
	CString name;
	afx_msg void OnBnClickedSelectNum();
	afx_msg void OnBnClickedSelectname();
	CComboBox type_ctrl;
	afx_msg void OnBnClickedSelecttype();
	virtual BOOL OnInitDialog();
};
