#pragma once
#include "afxwin.h"


// CInsertCars �Ի���

class CInsertCars : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertCars)

public:
	CInsertCars(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInsertCars();

// �Ի�������
	enum { IDD = IDD_Insert_Cars };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit cars_city_ctrl;
	CString cars_city;
	CEdit cars_price_ctrl;
	int cars_price;
	CEdit cars_num_ctrl;
	int cars_num;
	afx_msg void OnBnClickedInsertCars();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnEnChangeEdit3();
};
