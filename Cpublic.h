#pragma once


// Cpublic

class Cpublic : public CWnd
{
	DECLARE_DYNAMIC(Cpublic)

public:
	Cpublic();
	virtual ~Cpublic();

	static CDatabase my_db;		// ��Ϊmy_db��Ҫ��ȫ�ֱ��������Ծʹ���һ��public����������ˣ���һ��Ҫ����Ϊstatic
	static bool limit;

protected:
	DECLARE_MESSAGE_MAP()
};


