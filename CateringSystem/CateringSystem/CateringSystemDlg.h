
// CateringSystemDlg.h : header file
//

#pragma once


// CCateringSystemDlg dialog
class CCateringSystemDlg : public CDialogEx
{
// Construction
public:
	CCateringSystemDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CATERINGSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CImageList		m_ImageList;
	CStatusBar		m_StatusBar;
	CToolBar		m_ToolBar;
	_RecordsetPtr m_pRs;

	afx_msg void OnMenuLogin();
};
