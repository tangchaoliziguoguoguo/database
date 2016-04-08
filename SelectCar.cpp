// SelectCar.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "SelectCar.h"
#include "afxdialogex.h"
#include "UpdateDlg.h"
#include "Cpublic.h"
#include "Client.h"


// CSelectCar �Ի���

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


// CSelectCar ��Ϣ�������


void CSelectCar::OnBnClickedSelect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
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
	else MessageBox(_T("��������У�"), _T("��ʾ"));
}
