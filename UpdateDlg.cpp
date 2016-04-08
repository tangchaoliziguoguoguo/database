// UpdateDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "UpdateDlg.h"
#include "afxdialogex.h"
#include "InsertCustomer.h"
#include "Cpublic.h"
#include "InsertFlights.h"
#include "db_lab2Dlg.h"
#include "InsertHotels.h"
#include "InsertCars.h"
#include "InsertResv.h"
#include "ResvFlight.h"
#include "ResvHotel.h"
#include "ResvCar.h"
#include "SelectFlight.h"
#include "SelectCustomer.h"
#include "SelectHotel.h"
#include "SelectCar.h"
#include "SelectResv.h"
#include "Route.h"
#include "Delwarn.h"
#include "Confirm.h"

// CUpdateDlg �Ի���

IMPLEMENT_DYNAMIC(CUpdateDlg, CDialogEx)

CUpdateDlg::CUpdateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUpdateDlg::IDD, pParent)
{
	
	//update_choose_talbe.AddString(_T("������"));
}

CUpdateDlg::~CUpdateDlg()
{
}

void CUpdateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Update_Choose_Table, update_choose_table);

	//update_choose_talbe.AddString(_T("click"));
	DDX_Control(pDX, IDC_LIST2, insert_view_text);
	DDX_Control(pDX, IDC_LIST5, resv_view);
}

BEGIN_MESSAGE_MAP(CUpdateDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_Update_Choose_Table, &CUpdateDlg::OnCbnSelchangeUpdateChooseTable)
	ON_BN_CLICKED(IDCANCEL, &CUpdateDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_Update_Insert, &CUpdateDlg::OnBnClickedUpdateInsert)
	ON_BN_CLICKED(IDC_DELETE, &CUpdateDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_UPDATE, &CUpdateDlg::OnBnClickedUpdate)
	ON_BN_CLICKED(IDC_Reservation, &CUpdateDlg::OnBnClickedReservation)
	ON_BN_CLICKED(IDC_SELECT, &CUpdateDlg::OnBnClickedSelect)
	ON_BN_CLICKED(IDC_Route, &CUpdateDlg::OnBnClickedRoute)
	ON_STN_CLICKED(IDC_PROMPT, &CUpdateDlg::OnStnClickedPrompt)
	ON_BN_CLICKED(IDC_DELETE_RESV, &CUpdateDlg::OnBnClickedDeleteResv)
	ON_BN_CLICKED(IDC_SELECT_RESV, &CUpdateDlg::OnBnClickedSelectResv)
	ON_BN_CLICKED(IDC_ALL, &CUpdateDlg::OnBnClickedAll)
END_MESSAGE_MAP()


// CUpdateDlg ��Ϣ�������

/****���Լ�����ĺ�������***/
void CUpdateDlg::open_insert_customers_table()
{
	// �򿪲����û��Ĵ��ڣ����ڹرպ�ˢ����ͼ�б�
	CRecordset rec(&Cpublic::my_db);
	INT_PTR nRes;
	CInsertCustomer insert_cus;
	nRes = insert_cus.DoModal();
	// ˢ����ͼ�б�ҳ��
	init_view_text_customer(_T("select* from CUSTOMERS"));
	//insert_view_text.DeleteAllItems();
	//rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from CUSTOMERS"));
	//rec.Requery();
	//while (!rec.IsEOF()) {
	//	CString str;
	//	rec.GetFieldValue(short(0), str);
	//	insert_view_text.InsertItem(0, str);		// ���ֶμӵ���ͼ�б���
	//	rec.MoveNext();
	//}
}

void CUpdateDlg::open_insert_flights_table()
{
	// �򿪲��뺽��Ĵ��ڣ����ڹرպ�ˢ����ͼ�б�
	CRecordset rec(&Cpublic::my_db);
	INT_PTR nRes;
	CInsertFlights insert_flights;
	nRes = insert_flights.DoModal();
	init_view_text_flight(_T("select* from FLIGHTS"));
	//insert_view_text.DeleteAllItems();
	//rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from FLIGHTS"));
	//rec.Requery();
	//int index = 0;
	//while (!rec.IsEOF()) {
	//	CString str;
	//	CDBVariant varValue;
	//	rec.GetFieldValue(short(0), str);
	//	insert_view_text.InsertItem(index, str);
	//	rec.GetFieldValue(short(1), varValue);
	//	str.Format(_T("%d"), varValue.m_iVal);
	//	insert_view_text.SetItemText(index, 1, str);
	//	rec.GetFieldValue(short(2), varValue);
	//	str.Format(_T("%d"), varValue.m_iVal);
	//	insert_view_text.SetItemText(index, 2, str);
	//	rec.GetFieldValue(short(3), varValue);
	//	str.Format(_T("%d"), varValue.m_iVal);
	//	insert_view_text.SetItemText(index, 3, str);
	//	rec.GetFieldValue(short(4), str);
	//	insert_view_text.SetItemText(index, 4, str);
	//	rec.GetFieldValue(short(5), str);
	//	insert_view_text.SetItemText(index, 5, str);
	//	rec.MoveNext();
	//	index++;
	//}
}

