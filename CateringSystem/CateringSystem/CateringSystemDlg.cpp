
// CateringSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CateringSystem.h"
#include "CateringSystemDlg.h"
#include "afxdialogex.h"

#include "logindlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCateringSystemDlg dialog



CCateringSystemDlg::CCateringSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CATERINGSYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCateringSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCateringSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENU_login, &CCateringSystemDlg::OnMenuLogin)
END_MESSAGE_MAP()


// CCateringSystemDlg message handlers

BOOL CCateringSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	//SetIcon(m_hIcon, TRUE);			// Set big icon
	//SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SetWindowPos(nullptr, -1, -1, 640, 480, 
		SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
	ModifyStyle(WS_SIZEBOX, 0);

	SetIcon(LoadIcon(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDI_APP)), FALSE);

	m_ImageList.Create(32, 32, ILC_COLOR24 | ILC_MASK, 1, 1);
	CWinApp* pApp = AfxGetApp();
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_login));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_open));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_add));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_pay));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_rishouru));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_reg));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_cancel));

	UINT toolbarArray[7];
	for (int i = 0; i<7; i++)
	{
		toolbarArray[i] = 9000 + i;
	}
	m_ToolBar.Create(this);//����������
	m_ToolBar.SetButtons(toolbarArray, 7);//���ð�ťID��
	m_ToolBar.SetButtonText(0, _T("ϵͳ��¼"));//���ð�ť�ı�
	m_ToolBar.SetButtonText(1, _T("��̨���"));
	m_ToolBar.SetButtonText(2, _T("�Ӽ���"));
	m_ToolBar.SetButtonText(3, _T("�˿���"));
	m_ToolBar.SetButtonText(4, _T("��������"));
	m_ToolBar.SetButtonText(5, _T("Ա��ע��"));
	m_ToolBar.SetButtonText(6, _T("�˳�ϵͳ"));
	m_ToolBar.GetToolBarCtrl().SetButtonWidth(60, 120); //���ð�ť��С�����
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList);//����buttonͼƬ
	m_ToolBar.SetSizes(CSize(70, 60), CSize(28, 40)); //���ð�ť��ͼ��ߴ�

	UINT statusArray[3];//�������飬���ڴ���status��ID��
	for (int i = 0; i<3; i++)
	{
		statusArray[i] = 10000 + 1;
	}
	m_StatusBar.Create(this);//����״̬��
	m_StatusBar.SetIndicators(statusArray, 3);
	//���ô�����
	m_StatusBar.SetPaneInfo(0, statusArray[0], 0, 200);
	m_StatusBar.SetPaneInfo(1, statusArray[1], 0, 150);
	m_StatusBar.SetPaneInfo(2, statusArray[2], 0, 500);
	CTime Time;//����CTime��Ķ������ڴ���ϵͳʱ��
	Time = CTime::GetCurrentTime();//�õ���ǰϵͳʱ��
	CString TimeString = Time.Format("%Y-%m-%d");//ʱ������ʽ��Ϊ�ַ�������������CString��Ķ�����

	m_StatusBar.SetPaneText(2, _T("��ǰ����:") + TimeString);//����״̬�����ı���Ϣ
	m_StatusBar.SetPaneText(0, _T("����ѧԺУ�Ѳ�������ϵͳ"));//����״̬�����ı���Ϣ

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);//��ʾ��������״̬��

	CMenu* pMenu = GetMenu();
	pMenu->GetSubMenu(1)->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(1)->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(2)->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(2)->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(2)->EnableMenuItem(2, MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(3)->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(3)->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCateringSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCateringSystemDlg::OnPaint()
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
HCURSOR CCateringSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCateringSystemDlg::OnMenuLogin()
{
	// TODO: Add your command handler code here
	CLoginDlg Logindlg;
	if (Logindlg.DoModal() == IDOK)//�����Ի���
	{
		CString Sql = _T("select * from LoginInfo where Uname='") + theApp.name + _T("'");
		m_pRs = theApp.m_pCon->Execute((_bstr_t)Sql, NULL, adCmdText);//ִ�в�ѯ
		CString Str = (_bstr_t)m_pRs->GetCollect("power");//�û�Ȩ��
		int radio = _ttoi(Str);//ת��Ϊ����
		if (radio == 0)//����
		{
			CMenu* pMenu = GetMenu();//��ȡ�˵�ָ��
			pMenu->GetSubMenu(1)->EnableMenuItem(0, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(1)->EnableMenuItem(1, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(2)->EnableMenuItem(0, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(2)->EnableMenuItem(1, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(2)->EnableMenuItem(2, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(3)->EnableMenuItem(0, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(3)->EnableMenuItem(1, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(2, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(3, MF_BYPOSITION | MF_ENABLED);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_kaitai, true);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_pay, true);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_rishouru, true);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_reg, true);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_add, true);
		}
		if (radio == 1)//����
		{
			CMenu* pMenu = GetMenu();//��ȡ�˵�ָ��
			pMenu->GetSubMenu(1)->EnableMenuItem(0, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(1)->EnableMenuItem(1, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(2)->EnableMenuItem(0, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(2)->EnableMenuItem(1, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(2)->EnableMenuItem(2, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(2, MF_BYPOSITION | MF_GRAYED);
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(3, MF_BYPOSITION | MF_GRAYED);
			pMenu->GetSubMenu(3)->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED);
			pMenu->GetSubMenu(3)->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_kaitai, true);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_pay, true);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_rishouru, true);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_reg, true);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_add, true);
		}
		if (radio == 2)//ֵ��Ա
		{
			CMenu* pMenu = GetMenu();//��ȡ�˵�ָ��
			pMenu->GetSubMenu(1)->EnableMenuItem(0, MF_BYPOSITION | MF_ENABLED);
			pMenu->GetSubMenu(1)->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED);
			pMenu->GetSubMenu(2)->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED);
			pMenu->GetSubMenu(2)->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED);
			pMenu->GetSubMenu(2)->EnableMenuItem(2, MF_BYPOSITION | MF_GRAYED);
			pMenu->GetSubMenu(3)->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED);
			pMenu->GetSubMenu(3)->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_kaitai, true);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_pay, true);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_rishouru, true);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_reg, false);
			m_ToolBar.GetToolBarCtrl().EnableButton(IDB_add, true);
		}
		m_StatusBar.SetPaneText(1, _T("��ǰ�û�:") + theApp.name);//����״̬������
		SetWindowText(_T("��������ϵͳ    ��ǰ��¼�û�:") + theApp.name);//���öԻ������

	}

}


//BOOL CAboutDlg::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
//	// TODO:  Add extra initialization here
//	
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//				  // EXCEPTION: OCX Property Pages should return FALSE
//}
