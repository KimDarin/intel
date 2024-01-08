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

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CmfcFindDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_RETURN:					//������ �Է� + Enter
		GetDlgItem(ID_EDIT_FIND)->GetWindowText(mStr);
		break;
	case VK_ESCAPE:					//esc�� ������ ��
		mStr = "";
		break;
	default:
		break;
	}
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CmfcFindDlg::PreTranslateMessage(MSG* pMsg)	//��� �̺�Ʈ�� ���� ��� �޽����� ����(�̺�Ʈ ����)
{
	switch (pMsg->message)	
	{
	case WM_KEYDOWN:			//�׷� �޽��� �߿��� keydown ���� ������ ������ ����
		switch (pMsg->wParam)			//� Ű�� ���ȴ��� wParam�� �������
		{
		case VK_RETURN:					//������ �Է� + Enter
			GetDlgItem(ID_EDIT_FIND)->GetWindowText(mStr);
			EndDialog(IDOK);	//�� dlg�� ���ϰ��� �����ؼ� ������ �� ����(IDOK�� �����س�����)
			break;
		case VK_ESCAPE:					//esc�� ������ ��
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