void CUpdateDlg::open_insert_hotels_table()
{
	// �򿪲�����ݵĴ��ڣ����ڹرպ�ˢ����ͼ�б�
	CRecordset rec(&Cpublic::my_db);
	INT_PTR nRes;
	CInsertHotels insert_hotels;
	nRes = insert_hotels.DoModal();
	init_view_text_hotel(_T("select* from HOTELS"));
	/*insert_view_text.DeleteAllItems();
	rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from HOTELS"));
	rec.Requery();
	int index = 0;
	while (!rec.IsEOF()) {
		CString str;
		CDBVariant varValue;
		rec.GetFieldValue(short(0), str);
		insert_view_text.InsertItem(index, str);
		rec.GetFieldValue(short(1), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 1, str);
		rec.GetFieldValue(short(2), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 2, str);
		rec.GetFieldValue(short(3), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 3, str);
		rec.MoveNext();
		index++;
	}*/
}

void CUpdateDlg::open_insert_cars_table()
{
	// �򿪲����⳵�Ĵ��ڣ����ڹرպ�ˢ����ͼ�б�
	CRecordset rec(&Cpublic::my_db);
	INT_PTR nRes;
	CInsertCars insert_cars;
	nRes = insert_cars.DoModal();
	init_view_text_car(_T("select* from CARS"));
	/*insert_view_text.DeleteAllItems();
	rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from CARS"));
	rec.Requery();
	int index = 0;
	while (!rec.IsEOF()) {
		CString str;
		CDBVariant varValue;
		rec.GetFieldValue(short(0), str);
		insert_view_text.InsertItem(index, str);
		rec.GetFieldValue(short(1), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 1, str);
		rec.GetFieldValue(short(2), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 2, str);
		rec.GetFieldValue(short(3), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 3, str);
		rec.MoveNext();
		index++;
	}*/
}

void CUpdateDlg::open_insert_reservations_table()
{
	// �򿪲���Ԥ���Ĵ��ڣ����ڹرպ�ˢ����ͼ�б�
	CRecordset rec(&Cpublic::my_db);
	INT_PTR nRes;
	CInsertResv insert_resv;
	nRes = insert_resv.DoModal();
	init_view_text_reservation(_T("select* from RESERVATIONS"));
	/*insert_view_text.DeleteAllItems();
	rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from RESERVATIONS"));
	rec.Requery();
	int index = 0;
	while (!rec.IsEOF()) {
		CString str;
		CDBVariant varValue;
		rec.GetFieldValue(short(0), str);
		insert_view_text.InsertItem(index, str);
		rec.GetFieldValue(short(1), str);
		insert_view_text.SetItemText(index, 1, str);
		rec.GetFieldValue(short(2), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 2, str);
		rec.GetFieldValue(short(3), str);
		insert_view_text.SetItemText(index, 3, str);
		rec.MoveNext();
		index++;
	}*/
}

