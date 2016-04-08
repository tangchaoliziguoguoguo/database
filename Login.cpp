// Login.cpp : 实现文件
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


// CLogin 对话框

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


// CLogin 消息处理程序


void CLogin::OnBnClickedlogin()
{
	// TODO: 在此添加控件通知处理程序代码

	Cdb_lab2Dlg* dlg = (Cdb_lab2Dlg*)GetParent();
	if (dlg->limit == false) {		// 用户权限
		CClient client;
		UpdateData(TRUE);
		CRecordset rec(&Cpublic::my_db);
		CString strSQL;
		strSQL.Format(_T("select * from CUSTOMERS where custName = '%s'"), name);
		rec.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
		rec.Requery();
		if (!name.Compare(_T(""))) {
			MessageBox(_T("请输入姓名！"), _T("提示"));
			return ;
		}
		else if (rec.IsEOF()) {
			MessageBox(_T("用户不存在，请先注册！"), _T("提示"));
			CSign sign;
			sign.DoModal();
			return ;
		}
		Cdb_lab2App* app = (Cdb_lab2App*)AfxGetApp();
		app->username.Format(_T("%s"), name);
		client.DoModal();
	}
	else {		// 鹳狸猿
		CUpdateDlg dlg;
		dlg.DoModal();
	}
}


BOOL CLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	Cdb_lab2Dlg* dlg = (Cdb_lab2Dlg*)GetParent();
	if (dlg->limit == true) {		// 鹳狸猿权限
		SetDlgItemText(IDC_name, _T("system"));
		GetDlgItem(IDC_name)->EnableWindow(FALSE);
		GetDlgItem(IDC_sign)->EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CLogin::OnBnClickedsign()
{
	// TODO: 在此添加控件通知处理程序代码
	CSign sign;
	sign.DoModal();
}
