#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CClient �Ի���

class CClient : public CDialogEx
{
	DECLARE_DYNAMIC(CClient)

public:
	CClient(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CClient();

// �Ի�������
	enum { IDD = IDD_client };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl insert_view_text;
	CListCtrl resv_view;
	CComboBox update_choose_table;
	virtual BOOL OnInitDialog();void open_insert_customers_table();
	void open_insert_flights_table();
	void open_insert_hotels_table();
	void open_insert_cars_table();
	void open_insert_reservations_table();
	void init_view_text(int);		// ��ʼ����ͼ�б�
	void init_view_text_flight(CString);		// CString�洢sql��䣬��ʾ��ѯ���������ݲ�ѯ����������ʾ
	void init_view_text_hotel(CString);
	void init_view_text_car(CString);
	void init_view_text_reservation(CString);
	void init_resv_view(CString);
	int button_choice;		// ��������롱�͡�ɾ������ť��������ͬһ�����ڣ�������Ҫ�в�ͬ����ʾ���øñ�����¼��ť��ѡ��
	int selectitem;
	CString username;
	afx_msg void OnCbnSelchangeUpdateChooseTable();
	afx_msg void OnBnClickedReservation();
	afx_msg void OnBnClickedSelect();
	afx_msg void OnBnClickedDeleteResv();
	afx_msg void OnBnClickedRoute();
};