void CUpdateDlg::init_view_text(int num)
{
	CString strSQL;

	switch(num) {
	case 0:
		strSQL.Format(_T("select * from CUSTOMERS"));
		init_view_text_customer(strSQL);
		break;
	case 1:
		strSQL.Format(_T("select * from FLIGHTS"));
		init_view_text_flight(strSQL);
		break;
	case 2:
		strSQL.Format(_T("select * from HOTELS"));
		init_view_text_hotel(strSQL);
		break;
	case 3:
		strSQL.Format(_T("select * from CARS"));
		init_view_text_car(strSQL);
		break;
	case 4:
		strSQL.Format(_T("select * from RESERVATIONS"));
		init_view_text_reservation(strSQL);
		break;
	}

//	if (num == 0) {		// 0����CUSTOMERS��
//		insert_view_text.DeleteAllItems();
//		while (insert_view_text.DeleteColumn(0));		// ɾ��������
//		insert_view_text.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width()/5, 0);
//		rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from CUSTOMERS"));
//		rec.Requery();
//		while (!rec.IsEOF()) {
//			CString str;
//			rec.GetFieldValue(short(0), str);
////			CString str = *(dbvar.m_pstring);
//			insert_view_text.InsertItem(0, str);		// ���ֶμӵ���ͼ�б���
//			rec.MoveNext();
//		}
//	}
//
//	if (num == 1) {		// 1����FLIGHTS��
//		insert_view_text.DeleteAllItems();
//		while (insert_view_text.DeleteColumn(0));		// ɾ��������
//		insert_view_text.InsertColumn(0, _T("�����"), LVCFMT_CENTER, rect.Width()/6, 0);
//		insert_view_text.InsertColumn(1, _T("�۸�"), LVCFMT_CENTER, rect.Width()/6, 1);
//		insert_view_text.InsertColumn(2, _T("��λ����"), LVCFMT_CENTER, rect.Width()/6, 2);
//		insert_view_text.InsertColumn(3, _T("ʣ��"), LVCFMT_CENTER, rect.Width()/6, 3);
//		insert_view_text.InsertColumn(4, _T("���"), LVCFMT_CENTER, rect.Width()/6, 4);
//		insert_view_text.InsertColumn(5, _T("�յ�"), LVCFMT_CENTER, rect.Width()/6, 5);
//		rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from FLIGHTS"));
//		rec.Requery();
//		int index = 0;
//		while (!rec.IsEOF()) {
//			CString str;
//			CDBVariant varValue;
//			rec.GetFieldValue(short(0), str);
//			insert_view_text.InsertItem(index, str);
//			rec.GetFieldValue(short(1), varValue);
//			str.Format(_T("%d"), varValue.m_iVal);
//			insert_view_text.SetItemText(index, 1, str);
//			rec.GetFieldValue(short(2), varValue);
//			str.Format(_T("%d"), varValue.m_iVal);
//			insert_view_text.SetItemText(index, 2, str);
//			rec.GetFieldValue(short(3), varValue);
//			str.Format(_T("%d"), varValue.m_iVal);
//			insert_view_text.SetItemText(index, 3, str);
//			rec.GetFieldValue(short(4), str);
//			insert_view_text.SetItemText(index, 4, str);
//			rec.GetFieldValue(short(5), str);
//			insert_view_text.SetItemText(index, 5, str);
//			rec.MoveNext();
//			index++;
//		}
//	}
//
//	if (num == 2) {		// 2����HOTELS��
//		insert_view_text.DeleteAllItems();
//		while (insert_view_text.DeleteColumn(0));		// ɾ��������
//		insert_view_text.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width()/4, 0);
//		insert_view_text.InsertColumn(1, _T("�۸�"), LVCFMT_CENTER, rect.Width()/4, 1);
//		insert_view_text.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width()/4, 2);
//		insert_view_text.InsertColumn(3, _T("ʣ��"), LVCFMT_CENTER, rect.Width()/4, 3);
//		rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from HOTELS"));
//		rec.Requery();
//		int index = 0;
//		while (!rec.IsEOF()) {
//			CString str;
//			CDBVariant varValue;
//			rec.GetFieldValue(short(0), str);
//			insert_view_text.InsertItem(index, str);
//			rec.GetFieldValue(short(1), varValue);
//			str.Format(_T("%d"), varValue.m_iVal);
//			insert_view_text.SetItemText(index, 1, str);
//			rec.GetFieldValue(short(2), varValue);
//			str.Format(_T("%d"), varValue.m_iVal);
//			insert_view_text.SetItemText(index, 2, str);
//			rec.GetFieldValue(short(3), varValue);
//			str.Format(_T("%d"), varValue.m_iVal);
//			insert_view_text.SetItemText(index, 3, str);
//			rec.MoveNext();
//			index++;
//		}
//	}
//
//	if (num == 3) {		// 3����CARS��
//		insert_view_text.DeleteAllItems();
//		while (insert_view_text.DeleteColumn(0));		// ɾ��������
//		insert_view_text.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width()/4, 0);
//		insert_view_text.InsertColumn(1, _T("�۸�"), LVCFMT_CENTER, rect.Width()/4, 1);
//		insert_view_text.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width()/4, 2);
//		insert_view_text.InsertColumn(3, _T("ʣ��"), LVCFMT_CENTER, rect.Width()/4, 3);
//		rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from CARS"));
//		rec.Requery();
//		int index = 0;
//		while (!rec.IsEOF()) {
//			CString str;
//			CDBVariant varValue;
//			rec.GetFieldValue(short(0), str);
//			insert_view_text.InsertItem(index, str);
//			rec.GetFieldValue(short(1), varValue);
//			str.Format(_T("%d"), varValue.m_iVal);
//			insert_view_text.SetItemText(index, 1, str);
//			rec.GetFieldValue(short(2), varValue);
//			str.Format(_T("%d"), varValue.m_iVal);
//			insert_view_text.SetItemText(index, 2, str);
//			rec.GetFieldValue(short(3), varValue);
//			str.Format(_T("%d"), varValue.m_iVal);
//			insert_view_text.SetItemText(index, 3, str);
//			rec.MoveNext();
//			index++;
//		}
//	}
//
//	if (num == 4) {		// 4����RESERVATIONS��
//		insert_view_text.DeleteAllItems();
//		while (insert_view_text.DeleteColumn(0));		// ɾ��������
//		insert_view_text.InsertColumn(0, _T("������"), LVCFMT_CENTER, rect.Width()/4, 0);
//		insert_view_text.InsertColumn(1, _T("�ͻ�"), LVCFMT_CENTER, rect.Width()/4, 1);
//		insert_view_text.InsertColumn(2, _T("��������"), LVCFMT_CENTER, rect.Width()/4, 2);
//		insert_view_text.InsertColumn(3, _T("��������"), LVCFMT_CENTER, rect.Width()/4, 3);
//		rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from RESERVATIONS"));
//		rec.Requery();
//		int index = 0;
//		while (!rec.IsEOF()) {
//			CString str;
//			CDBVariant varValue;
//			rec.GetFieldValue(short(0), str);
//			insert_view_text.InsertItem(index, str);
//			rec.GetFieldValue(short(1), str);
//			insert_view_text.SetItemText(index, 1, str);
//			rec.GetFieldValue(short(2), varValue);
//			str.Format(_T("%d"), varValue.m_iVal);
//			insert_view_text.SetItemText(index, 2, str);
//			rec.GetFieldValue(short(3), str);
//			insert_view_text.SetItemText(index, 3, str);
//			rec.MoveNext();
//			index++;
//		}
//	}
}

