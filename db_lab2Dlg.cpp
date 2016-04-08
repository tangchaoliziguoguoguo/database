
// db_lab2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Cpublic.h"
#include "db_lab2.h"
#include "db_lab2Dlg.h"
#include "afxdialogex.h"
#include "UpdateDlg.h"
#include "Client.h"
#include "Login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//CComboBox update_choose_talbe;


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cdb_lab2Dlg �Ի���




Cdb_lab2Dlg::Cdb_lab2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cdb_lab2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdb_lab2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cdb_lab2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_UPDATE, &Cdb_lab2Dlg::OnBnClickedUpdate)
	ON_BN_CLICKED(IDC_BUTTON9, &Cdb_lab2Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_client_login, &Cdb_lab2Dlg::OnBnClickedclientlogin)
END_MESSAGE_MAP()


// Cdb_lab2Dlg ��Ϣ�������

BOOL Cdb_lab2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

//	ShowWindow(SW_MINIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	CRecordset rec(&Cpublic::my_db);
	/**�����ǽ���Ĳ���**/
	Cpublic::my_db.Open(NULL, FALSE, FALSE, _T("ODBC;DSN=lab;UID=sa;PWD=123456"));
	CString strSQL;
	strSQL.Format(_T("if not exists (select * from sysobjects where id = object_id(N'[dbo].[CUSTOMERS]') and OBJECTPROPERTY(id, N'IsUserTable') = 1) create table CUSTOMERS(custName varchar(20) not NULL,primary key(custName));"));
	Cpublic::my_db.ExecuteSQL(strSQL);
	strSQL.Format(_T("if not exists (select * from sysobjects where id = object_id(N'[dbo].[FLIGHTS]') and OBJECTPROPERTY(id, N'IsUserTable') = 1) create table FLIGHTS(flightNum varchar(20) not NULL,price int check(price>0),numSeats int check(numSeats>0),numAvail int check(numAvail>=0),FromCity varchar(20) not NULL,ArivCity varchar(20) not NULL,date int check(date>0),primary key (flightNum));"));
	Cpublic::my_db.ExecuteSQL(strSQL);
	strSQL.Format(_T("if not exists (select * from sysobjects where id = object_id(N'[dbo].[HOTELS]') and OBJECTPROPERTY(id, N'IsUserTable') = 1) create table HOTELS(location varchar(20) not NULL,price int check(price>0),numRooms int check(numRooms>0),numAvail int check(numAvail>=0),primary key (location));"));
	Cpublic::my_db.ExecuteSQL(strSQL);
	strSQL.Format(_T("if not exists (select * from sysobjects where id = object_id(N'[dbo].[CARS]') and OBJECTPROPERTY(id, N'IsUserTable') = 1) create table CARS(location varchar(20) not NULL,price int check(price>0),numCars int check(numCars>0),numAvail int check(numAvail>=0),primary key (location));"));
	Cpublic::my_db.ExecuteSQL(strSQL);
	strSQL.Format(_T("if not exists (select * from sysobjects where id = object_id(N'[dbo].[RESERVATIONS]') and OBJECTPROPERTY(id, N'IsUserTable') = 1) create table RESERVATIONS(resvKey varchar(20) not NULL,custName varchar(20) not NULL,resvType int,resvChoice varchar(20) not NULL,primary key (resvKey));"));
	Cpublic::my_db.ExecuteSQL(strSQL);
	/**�����ǽ���Ĳ���**/
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cdb_lab2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cdb_lab2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cdb_lab2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void Cdb_lab2Dlg::OnBnClickedUpdate()		// ����Գ��¼
{
	INT_PTR nRes;
	CLogin login;
	Cpublic::limit = true;
	limit = true;
	nRes = login.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Cdb_lab2Dlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void Cdb_lab2Dlg::OnBnClickedclientlogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;
	CLogin login;
	Cpublic::limit = false;
	limit = false;
	nRes = login.DoModal();
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
