
// db_lab2Dlg.h : ͷ�ļ�
//

#pragma once


// Cdb_lab2Dlg �Ի���
class Cdb_lab2Dlg : public CDialogEx
{
// ����
public:
	Cdb_lab2Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	
//	CDatabase my_db;

// �Ի�������
	enum { IDD = IDD_DB_LAB2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedclientlogin();
	bool limit;
};
