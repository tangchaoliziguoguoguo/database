#pragma once
#include "afxwin.h"


// CSelectResv �Ի���

class CSelectResv : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectResv)

public:
	CSelectResv(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelectResv();

// �Ի�������
	enum { IDD = IDD_Select_Resv };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString num;
	CString name;
	afx_msg void OnBnClickedSelectNum();
	afx_msg void OnBnClickedSelectname();
	CComboBox type_ctrl;
	afx_msg void OnBnClickedSelecttype();
	virtual BOOL OnInitDialog();
};
