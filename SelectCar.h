#pragma once


// CSelectCar 对话框

class CSelectCar : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectCar)

public:
	CSelectCar(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectCar();

// 对话框数据
	enum { IDD = IDD_Select_Car };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString city;
	afx_msg void OnBnClickedSelect();
};