void CUpdateDlg::init_view_text_customer(CString str)
{
	CRect rect;
	CRecordset rec(&Cpublic::my_db);
	insert_view_text.GetClientRect(&rect);
	insert_view_text.DeleteAllItems();
	while (insert_view_text.DeleteColumn(0));		// ɾ�������У���ȫ�����´���
	insert_view_text.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width()/5, 0);
	rec.Open(AFX_DB_USE_DEFAULT_TYPE,str);
	rec.Requery();
	while (!rec.IsEOF()) {
		CString str;
		rec.GetFieldValue(short(0), str);
		insert_view_text.InsertItem(0, str);		// ���ֶμӵ���ͼ�б���
		rec.MoveNext();
	}
}

void CUpdateDlg::init_view_text_flight(CString str)
{
	CRect rect;
	CRecordset rec(&Cpublic::my_db);
//	CDBVariant dbvar;
	insert_view_text.GetClientRect(&rect);
	insert_view_text.DeleteAllItems();
	while (insert_view_text.DeleteColumn(0));		// ɾ��������
	insert_view_text.InsertColumn(0, _T("�����"), LVCFMT_CENTER, rect.Width()*2/15, 0);
	insert_view_text.InsertColumn(1, _T("���"), LVCFMT_CENTER, rect.Width()*2/15, 1);
	insert_view_text.InsertColumn(2, _T("�յ�"), LVCFMT_CENTER, rect.Width()*2/15, 2);
	insert_view_text.InsertColumn(3, _T("����"), LVCFMT_CENTER, rect.Width()*2/15, 3);
	insert_view_text.InsertColumn(4, _T("�۸�"), LVCFMT_CENTER, rect.Width()*2/15, 4);
	insert_view_text.InsertColumn(5, _T("��λ����"), LVCFMT_CENTER, rect.Width()*3/15, 5);
	insert_view_text.InsertColumn(6, _T("ʣ��"), LVCFMT_CENTER, rect.Width()*2/15, 6);
	rec.Open(AFX_DB_USE_DEFAULT_TYPE,str);
	rec.Requery();
	int index = 0;
	while (!rec.IsEOF()) {
		CString str;
		CDBVariant varValue;
		rec.GetFieldValue(short(0), str);
		insert_view_text.InsertItem(index, str);
		rec.GetFieldValue(short(1), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 4, str);
		rec.GetFieldValue(short(2), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 5, str);
		rec.GetFieldValue(short(3), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 6, str);
		rec.GetFieldValue(short(4), str);
		insert_view_text.SetItemText(index, 1, str);
		rec.GetFieldValue(short(5), str);
		insert_view_text.SetItemText(index, 2, str);
		rec.GetFieldValue(short(6), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 3, str);
		rec.MoveNext();
		index++;
	}
}

