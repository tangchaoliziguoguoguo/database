// SelectCar.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "SelectCar.h"
#include "afxdialogex.h"
#include "UpdateDlg.h"
#include "Cpublic.h"
#include "Client.h"


// CSelectCar 对话框

IMPLEMENT_DYNAMIC(CSelectCar, CDialogEx)

CSelectCar::CSelectCar(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectCar::IDD, pParent)
	, city(_T(""))
{

}

CSelectCar::~CSelectCar()
{
}

void CSelectCar::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, city);
}


BEGIN_MESSAGE_MAP(CSelectCar, CDialogEx)
	ON_BN_CLICKED(IDC_SELECT, &CSelectCar::OnBnClickedSelect)
END_MESSAGE_MAP()


// CSelectCar 消息处理程序


void CSelectCar::OnBnClickedSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("select * from CARS where location = '%s'"), city);
	if (city != _T("")) {
		if (Cpublic::limit == true) {
			((CUpdateDlg*)GetParent())->init_view_text_car(strSQL);
		}
		else {
			((CClient*)GetParent())->init_view_text_car(strSQL);
		}
		CDialogEx::OnCancel();
	}
	else MessageBox(_T("请输入城市！"), _T("提示"));
}
