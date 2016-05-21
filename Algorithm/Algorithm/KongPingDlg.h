#pragma once
#include "afxwin.h"


// CKongPingDlg dialog

class CKongPingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CKongPingDlg)

public:
	CKongPingDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CKongPingDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KongPing };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_NumPersons;
//	CString m_NumPersons;
	int m_NumExchange;
	int m_NumPersons;
	CEdit m_result;
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void PostNcDestroy();
	afx_msg void OnClickedCalc();


	// calc the result
	void f(int kong, int yu, int& sum);
};
