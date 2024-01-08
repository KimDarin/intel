#include "pch.h"
#include "CmfcFindDlg.h"
#include "framework.h"
#include "mfcMemo1.h"
#include "mfcMemo1Dlg.h" 
#include "afxdialogex.h"


BEGIN_MESSAGE_MAP(CmfcFindDlg, CDialogEx)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

CmfcFindDlg::CmfcFindDlg() : CDialogEx(IDD_FIND_DIALOG)
{

}

void CmfcFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CmfcFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	mStr = "";

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CmfcFindDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_RETURN:					//정상적 입력 + Enter
		GetDlgItem(ID_EDIT_FIND)->GetWindowText(mStr);
		break;
	case VK_ESCAPE:					//esc로 종료할 때
		mStr = "";
		break;
	default:
		break;
	}
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CmfcFindDlg::PreTranslateMessage(MSG* pMsg)	//모든 이벤트에 대한 모든 메시지가 들어옴(이벤트 관문)
{
	switch (pMsg->message)	
	{
	case WM_KEYDOWN:			//그런 메시지 중에서 keydown 됐을 때에만 관심이 있음
		switch (pMsg->wParam)			//어떤 키가 눌렸는지 wParam에 들어있음
		{
		case VK_RETURN:					//정상적 입력 + Enter
			GetDlgItem(ID_EDIT_FIND)->GetWindowText(mStr);
			EndDialog(IDOK);	//이 dlg의 리턴값을 지정해서 던져줄 수 있음(IDOK로 지정해놨었음)
			break;
		case VK_ESCAPE:					//esc로 종료할 때
			mStr = "";
			EndDialog(IDCANCEL);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

