#pragma once


// CSign �Ի���

class CSign : public CDialogEx
{
	DECLARE_DYNAMIC(CSign)

public:
	CSign(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSign();

// �Ի�������
	enum { IDD = IDD_sign };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	afx_msg void OnBnClickedsign();
};
