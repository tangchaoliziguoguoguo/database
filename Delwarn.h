#pragma once


// CDelwarn �Ի���

class CDelwarn : public CDialogEx
{
	DECLARE_DYNAMIC(CDelwarn)

public:
	CDelwarn(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDelwarn();

// �Ի�������
	enum { IDD = IDD_WARNING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
