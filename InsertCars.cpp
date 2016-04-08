// InsertCars.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "InsertCars.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CInsertCars �Ի���

IMPLEMENT_DYNAMIC(CInsertCars, CDialogEx)

CInsertCars::CInsertCars(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertCars::IDD, pParent)
	, cars_city(_T(""))
	, cars_price(0)
	, cars_num(0)
{

}

CInsertCars::~CInsertCars()
{
}

void CInsertCars::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, cars_city_ctrl);
	DDX_Text(pDX, IDC_EDIT1, cars_city);
	DDX_Control(pDX, IDC_EDIT2, cars_price_ctrl);
	DDX_Text(pDX, IDC_EDIT2, cars_price);
	DDX_Control(pDX, IDC_EDIT3, cars_num_ctrl);
	DDX_Text(pDX, IDC_EDIT3, cars_num);
}


BEGIN_MESSAGE_MAP(CInsertCars, CDialogEx)
	ON_BN_CLICKED(IDC_Insert_Cars, &CInsertCars::OnBnClickedInsertCars)
	ON_BN_CLICKED(IDC_UPDATE, &CInsertCars::OnBnClickedUpdate)
	//ON_EN_CHANGE(IDC_EDIT3, &CInsertCars::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CInsertCars ��Ϣ�������


void CInsertCars::OnBnClickedInsertCars()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into CARS values('%s',%d,%d,%d)"), cars_city, cars_price, cars_num, cars_num);
	if (cars_city != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		cars_city_ctrl.SetWindowTextW(_T(""));
		cars_price_ctrl.SetWindowTextW(0);
		cars_num_ctrl.SetWindowTextW(0);
		MessageBox(_T("����ɹ�"), _T("��ʾ"));
	}
	else MessageBox(_T("����ȷ����"), _T("��ʾ"));
}


BOOL CInsertCars::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if (((CUpdateDlg*)GetParent())->button_choice == 1) {		// ��ȡ�������г�Ա����button_choice��ֵ
		GetDlgItem(IDC_Insert_Cars)->EnableWindow(FALSE);			// button_choiceΪ1ʱ�����á����롱��ť��������á��޸ġ���ť
		int item = ((CUpdateDlg*)GetParent())->selectitem;
		// �ڽ��С��޸ġ�����ʱ�������ĶԻ�������Ҫ��ʾԭ������Ŀֵ
		cars_city_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));
		cars_price_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 1));
		cars_num_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 2));
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		//GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);		// ��֧�ֶԡ����������޸�
	}
	else {
		GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CInsertCars::OnBnClickedUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("update CARS set price = %d,where location = '%s'"), cars_price, cars_city);
	if (cars_city != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		MessageBox(_T("�޸ĳɹ�"), _T("��ʾ"));
	}
}


//void CInsertCars::OnEnChangeEdit3()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//	CString show;
//	UpdateData(TRUE);
//	show.Format(_T("%d"), cars_num);
//	cars_num_avail_ctrl.SetWindowTextW(show);
//}
