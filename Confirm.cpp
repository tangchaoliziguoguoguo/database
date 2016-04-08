// Confirm.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "Confirm.h"
#include "afxdialogex.h"


// CConfirm 对话框

IMPLEMENT_DYNAMIC(CConfirm, CDialogEx)

CConfirm::CConfirm(CWnd* pParent /*=NULL*/)
	: CDialogEx(CConfirm::IDD, pParent)
{

}

CConfirm::~CConfirm()
{
}

void CConfirm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConfirm, CDialogEx)
END_MESSAGE_MAP()


// CConfirm 消息处理程序
