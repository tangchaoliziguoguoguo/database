#pragma once


// CConfirm �Ի���

class CConfirm : public CDialogEx
{
	DECLARE_DYNAMIC(CConfirm)

public:
	CConfirm(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConfirm();

// �Ի�������
	enum { IDD = IDD_confirm };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
