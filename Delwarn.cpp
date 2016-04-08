// Delwarn.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "Delwarn.h"
#include "afxdialogex.h"


// CDelwarn 对话框

IMPLEMENT_DYNAMIC(CDelwarn, CDialogEx)

CDelwarn::CDelwarn(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDelwarn::IDD, pParent)
{

}

CDelwarn::~CDelwarn()
{
}

void CDelwarn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDelwarn, CDialogEx)
END_MESSAGE_MAP()


// CDelwarn 消息处理程序
