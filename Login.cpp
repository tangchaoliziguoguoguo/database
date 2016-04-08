// Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "Login.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "Client.h"
#include "db_lab2Dlg.h"
#include "UpdateDlg.h"
#include "Sign.h"


// CLogin �Ի���

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogin::IDD, pParent)
	, name(_T(""))
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_name, name);
	DDX_Control(pDX, IDC_name, name_ctrl);
}


BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_BN_CLICKED(IDC_login, &CLogin::OnBnClickedlogin)
	ON_BN_CLICKED(IDC_sign, &CLogin::OnBnClickedsign)
END_MESSAGE_MAP()


// CLogin ��Ϣ�������


void CLogin::OnBnClickedlogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	Cdb_lab2Dlg* dlg = (Cdb_lab2Dlg*)GetParent();
	if (dlg->limit == false) {		// �û�Ȩ��
		CClient client;
		UpdateData(TRUE);
		CRecordset rec(&Cpublic::my_db);
		CString strSQL;
		strSQL.Format(_T("select * from CUSTOMERS where custName = '%s'"), name);
		rec.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
		rec.Requery();
		if (!name.Compare(_T(""))) {
			MessageBox(_T("������������"), _T("��ʾ"));
			return ;
		}
		else if (rec.IsEOF()) {
			MessageBox(_T("�û������ڣ�����ע�ᣡ"), _T("��ʾ"));
			CSign sign;
			sign.DoModal();
			return ;
		}
		Cdb_lab2App* app = (Cdb_lab2App*)AfxGetApp();
		app->username.Format(_T("%s"), name);
		client.DoModal();
	}
	else {		// ����Գ
		CUpdateDlg dlg;
		dlg.DoModal();
	}
}


BOOL CLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	Cdb_lab2Dlg* dlg = (Cdb_lab2Dlg*)GetParent();
	if (dlg->limit == true) {		// ����ԳȨ��
		SetDlgItemText(IDC_name, _T("system"));
		GetDlgItem(IDC_name)->EnableWindow(FALSE);
		GetDlgItem(IDC_sign)->EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CLogin::OnBnClickedsign()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSign sign;
	sign.DoModal();
}
