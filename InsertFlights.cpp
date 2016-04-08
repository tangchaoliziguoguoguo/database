// InsertFlights.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "InsertFlights.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"


// CInsertFlights 对话框

IMPLEMENT_DYNAMIC(CInsertFlights, CDialogEx)

CInsertFlights::CInsertFlights(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertFlights::IDD, pParent)
	, flight_num(_T(""))
	, flight_price(0)
	, num_seat(0)
	, from_city(_T(""))
	, ariv_city(_T(""))
	, date(0)
{

}

CInsertFlights::~CInsertFlights()
{
}

void CInsertFlights::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, flight_num);
	DDX_Text(pDX, IDC_EDIT4, flight_price);
	DDX_Text(pDX, IDC_EDIT2, num_seat);
	DDX_Text(pDX, IDC_EDIT3, from_city);
	DDX_Text(pDX, IDC_EDIT6, ariv_city);
	DDV_MaxChars(pDX, ariv_city, 10);
	DDV_MaxChars(pDX, from_city, 10);
	DDX_Control(pDX, IDC_EDIT1, flight_num_ctrl);
	DDX_Control(pDX, IDC_EDIT4, flight_price_ctrl);
	DDX_Control(pDX, IDC_EDIT2, num_seat_ctrl);
	DDX_Control(pDX, IDC_EDIT3, from_city_ctrl);
	DDX_Control(pDX, IDC_EDIT6, ariv_city_ctrl);
	DDX_Control(pDX, IDC_date, date_ctrl);
	DDX_Text(pDX, IDC_date, date);
}


BEGIN_MESSAGE_MAP(CInsertFlights, CDialogEx)
	ON_BN_CLICKED(IDC_Insert_Flights, &CInsertFlights::OnBnClickedInsertFlights)
	ON_BN_CLICKED(IDC_UPDATE, &CInsertFlights::OnBnClickedUpdate)
	//ON_EN_CHANGE(IDC_EDIT2, &CInsertFlights::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CInsertFlights 消息处理程序


void CInsertFlights::OnBnClickedInsertFlights()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into FLIGHTS values('%s',%d,%d,%d,'%s','%s',%d)"), flight_num, flight_price, num_seat, num_seat, from_city, ariv_city, date);
	if (flight_num != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		flight_num_ctrl.SetWindowTextW(_T(""));
		flight_price_ctrl.SetWindowTextW(0);
		num_seat_ctrl.SetWindowTextW(0);
		from_city_ctrl.SetWindowTextW(_T(""));
		ariv_city_ctrl.SetWindowTextW(_T(""));
		date_ctrl.SetWindowTextW(0);
//	Insert_Customer_Text.SetFocus();
		MessageBox(_T("插入成功"), _T("提示"));
	}
	else MessageBox(_T("请正确输入"), _T("提示"));
}


BOOL CInsertFlights::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (((CUpdateDlg*)GetParent())->button_choice == 1) {		// 获取父窗口中成员变量button_choice的值
		GetDlgItem(IDC_Insert_Flights)->EnableWindow(FALSE);			// button_choice为1时，禁用“插入”按钮，否则禁用“修改”按钮
		int item = ((CUpdateDlg*)GetParent())->selectitem;
		// 在进行“修改”操作时，弹出的对话框内需要显示原来的条目值
		flight_num_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));
		flight_price_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 4));
		num_seat_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 5));
//		num_seat_avail_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 3));
		from_city_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 1));
		ariv_city_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 2));
		date_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 3));
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);		// 不允许修改“航班号”
		//GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);	
		//GetDlgItem(IDC_date)->EnableWindow(FALSE);	
	}
	else {
		GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CInsertFlights::OnBnClickedUpdate()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("update FLIGHTS set price = %d,FromCity ='%s',ArivCity = '%s' where flightNum = '%s'"), flight_price, from_city, ariv_city, flight_num);
	Cpublic::my_db.ExecuteSQL(strSQL);
	MessageBox(_T("修改成功"), _T("提示"));
}


//void CInsertFlights::OnEnChangeEdit2()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//	CString show;
//	UpdateData(TRUE);
//	show.Format(_T("%d"), num_seat);
//	num_seat_avail_ctrl.SetWindowTextW(show);
//}
