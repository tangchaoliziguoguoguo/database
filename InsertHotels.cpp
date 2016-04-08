// InsertHotels.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "InsertHotels.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CInsertHotels �Ի���

IMPLEMENT_DYNAMIC(CInsertHotels, CDialogEx)

CInsertHotels::CInsertHotels(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertHotels::IDD, pParent)
	, hotel_city(_T(""))
	, hotel_price(0)
	, hotel_num(0)
{

}

CInsertHotels::~CInsertHotels()
{
}

void CInsertHotels::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, hotel_city);
	DDX_Text(pDX, IDC_EDIT2, hotel_price);
	DDX_Text(pDX, IDC_EDIT3, hotel_num);
	DDX_Control(pDX, IDC_EDIT1, hotel_city_ctrl);
	DDX_Control(pDX, IDC_EDIT2, hotel_price_ctrl);
	DDX_Control(pDX, IDC_EDIT3, hotel_num_ctrl);
}


BEGIN_MESSAGE_MAP(CInsertHotels, CDialogEx)
	ON_BN_CLICKED(IDC_Insert_Hotel, &CInsertHotels::OnBnClickedInsertHotel)
	ON_BN_CLICKED(IDC_UPDATE, &CInsertHotels::OnBnClickedUpdate)
	ON_BN_CLICKED(IDCANCEL, &CInsertHotels::OnBnClickedCancel)
	//ON_EN_CHANGE(IDC_EDIT3, &CInsertHotels::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CInsertHotels ��Ϣ�������


void CInsertHotels::OnBnClickedInsertHotel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into HOTELS values('%s',%d,%d,%d)"), hotel_city, hotel_price, hotel_num, hotel_num);
	if (hotel_city != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		hotel_city_ctrl.SetWindowTextW(_T(""));
		hotel_price_ctrl.SetWindowTextW(0);
		hotel_num_ctrl.SetWindowTextW(0);
		MessageBox(_T("����ɹ�"), _T("��ʾ"));
	}
	else MessageBox(_T("����ȷ����"), _T("��ʾ"));
}

BOOL CInsertHotels::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if (((CUpdateDlg*)GetParent())->button_choice == 1) {		// ��ȡ�������г�Ա����button_choice��ֵ
		GetDlgItem(IDC_Insert_Hotel)->EnableWindow(FALSE);			// button_choiceΪ1ʱ�����á����롱��ť��������á��޸ġ���ť
		int item = ((CUpdateDlg*)GetParent())->selectitem;
		// �ڽ��С��޸ġ�����ʱ�������ĶԻ�������Ҫ��ʾԭ������Ŀֵ
		hotel_city_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));
		hotel_price_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 1));
		hotel_num_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 2));
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);		// �������޸ġ����С�
		//GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	}
	else {
		GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CInsertHotels::OnBnClickedUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("update HOTELS set price = %d,where location = '%s'"), hotel_price, hotel_city);
	Cpublic::my_db.ExecuteSQL(strSQL);
	MessageBox(_T("�޸ĳɹ�"), _T("��ʾ"));
}


void CInsertHotels::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


//void CInsertHotels::OnEnChangeEdit3()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//	CString show;
//	UpdateData(TRUE);
//	show.Format(_T("%d"), hotel_num);
//	//GetDlgItemText(IDC_EDIT3, show);
//	hotel_num_avail_ctrl.SetWindowTextW(show);
//	UpdateData(TRUE);
//}
