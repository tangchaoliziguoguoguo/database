// ResvCar.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "ResvCar.h"
#include "afxdialogex.h"
#include "UpdateDlg.h"
#include "Cpublic.h"
#include "Client.h"
#include <ctime>


// CResvCar �Ի���

IMPLEMENT_DYNAMIC(CResvCar, CDialogEx)

CResvCar::CResvCar(CWnd* pParent /*=NULL*/)
	: CDialogEx(CResvCar::IDD, pParent)
	, city(_T(""))
	, customer(_T(""))
	, resv_num(_T(""))
{

}

CResvCar::~CResvCar()
{
}

void CResvCar::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, city_ctrl);
	DDX_Text(pDX, IDC_EDIT1, city);
	DDX_Control(pDX, IDC_COMBO1, customer_ctrl);
	DDX_CBString(pDX, IDC_COMBO1, customer);
	DDX_Text(pDX, IDC_EDIT3, resv_num);
	DDX_Control(pDX, IDC_EDIT3, resv_num_ctrl);
}


BEGIN_MESSAGE_MAP(CResvCar, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CResvCar::OnBnClickedButton1)
END_MESSAGE_MAP()


// CResvCar ��Ϣ�������


BOOL CResvCar::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	CString resv_number;
	resv_number.Format(_T("%d"), time(NULL));

	if (Cpublic::limit == true) {
		int item = ((CUpdateDlg*)GetParent())->selectitem;
		city_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));		// ��ʼ�������С�
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);		// �������޸ġ����С�
		resv_num_ctrl.SetWindowTextW(resv_number);
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	
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
		// �ڽ��С��޸ġ�����ʱ�������ĶԻ�������Ҫ��ʾԭ������Ŀֵ
		city_ctrl.SetWindowTextW(((CClient*)GetParent())->insert_view_text.GetItemText(item, 0));
		resv_num_ctrl.SetWindowTextW(resv_number);
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);		// �������޸ġ����С�
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
		Cdb_lab2App* app = (Cdb_lab2App*)AfxGetApp();
		customer_ctrl.InsertString(0, app->username);
		customer_ctrl.SetCurSel(0);
		GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CResvCar::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������UpdateData(TRUE);
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into RESERVATIONS values('%s','%s',3,'%s')"), resv_num, customer, city);
	if (resv_num != _T("") && customer != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		strSQL.Format(_T("update CARS set numAvail = numAvail - 1 where location = '%s'"), city);
		Cpublic::my_db.ExecuteSQL(strSQL);
		MessageBox(_T("Ԥ���ɹ�"), _T("��ʾ"));
		CDialogEx::OnCancel();
	}
	else if (customer == _T("")) MessageBox(_T("��ѡ��ͻ�"), _T("��ʾ"));
	else MessageBox(_T("�����붩����"), _T("��ʾ"));
}
