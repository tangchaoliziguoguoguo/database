#pragma once


// CSelectCar �Ի���

class CSelectCar : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectCar)

public:
	CSelectCar(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelectCar();

// �Ի�������
	enum { IDD = IDD_Select_Car };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString city;
	afx_msg void OnBnClickedSelect();
};
