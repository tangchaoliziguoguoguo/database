// InsertHotels.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "InsertHotels.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CInsertHotels 对话框

IMPLEMENT_DYNAMIC(CInsertHotels, CDialogEx)

CInsertHotels::CInsertHotels(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertHotels::IDD, pParent)
	, hotel_city(_T(""))
	, hotel_price(0)
	, hotel_num(0)
{

}

CInsertHotels::~CInsertHotels()
{
}

void CInsertHotels::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, hotel_city);
	DDX_Text(pDX, IDC_EDIT2, hotel_price);
	DDX_Text(pDX, IDC_EDIT3, hotel_num);
	DDX_Control(pDX, IDC_EDIT1, hotel_city_ctrl);
	DDX_Control(pDX, IDC_EDIT2, hotel_price_ctrl);
	DDX_Control(pDX, IDC_EDIT3, hotel_num_ctrl);
}


BEGIN_MESSAGE_MAP(CInsertHotels, CDialogEx)
	ON_BN_CLICKED(IDC_Insert_Hotel, &CInsertHotels::OnBnClickedInsertHotel)
	ON_BN_CLICKED(IDC_UPDATE, &CInsertHotels::OnBnClickedUpdate)
	ON_BN_CLICKED(IDCANCEL, &CInsertHotels::OnBnClickedCancel)
	//ON_EN_CHANGE(IDC_EDIT3, &CInsertHotels::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CInsertHotels 消息处理程序


void CInsertHotels::OnBnClickedInsertHotel()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into HOTELS values('%s',%d,%d,%d)"), hotel_city, hotel_price, hotel_num, hotel_num);
	if (hotel_city != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		hotel_city_ctrl.SetWindowTextW(_T(""));
		hotel_price_ctrl.SetWindowTextW(0);
		hotel_num_ctrl.SetWindowTextW(0);
		MessageBox(_T("插入成功"), _T("提示"));
	}
	else MessageBox(_T("请正确输入"), _T("提示"));
}

BOOL CInsertHotels::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (((CUpdateDlg*)GetParent())->button_choice == 1) {		// 获取父窗口中成员变量button_choice的值
		GetDlgItem(IDC_Insert_Hotel)->EnableWindow(FALSE);			// button_choice为1时，禁用“插入”按钮，否则禁用“修改”按钮
		int item = ((CUpdateDlg*)GetParent())->selectitem;
		// 在进行“修改”操作时，弹出的对话框内需要显示原来的条目值
		hotel_city_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));
		hotel_price_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 1));
		hotel_num_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 2));
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);		// 不允许修改“城市”
		//GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	}
	else {
		GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CInsertHotels::OnBnClickedUpdate()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("update HOTELS set price = %d,where location = '%s'"), hotel_price, hotel_city);
	Cpublic::my_db.ExecuteSQL(strSQL);
	MessageBox(_T("修改成功"), _T("提示"));
}


void CInsertHotels::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


//void CInsertHotels::OnEnChangeEdit3()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//	CString show;
//	UpdateData(TRUE);
//	show.Format(_T("%d"), hotel_num);
//	//GetDlgItemText(IDC_EDIT3, show);
//	hotel_num_avail_ctrl.SetWindowTextW(show);
//	UpdateData(TRUE);
//}
