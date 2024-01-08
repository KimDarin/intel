// mfcMemo1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfcMemo1.h"
#include "mfcMemo1Dlg.h"
#include "afxdialogex.h"
#include "CmfcFindDlg.h"
#include "CmfcReplace.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <fstream>
#include <iostream>
#include <cstring>


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CmfcMemo1Dlg 대화 상자
CmfcMemo1Dlg::CmfcMemo1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCMEMO1_DIALOG, pParent),
	lastSearch(-1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CmfcMemo1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_MEMO, mEditMemo);
}

BEGIN_MESSAGE_MAP(CmfcMemo1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENU_OPEN, &CmfcMemo1Dlg::OnMenuOpen)
	ON_COMMAND(ID_MENU_ABOUT, &CmfcMemo1Dlg::OnMenuAbout)
	ON_COMMAND(ID_MENU_FIND, &CmfcMemo1Dlg::OnMenuFind)
	ON_COMMAND(ID_MENU_FIND_NEXT, &CmfcMemo1Dlg::OnMenuFindNext)
	ON_COMMAND(ID_MENU_REPLACE, &CmfcMemo1Dlg::OnMenuReplace)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CmfcMemo1Dlg 메시지 처리기

BOOL CmfcMemo1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	mAccel = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCEL1));
	mStatusBar.Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 0); //CRect(좌상우하)
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 2);
	GetDynamicLayout()->AddItem(mStatusBar.GetSafeHwnd(), 
		CMFCDynamicLayout::MoveVertical(100), 
		CMFCDynamicLayout::SizeHorizontal(100));
	int sec[] = { 100, 200 };	
	mStatusBar.SetParts(2, sec);
	mStatusBar.SetText(" Test1", 0, SBT_NOBORDERS);
	mStatusBar.SetText(" Test2", 1, SBT_NOBORDERS);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcMemo1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcMemo1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmfcMemo1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CmfcMemo1Dlg::OnMenuOpen()		//file open menu 처리기
{
	char buf[512];
	CString str;

	char fName[100];				//ofn의 filename을 저장하기 위한 공간
	OPENFILENAME ofn;				//OPENFILENAME이라는 구조체가 있음
	ZeroMemory(&ofn, sizeof(ofn));	//메모리 공간 청소
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrFile = fName;
	ZeroMemory(fName, sizeof(fName));
	ofn.nMaxFile = 100;
	ofn.lpstrDefExt = "";	//wild타입으로 적용해주기 위해 'L' 붙임
	
	if (!GetOpenFileName(&ofn)) return;	//esc 눌렀을 경우(GetOpenFileNameW(&ofn) == 0과 같음)
	
	str = buf;	//CString은 WCHAR을 다이렉트로 대입 가능, char도 대입 가능
	
	/*C언어 표준 함수. ANSI encoding
	FILE* fp = fopen(fName, "rb");		
	while (fgets(buf, 512, fp))
	{
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		//((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowTextW(str); 얘가 정석임~!~!

		GetDlgItem(IDC_EDIT1)->SetWindowText(str + buf);
	}*/

	//C++ stream 표준, UTF-8 encoding
	wchar_t buf1[512];
	std::locale::global(std::locale(".UTF-8"));
	std::wifstream ff(fName);	// = FILE* fp = fopen(CStringA(str), "rb");
	//ff.open(fName);

	for (; ff.getline(buf1, 512);)	//getline은 줄바꿈 문자들을 다 날려버림
	{
		str = buf1;
		AddText(str); AddText("\r\n");
	}
}

void CmfcMemo1Dlg::AddText(CString s)	//입력기 함수(기존에 있는 문자열에 add만 해줌)
{
	CString str;
	((CEdit*)GetDlgItem(IDC_EDIT_MEMO))->GetWindowText(str);
	str += s;
	GetDlgItem(IDC_EDIT_MEMO)->SetWindowText(str);
}

void CmfcMemo1Dlg::OnMenuAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}


void CmfcMemo1Dlg::OnMenuFind()		//찾기 함수
{
	//CmfcFindDlg dlg;
	if (m_findDlg.DoModal() == IDOK)	//find할 문자열 입력
	{
		CString s;
		mEditMemo.GetWindowText(s);
		int start = s.Find(m_findDlg.mStr);		//찾고자 하는 문자열의 위치를 가져올 수 있음
		int end = start + m_findDlg.mStr.GetLength();
		mEditMemo.SetSel(start, end); 	
		
		lastSearch = end;
		//select 해주는 함수(드래그) 
		//인자에는 start 포지션과 end 포지션(start+해당문자열의 길이)을 적어야함
		// 
		//AddText(dlg.mStr);	//mStr = 입력한 값
	}
}

void CmfcMemo1Dlg::OnMenuFindNext()	//다음 찾기
{
	//CmfcFindDlg dlg;

	CString s;
	mEditMemo.GetWindowText(s);

	// 현재 선택된 부분의 끝 다음 위치부터 찾기 시작
	lastSearch = s.Find(m_findDlg.mStr, lastSearch + 1);

	if (lastSearch != -1)
	{
		int end = lastSearch + m_findDlg.mStr.GetLength();
		mEditMemo.SetSel(lastSearch, end);
	}
}

void CmfcMemo1Dlg::OnMenuReplace()
{
	CmfcReplace dlg;
	if (dlg.DoModal() == IDOK)	//find & replace 할 문자열 입력
	{
		CString s;
		mEditMemo.GetWindowText(s);
		sFind = dlg.mStrFind;
		sReplace = dlg.mStrReplace;
		s.Replace(sFind, sReplace);
		mEditMemo.SetWindowText(s);
	}
}

BOOL CmfcMemo1Dlg::PreTranslateMessage(MSG* pMsg)
{
	if (mAccel)
	{
		if (TranslateAccelerator(m_hWnd, mAccel, pMsg))	return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CmfcMemo1Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
