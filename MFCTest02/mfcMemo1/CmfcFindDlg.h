#pragma once
#include <afxdialogex.h>
class CmfcFindDlg :
    public CDialogEx
{
public:
    CString mStr;

    CmfcFindDlg();

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_FIND_DIALOG };
#endif
    virtual void CmfcFindDlg::DoDataExchange(CDataExchange* pDX);

    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()

    virtual BOOL PreTranslateMessage(MSG* pMsg);
};

