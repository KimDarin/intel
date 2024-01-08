// mfcMemo1Dlg.h: 헤더 파일
//

#pragma once
#include "CmfcFindDlg.h"

// CmfcMemo1Dlg 대화 상자
class CmfcMemo1Dlg : public CDialogEx
{
// 생성입니다.
	CString sFind, sReplace;
public:
	CmfcMemo1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCMEMO1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	HACCEL mAccel;
	CEdit mEditMemo;
	CStatusBarCtrl mStatusBar;
	CmfcFindDlg m_findDlg;
	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private: 
	int lastSearch;
public:
	afx_msg void OnMenuOpen();
	afx_msg void OnMenuAbout();
	afx_msg void OnMenuFind();
	void AddText(CString s);
	afx_msg void OnMenuFindNext();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnMenuReplace();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
