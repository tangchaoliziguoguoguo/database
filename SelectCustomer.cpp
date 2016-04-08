// SelectCustomer.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "SelectCustomer.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CSelectCustomer 对话框

IMPLEMENT_DYNAMIC(CSelectCustomer, CDialogEx)

CSelectCustomer::CSelectCustomer(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectCustomer::IDD, pParent)
	, name(_T(""))
{

}

CSelectCustomer::~CSelectCustomer()
{
}

void CSelectCustomer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
}


BEGIN_MESSAGE_MAP(CSelectCustomer, CDialogEx)
	ON_BN_CLICKED(IDC_SELECT, &CSelectCustomer::OnBnClickedSelect)
END_MESSAGE_MAP()


// CSelectCustomer 消息处理程序


void CSelectCustomer::OnBnClickedSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("select * from CUSTOMERS where custName = '%s'"), name);
	if (name != _T("")) {
		((CUpdateDlg*)GetParent())->init_view_text_customer(strSQL);
		CDialogEx::OnCancel();
	}
	else MessageBox(_T("请输入姓名！"), _T("提示"));
}
