// FindDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCStuInfoSystem.h"
#include "afxdialogex.h"
#include "FindDlg.h"


// FindDlg 对话框

IMPLEMENT_DYNAMIC(FindDlg, CDialogEx)

FindDlg::FindDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_name(_T(""))
{

}

FindDlg::~FindDlg()
{
}

void FindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
}


BEGIN_MESSAGE_MAP(FindDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &FindDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// FindDlg 消息处理程序


void FindDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_name == _T(""))
	{
		AfxMessageBox(_T("请输入信息"));
		return;

	}

	CDialogEx::OnOK();
}