void CUpdateDlg::init_view_text_hotel(CString str)
{
	CRect rect;
	CRecordset rec(&Cpublic::my_db);
//	CDBVariant dbvar;
	insert_view_text.GetClientRect(&rect);
	insert_view_text.DeleteAllItems();
	while (insert_view_text.DeleteColumn(0));		// ɾ��������
	insert_view_text.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width()/4, 0);
	insert_view_text.InsertColumn(1, _T("�۸�"), LVCFMT_CENTER, rect.Width()/4, 1);
	insert_view_text.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width()/4, 2);
	insert_view_text.InsertColumn(3, _T("ʣ��"), LVCFMT_CENTER, rect.Width()/4, 3);
	rec.Open(AFX_DB_USE_DEFAULT_TYPE,str);
	rec.Requery();
	int index = 0;
	while (!rec.IsEOF()) {
		CString str;
		CDBVariant varValue;
		rec.GetFieldValue(short(0), str);
		insert_view_text.InsertItem(index, str);
		rec.GetFieldValue(short(1), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 1, str);
		rec.GetFieldValue(short(2), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 2, str);
		rec.GetFieldValue(short(3), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 3, str);
		rec.MoveNext();
		index++;
	}
}

void CUpdateDlg::init_view_text_car(CString str)
{
	CRect rect;
	CRecordset rec(&Cpublic::my_db);
//	CDBVariant dbvar;
	insert_view_text.GetClientRect(&rect);
	insert_view_text.DeleteAllItems();
	while (insert_view_text.DeleteColumn(0));		// ɾ��������
	insert_view_text.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width()/4, 0);
	insert_view_text.InsertColumn(1, _T("�۸�"), LVCFMT_CENTER, rect.Width()/4, 1);
	insert_view_text.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width()/4, 2);
	insert_view_text.InsertColumn(3, _T("ʣ��"), LVCFMT_CENTER, rect.Width()/4, 3);
	rec.Open(AFX_DB_USE_DEFAULT_TYPE,str);
	rec.Requery();
	int index = 0;
	while (!rec.IsEOF()) {
		CString str;
		CDBVariant varValue;
		rec.GetFieldValue(short(0), str);
		insert_view_text.InsertItem(index, str);
		rec.GetFieldValue(short(1), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 1, str);
		rec.GetFieldValue(short(2), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 2, str);
		rec.GetFieldValue(short(3), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 3, str);
		rec.MoveNext();
		index++;
	}
}

void CUpdateDlg::init_view_text_reservation(CString str)
{
	CRect rect;
	CRecordset rec(&Cpublic::my_db);
//	CDBVariant dbvar;
	insert_view_text.GetClientRect(&rect);
	insert_view_text.DeleteAllItems();
	while (insert_view_text.DeleteColumn(0));		// ɾ��������
	insert_view_text.InsertColumn(0, _T("������"), LVCFMT_CENTER, rect.Width()/4, 0);
	insert_view_text.InsertColumn(1, _T("�ͻ�"), LVCFMT_CENTER, rect.Width()/4, 1);
	insert_view_text.InsertColumn(2, _T("��������"), LVCFMT_CENTER, rect.Width()/4, 2);
	insert_view_text.InsertColumn(3, _T("��������"), LVCFMT_CENTER, rect.Width()/4, 3);
	rec.Open(AFX_DB_USE_DEFAULT_TYPE,str);
	rec.Requery();
	int index = 0;
	while (!rec.IsEOF()) {
		CString str;
		CDBVariant varValue;
		rec.GetFieldValue(short(0), str);
		insert_view_text.InsertItem(index, str);
		rec.GetFieldValue(short(1), str);
		insert_view_text.SetItemText(index, 1, str);
		rec.GetFieldValue(short(2), varValue);
		str.Format(_T("%d"), varValue.m_iVal);
		insert_view_text.SetItemText(index, 2, str);
		rec.GetFieldValue(short(3), str);
		insert_view_text.SetItemText(index, 3, str);
		rec.MoveNext();
		index++;
	}
}

