#pragma once


// CSelectCustomer 对话框

class CSelectCustomer : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectCustomer)

public:
	CSelectCustomer(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectCustomer();

// 对话框数据
	enum { IDD = IDD_Select_Customer };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	afx_msg void OnBnClickedSelect();
};
