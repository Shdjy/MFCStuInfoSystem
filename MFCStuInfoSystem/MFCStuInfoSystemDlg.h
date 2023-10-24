
// MFCStuInfoSystemDlg.h: 头文件
//

#pragma once
#include "sqlinterface.h"
#include "InfoDlg.h"
#include "FindDlg.h"

// CMFCStuInfoSystemDlg 对话框
class CMFCStuInfoSystemDlg : public CDialogEx
{
// 构造
public:
	CMFCStuInfoSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSTUINFOSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo2();

	sqlinterface m_sql;
	vector<StuInfo> m_info;
	afx_msg void OnBnClickedButton1();
	CListCtrl m_list;
	afx_msg void OnBnClickedButton2();
	void UpdataList();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CComboBox m_class;
	CComboBox m_subject;
	double m_average;
	int m_max;
	int m_min;
	double m_passRate;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton6();
};
