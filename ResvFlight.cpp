// ResvFlight.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "ResvFlight.h"
#include "afxdialogex.h"
#include "UpdateDlg.h"
#include "Cpublic.h"
#include "Client.h"
#include <ctime>


// CResvFlight �Ի���

IMPLEMENT_DYNAMIC(CResvFlight, CDialogEx)

CResvFlight::CResvFlight(CWnd* pParent /*=NULL*/)
	: CDialogEx(CResvFlight::IDD, pParent)
	, flight_num(_T(""))
	, resv_num(_T(""))
	, customer(_T(""))
{

}

CResvFlight::~CResvFlight()
{
}

void CResvFlight::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, flight_num_ctrl);
	DDX_Text(pDX, IDC_EDIT1, flight_num);
	DDX_Text(pDX, IDC_EDIT2, resv_num);
	DDX_Control(pDX, IDC_resv_flight, customer_ctrl);
	DDX_CBString(pDX, IDC_resv_flight, customer);
	DDX_Control(pDX, IDC_EDIT2, resv_num_ctrl);
	DDX_Control(pDX, IDC_Route, route_ctrl);
	DDX_Control(pDX, IDC_date, date_ctrl);
}


BEGIN_MESSAGE_MAP(CResvFlight, CDialogEx)
	ON_BN_CLICKED(IDC_Resv, &CResvFlight::OnBnClickedResv)
END_MESSAGE_MAP()


// CResvFlight ��Ϣ�������


BOOL CResvFlight::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	CString resv_number;
	resv_number.Format(_T("%d"), time(NULL));
	
	
	if (Cpublic::limit == true) {
		int item = ((CUpdateDlg*)GetParent())->selectitem;
		CString from, to, str;
		// �ڽ��С��޸ġ�����ʱ�������ĶԻ�������Ҫ��ʾԭ������Ŀֵ
		flight_num_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));
		from.Format(_T("%s"), ((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 1));
		to.Format(_T("%s"), ((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 2));
		str.Format(_T("%s->%s"), from, to);
		route_ctrl.SetWindowTextW(str);
		date_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 3));
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);		// �������޸ġ�����š�
		resv_num_ctrl.SetWindowTextW(resv_number);
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_Route)->EnableWindow(FALSE);
		GetDlgItem(IDC_date)->EnableWindow(FALSE);

		CRecordset rec(&Cpublic::my_db);
		rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from CUSTOMERS"));
		rec.Requery();
		int index = 0;
		while (!rec.IsEOF()) {
			CString str;
			rec.GetFieldValue(short(0), str);
			customer_ctrl.InsertString(index, str);		// ���ֶμӵ���ͼ�б���
			index++;
			rec.MoveNext();
		}
	}

	else {
		int item = ((CClient*)GetParent())->selectitem;
		CString from, to, str;
		// �ڽ��С��޸ġ�����ʱ�������ĶԻ�������Ҫ��ʾԭ������Ŀֵ
		flight_num_ctrl.SetWindowTextW(((CClient*)GetParent())->insert_view_text.GetItemText(item, 0));
		from.Format(_T("%s"), ((CClient*)GetParent())->insert_view_text.GetItemText(item, 1));
		to.Format(_T("%s"), ((CClient*)GetParent())->insert_view_text.GetItemText(item, 2));
		str.Format(_T("%s->%s"), from, to);
		route_ctrl.SetWindowTextW(str);
		date_ctrl.SetWindowTextW(((CClient*)GetParent())->insert_view_text.GetItemText(item, 3));
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);		// �������޸ġ�����š�
		resv_num_ctrl.SetWindowTextW(resv_number);
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_Route)->EnableWindow(FALSE);
		GetDlgItem(IDC_date)->EnableWindow(FALSE);

		Cdb_lab2App* app = (Cdb_lab2App*)AfxGetApp();
		customer_ctrl.InsertString(0, app->username);
		customer_ctrl.SetCurSel(0);
		GetDlgItem(IDC_resv_flight)->EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CResvFlight::OnBnClickedResv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strSQL, from, to, str;
	//if (Cpublic::limit == true) {
	//	int item = ((CUpdateDlg*)GetParent())->selectitem;
	//	from.Format(_T("%s"), ((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 4));
	//	to.Format(_T("%s"), ((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 5));
	//}
	//else {
	//	int item = ((CClient*)GetParent())->selectitem;
	//	from.Format(_T("%s"), ((CClient*)GetParent())->insert_view_text.GetItemText(item, 4));
	//	to.Format(_T("%s"), ((CClient*)GetParent())->insert_view_text.GetItemText(item, 5));
	//}
	//str.Format(_T("%s(%s->%s)"), flight_num, from, to);		// ��ʾ������ţ����->�յ�)��
	strSQL.Format(_T("insert into RESERVATIONS values('%s','%s',1,'%s')"), resv_num, customer, flight_num);
	if (resv_num != _T("") && customer != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		strSQL.Format(_T("update FLIGHTS set numAvail = numAvail - 1 where flightNum = '%s'"), flight_num);		// Ԥ����֮����Ӧ��availableֵҪ��һ
		Cpublic::my_db.ExecuteSQL(strSQL);
		MessageBox(_T("Ԥ���ɹ�"), _T("��ʾ"));
		CDialogEx::OnCancel();
	}
	else if (customer == _T("")) MessageBox(_T("��ѡ��ͻ�"), _T("��ʾ"));
	else MessageBox(_T("�����붩����"), _T("��ʾ"));
}
