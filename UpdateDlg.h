#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CUpdateDlg �Ի���

class CUpdateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateDlg)

public:
	CUpdateDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUpdateDlg();

// �Ի�������
	enum { IDD = IDD_UPDATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeUpdateChooseTable();
	CComboBox update_choose_table;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedUpdateInsert();
	CListCtrl insert_view_text;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedUpdate();
	void open_insert_customers_table();
	void open_insert_flights_table();
	void open_insert_hotels_table();
	void open_insert_cars_table();
	void open_insert_reservations_table();
	void init_view_text(int);		// ��ʼ����ͼ�б�
	void init_view_text_customer(CString);		// CString�洢sql��䣬��ʾ��ѯ���������ݲ�ѯ����������ʾ
	void init_view_text_flight(CString);
	void init_view_text_hotel(CString);
	void init_view_text_car(CString);
	void init_view_text_reservation(CString);
	void init_resv_view(CString);
	int button_choice;		// ��������롱�͡�ɾ������ť��������ͬһ�����ڣ�������Ҫ�в�ͬ����ʾ���øñ�����¼��ť��ѡ��
	int selectitem;
	afx_msg void OnBnClickedReservation();
	afx_msg void OnBnClickedSelect();
	afx_msg void OnBnClickedRoute();
	afx_msg void OnStnClickedPrompt();
	CListCtrl resv_view;
	afx_msg void OnBnClickedDeleteResv();
	afx_msg void OnBnClickedSelectResv();
	afx_msg void OnBnClickedAll();
};
