#pragma once


// Cpublic

class Cpublic : public CWnd
{
	DECLARE_DYNAMIC(Cpublic)

public:
	Cpublic();
	virtual ~Cpublic();

	static CDatabase my_db;		// 因为my_db需要是全局变量，所以就创建一个public类放在这里了，且一定要定义为static
	static bool limit;

protected:
	DECLARE_MESSAGE_MAP()
};


