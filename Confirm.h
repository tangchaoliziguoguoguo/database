#pragma once


// CConfirm 对话框

class CConfirm : public CDialogEx
{
	DECLARE_DYNAMIC(CConfirm)

public:
	CConfirm(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConfirm();

// 对话框数据
	enum { IDD = IDD_confirm };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
