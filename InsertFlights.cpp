// InsertFlights.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "InsertFlights.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CInsertFlights �Ի���

IMPLEMENT_DYNAMIC(CInsertFlights, CDialogEx)

CInsertFlights::CInsertFlights(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertFlights::IDD, pParent)
	, flight_num(_T(""))
	, flight_price(0)
	, num_seat(0)
	, from_city(_T(""))
	, ariv_city(_T(""))
	, date(0)
{

}

CInsertFlights::~CInsertFlights()
{
}

void CInsertFlights::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, flight_num);
	DDX_Text(pDX, IDC_EDIT4, flight_price);
	DDX_Text(pDX, IDC_EDIT2, num_seat);
	DDX_Text(pDX, IDC_EDIT3, from_city);
	DDX_Text(pDX, IDC_EDIT6, ariv_city);
	DDV_MaxChars(pDX, ariv_city, 10);
	DDV_MaxChars(pDX, from_city, 10);
	DDX_Control(pDX, IDC_EDIT1, flight_num_ctrl);
	DDX_Control(pDX, IDC_EDIT4, flight_price_ctrl);
	DDX_Control(pDX, IDC_EDIT2, num_seat_ctrl);
	DDX_Control(pDX, IDC_EDIT3, from_city_ctrl);
	DDX_Control(pDX, IDC_EDIT6, ariv_city_ctrl);
	DDX_Control(pDX, IDC_date, date_ctrl);
	DDX_Text(pDX, IDC_date, date);
}


BEGIN_MESSAGE_MAP(CInsertFlights, CDialogEx)
	ON_BN_CLICKED(IDC_Insert_Flights, &CInsertFlights::OnBnClickedInsertFlights)
	ON_BN_CLICKED(IDC_UPDATE, &CInsertFlights::OnBnClickedUpdate)
	//ON_EN_CHANGE(IDC_EDIT2, &CInsertFlights::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CInsertFlights ��Ϣ�������


void CInsertFlights::OnBnClickedInsertFlights()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into FLIGHTS values('%s',%d,%d,%d,'%s','%s',%d)"), flight_num, flight_price, num_seat, num_seat, from_city, ariv_city, date);
	if (flight_num != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		flight_num_ctrl.SetWindowTextW(_T(""));
		flight_price_ctrl.SetWindowTextW(0);
		num_seat_ctrl.SetWindowTextW(0);
		from_city_ctrl.SetWindowTextW(_T(""));
		ariv_city_ctrl.SetWindowTextW(_T(""));
		date_ctrl.SetWindowTextW(0);
//	Insert_Customer_Text.SetFocus();
		MessageBox(_T("����ɹ�"), _T("��ʾ"));
	}
	else MessageBox(_T("����ȷ����"), _T("��ʾ"));
}


BOOL CInsertFlights::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if (((CUpdateDlg*)GetParent())->button_choice == 1) {		// ��ȡ�������г�Ա����button_choice��ֵ
		GetDlgItem(IDC_Insert_Flights)->EnableWindow(FALSE);			// button_choiceΪ1ʱ�����á����롱��ť��������á��޸ġ���ť
		int item = ((CUpdateDlg*)GetParent())->selectitem;
		// �ڽ��С��޸ġ�����ʱ�������ĶԻ�������Ҫ��ʾԭ������Ŀֵ
		flight_num_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));
		flight_price_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 4));
		num_seat_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 5));
//		num_seat_avail_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 3));
		from_city_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 1));
		ariv_city_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 2));
		date_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 3));
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);		// �������޸ġ�����š�
		//GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);	
		//GetDlgItem(IDC_date)->EnableWindow(FALSE);	
	}
	else {
		GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CInsertFlights::OnBnClickedUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("update FLIGHTS set price = %d,FromCity ='%s',ArivCity = '%s' where flightNum = '%s'"), flight_price, from_city, ariv_city, flight_num);
	Cpublic::my_db.ExecuteSQL(strSQL);
	MessageBox(_T("�޸ĳɹ�"), _T("��ʾ"));
}


//void CInsertFlights::OnEnChangeEdit2()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//	CString show;
//	UpdateData(TRUE);
//	show.Format(_T("%d"), num_seat);
//	num_seat_avail_ctrl.SetWindowTextW(show);
//}
