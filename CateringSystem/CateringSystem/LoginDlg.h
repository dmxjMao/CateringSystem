#pragma once


// CLoginDlg dialog

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLoginDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Lgoin };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	CString m_passwd;
	_RecordsetPtr m_pRs;

	virtual BOOL OnInitDialog();
	virtual void OnOK();
};
