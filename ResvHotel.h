#pragma once
#include "afxwin.h"


// CResvHotel �Ի���

class CResvHotel : public CDialogEx
{
	DECLARE_DYNAMIC(CResvHotel)

public:
	CResvHotel(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CResvHotel();

// �Ի�������
	enum { IDD = IDD_Resv_Hotel };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit city_ctrl;
	CString city;
	CComboBox customer_ctrl;
	CString customer;
	CString resv_num;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CEdit resv_num_ctrl;
};
