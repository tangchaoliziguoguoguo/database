// SelectResv.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "SelectResv.h"
#include "afxdialogex.h"
#include "UpdateDlg.h"


// CSelectResv �Ի���

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


// CSelectResv ��Ϣ�������


void CSelectResv::OnBnClickedSelectNum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("select * from RESERVATIONS where resvKey = '%s'"), num);
	if (num != _T("")) {
		((CUpdateDlg*)GetParent())->init_resv_view(strSQL);
		CDialogEx::OnCancel();
	}
	else MessageBox(_T("�����붩���ţ�"), _T("��ʾ"));
}


void CSelectResv::OnBnClickedSelectname()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("select * from RESERVATIONS where custName = '%s'"), name);
	if (name != _T("")) {
		((CUpdateDlg*)GetParent())->init_resv_view(strSQL);
		CDialogEx::OnCancel();
	}
	else MessageBox(_T("������������"), _T("��ʾ"));
}


void CSelectResv::OnBnClickedSelecttype()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	type_ctrl.InsertString(0, _T("����"));
	type_ctrl.InsertString(1, _T("����"));
	type_ctrl.InsertString(2, _T("�⳵"));
	type_ctrl.SetCurSel(0);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
