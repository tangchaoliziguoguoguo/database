#pragma once
#include "afxwin.h"


// CResvCar �Ի���

class CResvCar : public CDialogEx
{
	DECLARE_DYNAMIC(CResvCar)

public:
	CResvCar(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CResvCar();

// �Ի�������
	enum { IDD = IDD_Resv_Car };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit city_ctrl;
	CString city;
	CComboBox customer_ctrl;
	CString customer;
	CString resv_num;
	afx_msg void OnBnClickedButton1();
	CEdit resv_num_ctrl;
};
