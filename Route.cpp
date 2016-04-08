// Route.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "Route.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CRoute 对话框

IMPLEMENT_DYNAMIC(CRoute, CDialogEx)

CRoute::CRoute(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRoute::IDD, pParent)
	, customer(_T(""))
{

}

CRoute::~CRoute()
{
}

void CRoute::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_cust, cust_ctrl);
	DDX_CBString(pDX, IDC_cust, customer);
	DDX_Control(pDX, IDC_LIST1, list);
}


BEGIN_MESSAGE_MAP(CRoute, CDialogEx)
	ON_CBN_SELCHANGE(IDC_cust, &CRoute::OnCbnSelchangecust)
	ON_BN_CLICKED(IDC_check, &CRoute::OnBnClickedcheck)
END_MESSAGE_MAP()


// CRoute 消息处理程序


BOOL CRoute::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
		


	// TODO:  在此添加额外的初始化
	if (Cpublic::limit == true) {
		CRecordset rec(&Cpublic::my_db);
		rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from CUSTOMERS"));
		rec.Requery();
		int index = 0;
		while (!rec.IsEOF()) {
			CString str;
			rec.GetFieldValue(short(0), str);
			cust_ctrl.InsertString(index, str);		// 将字段加到视图列表中
			index++;
			rec.MoveNext();
		}
//		int item = ((CUpdateDlg*)GetParent())->selectitem;
//		SetDlgItemText(IDC_cust, ((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));
	}
	else {
		Cdb_lab2App* app = (Cdb_lab2App*)AfxGetApp();
		cust_ctrl.InsertString(0, app->username);
		cust_ctrl.SetCurSel(0);
		OnCbnSelchangecust();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRoute::OnCbnSelchangecust()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strSQL, from_city, ariv_city;
	UpdateData(TRUE);

	CRect rect_resv;
	list.GetClientRect(&rect_resv);
	list.DeleteAllItems();
	while (list.DeleteColumn(0));		// 删除所有列
	list.InsertColumn(0, _T("日期"), LVCFMT_CENTER, rect_resv.Width()/3, 0);
	list.InsertColumn(1, _T("行程"), LVCFMT_CENTER, rect_resv.Width()*2/3, 1);

	strSQL.Format(_T("select FLIGHTS.FromCity,FLIGHTS.ArivCity,FLIGHTS.date from FLIGHTS,RESERVATIONS where FLIGHTS.flightNum = RESERVATIONS.resvChoice and RESERVATIONS.custName = '%s' order by date"), customer);
	CRecordset rec(&Cpublic::my_db);
	rec.Open(AFX_DB_USE_DEFAULT_TYPE, strSQL);
	rec.Requery();
	int index = 0;
	CString str, date;
	while (!rec.IsEOF()) {
		CDBVariant varValue;
		rec.GetFieldValue(short(0), from_city);
		rec.GetFieldValue(short(1), ariv_city);
		rec.GetFieldValue(short(2), varValue);
		str.Format(_T("%s->%s"), from_city, ariv_city);
		date.Format(_T("%d"), varValue.m_iVal);
		list.InsertItem(index, date);
		list.SetItemText(index, 1, str);
		index++;
		rec.MoveNext();
	}
}


void CRoute::OnBnClickedcheck()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strSQL, from_city, ariv_city;
	static CString start;
	CString end;
	UpdateData(TRUE);
	strSQL.Format(_T("select FLIGHTS.FromCity,FLIGHTS.ArivCity,FLIGHTS.date from FLIGHTS,RESERVATIONS where FLIGHTS.flightNum = RESERVATIONS.resvChoice and RESERVATIONS.custName = '%s' order by date"), customer);
	CRecordset rec(&Cpublic::my_db);
	rec.Open(AFX_DB_USE_DEFAULT_TYPE, strSQL);
	rec.Requery();
	int index = 0;
	while (!rec.IsEOF()) {
		CString str;
		CDBVariant varValue;
		rec.GetFieldValue(short(0), from_city);
		rec.GetFieldValue(short(1), ariv_city);
		rec.GetFieldValue(short(2), varValue);
		if (index == 0) start.Format(_T("%s"), from_city);
		if (index != 0) {
			if (end.Compare(from_city)) {
				MessageBox(_T("线路不完整！"), _T("提示"));
				return ;
			}
		}
		end.Format(_T("%s"), ariv_city);
		index++;
		rec.MoveNext();
	}
	if (index == 0) {
		MessageBox(_T("尚无旅行计划！"), _T("提示"));
		return ;
	}
	else if (start.Compare(end)) {
		MessageBox(_T("线路不完整！"), _T("提示"));
		return ;
	}
	MessageBox(_T("线路完整！"), _T("提示"));
}
