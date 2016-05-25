
// AlgorithmDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Algorithm.h"
#include "AlgorithmDlg.h"
#include "afxdialogex.h"

#include "ProblemDesciption.h"
#include "KongPingDlg.h"
#include "FunctionAlgorithm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// item data enum
enum ITEM_DATA
{
	Kong_Ping = 1,
	ITEM_DATA_BUF
};

CDialogEx* g_DlgPtrArray[ITEM_DATA_BUF];
int g_DlgID[ITEM_DATA_BUF] = { 0, IDD_KongPing };

// CAlgorithmDlg dialog


CAlgorithmDlg::CAlgorithmDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ALGORITHM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAlgorithmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_problems, m_tree);
	DDX_Control(pDX, IDC_describe, m_stsDescription);
}

BEGIN_MESSAGE_MAP(CAlgorithmDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_problems, &CAlgorithmDlg::OnSelchangedProblems)
	ON_NOTIFY(NM_DBLCLK, IDC_problems, &CAlgorithmDlg::OnDblclkProblems)
END_MESSAGE_MAP()


// CAlgorithmDlg message handlers

BOOL CAlgorithmDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_tree.ModifyStyle(0, TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT, 0);

	HTREEITEM item, sub;
	item = m_tree.InsertItem(_T("Algorithm"), TVI_ROOT);
	sub = m_tree.InsertItem(_T("¿ÕÆ¿½»»»"), item);
	m_tree.SetItemData(sub, Kong_Ping);
	sub = m_tree.InsertItem(_T("..."), item, sub);

	m_tree.Expand(item, TVE_EXPAND);

	// init the global object array
	//g_DlgPtrArray = new CDialogEx;
	g_DlgPtrArray[Kong_Ping] = new CKongPingDlg;

	// function test
	string result;
	MultiBigNumber("999", "999", result);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAlgorithmDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAlgorithmDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAlgorithmDlg::OnSelchangedProblems(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	HTREEITEM hItem = pNMTreeView->itemNew.hItem;
	DWORD_PTR dw = m_tree.GetItemData(hItem);

	m_stsDescription.SetWindowText(g_ProblemDescription[dw]);

	*pResult = 0;
}


void CAlgorithmDlg::OnDblclkProblems(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	//LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	//HTREEITEM hItem = pNMTreeView->itemNew.hItem;
	//DWORD_PTR dw = m_tree.GetItemData(hItem);
	HTREEITEM item = m_tree.GetSelectedItem();
	DWORD_PTR dw = m_tree.GetItemData(item);

	CDialogEx* pDlg = g_DlgPtrArray[dw];
	if (!pDlg)
		return;

	//pDlg->Create(g_DlgID[dw], this);
	//pDlg->ShowWindow(SW_SHOW);

	if (pDlg->GetSafeHwnd()) {
		pDlg->ShowWindow(SW_SHOW);
	}
	else
	{
		pDlg->Create(g_DlgID[dw], this);
		pDlg->ShowWindow(SW_SHOW);
	}
	
	

	*pResult = 0;
}