void CUpdateDlg::init_resv_view(CString str)
{
	// ��ʼ��������Ϣ����
	CString strSQL;
	CRect rect_resv;
	CRecordset rec(&Cpublic::my_db);
//	CDBVariant dbvar;
	resv_view.GetClientRect(&rect_resv);
	resv_view.DeleteAllItems();
	while (resv_view.DeleteColumn(0));		// ɾ��������
	resv_view.InsertColumn(0, _T("������"), LVCFMT_CENTER, rect_resv.Width()/5, 0);
	resv_view.InsertColumn(1, _T("�ͻ�"), LVCFMT_CENTER, rect_resv.Width()/5, 1);
	resv_view.InsertColumn(2, _T("��������"), LVCFMT_CENTER, rect_resv.Width()/5, 2);
	resv_view.InsertColumn(3, _T("��ϸ��Ϣ"), LVCFMT_CENTER, rect_resv.Width()*2/5, 3);
	rec.Open(AFX_DB_USE_DEFAULT_TYPE,str);
	rec.Requery();
	int index = 0;
	while (!rec.IsEOF()) {
		CString str;
		CDBVariant varValue;
		rec.GetFieldValue(short(0), str);
		resv_view.InsertItem(index, str);
		rec.GetFieldValue(short(1), str);
		resv_view.SetItemText(index, 1, str);
		rec.GetFieldValue(short(2), varValue);
	//	str.Format(_T("%d"), varValue.m_iVal);
		if (varValue.m_iVal == 1) {
			resv_view.SetItemText(index, 2, _T("����"));
		}
		else if (varValue.m_iVal == 2) {
			resv_view.SetItemText(index, 2, _T("����"));
		}
		else if (varValue.m_iVal == 3) {
			resv_view.SetItemText(index, 2, _T("�⳵"));
		}



		
		rec.GetFieldValue(short(3), str);

		if (varValue.m_iVal == 1) {
			strSQL.Format(_T("select FromCity,ArivCity from FLIGHTS where flightNum = '%s'"), str);

			CRecordset rec_(&Cpublic::my_db);
			rec_.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
			rec_.Requery();
			CString from, to, str_;
			while (!rec_.IsEOF()) {
				rec_.GetFieldValue(short(0), from);
				rec_.GetFieldValue(short(1), to);
				rec_.MoveNext();
			}
			str_.Format(_T("%s(%s->%s)"), str, from, to);

			resv_view.SetItemText(index, 3, str_);
		}
		else resv_view.SetItemText(index, 3, str);

		rec.MoveNext();
		index++;
	}
}

/****���Լ�����ĺ�������***/

void CUpdateDlg::OnCbnSelchangeUpdateChooseTable()
{
	// ��ѡ�����ʱ����Ҫ��Ӧ�ı��б���ͼ�ؼ�����ʾ
	int num = update_choose_table.GetCurSel();
	if (num == 4) {
		GetDlgItem(IDC_Update_Insert)->EnableWindow(FALSE);		// ��ѡ����ΪԤ���ǣ����á����롱��ť
	}
	else {
		GetDlgItem(IDC_Update_Insert)->EnableWindow(TRUE);
	}
	if (num == 0 || num == 4) {
		GetDlgItem(IDC_Reservation)->EnableWindow(FALSE);		// ��ѡ����Ϊ�ͻ���Ԥ��ʱ�����á�Ԥ������ť
		GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);		// ���á��޸ġ���ť
	}
	else {
		GetDlgItem(IDC_Reservation)->EnableWindow(TRUE);
		GetDlgItem(IDC_UPDATE)->EnableWindow(TRUE);
	}
	init_view_text(num);
}


BOOL CUpdateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//CFont font;
	//font.CreatePointFont(100,_T("����"),NULL);
	//GetDlgItem(IDC_STATIC)->SetFont(&font);		// �޸ľ�̬�ı���������С

	update_choose_table.InsertString(0, _T("�ͻ�"));
	update_choose_table.InsertString(1, _T("����"));
	update_choose_table.InsertString(2, _T("�ù�"));
	update_choose_table.InsertString(3, _T("�⳵"));
	update_choose_table.SetCurSel(0);
	
	init_resv_view(_T("select * from RESERVATIONS"));
	int num = update_choose_table.GetCurSel();
	init_view_text(num);

	GetDlgItem(IDC_Reservation)->EnableWindow(FALSE);
	GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);

	
	GetParent()->PostMessage(WM_CLOSE,0,0);		// �رյ�¼��
	GetParent()->GetParent()->PostMessage(WM_CLOSE,0,0);	// �ر����Ի���

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CUpdateDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CUpdateDlg::OnBnClickedUpdateInsert()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	button_choice = 0;
	if (update_choose_table.GetCurSel() == 0) {		// 0����ѡ��CUSTOMERS��
		open_insert_customers_table();
	}
	if (update_choose_table.GetCurSel() == 1) {		// 1��ʾFLIGHTS��
		open_insert_flights_table();
	}
	if (update_choose_table.GetCurSel() == 2) {		// 2��ʾHOTELS��
		open_insert_hotels_table();
	}
	if (update_choose_table.GetCurSel() == 3) {		// 3��ʾCARS��
		open_insert_cars_table();
	}

	if (update_choose_table.GetCurSel() == 4) {		// 4����RESERVATIONS��
		open_insert_reservations_table();
	}
}


void CUpdateDlg::OnBnClickedDelete()		// ɾ����ѡ����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = insert_view_text.GetFirstSelectedItemPosition();		// ��ͼ�б��б�ѡ�����λ��
	if (pos == NULL) {
		MessageBox(_T("����ѡ��Ҫɾ������Ŀ��"), _T("��ʾ"));
		return ;
	}

	CDelwarn warn;
	INT_PTR nRes;
	nRes = warn.DoModal();
	if (IDCANCEL == nRes) return ;

	int selectitem = insert_view_text.GetNextSelectedItem(pos);		// ��ѡ���������
	CString to_del = insert_view_text.GetItemText(selectitem, 0);
