#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CUpdateDlg 对话框

class CUpdateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateDlg)

public:
	CUpdateDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUpdateDlg();

// 对话框数据
	enum { IDD = IDD_UPDATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeUpdateChooseTable();
	CComboBox update_choose_table;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedUpdateInsert();
	CListCtrl insert_view_text;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedUpdate();
	void open_insert_customers_table();
	void open_insert_flights_table();
	void open_insert_hotels_table();
	void open_insert_cars_table();
	void open_insert_reservations_table();
	void init_view_text(int);		// 初始化视图列表
	void init_view_text_customer(CString);		// CString存储sql语句，表示查询条件，根据查询条件进行显示
	void init_view_text_flight(CString);
	void init_view_text_hotel(CString);
	void init_view_text_car(CString);
	void init_view_text_reservation(CString);
	void init_resv_view(CString);
	int button_choice;		// 点击“插入”和“删除”按钮弹出的是同一个窗口，但是需要有不同的显示，用该变量记录按钮的选择
	int selectitem;
	afx_msg void OnBnClickedReservation();
	afx_msg void OnBnClickedSelect();
	afx_msg void OnBnClickedRoute();
	afx_msg void OnStnClickedPrompt();
	CListCtrl resv_view;
	afx_msg void OnBnClickedDeleteResv();
	afx_msg void OnBnClickedSelectResv();
	afx_msg void OnBnClickedAll();
};
