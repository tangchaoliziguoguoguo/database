#pragma once


// CSelectHotel �Ի���

class CSelectHotel : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectHotel)

public:
	CSelectHotel(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelectHotel();

// �Ի�������
	enum { IDD = IDD_Select_Hotel };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSelect();
	CString city;
};
