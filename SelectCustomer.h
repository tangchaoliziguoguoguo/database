#pragma once


// CSelectCustomer �Ի���

class CSelectCustomer : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectCustomer)

public:
	CSelectCustomer(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelectCustomer();

// �Ի�������
	enum { IDD = IDD_Select_Customer };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	afx_msg void OnBnClickedSelect();
};