//	CString table;
	int sel = update_choose_table.GetCurSel();
//	update_choose_table.GetLBText(sel, table);		// �����Ͽ��ѡ������ĸ�����ɾ����
	CString strSQL;
	switch(sel) {
	case 0:		// CUSTOMERS
		strSQL.Format(_T("delete from CUSTOMERS where custName = '%s'"), to_del);
		Cpublic::my_db.ExecuteSQL(strSQL);
		strSQL.Format(_T("delete from RESERVATIONS where custName = '%s'"), to_del);
		Cpublic::my_db.ExecuteSQL(strSQL);
		break;
	case 1:
		strSQL.Format(_T("delete from FLIGHTS where flightNum = '%s'"), to_del);
		Cpublic::my_db.ExecuteSQL(strSQL);
		strSQL.Format(_T("delete from RESERVATIONS where resvChoice = '%s'"), to_del);
		Cpublic::my_db.ExecuteSQL(strSQL);
		break;
	case 2:
		strSQL.Format(_T("delete from HOTELS where location = '%s'"), to_del);
		Cpublic::my_db.ExecuteSQL(strSQL);
		strSQL.Format(_T("delete from RESERVATIONS where resvChoice = '%s'"), to_del);
		Cpublic::my_db.ExecuteSQL(strSQL);
		break;
	case 3:
		strSQL.Format(_T("delete from CARS where location = '%s'"), to_del);
		Cpublic::my_db.ExecuteSQL(strSQL);
		strSQL.Format(_T("delete from RESERVATIONS where resvChoice = '%s'"), to_del);
		Cpublic::my_db.ExecuteSQL(strSQL);
		break;
	case 4:
		strSQL.Format(_T("delete from RESERVATIONS where resvKey = '%s'"), to_del);
		Cpublic::my_db.ExecuteSQL(strSQL);
		// ɾ����ĳ������֮����Ӧ��availableҪ��һ
		if (insert_view_text.GetItemText(selectitem, 2) == _T("1")) {
			CString str = insert_view_text.GetItemText(selectitem, 3);
			strSQL.Format(_T("update FLIGHTS set numAvail = numAvail + 1 where flightNum = '%s'"), str);
			Cpublic::my_db.ExecuteSQL(strSQL);
		}
		else if (insert_view_text.GetItemText(selectitem, 2) == _T("2")) {
			CString str = insert_view_text.GetItemText(selectitem, 3);
			strSQL.Format(_T("update HOTELS set numAvail = numAvail + 1 where location = '%s'"), str);
			Cpublic::my_db.ExecuteSQL(strSQL);
		}
		else if (insert_view_text.GetItemText(selectitem, 2) == _T("3")) {
			CString str = insert_view_text.GetItemText(selectitem, 3);
			strSQL.Format(_T("update CARS set numAvail = numAvail + 1 where location = '%s'"), str);
			Cpublic::my_db.ExecuteSQL(strSQL);
		}
		break;
	}
	MessageBox(_T("ɾ���ɹ���"), _T("��ʾ"));
	insert_view_text.DeleteItem(selectitem);
	init_resv_view(_T("select * from RESERVATIONS"));
}


void CUpdateDlg::OnBnClickedUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = insert_view_text.GetFirstSelectedItemPosition();		// ��ͼ�б��б�ѡ�����λ��
	if (pos == NULL) {
		MessageBox(_T("����ѡ��Ҫ�޸ĵ���Ŀ��"), _T("��ʾ"));
		return ;
	}
	selectitem = insert_view_text.GetNextSelectedItem(pos);		// ��ѡ���������
//	CString to_update = insert_view_text.GetItemText(selectitem, 0);
	button_choice = 1;		// 1��ʾѡ����ǡ��޸ġ���ť
	switch(update_choose_table.GetCurSel()) {
	case 0:		// 0��ʾCUSTOMERS
//		open_insert_customers_table();
		MessageBox(_T("��֧�ֶԡ��ͻ����������޸ģ�"), _T("��ʾ"));
		break;
	case 1:		// 1��ʾflights
		open_insert_flights_table();
		break;
	case 2:		// 2--hotels
		open_insert_hotels_table();
		break;
	case 3:		// 3--cars
		open_insert_cars_table();
		break;
	case 4:		// 4--reservations
		open_insert_reservations_table();
		break;
	}
}


