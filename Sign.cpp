// Sign.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "db_lab2.h"
#include "Sign.h"
#include "afxdialogex.h"
#include "Cpublic.h"


// CSign �Ի���

IMPLEMENT_DYNAMIC(CSign, CDialogEx)

CSign::CSign(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSign::IDD, pParent)
	, name(_T(""))
{

}

CSign::~CSign()
{
}

void CSign::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
}


BEGIN_MESSAGE_MAP(CSign, CDialogEx)
	ON_BN_CLICKED(IDC_sign, &CSign::OnBnClickedsign)
END_MESSAGE_MAP()


// CSign ��Ϣ�������


void CSign::OnBnClickedsign()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strSQL;
	CRecordset rec(&Cpublic::my_db);
	if (name != _T("")) {
		strSQL.Format(_T("select * from CUSTOMERS where custName = '%s'"), name);
		rec.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
		rec.Requery();
		if (!rec.IsEOF()) {
			MessageBox(_T("�û����Ѵ��ڣ�"),_T("��ʾ"));
			return ;
		}
		strSQL.Format(_T("insert into CUSTOMERS values('%s')"), name);
		Cpublic::my_db.ExecuteSQL(strSQL);
		MessageBox(_T("ע��ɹ���"), _T("��ʾ"));
		CDialogEx::OnCancel();
	}
	else MessageBox(_T("������������"), _T("��ʾ"));
}
