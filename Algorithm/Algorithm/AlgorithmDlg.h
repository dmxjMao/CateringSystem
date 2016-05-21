
// AlgorithmDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CAlgorithmDlg dialog
class CAlgorithmDlg : public CDialogEx
{
// Construction
public:
	CAlgorithmDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALGORITHM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	// add tree parent item
	// add tree sibling item

	// add description

public:
	CTreeCtrl m_tree;
	CStatic m_stsDescription;
	afx_msg void OnSelchangedProblems(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDblclkProblems(NMHDR *pNMHDR, LRESULT *pResult);
};
