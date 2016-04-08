// SelectResv.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "SelectResv.h"
#include "afxdialogex.h"
#include "UpdateDlg.h"


// CSelectResv 对话框

IMPLEMENT_DYNAMIC(CSelectResv, CDialogEx)

CSelectResv::CSelectResv(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectResv::IDD, pParent)
	, num(_T(""))
	, name(_T(""))
{

}

CSelectResv::~CSelectResv()
{
}

void CSelectResv::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, num);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Control(pDX, IDC_COMBO1, type_ctrl);
}


BEGIN_MESSAGE_MAP(CSelectResv, CDialogEx)
	ON_BN_CLICKED(IDC_SELECT_NUM, &CSelectResv::OnBnClickedSelectNum)
	ON_BN_CLICKED(IDC_Select_name, &CSelectResv::OnBnClickedSelectname)
	ON_BN_CLICKED(IDC_Select_type, &CSelectResv::OnBnClickedSelecttype)
END_MESSAGE_MAP()


// CSelectResv 消息处理程序


void CSelectResv::OnBnClickedSelectNum()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("select * from RESERVATIONS where resvKey = '%s'"), num);
	if (num != _T("")) {
		((CUpdateDlg*)GetParent())->init_resv_view(strSQL);
		CDialogEx::OnCancel();
	}
	else MessageBox(_T("请输入订单号！"), _T("提示"));
}


void CSelectResv::OnBnClickedSelectname()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("select * from RESERVATIONS where custName = '%s'"), name);
	if (name != _T("")) {
		((CUpdateDlg*)GetParent())->init_resv_view(strSQL);
		CDialogEx::OnCancel();
	}
	else MessageBox(_T("请输入姓名！"), _T("提示"));
}


void CSelectResv::OnBnClickedSelecttype()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strSQL;
	switch(type_ctrl.GetCurSel()) {
	case 0:
		strSQL.Format(_T("select * from RESERVATIONS where resvType = 1"));
		((CUpdateDlg*)GetParent())->init_resv_view(strSQL);
		break;
	case 1:
		strSQL.Format(_T("select * from RESERVATIONS where resvType = 2"));
		((CUpdateDlg*)GetParent())->init_resv_view(strSQL);
		break;
	case 2:
		strSQL.Format(_T("select * from RESERVATIONS where resvType = 3"));
		((CUpdateDlg*)GetParent())->init_resv_view(strSQL);
		break;
	}
	CDialogEx::OnCancel();
}


BOOL CSelectResv::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	type_ctrl.InsertString(0, _T("航班"));
	type_ctrl.InsertString(1, _T("宾馆"));
	type_ctrl.InsertString(2, _T("租车"));
	type_ctrl.SetCurSel(0);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
