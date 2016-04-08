// InsertCustomer.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "InsertCustomer.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CInsertCustomer 对话框

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


// CInsertCustomer 消息处理程序


void CInsertCustomer::OnEnChangeInsertCustomer()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CInsertCustomer::OnBnClickedInsert()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString insert = Insert_Customer;
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into CUSTOMERS values('%s')"),Insert_Customer);
	if (Insert_Customer != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		Insert_Customer_Text.SetWindowTextW(_T(""));
		Insert_Customer_Text.SetFocus();
		MessageBox(_T("插入成功"), _T("提示"));
	}
	else MessageBox(_T("请输入姓名"), _T("提示"));
}


BOOL CInsertCustomer::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
