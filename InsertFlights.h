#pragma once
#include "afxwin.h"


// CInsertFlights �Ի���

class CInsertFlights : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertFlights)

public:
	CInsertFlights(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInsertFlights();

// �Ի�������
	enum { IDD = IDD_Insert_Flights };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString flight_num;
	int flight_price;
	int num_seat;
	CString from_city;
	CString ariv_city;
	afx_msg void OnBnClickedInsertFlights();
	CEdit flight_num_ctrl;
	CEdit flight_price_ctrl;
	CEdit num_seat_ctrl;
	CEdit from_city_ctrl;
	CEdit ariv_city_ctrl;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnEnChangeEdit2();
	CEdit date_ctrl;
	int date;
};
