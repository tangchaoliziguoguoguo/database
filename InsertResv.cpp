// InsertResv.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "InsertResv.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CInsertResv �Ի���

IMPLEMENT_DYNAMIC(CInsertResv, CDialogEx)

CInsertResv::CInsertResv(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertResv::IDD, pParent)
	, resv_custname(_T(""))
	, resv_num(_T(""))
	, resv_type(0)
	, resv(_T(""))
{

}

CInsertResv::~CInsertResv()
{
}

void CInsertResv::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, resv_custname_ctrl);
	DDX_Text(pDX, IDC_EDIT1, resv_custname);
	DDX_Control(pDX, IDC_EDIT2, resv_num_ctrl);
	DDX_Text(pDX, IDC_EDIT2, resv_num);
	DDX_Control(pDX, IDC_EDIT3, resv_type_ctrl);
	DDX_Text(pDX, IDC_EDIT3, resv_type);
	DDX_Control(pDX, IDC_EDIT4, resv_ctrl);
	DDX_Text(pDX, IDC_EDIT4, resv);
	DDV_MinMaxInt(pDX, resv_type, 1, 3);
}


BEGIN_MESSAGE_MAP(CInsertResv, CDialogEx)
	ON_BN_CLICKED(IDC_Insert_Resv, &CInsertResv::OnBnClickedInsertResv)
	ON_BN_CLICKED(IDC_UPDATE, &CInsertResv::OnBnClickedUpdate)
END_MESSAGE_MAP()


// CInsertResv ��Ϣ�������


void CInsertResv::OnBnClickedInsertResv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into RESERVATIONS values('%s','%s',%d,'%s')"), resv_num, resv_custname, resv_type, resv);
	if (resv_custname != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		resv_custname_ctrl.SetWindowTextW(_T(""));
		resv_type_ctrl.SetWindowTextW(0);
		resv_ctrl.SetWindowTextW(_T(""));
		resv_num_ctrl.SetWindowTextW(0);
		MessageBox(_T("����ɹ�"), _T("��ʾ"));
	}
	else MessageBox(_T("����ȷ����"), _T("��ʾ"));
}


BOOL CInsertResv::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if (((CUpdateDlg*)GetParent())->button_choice == 1) {		// ��ȡ�������г�Ա����button_choice��ֵ
		GetDlgItem(IDC_Insert_Resv)->EnableWindow(FALSE);			// button_choiceΪ1ʱ�����á����롱��ť��������á��޸ġ���ť
		int item = ((CUpdateDlg*)GetParent())->selectitem;
		// �ڽ��С��޸ġ�����ʱ�������ĶԻ�������Ҫ��ʾԭ������Ŀֵ
		resv_num_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));
		resv_custname_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 1));
		resv_type_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 2));
		resv_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 3));
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);		// �������޸ġ������š�	
	}
	else GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CInsertResv::OnBnClickedUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("update RESERVATIONS set custName = '%s',resvType = %d,resvChoice = '%s' where resvKey = '%s'"), resv_custname, resv_type, resv, resv_num);
	Cpublic::my_db.ExecuteSQL(strSQL);
	MessageBox(_T("�޸ĳɹ�"), _T("��ʾ"));
}
