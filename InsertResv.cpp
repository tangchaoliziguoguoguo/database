// InsertResv.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "InsertResv.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CInsertResv 对话框

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


// CInsertResv 消息处理程序


void CInsertResv::OnBnClickedInsertResv()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into RESERVATIONS values('%s','%s',%d,'%s')"), resv_num, resv_custname, resv_type, resv);
	if (resv_custname != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		resv_custname_ctrl.SetWindowTextW(_T(""));
		resv_type_ctrl.SetWindowTextW(0);
		resv_ctrl.SetWindowTextW(_T(""));
		resv_num_ctrl.SetWindowTextW(0);
		MessageBox(_T("插入成功"), _T("提示"));
	}
	else MessageBox(_T("请正确输入"), _T("提示"));
}


BOOL CInsertResv::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (((CUpdateDlg*)GetParent())->button_choice == 1) {		// 获取父窗口中成员变量button_choice的值
		GetDlgItem(IDC_Insert_Resv)->EnableWindow(FALSE);			// button_choice为1时，禁用“插入”按钮，否则禁用“修改”按钮
		int item = ((CUpdateDlg*)GetParent())->selectitem;
		// 在进行“修改”操作时，弹出的对话框内需要显示原来的条目值
		resv_num_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));
		resv_custname_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 1));
		resv_type_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 2));
		resv_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 3));
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);		// 不允许修改“订单号”	
	}
	else GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CInsertResv::OnBnClickedUpdate()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("update RESERVATIONS set custName = '%s',resvType = %d,resvChoice = '%s' where resvKey = '%s'"), resv_custname, resv_type, resv, resv_num);
	Cpublic::my_db.ExecuteSQL(strSQL);
	MessageBox(_T("修改成功"), _T("提示"));
}
