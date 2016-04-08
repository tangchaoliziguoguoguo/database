
// db_lab2Dlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Cdb_lab2Dlg 对话框




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


// Cdb_lab2Dlg 消息处理程序

BOOL Cdb_lab2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

//	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	CRecordset rec(&Cpublic::my_db);
	/**这里是建表的操作**/
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
	/**这里是建表的操作**/
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cdb_lab2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cdb_lab2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void Cdb_lab2Dlg::OnBnClickedUpdate()		// 鹳狸猿登录
{
	INT_PTR nRes;
	CLogin login;
	Cpublic::limit = true;
	limit = true;
	nRes = login.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void Cdb_lab2Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void Cdb_lab2Dlg::OnBnClickedclientlogin()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;
	CLogin login;
	Cpublic::limit = false;
	limit = false;
	nRes = login.DoModal();
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
