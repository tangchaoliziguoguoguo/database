#pragma once


// CSign 对话框

class CSign : public CDialogEx
{
	DECLARE_DYNAMIC(CSign)

public:
	CSign(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSign();

// 对话框数据
	enum { IDD = IDD_sign };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	afx_msg void OnBnClickedsign();
};
