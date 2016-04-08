// SelectFlight.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "SelectFlight.h"
#include "afxdialogex.h"
#include "Cpublic.h"
#include "UpdateDlg.h"
#include "Client.h"


// CSelectFlight �Ի���

IMPLEMENT_DYNAMIC(CSelectFlight, CDialogEx)

CSelectFlight::CSelectFlight(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectFlight::IDD, pParent)
	, num(_T(""))
	, from_city(_T(""))
	, ariv_city(_T(""))
{

}

CSelectFlight::~CSelectFlight()
{
}

void CSelectFlight::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, num);
	DDX_Text(pDX, IDC_EDIT3, from_city);
	DDX_Text(pDX, IDC_EDIT4, ariv_city);
	DDX_Control(pDX, IDC_COMBO1, date_ctrl);
}


BEGIN_MESSAGE_MAP(CSelectFlight, CDialogEx)
	ON_BN_CLICKED(IDC_SELECT_NUM, &CSelectFlight::OnBnClickedSelectNum)
	ON_BN_CLICKED(IDC_SELECT_CITY, &CSelectFlight::OnBnClickedSelectCity)
END_MESSAGE_MAP()


// CSelectFlight ��Ϣ�������


void CSelectFlight::OnBnClickedSelectNum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("select * from FLIGHTS where flightNum = '%s'"), num);
	if (num != _T("")) {
		if (Cpublic::limit == true) {
			((CUpdateDlg*)GetParent())->init_view_text_flight(strSQL);
		}
		else {
			((CClient*)GetParent())->init_view_text_flight(strSQL);
		}
		CDialogEx::OnCancel();
	}
	else MessageBox(_T("�����뺽��ţ�"), _T("��ʾ"));
}


void CSelectFlight::OnBnClickedSelectCity()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	UpdateData(TRUE);
	CString strSQL;
	int date = date_ctrl.GetCurSel();
	if (date == 0) {
		strSQL.Format(_T("select * from FLIGHTS where FromCity = '%s' and ArivCity = '%s'"), from_city, ariv_city);
	}
	else {
		strSQL.Format(_T("select * from FLIGHTS where FromCity = '%s' and ArivCity = '%s' and date = %d"), from_city, ariv_city, date);
	}
	if (from_city != _T("") && ariv_city != _T("")) {
		if (Cpublic::limit == true) {
			((CUpdateDlg*)GetParent())->init_view_text_flight(strSQL);
		}
		else {
			((CClient*)GetParent())->init_view_text_flight(strSQL);
		}
		CDialogEx::OnCancel();
	}
	else if (from_city == _T("")) MessageBox(_T("������������У�"), _T("��ʾ"));
	else MessageBox(_T("�����뵽����У�"), _T("��ʾ"));
}


BOOL CSelectFlight::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	date_ctrl.InsertString(0, _T("��ѡ"));
	CString date;
	for (int i = 1; i <= 31; i++) {
		date.Format(_T("%d"), i);
		date_ctrl.InsertString(i, date);
	}
	date_ctrl.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
