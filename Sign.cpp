// Sign.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "Sign.h"
#include "afxdialogex.h"
#include "Cpublic.h"


// CSign 对话框

IMPLEMENT_DYNAMIC(CSign, CDialogEx)

CSign::CSign(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSign::IDD, pParent)
	, name(_T(""))
{

}

CSign::~CSign()
{
}

void CSign::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
}


BEGIN_MESSAGE_MAP(CSign, CDialogEx)
	ON_BN_CLICKED(IDC_sign, &CSign::OnBnClickedsign)
END_MESSAGE_MAP()


// CSign 消息处理程序


void CSign::OnBnClickedsign()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strSQL;
	CRecordset rec(&Cpublic::my_db);
	if (name != _T("")) {
		strSQL.Format(_T("select * from CUSTOMERS where custName = '%s'"), name);
		rec.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
		rec.Requery();
		if (!rec.IsEOF()) {
			MessageBox(_T("用户名已存在！"),_T("提示"));
			return ;
		}
		strSQL.Format(_T("insert into CUSTOMERS values('%s')"), name);
		Cpublic::my_db.ExecuteSQL(strSQL);
		MessageBox(_T("注册成功！"), _T("提示"));
		CDialogEx::OnCancel();
	}
	else MessageBox(_T("请输入姓名！"), _T("提示"));
}
