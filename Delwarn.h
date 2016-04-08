#pragma once


// CDelwarn 对话框

class CDelwarn : public CDialogEx
{
	DECLARE_DYNAMIC(CDelwarn)

public:
	CDelwarn(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDelwarn();

// 对话框数据
	enum { IDD = IDD_WARNING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
