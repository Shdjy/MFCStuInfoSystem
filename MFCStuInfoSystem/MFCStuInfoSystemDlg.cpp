
// MFCStuInfoSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCStuInfoSystem.h"
#include "MFCStuInfoSystemDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCStuInfoSystemDlg 对话框



CMFCStuInfoSystemDlg::CMFCStuInfoSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSTUINFOSYSTEM_DIALOG, pParent)
	, m_average(0)
	, m_max(0)
	, m_min(0)
	, m_passRate(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCStuInfoSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO2, m_class);
	DDX_Control(pDX, IDC_COMBO3, m_subject);
	DDX_Text(pDX, IDC_EDIT1, m_average);
	DDX_Text(pDX, IDC_EDIT2, m_max);
	DDX_Text(pDX, IDC_EDIT3, m_min);
	DDX_Text(pDX, IDC_EDIT5, m_passRate);
}

BEGIN_MESSAGE_MAP(CMFCStuInfoSystemDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCStuInfoSystemDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCStuInfoSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCStuInfoSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCStuInfoSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCStuInfoSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCStuInfoSystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCStuInfoSystemDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCStuInfoSystemDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CMFCStuInfoSystemDlg 消息处理程序

BOOL CMFCStuInfoSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
	m_list.InsertColumn(0, "姓名", LVCFMT_LEFT, 120);
	m_list.InsertColumn(1, "性别", LVCFMT_LEFT, 120);
	m_list.InsertColumn(2, "班级", LVCFMT_LEFT, 120);
	m_list.InsertColumn(3, "语文", LVCFMT_LEFT, 120);
	m_list.InsertColumn(4, "数学", LVCFMT_LEFT, 120);
	m_list.InsertColumn(5, "英语", LVCFMT_LEFT, 120);

	m_class.AddString(_T("1班"));
	m_class.AddString(_T("2班"));
	m_class.AddString(_T("3班"));
	m_class.AddString(_T("4班"));
	m_class.AddString(_T("全部"));
	m_class.SetCurSel(4);

	m_subject.AddString(_T("语文"));
	m_subject.AddString(_T("数学"));
	m_subject.AddString(_T("英语"));
	m_subject.SetCurSel(0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCStuInfoSystemDlg::OnPaint()
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
HCURSOR CMFCStuInfoSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCStuInfoSystemDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCStuInfoSystemDlg::OnBnClickedButton1()//导入数据
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_sql.Connect_MySql())
	{
		m_info = m_sql.GetAllInfo();
		UpdataList();
		return;
	}
	else
	{
		return;
	}

}


void CMFCStuInfoSystemDlg::OnBnClickedButton2()//添加数据
{
	// TODO: 在此添加控件通知处理程序代码
	InfoDlg infodlg;
	
	if (infodlg.DoModal() == IDOK)
	{
		StuInfo info(infodlg.m_name.GetBuffer(), infodlg.m_sex.GetBuffer(), infodlg.m_class_, infodlg.m_chinese, infodlg.m_math, infodlg.m_english);
		if (m_sql.AddInfo(info))
		{
			m_info.push_back(info);
			UpdataList();
			AfxMessageBox(_T("添加成功!"));
		}
	}
}

void CMFCStuInfoSystemDlg::UpdataList()
{
	m_list.DeleteAllItems();
	//MessageBox(TEXT("123"));
	CString str;
	for (int i = 0; i < m_info.size(); i++)
	{
		m_list.InsertItem(i, m_info[i].m_name.c_str());
		m_list.SetItemText(i, 1, m_info[i].m_sex.c_str());
		str.Format(TEXT("%d"), m_info[i].m_class_);
		m_list.SetItemText(i, 2, str);
		str.Format(TEXT("%d"), m_info[i].m_chinese);
		m_list.SetItemText(i, 3, str);
		str.Format(TEXT("%d"), m_info[i].m_math);
		m_list.SetItemText(i, 4, str);
		str.Format(TEXT("%d"), m_info[i].m_english);
		m_list.SetItemText(i, 5, str);
	}
	return;
}


void CMFCStuInfoSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_list.GetSelectionMark();
	if (nIndex == -1)
	{
		AfxMessageBox(_T("请选择删除内容！"));
		return;
	}
	else
	{
		UINT i;
		i = MessageBox(_T("确定要删除吗？"),_T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			if (m_sql.DeleteInfo(m_info[nIndex]))
			{
				AfxMessageBox(_T("删除成功"));
				m_info.erase(m_info.begin() + nIndex);
				UpdataList();
			}
		}

	}
}


void CMFCStuInfoSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_list.GetSelectionMark();
	if (nIndex == -1)
	{
		AfxMessageBox(_T("请选择修改内容！"));
		return;
	}
	else
	{
		InfoDlg infodlg;

		infodlg.m_name = m_info[nIndex].m_name.c_str();
		infodlg.m_sex = m_info[nIndex].m_sex.c_str();
		infodlg.m_class_ = m_info[nIndex].m_class_;
		infodlg.m_chinese = m_info[nIndex].m_chinese;
		infodlg.m_math = m_info[nIndex].m_math;
		infodlg.m_english = m_info[nIndex].m_english;

		if (infodlg.DoModal() == IDOK)
		{
			

			StuInfo info(infodlg.m_name.GetBuffer(), infodlg.m_sex.GetBuffer(), infodlg.m_class_, infodlg.m_chinese, infodlg.m_math, infodlg.m_english);
			if (m_sql.UpdataInfo(m_info[nIndex],info))
			{
				m_info[nIndex] = info;
				UpdataList();
				AfxMessageBox(_T("修改成功!"));
			}
		}
	}
}


void CMFCStuInfoSystemDlg::OnBnClickedButton5()//按照名字查找
{
	// TODO: 在此添加控件通知处理程序代码
	FindDlg finddlg;
	
	if (finddlg.DoModal() == IDOK)
	{
		vector<StuInfo> info = m_sql.SelectInfo(finddlg.m_name);
		if (info.empty())
		{
			AfxMessageBox(_T("查无此人!"));
			return;
		}
		m_list.DeleteAllItems();
		
		CString str;
		for (int i = 0; i < info.size(); i++)
		{
			m_list.InsertItem(i, info[i].m_name.c_str());
			m_list.SetItemText(i, 1, info[i].m_sex.c_str());
			str.Format(TEXT("%d"), info[i].m_class_);
			m_list.SetItemText(i, 2, str);
			str.Format(TEXT("%d"), info[i].m_chinese);
			m_list.SetItemText(i, 3, str);
			str.Format(TEXT("%d"), info[i].m_math);
			m_list.SetItemText(i, 4, str);
			str.Format(TEXT("%d"), info[i].m_english);
			m_list.SetItemText(i, 5, str);
		}
	}
	
}


void CMFCStuInfoSystemDlg::OnBnClickedButton7()//计算数据
{
	// TODO: 在此添加控件通知处理程序代码
	int num = 0;
	int pass = 0;
	int max = 0;
	int min = 100;
	int sum = 0;
	double average = 0;

	int selectClass = m_class.GetCurSel();
	int selectSubject = m_subject.GetCurSel();

	vector<int> score;
	
	for (int i = 0; i < m_info.size(); i++)
	{
		if (m_info[i].m_class_ ==selectClass + 1 || selectClass == 4)
		{
			switch (selectSubject)
			{
			case 0:
				score.push_back(m_info[i].m_chinese);
				break;
			case 1:
				score.push_back(m_info[i].m_math);
				break;
			case 2:
				score.push_back(m_info[i].m_english);
				break;
			default:
				break;
			}
		}
	}
	for (int j = 0; j < score.size(); j++)
	{
		sum += score[j];
		num = score.size();
		max = max(max,score[j]);
		min = min(min,score[j]);
		if (score[j] >= 60)
		{
			pass++;
		}
	}
	m_average = sum * 1.0 / num;
	m_max = max;
	m_min = min;
	m_passRate = pass * 1.0 / num;
	UpdateData(FALSE);
}


void CMFCStuInfoSystemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i = MessageBox(_T("确定要退出吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES)
	{
		m_sql.CloseMysql();
		exit(0);
	}
}
