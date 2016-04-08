// ResvCar.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "ResvCar.h"
#include "afxdialogex.h"
#include "UpdateDlg.h"
#include "Cpublic.h"
#include "Client.h"
#include <ctime>


// CResvCar 对话框

IMPLEMENT_DYNAMIC(CResvCar, CDialogEx)

CResvCar::CResvCar(CWnd* pParent /*=NULL*/)
	: CDialogEx(CResvCar::IDD, pParent)
	, city(_T(""))
	, customer(_T(""))
	, resv_num(_T(""))
{

}

CResvCar::~CResvCar()
{
}

void CResvCar::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, city_ctrl);
	DDX_Text(pDX, IDC_EDIT1, city);
	DDX_Control(pDX, IDC_COMBO1, customer_ctrl);
	DDX_CBString(pDX, IDC_COMBO1, customer);
	DDX_Text(pDX, IDC_EDIT3, resv_num);
	DDX_Control(pDX, IDC_EDIT3, resv_num_ctrl);
}


BEGIN_MESSAGE_MAP(CResvCar, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CResvCar::OnBnClickedButton1)
END_MESSAGE_MAP()


// CResvCar 消息处理程序


BOOL CResvCar::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	CString resv_number;
	resv_number.Format(_T("%d"), time(NULL));

	if (Cpublic::limit == true) {
		int item = ((CUpdateDlg*)GetParent())->selectitem;
		city_ctrl.SetWindowTextW(((CUpdateDlg*)GetParent())->insert_view_text.GetItemText(item, 0));		// 初始化“城市”
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);		// 不允许修改“城市”
		resv_num_ctrl.SetWindowTextW(resv_number);
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	
		CRecordset rec(&Cpublic::my_db);
		rec.Open(AFX_DB_USE_DEFAULT_TYPE,_T("select* from CUSTOMERS"));
		rec.Requery();
		int index = 0;
		while (!rec.IsEOF()) {
			CString str;
			rec.GetFieldValue(short(0), str);
			customer_ctrl.InsertString(index, str);		// 将字段加到视图列表中
			index++;
			rec.MoveNext();
		}
	}

	else {
		int item = ((CClient*)GetParent())->selectitem;
		// 在进行“修改”操作时，弹出的对话框内需要显示原来的条目值
		city_ctrl.SetWindowTextW(((CClient*)GetParent())->insert_view_text.GetItemText(item, 0));
		resv_num_ctrl.SetWindowTextW(resv_number);
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);		// 不允许修改“城市”
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
		Cdb_lab2App* app = (Cdb_lab2App*)AfxGetApp();
		customer_ctrl.InsertString(0, app->username);
		customer_ctrl.SetCurSel(0);
		GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CResvCar::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码UpdateData(TRUE);
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("insert into RESERVATIONS values('%s','%s',3,'%s')"), resv_num, customer, city);
	if (resv_num != _T("") && customer != _T("")) {
		Cpublic::my_db.ExecuteSQL(strSQL);
		strSQL.Format(_T("update CARS set numAvail = numAvail - 1 where location = '%s'"), city);
		Cpublic::my_db.ExecuteSQL(strSQL);
		MessageBox(_T("预定成功"), _T("提示"));
		CDialogEx::OnCancel();
	}
	else if (customer == _T("")) MessageBox(_T("请选择客户"), _T("提示"));
	else MessageBox(_T("请输入订单号"), _T("提示"));
}
