// SelectHotel.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "SelectHotel.h"
#include "afxdialogex.h"
#include "UpdateDlg.h"
#include "Client.h"
#include "Cpublic.h"


// CSelectHotel �Ի���

IMPLEMENT_DYNAMIC(CSelectHotel, CDialogEx)

CSelectHotel::CSelectHotel(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectHotel::IDD, pParent)
	, city(_T(""))
{

}

CSelectHotel::~CSelectHotel()
{
}

void CSelectHotel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, city);
}


BEGIN_MESSAGE_MAP(CSelectHotel, CDialogEx)
	ON_BN_CLICKED(IDC_SELECT, &CSelectHotel::OnBnClickedSelect)
END_MESSAGE_MAP()


// CSelectHotel ��Ϣ�������


void CSelectHotel::OnBnClickedSelect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	UpdateData(TRUE);
	CString strSQL;
	strSQL.Format(_T("select * from HOTELS where location = '%s'"), city);
	if (city != _T("")) {
		if (Cpublic::limit == true) {
			((CUpdateDlg*)GetParent())->init_view_text_hotel(strSQL);
		}
		else {
			((CClient*)GetParent())->init_view_text_hotel(strSQL);
		}
		CDialogEx::OnCancel();
	}
	else MessageBox(_T("��������У�"), _T("��ʾ"));
}
