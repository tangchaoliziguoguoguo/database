#pragma once


// CSelectHotel 对话框

class CSelectHotel : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectHotel)

public:
	CSelectHotel(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectHotel();

// 对话框数据
	enum { IDD = IDD_Select_Hotel };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSelect();
	CString city;
};
