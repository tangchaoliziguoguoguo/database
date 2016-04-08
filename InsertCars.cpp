// InsertCars.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "InsertCars.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CInsertCars 对话框

IMPLEMENT_DYNAMIC(CInsertCars, CDialogEx)

CInsertCars::CInsertCars(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertCars::IDD, pParent)
	, cars_city(_T(""))
	, cars_price(0)
	, cars_num(0)
{

}

CInsertCars::~CInsertCars()
{
}

void CInsertCars::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, cars_city_ctrl);
	DDX_Text(pDX, IDC_EDIT1, cars_city);
	DDX_Control(pDX, IDC_EDIT2, cars_price_ctrl);
	DDX_Text(pDX, IDC_EDIT2, cars_price);
	DDX_Control(pDX, IDC_EDIT3, cars_num_ctrl);
	DDX_Text(pDX, IDC_EDIT3, cars_num);
}


BEGIN_MESSAGE_MAP(CInsertCars, CDialogEx)
	ON_BN_CLICKED(IDC_Insert_Cars, &CInsertCars::OnBnClickedInsertCars)
	ON_BN_CLICKED(IDC_UPDATE, &CInsertCars::OnBnClickedUpdate)
	//ON_EN_CHANGE(IDC_EDIT3, &CInsertCars::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CInsertCars 消息处理程序


void CInsertCars::OnBnClickedInsertCars()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into CARS values('%s',%d,%d,%d)"), cars_city, cars_price, cars_num, cars_num);
	if (cars_city != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		cars_city_ctrl.SetWindowTextW(_T(""));
		cars_price_ctrl.SetWindowTextW(0);
		cars_num_ctrl.SetWindowTextW(0);
		MessageBox(_T("插入成功"), _T("提示"));
	}
	else MessageBox(_T("请正确输入"), _T("提示"));
}


BOOL CInsertCars::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (((CUpdateDlg*)GetParent())->button_choice == 1) {		// 获取父窗口中成员变量button_choice的值
		GetDlgItem(IDC_Insert_Cars)->EnableWindow(FALSE);			// button_choice为1时，禁用“插入”按钮，否则禁用“修改”按钮
		int item = ((CUpdateDlg*)GetParent())->selectitem;
		// 在进行“修改”操作时，弹出的对话框内需要显示原来的条目值
		cars_city_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));
		cars_price_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 1));
		cars_num_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 2));
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		//GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);		// 不支持对“总量”的修改
	}
	else {
		GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CInsertCars::OnBnClickedUpdate()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("update CARS set price = %d,where location = '%s'"), cars_price, cars_city);
	if (cars_city != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		MessageBox(_T("修改成功"), _T("提示"));
	}
}


//void CInsertCars::OnEnChangeEdit3()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//	CString show;
//	UpdateData(TRUE);
//	show.Format(_T("%d"), cars_num);
//	cars_num_avail_ctrl.SetWindowTextW(show);
//}
