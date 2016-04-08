// InsertCustomer.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "InsertCustomer.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CInsertCustomer �Ի���

IMPLEMENT_DYNAMIC(CInsertCustomer, CDialogEx)

CInsertCustomer::CInsertCustomer(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertCustomer::IDD, pParent)
	, Insert_Customer(_T(""))
{

}

CInsertCustomer::~CInsertCustomer()
{
}

void CInsertCustomer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Insert_Customer, Insert_Customer);
	DDX_Control(pDX, IDC_Insert_Customer, Insert_Customer_Text);
}


BEGIN_MESSAGE_MAP(CInsertCustomer, CDialogEx)
	ON_EN_CHANGE(IDC_Insert_Customer, &CInsertCustomer::OnEnChangeInsertCustomer)
	ON_BN_CLICKED(IDC_Insert, &CInsertCustomer::OnBnClickedInsert)
END_MESSAGE_MAP()


// CInsertCustomer ��Ϣ�������


void CInsertCustomer::OnEnChangeInsertCustomer()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CInsertCustomer::OnBnClickedInsert()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CString insert = Insert_Customer;
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into CUSTOMERS values('%s')"),Insert_Customer);
	if (Insert_Customer != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		Insert_Customer_Text.SetWindowTextW(_T(""));
		Insert_Customer_Text.SetFocus();
		MessageBox(_T("����ɹ�"), _T("��ʾ"));
	}
	else MessageBox(_T("����������"), _T("��ʾ"));
}


BOOL CInsertCustomer::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
