// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CateringSystem.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg dialog

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Lgoin, pParent)
	, m_name(_T(""))
	, m_passwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_passwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
END_MESSAGE_MAP()


// CLoginDlg message handlers


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CLoginDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData();
	if (m_name.IsEmpty() || m_passwd.IsEmpty()) {
		AfxMessageBox(_T("请输入用户名或密码！"));
		return;
	}

	CString Sql = _T("select * from LoginInfo where Uname='") + m_name + _T("' and Upasswd='")
		+ m_passwd + _T("'");
	CCateringSystemApp* pApp = (CCateringSystemApp*)AfxGetApp();
	try
	{
		m_pRs.CreateInstance("ADODB.Recordset");
		m_pRs->Open((_variant_t)Sql, pApp->m_pCon.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
		if (m_pRs->adoEOF)
		{
			AfxMessageBox(_T("用户名或密码错误!"));
			m_name = _T("");
			m_passwd = _T("");
			UpdateData(FALSE);
			CDialog::OnCancel();
			return;
		}
		else {
			pApp->name = m_name;
			pApp->pwd = m_passwd;
			CDialog::OnOK();
			return;
		}
	}
	catch (_com_error e)
	{

	}

}
