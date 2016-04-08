// Cpublic.cpp : 实现文件
//

#include "stdafx.h"
#include "db_lab2.h"
#include "Cpublic.h"


// Cpublic

CDatabase Cpublic::my_db;		// 初始化，声明在Cpublic.h中
bool Cpublic::limit;

IMPLEMENT_DYNAMIC(Cpublic, CWnd)

Cpublic::Cpublic()
{

}

Cpublic::~Cpublic()
{
}


BEGIN_MESSAGE_MAP(Cpublic, CWnd)
END_MESSAGE_MAP()



// Cpublic 消息处理程序


