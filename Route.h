#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CRoute �Ի���

class CRoute : public CDialogEx
{
	DECLARE_DYNAMIC(CRoute)

public:
	CRoute(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRoute();

// �Ի�������
	enum { IDD = IDD_Route };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void SetListBox(CString);
	CComboBox cust_ctrl;
	afx_msg void OnCbnSelchangecust();
	CString customer;
	afx_msg void OnBnClickedcheck();
	CListCtrl list;
};
