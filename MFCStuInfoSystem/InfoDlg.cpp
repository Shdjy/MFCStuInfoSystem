// InfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCStuInfoSystem.h"
#include "afxdialogex.h"
#include "InfoDlg.h"


// InfoDlg 对话框

IMPLEMENT_DYNAMIC(InfoDlg, CDialogEx)

InfoDlg::InfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_InfoDlg1, pParent)
	, m_name(_T(""))
	, m_sex(_T(""))
	, m_class_(1)
	, m_chinese(60)
	, m_math(60)
	, m_english(60)
{

}

InfoDlg::~InfoDlg()
{
}

void InfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_SEX, m_sex);
	DDX_Text(pDX, IDC_CLASS, m_class_);
	DDX_Text(pDX, IDC_CHINESE, m_chinese);
	DDX_Text(pDX, IDC_MATH, m_math);
	DDX_Text(pDX, IDC_ENGLISH, m_english);
}


BEGIN_MESSAGE_MAP(InfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &InfoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// InfoDlg 消息处理程序


void InfoDlg::OnBnClickedOk()//
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_name == _T("") || m_sex == _T(""))
	{
		AfxMessageBox(_T("请输入正确的信息!"));
		return;
	}
	if (m_chinese < 0 || m_chinese > 100 || m_math < 0 || m_math > 100 || m_english < 0 || m_english > 100)
	{
		AfxMessageBox(_T("请输入正确的成绩!"));
		return;
	}

	CDialogEx::OnOK();
}
