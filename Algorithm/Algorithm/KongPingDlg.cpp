// KongPingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Algorithm.h"
#include "KongPingDlg.h"
#include "afxdialogex.h"


// CKongPingDlg dialog

IMPLEMENT_DYNAMIC(CKongPingDlg, CDialogEx)

CKongPingDlg::CKongPingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_KongPing, pParent)
	/*, m_NumPersons(_T(""))*/
	, m_NumExchange(0)
	, m_NumPersons(0)
{

}

CKongPingDlg::~CKongPingDlg()
{

}

void CKongPingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_Persons, m_NumPersons);
	//  DDX_Text(pDX, IDC_Persons, m_NumPersons);
	DDX_Text(pDX, IDC_Exchange, m_NumExchange);
	DDX_Text(pDX, IDC_Persons, m_NumPersons);
	DDX_Control(pDX, IDC_Result, m_result);
}


BEGIN_MESSAGE_MAP(CKongPingDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Calc, &CKongPingDlg::OnClickedCalc)
END_MESSAGE_MAP()


// CKongPingDlg message handlers


BOOL CKongPingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CKongPingDlg::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	DestroyWindow();
	//CDialogEx::OnCancel();
}


void CKongPingDlg::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialogEx::PostNcDestroy();
	//delete this;
}


void CKongPingDlg::OnClickedCalc()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString str;
	if (m_NumPersons == 0 || m_NumExchange == 0)
	{
		str.Format(_T("%d"), m_NumPersons);
		m_result.SetWindowText(str);
		return;
	}

	bool bflag = false; //找最优解
	int priority = -1;
	int low, mid, high, sum;
	low = 0; high = m_NumPersons;
	while (low <= high)
	{
		sum = 0;
		mid = (low + high) / 2;
		sum += mid;
		f(mid, 0, sum);
		if (sum == m_NumPersons) {
			bflag = true; //找到一个解
			priority = mid;
			//break; //有一个问题：可能还有更优解，继续二分			
			high = mid - 1;
			continue;
		}
		if (bflag)
			if (sum < m_NumPersons)
				break;

		if (sum < m_NumPersons)
			low = mid + 1;
		if (sum > m_NumPersons)
			high = mid - 1;
	}

	str.Format(_T("%d"), priority);
	m_result.SetWindowText(str);
}


void CKongPingDlg::f(int kong, int yu, int& sum)
{
	if (sum == m_NumPersons)
		return; //如果全部人都喝上了

	if(kong + yu < m_NumExchange)
		return; //凑不出3个空瓶了

	int kong2 = (kong + yu) / m_NumExchange; //能换多少瓶
	int yu2 = (kong + yu) % m_NumExchange; //剩下的空瓶
	sum += kong2;

	f(kong2, yu2, sum);
}