void CUpdateDlg::OnBnClickedReservation()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int sel = update_choose_table.GetCurSel();
	CRecordset rec(&Cpublic::my_db);
	INT_PTR nRes;
	CResvFlight resvflight;
	CResvHotel resvhotel;
	CResvCar resvcar;
	POSITION pos = insert_view_text.GetFirstSelectedItemPosition();		// ��ͼ�б��б�ѡ�����λ��
	if (pos == NULL) {
		MessageBox(_T("����ѡ��ҪԤ������Ŀ��"), _T("��ʾ"));
		return ;
	}
	selectitem = insert_view_text.GetNextSelectedItem(pos);		// ��ѡ���������
	switch(sel) {
	case 1:
		nRes = resvflight.DoModal();
		break;
	case 2:
		nRes = resvhotel.DoModal();
		break;
	case 3:
		nRes = resvcar.DoModal();
		break;
	}
	init_view_text(update_choose_table.GetCurSel());
	init_resv_view(_T("select * from RESERVATIONS"));
}


void CUpdateDlg::OnBnClickedSelect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int num = update_choose_table.GetCurSel();
	CRecordset rec(&Cpublic::my_db);
	INT_PTR nRes;
	CSelectFlight selectflight;
	CSelectCustomer selectcust;
	CSelectHotel selecthotel;
	CSelectCar selectcar;
	CSelectResv selectresv;
	switch(num) {
	case 0:
		nRes = selectcust.DoModal();
		break;
	case 1:
		nRes = selectflight.DoModal();
		break;
	case 2:
		nRes = selecthotel.DoModal();
		break;
	case 3:
		nRes = selectcar.DoModal();
		break;
	case 4:
		nRes = selectresv.DoModal();
		break;
	}
}


void CUpdateDlg::OnBnClickedRoute()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRecordset rec(&Cpublic::my_db);
	CRoute route;
	POSITION pos = insert_view_text.GetFirstSelectedItemPosition();
	selectitem = insert_view_text.GetNextSelectedItem(pos);
	route.DoModal();
}


void CUpdateDlg::OnStnClickedPrompt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CUpdateDlg::OnBnClickedDeleteResv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = resv_view.GetFirstSelectedItemPosition();		// ��ͼ�б��б�ѡ�����λ��
	if (pos == NULL) {
		MessageBox(_T("����ѡ��Ҫɾ������Ŀ��"), _T("��ʾ"));
		return ;
	}

	CConfirm confirm;
	INT_PTR nRes;
	nRes = confirm.DoModal();
	if (IDCANCEL == nRes) return ;
	CString strSQL;
	int selectitem = resv_view.GetNextSelectedItem(pos);		// ��ѡ���������
	CString to_del = resv_view.GetItemText(selectitem, 0);

	CRecordset rec(&Cpublic::my_db);
	strSQL.Format(_T("select resvChoice from RESERVATIONS where resvKey = '%s'"), to_del);
	rec.Open(AFX_DB_USE_DEFAULT_TYPE, strSQL);
	rec.Requery();
	CString resv_choice;
	rec.GetFieldValue(short(0), resv_choice);

	strSQL.Format(_T("delete from RESERVATIONS where resvKey = '%s'"), to_del);
	Cpublic::my_db.ExecuteSQL(strSQL);
	// ɾ����ĳ������֮����Ӧ��availableҪ��һ
	if (resv_view.GetItemText(selectitem, 2) == _T("����")) {
		CString str = resv_view.GetItemText(selectitem, 3);
		strSQL.Format(_T("update FLIGHTS set numAvail = numAvail + 1 where flightNum = '%s'"), resv_choice);
		Cpublic::my_db.ExecuteSQL(strSQL);
	}
	else if (resv_view.GetItemText(selectitem, 2) == _T("����")) {
		CString str = resv_view.GetItemText(selectitem, 3);
		strSQL.Format(_T("update HOTELS set numAvail = numAvail + 1 where location = '%s'"), resv_choice);
		Cpublic::my_db.ExecuteSQL(strSQL);
	}
	else if (resv_view.GetItemText(selectitem, 2) == _T("�⳵")) {
		CString str = resv_view.GetItemText(selectitem, 3);
		strSQL.Format(_T("update CARS set numAvail = numAvail + 1 where location = '%s'"), resv_choice);
		Cpublic::my_db.ExecuteSQL(strSQL);
	}
	MessageBox(_T("ɾ���ɹ���"), _T("��ʾ"));
	resv_view.DeleteItem(selectitem);
	int num = update_choose_table.GetCurSel();
	init_view_text(num);
}


void CUpdateDlg::OnBnClickedSelectResv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRecordset rec(&Cpublic::my_db);
	INT_PTR nRes;
	CSelectResv selectresv;
	nRes = selectresv.DoModal();
}


void CUpdateDlg::OnBnClickedAll()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	init_resv_view(_T("select * from RESERVATIONS"));
}
