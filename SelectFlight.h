#pragma once
#include "afxwin.h"


// CSelectFlight �Ի���

class CSelectFlight : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectFlight)

public:
	CSelectFlight(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelectFlight();

// �Ի�������
	enum { IDD = IDD_SELECT_FLIGHT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString num;
	CString from_city;
	CString ariv_city;
	afx_msg void OnBnClickedSelectNum();
	afx_msg void OnBnClickedSelectCity();
	CComboBox date_ctrl;
	virtual BOOL OnInitDialog();
};
