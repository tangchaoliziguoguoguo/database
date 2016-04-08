
// db_lab2Dlg.h : 头文件
//

#pragma once


// Cdb_lab2Dlg 对话框
class Cdb_lab2Dlg : public CDialogEx
{
// 构造
public:
	Cdb_lab2Dlg(CWnd* pParent = NULL);	// 标准构造函数
	
//	CDatabase my_db;

// 对话框数据
	enum { IDD = IDD_DB_LAB2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedclientlogin();
	bool limit;
};
