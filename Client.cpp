// Client.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "Login.h"
#include "UpdateDlg.h"
#include "Client.h"
#include "afxdialogex.h"
#include "InsertCustomer.h"
#include "Cpublic.h"
#include "InsertFlights.h"
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
#include "Confirm.h"



// CClient 对话框

IMPLEMENT_DYNAMIC(CClient, CDialogEx)

CClient::CClient(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClient::IDD, pParent)
{

}

CClient::~CClient()
{
}

void CClient::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, insert_view_text);
	DDX_Control(pDX, IDC_LIST5, resv_view);
	DDX_Control(pDX, IDC_Update_Choose_Table, update_choose_table);
}


BEGIN_MESSAGE_MAP(CClient, CDialogEx)
	ON_CBN_SELCHANGE(IDC_Update_Choose_Table, &CClient::OnCbnSelchangeUpdateChooseTable)
	ON_BN_CLICKED(IDC_Reservation, &CClient::OnBnClickedReservation)
	ON_BN_CLICKED(IDC_SELECT, &CClient::OnBnClickedSelect)
	ON_BN_CLICKED(IDC_DELETE_RESV, &CClient::OnBnClickedDeleteResv)
	ON_BN_CLICKED(IDC_Route, &CClient::OnBnClickedRoute)
END_MESSAGE_MAP()


// CClient 消息处理程序


/****我自己定义的函数部分***/

void CClient::open_insert_flights_table()
{
	// 打开插入航班的窗口，并在关闭后刷新视图列表
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

void CClient::open_insert_hotels_table()
{
	// 打开插入宾馆的窗口，并在关闭后刷新视图列表
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

void CClient::open_insert_cars_table()
{
	// 打开插入租车的窗口，并在关闭后刷新视图列表
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

void CClient::open_insert_reservations_table()
{
	// 打开插入预定的窗口，并在关闭后刷新视图列表
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

void CClient::init_view_text(int num)
{
	CString strSQL;

	switch(num) {
	case 0:
		strSQL.Format(_T("select * from FLIGHTS"));
		init_view_text_flight(strSQL);
		break;
	case 1:
		strSQL.Format(_T("select * from HOTELS"));
		init_view_text_hotel(strSQL);
		break;
	case 2:
		strSQL.Format(_T("select * from CARS"));
		init_view_text_car(strSQL);
		break;
	}

//	if (num == 0) {		// 0代表CUSTOMERS表
//		insert_view_text.DeleteAllItems();
//		while (insert_view_text.DeleteColumn(0));		// 删除所有列
//		insert_view_text.InsertColumn(0, _T("姓名"), LVCFMT_CENTER, rect.Width()/5, 0);
//		rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from CUSTOMERS"));
//		rec.Requery();
//		while (!rec.IsEOF()) {
//			CString str;
//			rec.GetFieldValue(short(0), str);
////			CString str = *(dbvar.m_pstring);
//			insert_view_text.InsertItem(0, str);		// 将字段加到视图列表中
//			rec.MoveNext();
//		}
//	}
//
//	if (num == 1) {		// 1代表FLIGHTS表
//		insert_view_text.DeleteAllItems();
//		while (insert_view_text.DeleteColumn(0));		// 删除所有列
//		insert_view_text.InsertColumn(0, _T("航班号"), LVCFMT_CENTER, rect.Width()/6, 0);
//		insert_view_text.InsertColumn(1, _T("价格"), LVCFMT_CENTER, rect.Width()/6, 1);
//		insert_view_text.InsertColumn(2, _T("座位总数"), LVCFMT_CENTER, rect.Width()/6, 2);
//		insert_view_text.InsertColumn(3, _T("剩余"), LVCFMT_CENTER, rect.Width()/6, 3);
//		insert_view_text.InsertColumn(4, _T("起点"), LVCFMT_CENTER, rect.Width()/6, 4);
//		insert_view_text.InsertColumn(5, _T("终点"), LVCFMT_CENTER, rect.Width()/6, 5);
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
//	if (num == 2) {		// 2代表HOTELS表
//		insert_view_text.DeleteAllItems();
//		while (insert_view_text.DeleteColumn(0));		// 删除所有列
//		insert_view_text.InsertColumn(0, _T("城市"), LVCFMT_CENTER, rect.Width()/4, 0);
//		insert_view_text.InsertColumn(1, _T("价格"), LVCFMT_CENTER, rect.Width()/4, 1);
//		insert_view_text.InsertColumn(2, _T("总数"), LVCFMT_CENTER, rect.Width()/4, 2);
//		insert_view_text.InsertColumn(3, _T("剩余"), LVCFMT_CENTER, rect.Width()/4, 3);
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
//	if (num == 3) {		// 3代表CARS表
//		insert_view_text.DeleteAllItems();
//		while (insert_view_text.DeleteColumn(0));		// 删除所有列
//		insert_view_text.InsertColumn(0, _T("城市"), LVCFMT_CENTER, rect.Width()/4, 0);
//		insert_view_text.InsertColumn(1, _T("价格"), LVCFMT_CENTER, rect.Width()/4, 1);
//		insert_view_text.InsertColumn(2, _T("总数"), LVCFMT_CENTER, rect.Width()/4, 2);
//		insert_view_text.InsertColumn(3, _T("剩余"), LVCFMT_CENTER, rect.Width()/4, 3);
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
//	if (num == 4) {		// 4代表RESERVATIONS表
//		insert_view_text.DeleteAllItems();
//		while (insert_view_text.DeleteColumn(0));		// 删除所有列
//		insert_view_text.InsertColumn(0, _T("订单号"), LVCFMT_CENTER, rect.Width()/4, 0);
//		insert_view_text.InsertColumn(1, _T("客户"), LVCFMT_CENTER, rect.Width()/4, 1);
//		insert_view_text.InsertColumn(2, _T("订单类型"), LVCFMT_CENTER, rect.Width()/4, 2);
//		insert_view_text.InsertColumn(3, _T("订单内容"), LVCFMT_CENTER, rect.Width()/4, 3);
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


void CClient::init_view_text_flight(CString str)
{
	CRect rect;
	CRecordset rec(&Cpublic::my_db);
//	CDBVariant dbvar;
	insert_view_text.GetClientRect(&rect);
	insert_view_text.DeleteAllItems();
	while (insert_view_text.DeleteColumn(0));		// 删除所有列
	insert_view_text.InsertColumn(0, _T("航班号"), LVCFMT_CENTER, rect.Width()*2/15, 0);
	insert_view_text.InsertColumn(1, _T("起点"), LVCFMT_CENTER, rect.Width()*2/15, 1);
	insert_view_text.InsertColumn(2, _T("终点"), LVCFMT_CENTER, rect.Width()*2/15, 2);
	insert_view_text.InsertColumn(3, _T("日期"), LVCFMT_CENTER, rect.Width()*2/15, 3);
	insert_view_text.InsertColumn(4, _T("价格"), LVCFMT_CENTER, rect.Width()*2/15, 4);
	insert_view_text.InsertColumn(5, _T("座位总数"), LVCFMT_CENTER, rect.Width()*3/15, 5);
	insert_view_text.InsertColumn(6, _T("剩余"), LVCFMT_CENTER, rect.Width()*2/15, 6);
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

void CClient::init_view_text_hotel(CString str)
{
	CRect rect;
	CRecordset rec(&Cpublic::my_db);
//	CDBVariant dbvar;
	insert_view_text.GetClientRect(&rect);
	insert_view_text.DeleteAllItems();
	while (insert_view_text.DeleteColumn(0));		// 删除所有列
	insert_view_text.InsertColumn(0, _T("城市"), LVCFMT_CENTER, rect.Width()/4, 0);
	insert_view_text.InsertColumn(1, _T("价格"), LVCFMT_CENTER, rect.Width()/4, 1);
	insert_view_text.InsertColumn(2, _T("总数"), LVCFMT_CENTER, rect.Width()/4, 2);
	insert_view_text.InsertColumn(3, _T("剩余"), LVCFMT_CENTER, rect.Width()/4, 3);
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

void CClient::init_view_text_car(CString str)
{
	CRect rect;
	CRecordset rec(&Cpublic::my_db);
//	CDBVariant dbvar;
	insert_view_text.GetClientRect(&rect);
	insert_view_text.DeleteAllItems();
	while (insert_view_text.DeleteColumn(0));		// 删除所有列
	insert_view_text.InsertColumn(0, _T("城市"), LVCFMT_CENTER, rect.Width()/4, 0);
	insert_view_text.InsertColumn(1, _T("价格"), LVCFMT_CENTER, rect.Width()/4, 1);
	insert_view_text.InsertColumn(2, _T("总数"), LVCFMT_CENTER, rect.Width()/4, 2);
	insert_view_text.InsertColumn(3, _T("剩余"), LVCFMT_CENTER, rect.Width()/4, 3);
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

void CClient::init_view_text_reservation(CString str)
{
	CRect rect;
	CRecordset rec(&Cpublic::my_db);
//	CDBVariant dbvar;
	insert_view_text.GetClientRect(&rect);
	insert_view_text.DeleteAllItems();
	while (insert_view_text.DeleteColumn(0));		// 删除所有列
	insert_view_text.InsertColumn(0, _T("订单号"), LVCFMT_CENTER, rect.Width()/4, 0);
	insert_view_text.InsertColumn(1, _T("客户"), LVCFMT_CENTER, rect.Width()/4, 1);
	insert_view_text.InsertColumn(2, _T("订单类型"), LVCFMT_CENTER, rect.Width()/4, 2);
	insert_view_text.InsertColumn(3, _T("订单内容"), LVCFMT_CENTER, rect.Width()/4, 3);
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

void CClient::init_resv_view(CString str)
{
	// 初始化订单信息部分
	CString strSQL;
	CRect rect_resv;
	CRecordset rec(&Cpublic::my_db);
//	CDBVariant dbvar;
	resv_view.GetClientRect(&rect_resv);
	resv_view.DeleteAllItems();
	while (resv_view.DeleteColumn(0));		// 删除所有列
	resv_view.InsertColumn(0, _T("订单号"), LVCFMT_CENTER, rect_resv.Width()/5, 0);
	resv_view.InsertColumn(1, _T("客户"), LVCFMT_CENTER, rect_resv.Width()/5, 1);
	resv_view.InsertColumn(2, _T("订单类型"), LVCFMT_CENTER, rect_resv.Width()/5, 2);
	resv_view.InsertColumn(3, _T("详细信息"), LVCFMT_CENTER, rect_resv.Width()*2/5, 3);
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
//		str.Format(_T("%d"), varValue.m_iVal);
		if (varValue.m_iVal == 1) {
			resv_view.SetItemText(index, 2, _T("航班"));
		}
		else if (varValue.m_iVal == 2) {
			resv_view.SetItemText(index, 2, _T("宾馆"));
		}
		else if (varValue.m_iVal == 3) {
			resv_view.SetItemText(index, 2, _T("租车"));
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

/****我自己定义的函数部分***/

BOOL CClient::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	update_choose_table.InsertString(0, _T("航班"));
	update_choose_table.InsertString(1, _T("旅馆"));
	update_choose_table.InsertString(2, _T("租车"));
	update_choose_table.SetCurSel(0);
	
	int num = update_choose_table.GetCurSel();
	init_view_text(num);

	CLogin *login = (CLogin*)GetParent();
	SetDlgItemText(IDC_STATIC_NAME, login->name);

	CString str;
	str.Format(_T("select * from RESERVATIONS where custName = '%s'"), login->name);
	username.Format(_T("%s"), login->name);
	init_resv_view(str);

	GetParent()->PostMessage(WM_CLOSE,0,0);		// 关闭登录框
	GetParent()->GetParent()->PostMessage(WM_CLOSE,0,0);	// 关闭主对话框




	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CClient::OnCbnSelchangeUpdateChooseTable()
{
	// TODO: 在此添加控件通知处理程序代码
	int num = update_choose_table.GetCurSel();
	init_view_text(num);
}


void CClient::OnBnClickedReservation()
{
	// TODO: 在此添加控件通知处理程序代码
	int sel = update_choose_table.GetCurSel();
	CRecordset rec(&Cpublic::my_db);
	INT_PTR nRes;
	CResvFlight resvflight;
	CResvHotel resvhotel;
	CResvCar resvcar;
	POSITION pos = insert_view_text.GetFirstSelectedItemPosition();		// 视图列表中被选择项的位置
	if (pos == NULL) {
		MessageBox(_T("请先选中要预定的条目！"), _T("提示"));
		return ;
	}
	selectitem = insert_view_text.GetNextSelectedItem(pos);		// 被选择项的索引
	switch(sel) {
	case 0:
	//	resvflight.SetDlgItemTextW(IDC_resv_flight, username);
		nRes = resvflight.DoModal();
		break;
	case 1:
	//	resvhotel.SetDlgItemTextW(IDC_COMBO1, username);
		nRes = resvhotel.DoModal();
		break;
	case 2:
	//	resvcar.SetDlgItemTextW(IDC_COMBO1, username);
		nRes = resvcar.DoModal();
		break;
	}
	init_view_text(update_choose_table.GetCurSel());
	
	CLogin *login = (CLogin*)GetParent();
	SetDlgItemText(IDC_STATIC_NAME, login->name);

	CString str;
	str.Format(_T("select * from RESERVATIONS where custName = '%s'"), login->name);
	init_resv_view(str);
}


void CClient::OnBnClickedSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	int num = update_choose_table.GetCurSel();
	CRecordset rec(&Cpublic::my_db);
	INT_PTR nRes;
	CSelectFlight selectflight;
	CSelectHotel selecthotel;
	CSelectCar selectcar;
	switch(num) {
	case 0:
		nRes = selectflight.DoModal();
		break;
	case 1:
		nRes = selecthotel.DoModal();
		break;
	case 2:
		nRes = selectcar.DoModal();
		break;
	}
}


void CClient::OnBnClickedDeleteResv()
{
	// TODO: 在此添加控件通知处理程序代码
	POSITION pos = resv_view.GetFirstSelectedItemPosition();		// 视图列表中被选择项的位置
	if (pos == NULL) {
		MessageBox(_T("请先选中要删除的条目！"), _T("提示"));
		return ;
	}

	CConfirm confirm;
	INT_PTR nRes;
	nRes = confirm.DoModal();
	if (IDCANCEL == nRes) return ;
	CString strSQL;
	int selectitem = resv_view.GetNextSelectedItem(pos);		// 被选择项的索引
	CString to_del = resv_view.GetItemText(selectitem, 0);

	CRecordset rec(&Cpublic::my_db);
	strSQL.Format(_T("select resvChoice from RESERVATIONS where resvKey = '%s'"), to_del);
	rec.Open(AFX_DB_USE_DEFAULT_TYPE, strSQL);
	rec.Requery();
	CString resv_choice;
	rec.GetFieldValue(short(0), resv_choice);
	

	strSQL.Format(_T("delete from RESERVATIONS where resvKey = '%s'"), to_del);
	Cpublic::my_db.ExecuteSQL(strSQL);
	// 删除完某个订单之后，相应的available要加一
	if (resv_view.GetItemText(selectitem, 2) == _T("航班")) {
		CString str = resv_view.GetItemText(selectitem, 3);
		strSQL.Format(_T("update FLIGHTS set numAvail = numAvail + 1 where flightNum = '%s'"), resv_choice);
		Cpublic::my_db.ExecuteSQL(strSQL);
	}
	else if (resv_view.GetItemText(selectitem, 2) == _T("宾馆")) {
		CString str = resv_view.GetItemText(selectitem, 3);
		strSQL.Format(_T("update HOTELS set numAvail = numAvail + 1 where location = '%s'"), resv_choice);
		Cpublic::my_db.ExecuteSQL(strSQL);
	}
	else if (resv_view.GetItemText(selectitem, 2) == _T("租车")) {
		CString str = resv_view.GetItemText(selectitem, 3);
		strSQL.Format(_T("update CARS set numAvail = numAvail + 1 where location = '%s'"), resv_choice);
		Cpublic::my_db.ExecuteSQL(strSQL);
	}
	MessageBox(_T("删除成功！"), _T("提示"));
	resv_view.DeleteItem(selectitem);
	int num = update_choose_table.GetCurSel();
	init_view_text(num);
}


void CClient::OnBnClickedRoute()
{
	// TODO: 在此添加控件通知处理程序代码
	CRecordset rec(&Cpublic::my_db);
	CRoute route;
	POSITION pos = insert_view_text.GetFirstSelectedItemPosition();
	selectitem = insert_view_text.GetNextSelectedItem(pos);
	route.DoModal();
}
